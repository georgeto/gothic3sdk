#pragma once

#include <Game/ge_effectcommand.h>

#include <Engine.h>

struct gSEffectCommand_TriggerEntity
{
    GE_UNIMPL_STRUCT(gSEffectCommand_TriggerEntity)
};

class GE_DLLIMPORT gCEffectCommandTriggerEntity : public gCEffectCommand
{
    // clang-format off
    public: void Destroy() override;
    public: ~gCEffectCommandTriggerEntity() override;
    public: gEEffectCommand GetCommandType() const override;
    public: void Execute(eCEntity *, eCEntity *, bCMatrix const *, bTObjMap<GEInt, eCEntityProxy> &, bTObjArray<eCEntityProxy> &, GEBool) const override;
    public: gCEffectCommand * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffectCommandTriggerEntity, gCEffectCommand)
    GE_PROPERTY(GEInt, EntityIndex, m_iEntityIndex)
    GE_PROPERTY(bCString, Trigger, m_strTrigger)

  public:
    void GetDescriptor(gSEffectCommand_TriggerEntity &) const;
    void SetDescriptor(gSEffectCommand_TriggerEntity const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCEffectCommandTriggerEntity, 0x18)

GE_ASSERT_PROPERTY(gCEffectCommandTriggerEntity, m_iEntityIndex, 0x10, 4)
GE_ASSERT_PROPERTY(gCEffectCommandTriggerEntity, m_strTrigger, 0x14, 4)
