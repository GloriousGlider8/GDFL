import os
import colorama as c
import shutil
import click
import re

@click.command()
@click.option("--keep-build", "-K", help="Keeps the current build directory.", is_flag=True)
@click.option("--config-only", "-C", help="Only generates config files, no building.", is_flag=True)
@click.option("--debug", "-D", help="Generates a debug build.", is_flag=True)
@click.option("--godot-library", "-G", help="Name of library to use from godot-cpp. (default: windows.template_[buildtype].x86_64)", default="[DEFAULT]", type=str)
def main(keep_build, config_only, debug, godot_library):
	btype = "Debug" if debug else "Release"
	if godot_library == "[DEFAULT]":
		godot_library = f"windows.template_{btype.lower()}.x86_64"

	os.chdir(os.path.dirname(__file__))
  
	if not keep_build and os.path.exists("build"):
		shutil.rmtree("build")
	
	print("Configuring build...")
	if os.system(f"cmake -B build -DCMAKE_BUILD_TYPE={btype} -DCMAKE_INSTALL_PREFIX=GDExtensionTemplate-install -DGODOT_LIB_IMPORT=\"{os.path.join(os.path.dirname(__file__), "extern", "godot-cpp", "build", "bin", "libgodot-cpp." + godot_library + ".lib")}\" > {os.path.join(os.path.dirname(__file__), "logs", "config.log")}") != 0:
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
	shutil.copytree(os.path.join(os.path.dirname(__file__), "build", "GDFL"), os.path.join(os.path.dirname(__file__), os.path.join("testproj", "addons", "gdfl")), dirs_exist_ok=True)

if __name__ == "__main__":
	main()