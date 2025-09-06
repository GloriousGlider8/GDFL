import os
import colorama as c

os.rmdir("build")
os.system("vcpkg install gtest")
os.system("vcpkg install zlib")
os.system("cls")
if os.system("cmake -B build -G\"Visual Studio 17 2022\" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=GDExtensionTemplate-install -DCMAKE_TOOLCHAIN_FILE=\"D:\\vcpkg\scripts\\buildsystems\\vcpkg.cmake\"") != 0:
	print(f"{c.Fore.RED}CMake config generation failed!{c.Style.RESET_ALL}")
	exit(1)
os.system("cmake --build build --config Release")