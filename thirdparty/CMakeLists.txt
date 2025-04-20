# Include and configure CPM package manager.
set(CPM_USE_NAMED_CACHE_DIRECTORIES ON)
include(${G3SDK_CMAKE_DIR}/CPM.cmake)

add_subdirectory(asmjit)
add_subdirectory(distorm)
add_subdirectory(EABase)
add_subdirectory(EASTL)
