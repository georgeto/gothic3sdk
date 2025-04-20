#pragma once

#include <Engine.h>

class GE_DLLIMPORT eCAIHelperAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCAIHelperAdmin() override;
    public: bCGuid const & GetID() const override;
    public: bEResult Initialize() override;
    public: bEResult PreShutdown() override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCAIHelperAdmin, eCEngineComponentBase)

  public:
    GEBool IsLabelRenderingEnabled() const;

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(eCAIHelperAdmin, 0x18)
