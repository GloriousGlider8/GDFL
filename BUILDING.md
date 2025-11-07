# Building

## Preperation

* **Godot-CPP**
  * Get the Godot-CPP version for the Godot version you're compiling for from [here](https://github.com/godotengine/godot-cpp/releases)
  * Unzip it, and put the source in `extern/godot-cpp`
  * Build it using cmake.
* **Mii.fu**
  * Update the repo with `git submodule update --recursive --remote extern/Mii.fu`
  * Install [fut](https://github.com/fusionlanguage/fut) if you haven't
  * Follow the instructions in `extern/Mii.fu/GENERATING.txt`

## Requirements

* **PyPi** (only needed if you're building with `build.py`)
  * `colorama`
  * `click`
