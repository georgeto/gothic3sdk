include(${G3SDK_CMAKE_DIR}/TargetOptions.cmake)
include(${G3SDK_CMAKE_DIR}/TargetSources.cmake)

add_subdirectory(Common)
add_subdirectory(RtError)
add_subdirectory(RtLogAndError)
add_subdirectory(RtPatch)
add_subdirectory(RtPatchPure)
add_subdirectory(ScriptCommon)

add_library(util INTERFACE)
add_library(g3sdk::util ALIAS util)
target_link_libraries(util
  INTERFACE Common RtError RtLogAndError RtPatch RtPatchPure ScriptCommon)
