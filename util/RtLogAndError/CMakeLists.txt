add_library(RtLogAndError STATIC)
add_library(g3sdk::util::RtLogAndError ALIAS RtLogAndError)

target_gothic_common_options(RtLogAndError)
target_include_directories(RtLogAndError
  PUBLIC include
  PRIVATE include/g3sdk/util)

target_link_libraries(RtLogAndError PUBLIC RtError SharedBase)

target_tree_sources(RtLogAndError
  BASE include/g3sdk/util
  PRIVATE
    Logging.h
    Logging.inl

  BASE src
  PRIVATE
    Error.cpp
    Logging.cpp
)
