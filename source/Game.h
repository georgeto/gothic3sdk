#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Engine.h"

#include "Game/GameEnum.h"

#include "Game/ge_navigationadmin.h"
#include "Game/ge_navigationmap.h"

class gCSector;
class gCWorld;
#include "Game/ge_layerbase.h"
#include "Game/ge_dynamiclayer.h"
#include "Game/ge_geometrylayer.h"
#include "Game/ge_templatelayer.h"
#include "Game/ge_sector.h"
#include "Game/ge_world.h"

#include "Game/ge_scriptroutine_ps.h"
#include "Game/ge_scriptinit.h"
#include "Game/ge_scriptprocessingunit.h"
#include "Game/ge_scriptadmin.h"
#include "Game/ge_scriptadminext.h"

#include "Game/ge_attribute.h"
#include "Game/ge_stat.h"

class gCEntity;
#include "Game/ge_clock_ps.h"
#include "Game/ge_cameraai_ps.h"
#include "Game/ge_armorset_ps.h"
#include "Game/ge_treasureset_ps.h"
#include "Game/ge_inventoryslot.h"
#include "Game/ge_inventorystack.h"
#include "Game/ge_inventorylistener.h"
#include "Game/ge_inventory_ps.h"
#include "Game/ge_item_ps.h"
#include "Game/ge_playermemory_ps.h"
#include "Game/ge_skill_ps.h"
#include "Game/ge_magic_ps.h"
#include "Game/ge_infoscriptline_ps.h"
#include "Game/ge_infoscript_ps.h"
#include "Game/ge_info_ps.h"
#include "Game/ge_quest_ps.h"
#include "Game/ge_infomanager_ps.h"
#include "Game/ge_questmanager_ps.h"
#include "Game/ge_npc_ps.h"
#include "Game/ge_recipe_ps.h"
#include "Game/ge_interaction_ps.h"
#include "Game/ge_enclave_ps.h"
#include "Game/ge_enclaveadmin.h"
#include "Game/ge_movementbase_ps.h"
class gCCharacterSensor_PS;
#include "Game/ge_charactermovement_ps.h"
#include "Game/ge_charactercontrol_ps.h"
#include "Game/ge_charactersensor_ps.h"
#include "Game/ge_navigation_ps.h"
#include "Game/ge_focus_ps.h"
#include "Game/ge_negzone_psobj.h"
#include "Game/ge_navzone_ps.h"
#include "Game/ge_navpath_ps.h"
#include "Game/ge_party_ps.h"
#include "Game/ge_lock_ps.h"
#include "Game/ge_effect_ps.h"

#include "Game/ge_entity.h"

#include "Game/ge_dummycollectorbase.h"
#include "Game/ge_dummycollectorpset_base.h"
#include "Game/ge_dummycollectoradmin.h"
#include "Game/ge_dummycollectoranchor.h"
#include "Game/ge_dummycollectorcollisioncircle.h"
#include "Game/ge_dummycollectorcollisionshape.h"
#include "Game/ge_dummycollectordynamiccollisioncircle.h"
#include "Game/ge_dummycollectorenclave.h"
#include "Game/ge_dummycollectorentity.h"
#include "Game/ge_dummycollectorfreepoint.h"
#include "Game/ge_dummycollectorlinkcontainer.h"
#include "Game/ge_dummycollectornavoffset.h"
#include "Game/ge_dummycollectornavpath.h"
#include "Game/ge_dummycollectornavzone.h"
#include "Game/ge_dummycollectornegzone.h"
#include "Game/ge_dummycollectorparticle.h"
#include "Game/ge_dummycollectorprefpath.h"
#include "Game/ge_dummycollectortreasureset.h"
#include "Game/ge_dummyvisualbase_ps.h"
#include "Game/ge_entitydummyvisual_ps.h"
#include "Game/ge_propertydummyvisual_ps.h"

#include "Game/ge_svmmanager.h"

#include "Game/ge_guimanager.h"
#include "Game/ge_sessioncheats.h"
#include "Game/ge_sessioninfo.h"
#include "Game/ge_session.h"

#include "Game/ge_huddialog.h"
#include "Game/ge_hudmenu.h"
#include "Game/ge_hudpage.h"

#endif