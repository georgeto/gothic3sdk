#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_shaderbase.h>

#include <SharedBase.h>

class eCColorSrcProxy;

class GE_DLLIMPORT eCShaderSkin : public eCShaderBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCShaderSkin() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: GEBool IsVertexTexCoordUsed(GEInt, GEBool) const override;
    public: GEBool IsVertexDiffuseUsed(GEBool) const override;
    public: GEBool IsVertexTangentUsed() const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool SupportsInstancing() const override;
    public: GEBool Prefetch(GEInt) override;
    protected: GEBool CreateShaderVersion(eEShaderMaterialVersion) override;
    public: GEBool HasOpacity() const override;
    public: GEBool IsRefracted() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCShaderSkin, eCShaderBase)
    GE_ENUMPROP(eEShaderMaterialTransformation, TransformationType, m_eTransformationType)
    GE_PROPERTY(GEBool, EnableSpecular, m_bEnableSpecular)
    GE_PROPERTY(GEBool, DisableLighting, m_bDisableLighting)
    GE_PROPERTY(GEBool, EnableRimLighting, m_bEnableRimLighting)
    GE_PADDING(1)
    GE_PROPERTY(bCFloatColor, RimColor, m_ColorRim)
    GE_PROPERTY(GEFloat, RimPower, m_fRimPower)
    GE_PROPERTY(GEFloat, SubSurfaceRollOff, m_fSubSurfaceRollOff)

  public:
    eCColorSrcProxy &GetColorSrcDiffuse();
    eCColorSrcProxy &GetColorSrcNormal();
    eCColorSrcProxy &GetColorSrcOpacity();
    eCColorSrcProxy &GetColorSrcSelfIllumination();
    eCColorSrcProxy &GetColorSrcSpecular();
    eCColorSrcProxy &GetColorSrcSpecularPower();
    eCColorSrcProxy &GetColorSrcSubSurface();

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(344)
};

GE_ASSERT_SIZEOF(eCShaderSkin, 0x23c)

GE_ASSERT_PROPERTY(eCShaderSkin, m_eTransformationType, 0xc0, 8)
GE_ASSERT_PROPERTY(eCShaderSkin, m_bEnableSpecular, 0xc8, 1)
GE_ASSERT_PROPERTY(eCShaderSkin, m_bDisableLighting, 0xc9, 1)
GE_ASSERT_PROPERTY(eCShaderSkin, m_bEnableRimLighting, 0xca, 1)
GE_ASSERT_PROPERTY(eCShaderSkin, m_ColorRim, 0xcc, 16)
GE_ASSERT_PROPERTY(eCShaderSkin, m_fRimPower, 0xdc, 4)
GE_ASSERT_PROPERTY(eCShaderSkin, m_fSubSurfaceRollOff, 0xe0, 4)
