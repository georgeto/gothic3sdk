#pragma once

#include <Engine/ge_texcoordsrcbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTexCoordSrcBumpOffset : public eCTexCoordSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCTexCoordSrcBumpOffset() override;
    protected: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: GEBool IsVertexTexCoordUsed(GEInt, GEBool) const override;
    public: GEBool IsVertexDiffuseUsed(GEBool) const override;
    public: GEBool IsVertexTangentUsed() const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool Prefetch(GEBool, GEInt) override;
    public: GEBool GetVSImplementation(bCString &, GEInt, GEBool) override;
    public: GEBool GetPSImplementation(bCString &, GEInt, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCTexCoordSrcBumpOffset, eCTexCoordSrcBase)
    GE_PROPERTY(GEFloat, OffsetAmount, m_fOffsetAmount)

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(112)
};

GE_ASSERT_SIZEOF(eCTexCoordSrcBumpOffset, 0xb8)

GE_ASSERT_PROPERTY(eCTexCoordSrcBumpOffset, m_fOffsetAmount, 0x44, 4)
