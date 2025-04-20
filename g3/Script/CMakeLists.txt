add_library(Script STATIC)
add_library(g3sdk::g3::Script ALIAS Script)

target_gothic_lib_options(Script)

target_link_libraries(Script
  PUBLIC Game
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/Script.lib)

target_include_directories(Script
  PUBLIC include
  PUBLIC include/g3sdk)

target_tree_sources(Script
  BASE include/g3sdk
  PRIVATE
    Script.h

  BASE include/g3sdk/Script
  PRIVATE
    ScriptEnum.h
    gs_entity.h
    gs_gui.h
    gs_gui2.h
    gs_info.h
    gs_music.h
    gs_scriptargs.h
    gs_scriptmacros.h
    gs_template.h
    gs_world.h
    effect/gs_effect.h
    effect/gs_effectsystem.h
    propertyset/gs_propertymacros.h
    propertyset/gs_propertymacros.inl
    propertyset/gs_psaizone.h
    propertyset/gs_psanchor.h
    propertyset/gs_psanimation.h
    propertyset/gs_psarena.h
    propertyset/gs_psbook.h
    propertyset/gs_pscamera.h
    propertyset/gs_pscharactercontrol.h
    propertyset/gs_pscharactermovement.h
    propertyset/gs_psclock.h
    propertyset/gs_pscollisionshape.h
    propertyset/gs_psdamage.h
    propertyset/gs_psdamagereceiver.h
    propertyset/gs_psdialog.h
    propertyset/gs_psdoor.h
    propertyset/gs_pseffect.h
    propertyset/gs_psenclave.h
    propertyset/gs_psfocus.h
    propertyset/gs_psinfomanager.h
    propertyset/gs_psinfoscriptcommand.h
    propertyset/gs_psinteraction.h
    propertyset/gs_psinventory.h
    propertyset/gs_psitem.h
    propertyset/gs_psitemwrapper.h
    propertyset/gs_psletter.h
    propertyset/gs_pslock.h
    propertyset/gs_psmagic.h
    propertyset/gs_psmap.h
    propertyset/gs_psmover.h
    propertyset/gs_psnavigation.h
    propertyset/gs_psnpc.h
    propertyset/gs_psparticle.h
    propertyset/gs_psparty.h
    propertyset/gs_psplayermemory.h
    propertyset/gs_psprojectile.h
    propertyset/gs_psquestmanager.h
    propertyset/gs_psrecipe.h
    propertyset/gs_psrigidbody.h
    propertyset/gs_psroutine.h
    propertyset/gs_psskill.h
    propertyset/gs_psstatistics.h
    propertyset/gs_psstrip.h
    propertyset/gs_pstouchdamage.h
    propertyset/gs_pstreasureset.h
    propertyset/gs_pstrigger.h

  BASE src
  PRIVATE
    propertyset/gs_psitemwrapper.cpp
)
