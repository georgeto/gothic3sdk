#pragma once

#include <Game/ge_effectcommand.h>

#include <Engine.h>

struct gSEffectCommand_ModifyEntity
{
    GE_UNIMPL_STRUCT(gSEffectCommand_ModifyEntity)
};

class GE_DLLIMPORT gCEffectCommandModifyEntity : public gCEffectCommand
{
    // clang-format off
    public: void Destroy() override;
    public: ~gCEffectCommandModifyEntity() override;
    public: gEEffectCommand GetCommandType() const override;
    public: void Execute(eCEntity *, eCEntity *, bCMatrix const *, bTObjMap<GEInt, eCEntityProxy> &, bTObjArray<eCEntityProxy> &, GEBool) const override;
    public: gCEffectCommand * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffectCommandModifyEntity, gCEffectCommand)
    GE_PROPERTY(GEInt, EntityIndex, m_iEntityIndex)
    GE_ENUMPROP(eEPropertySetType, PropertySet, m_enuPropertySet)
    GE_PROPERTY(bCString, Property, m_strProperty)
    GE_PROPERTY(bCString, Value, m_strValue)

  public:
    void GetDescriptor(gSEffectCommand_ModifyEntity &) const;
    void SetDescriptor(gSEffectCommand_ModifyEntity const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCEffectCommandModifyEntity, 0x24)

GE_ASSERT_PROPERTY(gCEffectCommandModifyEntity, m_iEntityIndex, 0x10, 4)
GE_ASSERT_PROPERTY(gCEffectCommandModifyEntity, m_enuPropertySet, 0x14, 8)
GE_ASSERT_PROPERTY(gCEffectCommandModifyEntity, m_strProperty, 0x1c, 4)
GE_ASSERT_PROPERTY(gCEffectCommandModifyEntity, m_strValue, 0x20, 4)
