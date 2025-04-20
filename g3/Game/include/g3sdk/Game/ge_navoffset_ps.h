#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCNavOffset_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCNavOffset_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnPostRead() override;
    public: void OnPropertySetAdded() override;
    public: void OnPropertySetRemoved() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCNavOffset_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, OffsetCircle, m_bOffsetCircle)
    GE_PADDING(3)
    GE_PROPERTY(bTValArray<bCMotion>, OffsetPose, m_arrOffsetPose)
    GE_PROPERTY(bTValArray<gEDirection>, AniDirection, m_arrAniDirection)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCNavOffset_PS, 0x30)

GE_ASSERT_PROPERTY(gCNavOffset_PS, m_bOffsetCircle, 0x14, 1)
GE_ASSERT_PROPERTY(gCNavOffset_PS, m_arrOffsetPose, 0x18, 12)
GE_ASSERT_PROPERTY(gCNavOffset_PS, m_arrAniDirection, 0x24, 12)
