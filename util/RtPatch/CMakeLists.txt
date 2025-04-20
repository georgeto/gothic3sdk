add_library(RtPatch STATIC)
add_library(g3sdk::util::RtPatch ALIAS RtPatch)

target_gothic_common_options(RtPatch)
target_include_directories(RtPatch
  PUBLIC include
  PRIVATE include/g3sdk/util)

target_link_libraries(RtPatch PUBLIC RtPatchPure SharedBase)

target_tree_sources(RtPatch
  BASE include/g3sdk/util
  PRIVATE
    Hook.h

  BASE src
  PRIVATE
    Hook.cpp
)
