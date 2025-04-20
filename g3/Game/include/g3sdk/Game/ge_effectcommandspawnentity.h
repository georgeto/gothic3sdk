#pragma once

#include <Game/GameEnum.h>
#include <Game/ge_effectcommand.h>

#include <Engine.h>

struct gSEffectCommand_SpawnEntity
{
    GE_UNIMPL_STRUCT(gSEffectCommand_SpawnEntity)
};

class GE_DLLIMPORT gCEffectCommandSpawnEntity : public gCEffectCommand
{
    // clang-format off
    public: void Destroy() override;
    public: ~gCEffectCommandSpawnEntity() override;
    public: gEEffectCommand GetCommandType() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void Execute(eCEntity *, eCEntity *, bCMatrix const *, bTObjMap<GEInt, eCEntityProxy> &, bTObjArray<eCEntityProxy> &, GEBool) const override;
    public: gCEffectCommand * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffectCommandSpawnEntity, gCEffectCommand)
    GE_PROPERTY(GEInt, EntityIndex, m_iEntityIndex)
    GE_PROPERTY(eCTemplateEntityProxy, TemplateEntity, m_entTemplate)
    GE_PROPERTY(bCString, BoneName, m_strBone)
    GE_ENUMPROP(gEEffectLink, CoordinateSystem, m_enuLink)
    GE_PROPERTY(GEBool, AutoKill, m_bAutoKill)
    GE_PADDING(3)
    GE_PROPERTY(bCRange3, Offset, m_rngOffset)

  public:
    void GetDescriptor(gSEffectCommand_SpawnEntity &) const;
    void SetDescriptor(gSEffectCommand_SpawnEntity const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCEffectCommandSpawnEntity, 0x48)

GE_ASSERT_PROPERTY(gCEffectCommandSpawnEntity, m_iEntityIndex, 0x10, 4)
GE_ASSERT_PROPERTY(gCEffectCommandSpawnEntity, m_entTemplate, 0x14, 12)
GE_ASSERT_PROPERTY(gCEffectCommandSpawnEntity, m_strBone, 0x20, 4)
GE_ASSERT_PROPERTY(gCEffectCommandSpawnEntity, m_enuLink, 0x24, 8)
GE_ASSERT_PROPERTY(gCEffectCommandSpawnEntity, m_bAutoKill, 0x2c, 1)
GE_ASSERT_PROPERTY(gCEffectCommandSpawnEntity, m_rngOffset, 0x30, 24)
