#pragma once

#include <Engine/ge_texcoordsrcbase.h>

#include <SharedBase.h>

class eCTexCoordSrcProxy;

class GE_DLLIMPORT eCTexCoordSrcScale : public eCTexCoordSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCTexCoordSrcScale() override;
    protected: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool GetVSImplementation(bCString &, GEInt, GEBool) override;
    public: GEBool GetPSImplementation(bCString &, GEInt, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCTexCoordSrcScale, eCTexCoordSrcBase)
    GE_PROPERTY(bCVector2, Scale, m_vecScale)

  public:
    eCTexCoordSrcProxy &GetTexCoordSrc();

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(72)
};

GE_ASSERT_SIZEOF(eCTexCoordSrcScale, 0x94)

GE_ASSERT_PROPERTY(eCTexCoordSrcScale, m_vecScale, 0x44, 8)
