#pragma once

#include <Engine/ge_texcoordsrcbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTexCoordSrcColor : public eCTexCoordSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCTexCoordSrcColor() override;
    protected: bEResult PostInitializeProperties() override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool GetVSImplementation(bCString &, GEInt, GEBool) override;
    public: GEBool GetPSImplementation(bCString &, GEInt, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCTexCoordSrcColor, eCTexCoordSrcBase)

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(64)
};

GE_ASSERT_SIZEOF(eCTexCoordSrcColor, 0x84)
