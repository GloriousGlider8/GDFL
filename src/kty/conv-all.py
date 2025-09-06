import glob
import os

os.chdir(os.path.dirname(__file__))

for f in glob.glob("*.ksy"):
    os.system("kaitai-struct-compiler -t cpp_stl " + f)