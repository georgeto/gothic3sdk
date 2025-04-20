# Check for supported compiler.
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # Using Visual Studio.
  set(G3SDK_TARGET_COMPILER_MSVC ON)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
  # Using clang with clang-cl front end.
  set(G3SDK_TARGET_COMPILER_CLANG_CL ON)
else()
  message(FATAL_ERROR "Compiler ${CMAKE_CXX_COMPILER_ID} is not supported! (MSVC or clang-cl required)")
endif()

# Only do these if this is the main project, and not if it is included through add_subdirectory.
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # Require out-of-source builds
  file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
  if(EXISTS "${LOC_PATH}")
      message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
  endif()

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

# Remove default flags provided with CMake.
# TODO: This might be suboptimal if user provide custom options via CXXFLAGS.
set(CMAKE_CXX_FLAGS "")
set(CMAKE_CXX_FLAGS_DEBUG "")
set(CMAKE_CXX_FLAGS_RELEASE "")

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
