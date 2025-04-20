#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCNavHelper_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCNavHelper_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnPropertySetAdded() override;
    public: void OnPropertySetRemoved() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCNavHelper_PS, eCEntityPropertySet)
    GE_PROPERTY(bCPropertyID, LinkedToEntityID, m_idLinkedToEntityID)
    GE_PROPERTY(bCPropertyID, LinkedToSecondEntityID, m_idLinkedToSecondEntityID)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCNavHelper_PS, 0x3c)

GE_ASSERT_PROPERTY(gCNavHelper_PS, m_idLinkedToEntityID, 0x14, 20)
GE_ASSERT_PROPERTY(gCNavHelper_PS, m_idLinkedToSecondEntityID, 0x28, 20)
