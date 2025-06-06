add_library(Game STATIC)
add_library(g3sdk::g3::Game ALIAS Game)

target_gothic_lib_options(Game)

target_link_libraries(Game
  PUBLIC Engine
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/Game.lib)

target_include_directories(Game
  PUBLIC include
  PUBLIC include/g3sdk)

target_tree_sources(Game
  BASE include/g3sdk
  PRIVATE
    Game.h

  # TODO: Organize sources in folders.
  BASE include/g3sdk/Game
  PRIVATE
    GameEnum.h
    ge_aihelper_freepoint_ps.h
    ge_aihelper_label_ps.h
    ge_aizone_ps.h
    ge_ambientenvironment.h
    ge_ambientlibrary.h
    ge_ambientmodule.h
    ge_ambientsequencer.h
    ge_ambientsound.h
    ge_ambientsoundlist.h
    ge_ambientsystem.h
    ge_anchor_ps.h
    ge_arena_ps.h
    ge_armorset_ps.h
    ge_attrib.h
    ge_attribconddesc.h
    ge_attribdesc.h
    ge_attribmoddesc.h
    ge_attribute.h
    ge_boid.h
    ge_boidsadmin.h
    ge_book_ps.h
    ge_cameraai_ps.h
    ge_charactercontrol_ps.h
    ge_charactermovement_ps.h
    ge_charactersensor_ps.h
    ge_clock_ps.h
    ge_collisioncircle_ps.h
    ge_collisioncircle_psobj.h
    ge_damage_ps.h
    ge_damagereceiver_ps.h
    ge_database.h
    ge_dialog_ps.h
    ge_dialogmanagerctrl.h
    ge_distancetrigger_ps.h
    ge_door_ps.h
    ge_dummyvisualbase_ps.h
    ge_dynamiccollisioncircle_ps.h
    ge_ecaihelperadmin.h
    ge_editorentitypropertyset.h
    ge_effect.h
    ge_effect_ps.h
    ge_effectcommand.h
    ge_effectcommandcreatedecal.h
    ge_effectcommandearthquake.h
    ge_effectcommandkillentity.h
    ge_effectcommandmodifyentity.h
    ge_effectcommandmusictrigger.h
    ge_effectcommandplaysound.h
    ge_effectcommandplayvoice.h
    ge_effectcommandsequence.h
    ge_effectcommandspawnentity.h
    ge_effectcommandtriggerentity.h
    ge_effectmap.h
    ge_effectmodule.h
    ge_effectsystem.h
    ge_enclave_ps.h
    ge_enclaveadmin.h
    ge_entity.h
    ge_entitydummyvisual_ps.h
    ge_enumstr.h
    ge_eventscript_ps.h
    ge_flock_ps.h
    ge_focus_ps.h
    ge_gameapp.h
    ge_gsmapgenerate.h
    ge_gsmapmarker.h
    ge_guientityrenderer.h
    ge_guimanager.h
    ge_guimodule.h
    ge_hud.h
    ge_huddialog.h
    ge_hudmenu.h
    ge_hudpage.h
    ge_info_ps.h
    ge_infomanager_ps.h
    ge_infoscript_ps.h
    ge_infoscriptline_ps.h
    ge_interaction_ps.h
    ge_interactionadmin.h
    ge_item_ps.h
    ge_itemstats.h
    ge_letter_ps.h
    ge_lock_ps.h
    ge_magic_ps.h
    ge_magicbarrier_ps.h
    ge_map_ps.h
    ge_movementbase_ps.h
    ge_mover_ps.h
    ge_musicchannel.h
    ge_musicevent.h
    ge_musiceventfragment.h
    ge_musiceventstop.h
    ge_musiceventtransition.h
    ge_musicfragment.h
    ge_musicfragmentlist.h
    ge_musiclibrary.h
    ge_musiclink.h
    ge_musiclinksequence.h
    ge_musicmodule.h
    ge_musicsequencer.h
    ge_musicstream.h
    ge_musicsystem.h
    ge_musictransition.h
    ge_musictransitionlist.h
    ge_musictrigger.h
    ge_musictriggerlist.h
    ge_navhelper_ps.h
    ge_navigation_ps.h
    ge_navigationadmin.h
    ge_navigationmap.h
    ge_navoffset_ps.h
    ge_navpath_ps.h
    ge_navzone_ps.h
    ge_negzone_ps.h
    ge_negzone_psobj.h
    ge_npc_ps.h
    ge_npcadmin.h
    ge_npcinfoctrl.h
    ge_party_ps.h
    ge_playermemory_ps.h
    ge_prefpath_ps.h
    ge_prefpath_psobj.h
    ge_project.h
    ge_projectile_ps.h
    ge_propertydummyvisual_ps.h
    ge_quest_ps.h
    ge_questlogctrl.h
    ge_questmanager_ps.h
    ge_recipe_ps.h
    ge_screenoutputctrl.h
    ge_sectorpersistence_ps.h
    ge_session.h
    ge_sessioncheats.h
    ge_sessioneditor.h
    ge_sessioninfo.h
    ge_sessionkeys.h
    ge_skill_ps.h
    ge_stat.h
    ge_statistics_ps.h
    ge_stats.h
    ge_statsadmin.h
    ge_svmmanager.h
    ge_teleporter_ps.h
    ge_timezone_ps.h
    ge_touchdamage_ps.h
    ge_trait.h
    ge_traitdesc.h
    ge_treasureset_ps.h
    ge_treasuresetadmin.h
    ge_waterzone_ps.h
    ge_workspace.h
    dummycollector/ge_dummycollectoradmin.h
    dummycollector/ge_dummycollectoranchor.h
    dummycollector/ge_dummycollectorbase.h
    dummycollector/ge_dummycollectorcollisioncircle.h
    dummycollector/ge_dummycollectorcollisionshape.h
    dummycollector/ge_dummycollectordynamiccollisioncircle.h
    dummycollector/ge_dummycollectorenclave.h
    dummycollector/ge_dummycollectorentity.h
    dummycollector/ge_dummycollectorfreepoint.h
    dummycollector/ge_dummycollectorlinkcontainer.h
    dummycollector/ge_dummycollectornavoffset.h
    dummycollector/ge_dummycollectornavpath.h
    dummycollector/ge_dummycollectornavzone.h
    dummycollector/ge_dummycollectornegzone.h
    dummycollector/ge_dummycollectorparticle.h
    dummycollector/ge_dummycollectorprefpath.h
    dummycollector/ge_dummycollectorpset_base.h
    dummycollector/ge_dummycollectortreasureset.h
    inventory/ge_inventory_ps.h
    inventory/ge_inventorylistener.h
    inventory/ge_inventoryslot.h
    inventory/ge_inventorystack.h
    script/ge_scriptadmin.h
    script/ge_scriptadminext.h
    script/ge_scriptinit.h
    script/ge_scriptprocessingunit.h
    script/ge_scriptroutine_ps.h
    world/ge_dynamiclayer.h
    world/ge_geometrylayer.h
    world/ge_layerbase.h
    world/ge_sector.h
    world/ge_templatelayer.h
    world/ge_world.h

  BASE src
  PRIVATE
    script/ge_scriptadmin.cpp
    script/ge_scriptadminext.cpp
    script/ge_scriptinit.cpp
)
