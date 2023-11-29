# CMake DPP template
Cross-platform template for Discord bot written with DPP library and modern CMake build system. 

### Get the repository.
You can either your own Github repository from this template, or you can just download it directly as a zip file.

### Set up the repository.
Open terminal in the project directory and initialize the submodules with the following command:
```bash
git init && git submodule update --init --recursive
```

### Build the project
#### No IDE, just CLI
In the project directory, create the build folder and generate the CMake.
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug # Choose your build type, Debug/Release/RelWithDebInfo
```
You can then build the project.
```bash
cmake --build .
```