#pragma once

#include <Engine/entity/ge_entitypropertyset.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCEffectBase_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual void CopyFrom(eCEffectBase_PS const &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCEffectBase_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: GEBool IsEditorRelevant() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCEffectBase_PS, eCEntityPropertySet)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCEffectBase_PS, 0x14)
