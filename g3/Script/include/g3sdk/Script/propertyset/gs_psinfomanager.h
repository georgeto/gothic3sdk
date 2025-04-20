#pragma once

#include "gs_propertymacros.h"
#include "gs_psinfoscriptcommand.h"

#include <Script/gs_info.h>

#include <Game.h>

class Template;

class GE_DLLIMPORT PSInfoManager : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSInfoManager, gCInfoManager_PS)
    GS_PROPERTY(GEBool, ChildMode)

  public:
    GEBool End();
    gEAction GetAction(bCString const &);
    PSInfoScriptCommand GetCurrentCommand() const;
    Info GetCurrentInfo() const;
    gEFaceAni GetFaceAni(bCString const &);
    Entity GetNPC();
    gESecurityLevel GetSecurityLevel(bCString const &);
    GEBool Give(Entity const &, Entity const &, Template const &, GEU32);
    GEBool Give(Entity const &, Entity const &, GEInt, GEU32);
    GEBool HasCommentInfo(Entity const &, Entity const &) const;
    GEBool HasImportantInfo(Entity const &, Entity const &) const;
    GEBool HasInfo(Entity const &, Entity const &) const;
    GEBool IsRunning() const;
    GEBool IsWaitingforScript() const;
    GEBool OnCommandCompleted(GEBool a_bAbortExecution);
    GEBool Start(Entity const &, Entity const &);
    GEBool StartComment(Entity const &, Entity const &);
};
