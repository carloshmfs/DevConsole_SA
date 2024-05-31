# Build

## Requirements

* [CMake](https://cmake.org/download/)
* [PluginSDK](https://github.com/DK22Pac/plugin-sdk)

Clone the repository:
```bash
git clone --recurse-submodules https://github.com/carloshmfs/DevConsole_SA.git
```

And generate the build script files:

```bash
cmake -A Win32 -B build
```

Then Compile with:
```bash
cmake --build build
```
