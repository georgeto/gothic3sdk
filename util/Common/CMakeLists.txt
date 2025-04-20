add_library(Common STATIC)
add_library(g3sdk::util::Common ALIAS Common)

target_gothic_common_options(Common)
target_include_directories(Common
  PUBLIC include
  PRIVATE include/g3sdk/util)

target_link_libraries(Common PUBLIC RtPatch RtLogAndError Game)

target_tree_sources(Common
  BASE include/g3sdk/util
  PRIVATE
    Concurrency.h
    GameUtil.h
    Module.h
    Util.h

    property/me_defaultproperty.h
    property/me_defaultproperty.inl

  BASE src
  PRIVATE
    Concurrency.cpp
    GameUtil.cpp
    Module.cpp
    Util.cpp
)
