add_library(distorm STATIC IMPORTED GLOBAL)

target_include_directories(distorm INTERFACE include)

set_target_properties(distorm
  PROPERTIES
    IMPORTED_LOCATION_DEBUG ${CMAKE_CURRENT_LIST_DIR}/lib/distorm_d.lib
    IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/lib/distorm.lib
)
