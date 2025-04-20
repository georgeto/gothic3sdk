#pragma once

#include <Engine/ge_contextbase.h>
#include <Engine/ge_resourcedataentity.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCResourceStorageContext : public eCContextBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceStorageContext() override;
    public: eCResourceDataEntity * CreateSpecificEntity() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceStorageContext, eCContextBase)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCResourceStorageContext, 0x58)
