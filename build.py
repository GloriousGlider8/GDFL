import os
import colorama as c
import shutil
import runpy
import click

# Required libraries:
# VCPKG
#   zlib
#   libiconv
#   gtest
#   kaitai-struct-cpp-stl-runtime
# Python
#   click
#   colorama

# We need to prebuild godot-cpp so that we don't rebuild it every time we compile

@click.command()
@click.option("--keep-build", "-K", help="Keeps the current build directory.", is_flag=True)
@click.option("--vcpkg-root", "-V", help=f"Location of VCPKG. (default: {os.getenv("VCPKG_ROOT")})", default=os.getenv("VCPKG_ROOT"), type=str)
@click.option("--vcpkg-triplet", "-T", help="Target triplet for VCPKG. (default: x64-windows)", default="x64-windows", type=str)
@click.option("--config-only", "-C", help="Only generates config files, no building.", is_flag=True)
@click.option("--debug", "-D", help="Generates a debug build.", is_flag=True)
@click.option("--godot-library", help="Name of library to use from godot-cpp. (default: windows.debug.64)", default="windows.debug.64", type=str)
def main(keep_build, vcpkg_root, vcpkg_triplet, config_only, debug, godot_library):
	btype = "Debug" if debug else "Release"
 
	os.chdir(os.path.dirname(__file__))
 
	if not os.path.exists(os.path.join("ffl", "build", btype, "ffl.lib")):
		os.chdir("ffl")
		print(f"{c.Fore.CYAN}Building FFL...{c.Style.RESET_ALL}")
		os.system(f"cmake -S . -B build -DFFL_BUILD_SHARED=1 > {os.path.join(os.path.dirname(__file__), "logs", "ffl-config.log")}")
		os.system(f"cmake --build build --config {btype} > {os.path.join(os.path.dirname(__file__), "logs", "ffl-build.log")}")
	
	os.chdir(os.path.dirname(__file__))
 
	if not os.path.exists(os.path.join("kaitai_struct_cpp_stl_runtime", "build", btype, "kaitai_struct_cpp_stl_runtime.lib")):
		os.chdir("kaitai_struct_cpp_stl_runtime")
		print(f"{c.Fore.CYAN}Building kaitai_struct_cpp_stl_runtime...{c.Style.RESET_ALL}")
		os.system(f"cmake -S . -B build -DBUILD_TESTS=OFF > {os.path.join(os.path.dirname(__file__), "logs", "kt-config.log")}")
		os.system(f"cmake --build build --config {btype} > {os.path.join(os.path.dirname(__file__), "logs", "kt-build.log")}")
	
	os.chdir(os.path.dirname(__file__))

	if not os.path.exists(os.path.join("extern", "godot-cpp", "build", "bin", btype, "godot-cpp." + godot_library + ".lib")):
		os.chdir(os.path.join("extern", "godot-cpp"))
		print(f"{c.Fore.CYAN}Building godot-cpp...{c.Style.RESET_ALL}")
		os.system(f"cmake -S . -B build > {os.path.join(os.path.dirname(__file__), "logs", "godot-config.log")}")
		os.system(f"cmake --build build --config {btype} > {os.path.join(os.path.dirname(__file__), "logs", "godot-build.log")}")

	os.chdir(os.path.dirname(__file__))
  
	if not keep_build and os.path.exists("build"):
		shutil.rmtree("build")
 
	print(f"{c.Fore.CYAN}Configuring with VCPKG at {c.Fore.GREEN}{vcpkg_root}{c.Fore.CYAN}...{c.Fore.WHITE}{c.Style.DIM}")
	
	if os.system(f"cmake -B build -DCMAKE_BUILD_TYPE={btype} -DCMAKE_INSTALL_PREFIX=GDExtensionTemplate-install -DCMAKE_TOOLCHAIN_FILE=\"{os.path.join(vcpkg_root, "scripts", "buildsystems", "vcpkg.cmake")}\" -DVCPKG_TARGET_TRIPLET={vcpkg_triplet} -DGODOT_LIB_IMPORT=\"{os.path.join(os.path.dirname(__file__), "extern", "godot-cpp", "build", "bin", btype, "godot-cpp." + godot_library + ".lib")}\" -DFFL_LIB_IMPORT=\"{os.path.join(os.path.dirname(__file__), "ffl", "build", btype, "ffl.lib")}\" -DKT_LIB_IMPORT=\"{os.path.join(os.path.dirname(__file__), "kaitai_struct_cpp_stl_runtime", "build", btype, "kaitai_struct_cpp_stl_runtime.lib")}\" > {os.path.join(os.path.dirname(__file__), "logs", "config.log")}") != 0:
		print(f"{c.Style.RESET_ALL}{c.Fore.RED}CMake config generation failed!\n{c.Fore.LIGHTRED_EX}Logs written to logs/config.log{c.Style.RESET_ALL}")
		exit(1)
  
	print(f"{c.Style.RESET_ALL}{c.Fore.GREEN}CMake config generation successful!{c.Fore.CYAN}\nBuilding...{c.Fore.WHITE}{c.Style.DIM}")
 
	if config_only:
		print(c.Style.RESET_ALL, end="")
		exit(0)
  
	if os.system(f"cmake --build build --config {btype} > {os.path.join(os.path.dirname(__file__), "logs", "build.log")}") != 0:
		print(f"{c.Style.RESET_ALL}{c.Fore.RED}CMake build failed!\n{c.Fore.LIGHTRED_EX}Logs written to logs/build.log{c.Style.RESET_ALL}")
		exit(1)
  
	print(f"{c.Style.RESET_ALL}{c.Fore.GREEN}Build successful!{c.Style.RESET_ALL}")

if __name__ == "__main__":
	main()