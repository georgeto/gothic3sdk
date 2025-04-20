#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCTeleporter_PS : public eCTrigger_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCTeleporter_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: void TriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: GEBool CanBeActivatedNow(eCEntity *, eCContactIterator &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCTeleporter_PS, eCTrigger_PS)
    GE_PROPERTY(bCString, DestinationEntity, m_strDestinationEntity)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCTeleporter_PS, 0xe8)

GE_ASSERT_PROPERTY(gCTeleporter_PS, m_strDestinationEntity, 0xe4, 4)
