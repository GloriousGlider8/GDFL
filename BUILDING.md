# Building

## Preperation

* **Godot-CPP**
  * Get the Godot-CPP version for the Godot version you're compiling for from [here](https://github.com/godotengine/godot-cpp/releases)
  * Unzip it, and put the source in `extern/godot-cpp`
* **Mii.fu**
  * Update the repo with `git submodule update --recursive --remote extern/Mii.fu`
  * Install [fut](https://github.com/fusionlanguage/fut) if you haven't
  * Follow the instructions in `extern/Mii.fu/GENERATING.txt`

## Building

Now, just use CMake, for example:

```bash
cmake -S . -B build
cmake --build build
```

And there you go! The build files will appear in `build/GDFL` ready for you to install!
