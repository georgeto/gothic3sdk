add_library(ScriptCommon STATIC)
add_library(g3sdk::util::ScriptCommon ALIAS ScriptCommon)

target_gothic_common_options(ScriptCommon)
target_include_directories(ScriptCommon
  PUBLIC include
  PRIVATE include/g3sdk/util)

target_link_libraries(ScriptCommon PUBLIC Common Script)

target_tree_sources(ScriptCommon
  BASE include/g3sdk/util
  PRIVATE
    Database.h
    PropertyCompare.h
    ScriptInterface.h
    ScriptUtil.h
    TypeUtil.h

  BASE src
  PRIVATE
    Database.cpp
    PropertyCompare.cpp
    ScriptUtil.cpp
    TypeUtil.cpp
)
