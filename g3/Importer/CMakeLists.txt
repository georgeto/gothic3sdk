add_library(Importer STATIC)
add_library(g3sdk::g3::Importer ALIAS Importer)

target_gothic_lib_options(Importer)

target_link_libraries(Importer
  PUBLIC Game GFC
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/Importer.lib)

target_include_directories(Importer
  PUBLIC include
  PUBLIC include/g3sdk)

target_tree_sources(Importer
  BASE include/g3sdk
  PRIVATE
    Importer.h

  BASE include/g3sdk/Importer
  PRIVATE
    gi_importeradmin.h
    gi_layercompiler.h
    gi_meshimporter.h
    gi_resourcecompiler.h
    gi_scenecompiler.h
    gi_sectorcompiler.h
    gi_texturebaker.h

  BASE src
  PRIVATE
    Importer.cpp
)
