#pragma once

#include <Engine/ge_shaderellementbase.h>

#include <SharedBase.h>

enum eEShaderColorSrcComponent
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCColorSrcBase : public eCShaderEllementBase
{
    // clang-format off
    public: virtual GEBool GetImplementation(bCString &, eEShaderColorSrcComponent, GEBool);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCColorSrcBase() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCColorSrcBase, eCShaderEllementBase)

  public:
    bCString GetSwizzle(eEShaderColorSrcComponent) const;

  protected:
    void DestroyLocal();
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCColorSrcBase, 0x44)
