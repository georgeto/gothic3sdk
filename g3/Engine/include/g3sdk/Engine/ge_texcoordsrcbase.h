#pragma once

#include <Engine/ge_shaderellementbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTexCoordSrcBase : public eCShaderEllementBase
{
    // clang-format off
    public: virtual GEBool GetVSImplementation(bCString &, GEInt, GEBool);
    public: virtual GEBool GetPSImplementation(bCString &, GEInt, GEBool);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCTexCoordSrcBase() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCTexCoordSrcBase, eCShaderEllementBase)

  protected:
    void DestroyLocal();
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCTexCoordSrcBase, 0x44)
