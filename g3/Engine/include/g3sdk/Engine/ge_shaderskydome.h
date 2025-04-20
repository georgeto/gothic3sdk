#pragma once

#include <Engine/ge_shaderbase.h>

#include <SharedBase.h>

class eCColorSrcProxy;

class GE_DLLIMPORT eCShaderSkyDome : public eCShaderBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCShaderSkyDome() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedEnterEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: GEBool IsVertexTexCoordUsed(GEInt, GEBool) const override;
    public: GEBool IsVertexDiffuseUsed(GEBool) const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    protected: GEBool CreateShaderVersion(eEShaderMaterialVersion) override;
    public: GEBool HasOpacity() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCShaderSkyDome, eCShaderBase)
    GE_PROPERTY(bCFloatColor, SkyColor, m_colSky)
    GE_PROPERTY(bCFloatColor, SunColor, m_colSun)
    GE_PROPERTY(bCFloatColor, HazeColor, m_colHaze)
    GE_PROPERTY(bCVector, SunNormal, m_vecSunNormal)
    GE_PROPERTY(GEBool, SunOcclusionOnly, m_bSunOcclusionOnly)
    GE_PROPERTY(GEBool, BillboardOnly, m_bBillboardOnly)
    GE_PADDING(1)

  public:
    eCColorSrcProxy &GetColorSrcAbsorbation();
    eCColorSrcProxy &GetColorSrcClouds();

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(336)
};

GE_ASSERT_SIZEOF(eCShaderSkyDome, 0x250)

GE_ASSERT_PROPERTY(eCShaderSkyDome, m_colSky, 0xc0, 16)
GE_ASSERT_PROPERTY(eCShaderSkyDome, m_colSun, 0xd0, 16)
GE_ASSERT_PROPERTY(eCShaderSkyDome, m_colHaze, 0xe0, 16)
GE_ASSERT_PROPERTY(eCShaderSkyDome, m_vecSunNormal, 0xf0, 12)
GE_ASSERT_PROPERTY(eCShaderSkyDome, m_bSunOcclusionOnly, 0xfc, 1)
GE_ASSERT_PROPERTY(eCShaderSkyDome, m_bBillboardOnly, 0xfd, 1)
