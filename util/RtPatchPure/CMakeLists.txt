add_library(RtPatchPure STATIC)
add_library(g3sdk::util::RtPatchPure ALIAS RtPatchPure)

target_gothic_common_options(RtPatchPure)
target_include_directories(RtPatchPure
  PUBLIC include
  PRIVATE include/g3sdk/util)

target_link_libraries(RtPatchPure PUBLIC RtError asmjit asmtk distorm)

# Use only includes from SharedBase, do not link against it.
target_include_directories(RtPatchPure
  PUBLIC $<TARGET_PROPERTY:SharedBase,INCLUDE_DIRECTORIES>)

target_tree_sources(RtPatchPure
  BASE include/g3sdk/util
  PRIVATE
    AsmjitUtil.h
    Memory.h

  BASE src
  PRIVATE
    AsmjitUtil.cpp
    Memory.cpp
)
