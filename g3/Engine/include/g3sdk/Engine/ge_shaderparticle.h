#pragma once

#include <Engine/ge_shaderbase.h>

#include <SharedBase.h>

class eCColorSrcProxy;

class GE_DLLIMPORT eCShaderParticle : public eCShaderBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCShaderParticle() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: void SetTime(GEFloat) override;
    public: GEBool IsVertexTexCoordUsed(GEInt, GEBool) const override;
    public: GEBool IsVertexDiffuseUsed(GEBool) const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool Prefetch(GEInt) override;
    protected: GEBool CreateShaderVersion(eEShaderMaterialVersion) override;
    public: GEBool HasOpacity() const override;
    public: GEBool IsRefracted() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCShaderParticle, eCShaderBase)
    GE_PROPERTY(GEFloat, DistortionScale, m_fDistortionScale)
    GE_PROPERTY(GEFloat, SoftParticleScale, m_fSoftParticleScale)

  public:
    eCColorSrcProxy &GetColorSrcDiffuse();
    eCColorSrcProxy &GetColorSrcDistortion();

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(136)
};

GE_ASSERT_SIZEOF(eCShaderParticle, 0x150)

GE_ASSERT_PROPERTY(eCShaderParticle, m_fDistortionScale, 0xc0, 4)
GE_ASSERT_PROPERTY(eCShaderParticle, m_fSoftParticleScale, 0xc4, 4)
