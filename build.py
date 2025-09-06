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

@click.command()
@click.option("--keep-build", "-K", help="Keeps the current build directory.", is_flag=True)
@click.option("--vcpkg-root", "-V", help=f"Location of VCPKG. (default: {os.getenv("VCPKG_ROOT")})", default=os.getenv("VCPKG_ROOT"), type=str)
@click.option("--vcpkg-triplet", "-T", help="Target triplet for VCPKG. (default: x64-windows)", default="x64-windows", type=str)
@click.option("--config-only", "-C", help="Only generates config files, no building.", is_flag=True)
def main(keep_build, vcpkg_root, vcpkg_triplet, config_only):
	os.chdir(os.path.dirname(__file__))
	if not keep_build:
		shutil.rmtree("build")
	runpy.run_path(os.path.join(os.path.dirname(__file__), "src", "kty", "conv-all.py"))
	os.chdir(os.path.dirname(__file__))
	print(f"{c.Fore.CYAN}Configuring with VCPKG at {c.Fore.GREEN}{vcpkg_root}{c.Style.RESET_ALL}")
	if os.system(f"cmake -B build -G\"Visual Studio 17 2022\" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=GDExtensionTemplate-install -DCMAKE_TOOLCHAIN_FILE=\"{os.path.join(vcpkg_root, "scripts", "buildsystems", "vcpkg.cmake")}\" -DVCPKG_TARGET_TRIPLET={vcpkg_triplet}") != 0:
		print(f"{c.Fore.RED}CMake config generation failed!{c.Style.RESET_ALL}")
		exit(1)
	print(f"{c.Fore.GREEN}CMake config generation successful!{c.Style.RESET_ALL}")
	if config_only:
		exit(0)
	if os.system("cmake --build build --config Release") != 0:
		print(f"{c.Fore.RED}CMake build failed!{c.Style.RESET_ALL}")
		exit(1)

if __name__ == "__main__":
	main()