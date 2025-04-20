#pragma once

#include <Game.h>

class Entity;
class Template;

#include "gs_propertymacros.h"

class GE_DLLIMPORT PSQuestManager : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSQuestManager, gCQuestManager_PS)

  public:
    GEBool CancelQuest(bCString const &);
    GEBool CloseQuest(bCString const &);
    GEBool FailQuest(bCString const &);
    GEBool IsCancelled(bCString const &);
    GEBool IsFailed(bCString const &);
    GEBool IsFinished(bCString const &);
    GEBool IsObsolete(bCString const &);
    GEBool IsOpen(bCString const &);
    GEBool IsRunning(bCString const &);
    GEBool IsSucceeded(bCString const &);
    GEBool OnEnclaveStateChanged(Entity const &);
    GEBool OnEnter(Entity const &, bCString const &);
    GEBool OnLeave(Entity const &, bCString const &);
    GEBool OnNPCDefeated(Entity const &);
    GEBool OnNPCKilled(Entity const &);
    GEBool OnReceiveItem(Entity const &, Entity const &, Template const &, GEU32);
    GEBool OnSpellCast(Entity const &, Entity const &, bCString);
    GEBool RunQuest(bCString const &);
    GEBool SucceedQuest(bCString const &);
};
