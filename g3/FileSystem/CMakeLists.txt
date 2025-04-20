add_library(FileSystem STATIC)
add_library(g3sdk::g3::FileSystem ALIAS FileSystem)

target_gothic_lib_options(FileSystem)

target_link_libraries(FileSystem
  PUBLIC SharedBase
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/FileSystem.lib)

target_include_directories(FileSystem
  PUBLIC include
  PUBLIC include/g3sdk)

target_tree_sources(FileSystem
  BASE include/g3sdk
  PRIVATE
    FileSystem.h

  BASE include/g3sdk/FileSystem
  PRIVATE
    gfs_filesystemmodule.h
    gfs_modulefilesystem.h

  BASE src
  PRIVATE
    FileSystem.cpp
)
