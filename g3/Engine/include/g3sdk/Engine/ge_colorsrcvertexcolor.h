#pragma once

#include <Engine/ge_colorsrcbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCColorSrcVertexColor : public eCColorSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCColorSrcVertexColor() override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEBool IsVertexDiffuseUsed(GEBool) const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool GetImplementation(bCString &, eEShaderColorSrcComponent, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCColorSrcVertexColor, eCColorSrcBase)

  protected:
    void DestroyLocal();
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCColorSrcVertexColor, 0x44)
