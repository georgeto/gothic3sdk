#pragma once

#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_stringwrapper.h>

#include <SharedBase.h>

class eCGfxImageData;
class eCGfxVertexDecl;
class eCResourceImage_PS;
class eCShaderSkyDome;

class GE_DLLIMPORT eCSkydome_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCSkydome_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    protected: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    protected: GEBool HasRenderAlphaComponent() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    protected: void OnRender(GEI16) override;
    protected: void OnRenderAlpha(GEI16) override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCSkydome_PS, eCEntityPropertySet)
    GE_PROPERTY(bCImageResourceString, StarTexture, m_strStarTexture)
    GE_PROPERTY(GEInt, StarCount, m_iStarCount)
    GE_PROPERTY(bCFloatColor, SunColor, m_colSun)
    GE_PROPERTY(bCImageResourceString, SunTexture, m_strSunTexture)
    GE_PROPERTY(GEFloat, SunSize, m_fSunSize)
    GE_PROPERTY(bCFloatColor, MoonColor, m_colMoon)
    GE_PROPERTY(bCImageResourceString, MoonTexture, m_strMoonTexture)
    GE_PROPERTY(GEFloat, MoonSize, m_fMoonSize)
    GE_PROPERTY(bCImageResourceString, LensFlareTextures, m_strLensFlareTextures)
    GE_PROPERTY(GEFloat, LensFlareSize, m_fLensFlareSize)
    GE_PROPERTY(bCImageResourceString, CloudTexture1, m_strCloudTexture1)
    GE_PROPERTY(bCImageResourceString, CloudTexture2, m_strCloudTexture2)
    GE_PROPERTY(GEFloat, CloudThickness, m_fCloudThickness)
    GE_PROPERTY(bCFloatColor, CloudColor, m_colCloud)
    GE_PROPERTY(bCVector2, CloudDirection, m_vecCloudDirection)
    GE_PROPERTY(GEFloat, CloudSize1, m_fClodeSize1)
    GE_PROPERTY(GEFloat, CloudSize2, m_fClodeSize2)

  public:
    GEBool CreateSkydomeEnvCubemap(GEInt);
    GEBool DestroySkydomeEnvCubemap();
    GEBool ExecuteSkydomeEnvironmentMap(GEInt, GEFloat, GEInt);
    bCMatrix const &GetMoonMatrix() const;
    eCShaderSkyDome *GetSkyDomeShader();
    eCGfxImageData *GetSkydomeEnvironmentMap(GEFloat, GEInt);
    bCFloatColor const &GetStarsColor() const;
    bCMatrix const &GetStarsMatrix() const;
    bCMatrix const &GetSunMatrix() const;
    void SetMoonMatrix(bCMatrix const &);
    void SetStarsColor(bCFloatColor const &);
    void SetStarsMatrix(bCMatrix const &);
    void SetSunMatrix(bCMatrix const &);
    GEBool UpdateSkydomeEnvCubemap();

  protected:
    static eCGfxVertexDecl *ms_pCubemapCameraGfxVertexDecl;
    static eCGfxVertexDecl *ms_pGfxVertexDecl;

  protected:
    eCResourceImage_PS *CreateAbsorbationImage(eCResourceImage_PS *);
    GEBool CreateBuffers(GEBool);
    GEBool CreateLensFlare();
    GEBool CreateMoon();
    GEBool CreateShader();
    GEBool CreateStars();
    GEBool CreateSun();
    GEBool CreateSunOcclusion();
    void DestroyBuffers(GEBool);
    void DestroyLensFlare();
    void DestroyShader();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(572)
};

GE_ASSERT_SIZEOF(eCSkydome_PS, 0x2bc)

GE_ASSERT_PROPERTY(eCSkydome_PS, m_strStarTexture, 0x14, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_iStarCount, 0x18, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_colSun, 0x1c, 16)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_strSunTexture, 0x2c, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_fSunSize, 0x30, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_colMoon, 0x34, 16)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_strMoonTexture, 0x44, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_fMoonSize, 0x48, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_strLensFlareTextures, 0x4c, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_fLensFlareSize, 0x50, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_strCloudTexture1, 0x54, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_strCloudTexture2, 0x58, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_fCloudThickness, 0x5c, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_colCloud, 0x60, 16)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_vecCloudDirection, 0x70, 8)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_fClodeSize1, 0x78, 4)
GE_ASSERT_PROPERTY(eCSkydome_PS, m_fClodeSize2, 0x7c, 4)
