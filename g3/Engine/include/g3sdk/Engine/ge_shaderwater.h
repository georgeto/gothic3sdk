#pragma once

#include <Engine/ge_shaderbase.h>

#include <SharedBase.h>

class eCColorSrcProxy;

class GE_DLLIMPORT eCShaderWater : public eCShaderBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCShaderWater() override;
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
    public: GEBool Prefetch(GEInt) override;
    protected: GEBool CreateShaderVersion(eEShaderMaterialVersion) override;
    public: GEBool HasOpacity() const override;
    public: GEBool IsRefracted() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCShaderWater, eCShaderBase)
    GE_PROPERTY(GEBool, EnableSpecular, m_bEnableSpecular)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, FresnelConstant, m_fFresnelConstant)
    GE_PROPERTY(GEFloat, ShoreFadingScale, m_fShoreFadingScale)
    GE_PROPERTY(bCFloatColor, ReflectionColor, m_colReflectionColor)
    GE_PROPERTY(GEFloat, DepthRedHalfLife, m_fDepthRedHalfLife)
    GE_PROPERTY(GEFloat, DepthGreenHalfLife, m_fDepthGreenHalfLife)
    GE_PROPERTY(GEFloat, DepthBlueHalfLife, m_fDepthBlueHalfLife)
    GE_PROPERTY(GEFloat, DepthScale, m_fDepthScale)

  public:
    eCColorSrcProxy &GetColorSrcDiffuse();
    eCColorSrcProxy &GetColorSrcDistortion();
    eCColorSrcProxy &GetColorSrcFlowingBump();
    eCColorSrcProxy &GetColorSrcReflection();
    eCColorSrcProxy &GetColorSrcSpecular();
    eCColorSrcProxy &GetColorSrcSpecularPower();
    eCColorSrcProxy &GetColorSrcStaticBump();

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(368)
};

GE_ASSERT_SIZEOF(eCShaderWater, 0x25c)

GE_ASSERT_PROPERTY(eCShaderWater, m_bEnableSpecular, 0xc0, 1)
GE_ASSERT_PROPERTY(eCShaderWater, m_fFresnelConstant, 0xc4, 4)
GE_ASSERT_PROPERTY(eCShaderWater, m_fShoreFadingScale, 0xc8, 4)
GE_ASSERT_PROPERTY(eCShaderWater, m_colReflectionColor, 0xcc, 16)
GE_ASSERT_PROPERTY(eCShaderWater, m_fDepthRedHalfLife, 0xdc, 4)
GE_ASSERT_PROPERTY(eCShaderWater, m_fDepthGreenHalfLife, 0xe0, 4)
GE_ASSERT_PROPERTY(eCShaderWater, m_fDepthBlueHalfLife, 0xe4, 4)
GE_ASSERT_PROPERTY(eCShaderWater, m_fDepthScale, 0xe8, 4)
