#pragma once

#include <Game/ge_effectcommand.h>

#include <Engine.h>

struct gSEffectCommand_KillEntity
{
    GE_UNIMPL_STRUCT(gSEffectCommand_KillEntity)
};

class GE_DLLIMPORT gCEffectCommandKillEntity : public gCEffectCommand
{
    // clang-format off
    public: void Destroy() override;
    public: ~gCEffectCommandKillEntity() override;
    public: gEEffectCommand GetCommandType() const override;
    public: void Execute(eCEntity *, eCEntity *, bCMatrix const *, bTObjMap<GEInt, eCEntityProxy> &, bTObjArray<eCEntityProxy> &, GEBool) const override;
    public: gCEffectCommand * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffectCommandKillEntity, gCEffectCommand)
    GE_PROPERTY(GEInt, EntityIndex, m_iEntityIndex)

  public:
    void GetDescriptor(gSEffectCommand_KillEntity &) const;
    void SetDescriptor(gSEffectCommand_KillEntity const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCEffectCommandKillEntity, 0x14)

GE_ASSERT_PROPERTY(gCEffectCommandKillEntity, m_iEntityIndex, 0x10, 4)
