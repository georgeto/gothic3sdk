#pragma once

#include <Engine/ge_enginecomponentbase.h>

#include <SharedBase.h>

class eCGfxEffect;

class GE_DLLIMPORT eCImageProcessingAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCImageProcessingAdmin() override;
    public: bCGuid const & GetID() const override;
    public: bEResult PreShutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: bEResult RestoreResources(GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCImageProcessingAdmin, eCEngineComponentBase)

  public:
    eCGfxEffect *GetEffect(bCString const &);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(eCImageProcessingAdmin, 0x20)
