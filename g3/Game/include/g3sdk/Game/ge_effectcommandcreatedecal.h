#pragma once

#include <Game/ge_effectcommand.h>

#include <Engine.h>

struct gSEffectCommand_CreateDecal
{
    GE_UNIMPL_STRUCT(gSEffectCommand_CreateDecal)
};

class GE_DLLIMPORT gCEffectCommandCreateDecal : public gCEffectCommand
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~gCEffectCommandCreateDecal() override;
    public: gEEffectCommand GetCommandType() const override;
    public: void Execute(eCEntity *, eCEntity *, bCMatrix const *, bTObjMap<GEInt, eCEntityProxy> &, bTObjArray<eCEntityProxy> &, GEBool) const override;
    public: gCEffectCommand * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffectCommandCreateDecal, gCEffectCommand)
    GE_PROPERTY(bCImageOrMaterialResourceString, ImageOrMaterial, m_strImageOrMaterial)
    GE_PROPERTY(GEFloat, LifeTime, m_fLifeTime)
    GE_PROPERTY(bCVector, Size, m_vecSize)
    GE_PROPERTY(bCVector, Offset, m_vecOffset)
    GE_PROPERTY(bCString, BoneName, m_strBone)
    GE_PROPERTY(GEBool, UseTargetDirection, m_bUseTargetDirection)
    GE_PADDING(3)
    GE_PROPERTY(bCEulerAngles, DirectionOffset, m_eulDirectionOffset)
    GE_PROPERTY(GEFloat, FadeInTime, m_fFadeInTime)
    GE_PROPERTY(GEFloat, FadeOutTime, m_fFadeOutTime)
    GE_PROPERTY(GEBool, CreateOnDynamicEntities, m_bCreateOnDynamicEntities)
    GE_PADDING(1)

  public:
    void GetDescriptor(gSEffectCommand_CreateDecal &) const;
    void SetDescriptor(gSEffectCommand_CreateDecal const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCEffectCommandCreateDecal, 0x50)

GE_ASSERT_PROPERTY(gCEffectCommandCreateDecal, m_strImageOrMaterial, 0x10, 4)
GE_ASSERT_PROPERTY(gCEffectCommandCreateDecal, m_fLifeTime, 0x14, 4)
GE_ASSERT_PROPERTY(gCEffectCommandCreateDecal, m_vecSize, 0x18, 12)
GE_ASSERT_PROPERTY(gCEffectCommandCreateDecal, m_vecOffset, 0x24, 12)
GE_ASSERT_PROPERTY(gCEffectCommandCreateDecal, m_strBone, 0x30, 4)
GE_ASSERT_PROPERTY(gCEffectCommandCreateDecal, m_bUseTargetDirection, 0x34, 1)
GE_ASSERT_PROPERTY(gCEffectCommandCreateDecal, m_eulDirectionOffset, 0x38, 12)
GE_ASSERT_PROPERTY(gCEffectCommandCreateDecal, m_fFadeInTime, 0x44, 4)
GE_ASSERT_PROPERTY(gCEffectCommandCreateDecal, m_fFadeOutTime, 0x48, 4)
GE_ASSERT_PROPERTY(gCEffectCommandCreateDecal, m_bCreateOnDynamicEntities, 0x4c, 1)
