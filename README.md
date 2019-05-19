# Introduction
This inofficial Gothic 3 SDK is intended for modders with experience in C++ and reverse engineering.

The Gothic 3 game engine (Genome) consists of multiple dynamic-link libraries (DLLs) that depend on one another. Therefore, each of these DLLs exports most of its functionality.
We can reconstruct C++ class and function declarations from the exported symbols, which we then use to interface with the engine.

# Binary compatibility
Gothic 3 was build using Visual Studio 2005 (platform toolset v80) so for optimal compatibility we should use the same compiler for our project.
Citing the MSVC documentation regarding the [topic of binary compatibility](https://docs.microsoft.com/en-us/cpp/porting/binary-compat-2015-2017?view=vs-2019):
> In Visual Studio 2013 and earlier, binary compatibility between object files (OBJs), static libraries (LIBs), dynamic libraries (DLLs), and executables (EXEs) built by using different versions of the compiler toolset and runtime libraries was not guaranteed.

But let's face it, no one wants to work with Visual Studio 2005 these days.
After extensive testing I came to the conclusion that although not officially guaranteed, Visual Studio 2013 (platform toolset v120) seems to be binary compatible with the v80 compiler, at least in the areas relevant for this project.
Using the v120 compiler has the advantage of an improved IDE and the ability to use C++11 language features.

Possibly even more recent versions of Visual Studio (MSVC compiler) would work, but I haven't done extensive testing on that.

# Building
The Gothic 3 SDK is build using Visual Studio 2013 (Community Edition is sufficient).
Alternatively you can use a more recent version of Visual Studio, but you have to have the platform toolset v120 installed, which is shipped with Visual Studio 2013 (for background information see [Binary compatibility](#binary-compatibility)).

Under `source/Scripts/` you find a bunch of example projects and it's also the place where you can add your own creations.
The build artifacts end up in `bin/scripts/`.

# Installation
Copy the content of `bin` into your Gothic 3 installation directory.
Every DLL inside the `scripts` folder following the naming convention `Script_*.dll` is automatically loaded by the game.

# Credits
* NicoDE for his [RisenSDK](https://forum.worldofplayers.de/forum/threads/886883-release-RisenSDK), which was a great inspiration for the develompent of the Gothic 3 SDK.
* Baltram for his contributions to the [RisenSDK](https://forum.worldofplayers.de/forum/threads/886883-release-RisenSDK)
* [AsmJit](https://github.com/asmjit/asmjit)
* [AsmTK](https://github.com/asmjit/asmtk)
* [diStorm3](https://github.com/gdabah/distorm)
* [protobuf](https://github.com/protocolbuffers/protobuf)
* [ZeroMQ](https://github.com/zeromq/zeromq4-x)
* [PCG](http://www.pcg-random.org/)
