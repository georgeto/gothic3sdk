add_library(GUI STATIC)
add_library(g3sdk::g3::GUI ALIAS GUI)

target_gothic_lib_options(GUI)

target_link_libraries(GUI
  PUBLIC SharedBase
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/GUI.lib)

target_include_directories(GUI
  PUBLIC include
  PUBLIC include/g3sdk)

target_tree_sources(GUI
  BASE include/g3sdk
  PRIVATE
    GUI.h

  BASE include/g3sdk/GUI
  PRIVATE
    gui_guimodule.h
    gui_guimsgproc.h
    gui_guirenderer.h
    gui_modulegui.h

  BASE src
  PRIVATE
    GUI.cpp
)
