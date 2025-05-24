cmake_minimum_required(VERSION 3.16...3.24)

project(
  g3sdk
  VERSION 1.0.0
  DESCRIPTION "Gothic 3 SDK"
  LANGUAGES CXX C)

option(G3SDK_BINDING_ONLY "Use the binding only version of the library (no util and thirdparty)." OFF)
option(G3SDK_USE_STDCALL "Use the same calling convention as Gothic 3 by default. Avoids unpleasant surprises, as otherwise one has to be extremly careful to provide proper calling convetions when hooking into Gothic 3. However, under certain circumstances, such as using external (pre-compiled) libraries, it may be advantageous to not default to stdcall." ON)

# Check for supported architecture.
if (MSVC_CXX_ARCHITECTURE_ID)
  string(TOLOWER ${MSVC_CXX_ARCHITECTURE_ID} _TARGET_ARCHITECTURE)
else()
  string(TOLOWER ${CMAKE_SYSTEM_PROCESSOR} _TARGET_ARCHITECTURE)
endif()

if (NOT (_TARGET_ARCHITECTURE STREQUAL "x86"))
  message(FATAL_ERROR "Target architecture ${_TARGET_ARCHITECTURE} is not supported! (x86 32-bit required)")
endif()

# Use C++ 17.
set (CMAKE_CXX_STANDARD 17)

set(G3SDK_CMAKE_DIR ${PROJECT_SOURCE_DIR}/cmake)

include(${G3SDK_CMAKE_DIR}/SetupCommon.cmake)

add_library(SDK INTERFACE)
add_library(g3sdk::SDK ALIAS SDK)
target_link_libraries(SDK INTERFACE g3sdk::g3)

add_subdirectory(g3)

if (NOT G3SDK_BINDING_ONLY)
add_subdirectory(util)
target_link_libraries(SDK INTERFACE g3sdk::util)

add_subdirectory(thirdparty EXCLUDE_FROM_ALL)
endif()
