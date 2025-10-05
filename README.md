# Gothic 3 SDK
This unofficial Gothic 3 SDK is intended for modders with experience in C++ and reverse engineering.

The Gothic 3 game engine (Genome) consists of multiple dynamic-link libraries (DLLs) that depend on one another. Therefore, each of these DLLs exports most of its functionality.
We can reconstruct C++ class and function declarations from the exported symbols, which we then use to interface with the engine.

#### Note for existing users of the Gothic 3 SDK
In April 2025 a major overhaul of the SDK was released, which now uses CMake as its build system instead of Visual Studio. Furthermore, the previously incomplete bindings were completed, so that now there are bindings for all symbols exported by the Gothic 3 DLLs.

## Binary compatibility
Gothic 3 was build using Visual Studio 2005 (platform toolset v80) so for optimal compatibility we should use the same compiler for our project.
Citing the MSVC documentation regarding the [topic of binary compatibility](https://docs.microsoft.com/en-us/cpp/porting/binary-compat-2015-2017?view=vs-2019):
> In Visual Studio 2013 and earlier, binary compatibility between object files (OBJs), static libraries (LIBs), dynamic libraries (DLLs), and executables (EXEs) built by using different versions of the compiler toolset and runtime libraries was not guaranteed.

But let's face it, no one wants to work with Visual Studio 2005 these days.
After extensive testing I came to the conclusion that although not officially guaranteed, Visual Studio 2013 (platform toolset v120) seems to be binary compatible with the v80 compiler, at least in the areas relevant for this project.
Using the v120 compiler has the advantage of an improved IDE and the ability to use C++11 language features.
Even more recent versions of Visual Studio (MSVC compiler) turned out to work fine, the most recent that the Gothic 3 SDK was extensively tested with is Visual Studio 2022 (v143) with the C++17 Language Standard.

## Usage
Examples of using the Gothic 3 SDK are provided in the [gothic3sdk-examples](https://github.com/georgeto/gothic3sdk-examples) repository.
It also serves as a template and inspiration on how to use or integrate the Gothic 3 SDK into your own project.
For a list of possible integration options, see [Integration](#integration).

## Building
The Gothic 3 SDK is built with [CMake](https://cmake.org/).

To download and build the Gothic 3 SDK (here using Visual Studio 2022) execute the following commands:
```cmd
git clone https://github.com/georgeto/gothic3sdk
cd gothic3sdk
cmake -S . -B build -G "Visual Studio 17 2022" -A Win32
cmake --build build --config Release -j
```

The above sequence creates a build directory, generates a Visual Studio solution, and then builds the project in Release mode.
If you prefer working from within Visual Studio, you can skip the last build step and instead open the generated solution in Visual Studio and then build from there.

## Integration
There are several ways to integrate the Gothic 3 SDK into your project.
If you use CMake as your build system, you can choose to integrate it by fetching it with a package manager like [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) or using CMake's [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) module.
Alternatively you can include it as a Git submodule, or in vendor library style, by putting a copy of the gothic3sdk repository into your project.

### CPM
To integrate the Gothic 3 SDK via [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake?tab=readme-ov-file#setup-free-cmake-dependency-management), add the following snippet to your project's `CMakeLists.txt`, which will fetch and configure the SDK automatically during the CMake generation step:

```cmake
# Fetch and setup gothic3sdk.
CPMAddPackage(
  NAME gothic3sdk
  OPTIONS
    "G3SDK_HEADER_ONLY OFF"
  GITHUB_REPOSITORY georgeto/gothic3sdk
  GIT_TAG <revision to checkout>
)
include(${gothic3sdk_SOURCE_DIR}/cmake/Setup.cmake)
```

To see this in action, have a look at the [Gothic 3 SDK examples](https://github.com/georgeto/gothic3sdk-examples).

#### Local override
If you need to override the gothic3sdk package locally, for example when you need to modify the Gothic 3 SDK itself, please refer to the [local package override](https://github.com/cpm-cmake/CPM.cmake?tab=readme-ov-file#local-package-override) feature of CPM.make.

For the CMake generation step you can specify the location of your local gothic3sdk repository.
```cmake
cmake -S . -B build -G "Visual Studio 17 2022" -A Win32 -DCPM_gothic3sdk_SOURCE=C:/path/to/your/local/gothic3sdk
```

### Git submodule
To integrate the Gothic 3 SDK as a Git submodule, run the following commands in your project's root directory:

```cmd
git submodule add https://github.com/georgeto/gothic3sdk.git thirdparty/gothic3sdk
git submodule update --init --recursive
```

Then, include the SDK into your build by adding the following line to your `CMakeLists.txt`:
```cmake
add_subdirectory(thirdparty/gothic3sdk)
include(thirdparty/gothic3sdk/cmake/Setup.cmake)
```

### Vendor library style
For a vendor library style integration just put a copy of the gothic3sdk into a subfolder within your project (for example, `thirdparty/gothic3sdk`).

Then, include the SDK into your build by adding the following line to your `CMakeLists.txt`:
```cmake
add_subdirectory(thirdparty/gothic3sdk)
include(thirdparty/gothic3sdk/cmake/Setup.cmake)
```

## Formatting
All code, except  third-party code, is formatted with clang-format according to the style configured in [.clang-format](.clang-format).

## Exception Handling
By default C++ exception handling is disabled (see [MSVC: Default exception handling behavior](https://learn.microsoft.com/en-us/cpp/build/reference/eh-exception-handling-model?view=msvc-170#default-exception-handling-behavior)).
This is sufficient, because Gothic 3 does not use C++ exceptions, but only structured exception handling (SEH).

In case you use a library that needs C++ exception handling, you can set `target_compile_options(<my_target> PRIVATE "/EHsc")` to enable it for your target (see for example [Script_DumpProperties](https://github.com/georgeto/gothic3sdk-examples/blob/master/examples/Script_DumpProperties/CMakeLists.txt) and [Script_RemoteControl](https://github.com/georgeto/gothic3sdk-examples/blob/examples/Script_RemoteControl/CMakeLists.txt)).

## Legacy Version
For the legacy version of the Gothic 3 SDK, which does not use CMake but is only a Visual Studio Project, see the `legacy` branch.
It should be noted, however, that the legacy version is incomplete, i.e. it is missing a lot of bindings.

## Credits
* NicoDE for his [RisenSDK](https://forum.worldofplayers.de/forum/threads/886883-release-RisenSDK), which was a great inspiration for the develompent of the Gothic 3 SDK.
* Baltram for his contributions to the [RisenSDK](https://forum.worldofplayers.de/forum/threads/886883-release-RisenSDK)
* [AsmJit](https://github.com/asmjit/asmjit)
* [AsmTK](https://github.com/asmjit/asmtk)
* [diStorm3](https://github.com/gdabah/distorm)
