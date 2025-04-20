#pragma once

#include <Engine/ge_enginecomponentbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIteratorAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCIteratorAdmin() override;
    public: bCGuid const & GetID() const override;
    public: bEResult PreShutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCIteratorAdmin, eCEngineComponentBase)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCIteratorAdmin, 0x14)
