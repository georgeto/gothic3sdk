add_library(GFC STATIC)
add_library(g3sdk::g3::GFC ALIAS GFC)

target_gothic_lib_options(GFC)

target_link_libraries(GFC
  PUBLIC GUI
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/GFC.lib)

target_include_directories(GFC
  PUBLIC include
  PUBLIC include/g3sdk)

target_tree_sources(GFC
  BASE include/g3sdk
  PRIVATE
    GFC.h

  # TODO: Organize sources in folders.
  BASE include/g3sdk/GFC
  PRIVATE
    gfc_animatectrl.h
    gfc_animatedimage.h
    gfc_bitmap.h
    gfc_bitmapmap.h
    gfc_button.h
    gfc_checkbox.h
    gfc_dataexchange.h
    gfc_devicecontext.h
    gfc_devicecontextmap.h
    gfc_dialog.h
    gfc_edit.h
    gfc_font.h
    gfc_iffgfcclient.h
    gfc_imagelist.h
    gfc_imagelistmap.h
    gfc_listbox.h
    gfc_listctrl.h
    gfc_module.h
    gfc_progressbar.h
    gfc_radiobutton.h
    gfc_scrollbar.h
    gfc_slider.h
    gfc_static.h
    gfc_tabctrl.h
    gfc_toolbarctrl.h
    gfc_tooltipctrl.h
    gfc_view.h
    gfc_wnd.h
    gfc_wndmap.h

  BASE src
  PRIVATE
    GFC.cpp
)
