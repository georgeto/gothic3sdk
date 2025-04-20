add_library(RtError INTERFACE)
add_library(g3sdk::util::RtError ALIAS RtError)

target_include_directories(RtError INTERFACE include)
