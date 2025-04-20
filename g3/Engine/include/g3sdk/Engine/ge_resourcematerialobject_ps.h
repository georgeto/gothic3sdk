#pragma once

#include <Engine/ge_resourcematerialtechnique_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCResourceMaterialObject_PS : public eCResourceMaterialTechnique_PS
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceMaterialObject_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    protected: void CalculateSize() override;
    public: GEBool IsMapChannelUsed(GEU32, GEBool) override;
    public: GEBool IsDiffuseColorUsed(GEBool) override;
    public: GEInt Execute(GEInt, eCGfxVisual *, eCGfxImageData *, eCIlluminationAdmin::eSIllumination *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceMaterialObject_PS, eCResourceBase_PS)
    GE_PROPERTY(GEBool, IsBlended, m_bIsBlended)
    GE_PROPERTY(GEBool, SpecularEnabled, m_bSpecularEnabled)
    GE_PADDING(2)
    GE_PROPERTY(bCVector, DiffuseReflection, m_vecDiffuseReflection)
    GE_PROPERTY(bCVector, AmbientReflection, m_vecAmbientReflection)
    GE_PROPERTY(bCVector, SpecularReflection, m_vecSpecularReflection)
    GE_PROPERTY(GEFloat, SpecularPower, m_fSpecularPower)
    GE_PROPERTY(GEFloat, SpecularMapPower, m_fSpecularMapPower)
    GE_PROPERTY(GEBool, IsUniDetailed, m_bIsUniDetailed)
    GE_PROPERTY(GEBool, IsDepthRobust, m_bIsDepthRobust)
    GE_PROPERTY(GEBool, HasDetailSpecularMap, m_bHasDetailSpecularMap)
    GE_PROPERTY(GEBool, HasDetailNormalMap, m_bHasDetailNormalMap)
    GE_PROPERTY(GEBool, HasHeightMap, m_bHasHeightMap)
    GE_PROPERTY(GEBool, UseSpecShaderColor, m_bUseSpecShaderColor)
    GE_PROPERTY(GEBool, UseLightmaps, m_bUseLightmaps)
    GE_PADDING(1)
    GE_PROPERTY(GEU32, SpecularMapChannel, m_u32SpecularMapChannel)
    GE_PROPERTY(bCString, SpecularMapFilePath, m_strSpecularMapPath)
    GE_PROPERTY(bCMatrix, SpecularMapTexMatrix, m_matSpecularMapTexMatrix)
    GE_PROPERTY(GEU32, SecondSpecularMapChannel, m_u32SecondSpecularMapChannel)
    GE_PROPERTY(bCString, SecondSpecularMapFilePath, m_strSecondSpecularMapPath)
    GE_PROPERTY(bCMatrix, SecondSpecularMapTexMatrix, m_matSecondSpecularMapTexMatrix)
    GE_PROPERTY(GEU32, NormalMapChannel, m_u32NormalMapChannel)
    GE_PROPERTY(bCString, NormalMapFilePath, m_strNormalMapPath)
    GE_PROPERTY(bCMatrix, NormalMapTexMatrix, m_matNormalMapTexMatrix)
    GE_PROPERTY(GEU32, SecondNormalMapChannel, m_u32SecondNormalMapChannel)
    GE_PROPERTY(bCString, SecondNormalMapFilePath, m_strSecondNormalMapPath)
    GE_PROPERTY(bCMatrix, SecondNormalMapTexMatrix, m_matSecondNormalMapTexMatrix)
    GE_PROPERTY(GEU32, DiffuseMapChannel, m_u32DiffuseMapChannel)
    GE_PROPERTY(bCString, DiffuseMapFilePath, m_strDiffuseMapPath)
    GE_PROPERTY(bCMatrix, DiffuseMapTexMatrix, m_matDiffuseMapTexMatrix)
    GE_PROPERTY(GEU32, DetailMapChannel, m_u32DetailMapChannel)
    GE_PROPERTY(bCString, DetailMapFilePath, m_strDetailMapPath)
    GE_PROPERTY(bCMatrix, DetailMapTexMatrix, m_matDetailMapTexMatrix)
    GE_PROPERTY(GEU32, SecondDiffuseMapChannel, m_u32SecondDiffuseMapChannel)
    GE_PROPERTY(bCString, SecondDiffuseMapFilePath, m_strSecondDiffuseMapPath)
    GE_PROPERTY(bCMatrix, SecondDiffuseMapTexMatrix, m_matSecondDiffuseMapTexMatrix)
    GE_PROPERTY(GEU32, SecondDetailMapChannel, m_u32SecondDetailMapChannel)
    GE_PROPERTY(bCString, SecondDetailMapFilePath, m_strSecondDetailMapPath)
    GE_PROPERTY(bCMatrix, SecondDetailMapTexMatrix, m_matSecondDetailMapTexMatrix)

  public:
    static void GE_STDCALL GetProprietaryFileExt(bCString &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    eCResourceDataEntity *GetDetailImageResourceEntity() const;
    eCResourceDataEntity *GetDiffuseImageResourceEntity() const;
    eCResourceDataEntity *GetNormalImageResourceEntity() const;
    eCResourceDataEntity *GetSecondDetailImageResourceEntity() const;
    eCResourceDataEntity *GetSecondDiffuseImageResourceEntity() const;
    eCResourceDataEntity *GetSecondNormalImageResourceEntity() const;
    eCResourceDataEntity *GetSecondSpecularImageResourceEntity() const;
    eCResourceDataEntity *GetSpecularImageResourceEntity() const;
    void SetDetailImageResourceEntity(eCResourceDataEntity *);
    void SetDiffuseImageResourceEntity(eCResourceDataEntity *);
    void SetNormalImageResourceEntity(eCResourceDataEntity *);
    void SetSecondDetailImageResourceEntity(eCResourceDataEntity *);
    void SetSecondDiffuseImageResourceEntity(eCResourceDataEntity *);
    void SetSecondNormalImageResourceEntity(eCResourceDataEntity *);
    void SetSecondSpecularImageResourceEntity(eCResourceDataEntity *);
    void SetSpecularImageResourceEntity(eCResourceDataEntity *);

  protected:
    void DeleteResources();
    void Invalidate();
    bEResult RecreateCompleteMaterial();

  private:
    GE_UNIMPL_MEMBERS(32)
};

GE_ASSERT_SIZEOF(eCResourceMaterialObject_PS, 0x2c8)

GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_bIsBlended, 0x30, 1)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_bSpecularEnabled, 0x31, 1)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_vecDiffuseReflection, 0x34, 12)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_vecAmbientReflection, 0x40, 12)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_vecSpecularReflection, 0x4c, 12)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_fSpecularPower, 0x58, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_fSpecularMapPower, 0x5c, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_bIsUniDetailed, 0x60, 1)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_bIsDepthRobust, 0x61, 1)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_bHasDetailSpecularMap, 0x62, 1)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_bHasDetailNormalMap, 0x63, 1)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_bHasHeightMap, 0x64, 1)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_bUseSpecShaderColor, 0x65, 1)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_bUseLightmaps, 0x66, 1)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_u32SpecularMapChannel, 0x68, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_strSpecularMapPath, 0x6c, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_matSpecularMapTexMatrix, 0x70, 64)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_u32SecondSpecularMapChannel, 0xb0, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_strSecondSpecularMapPath, 0xb4, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_matSecondSpecularMapTexMatrix, 0xb8, 64)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_u32NormalMapChannel, 0xf8, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_strNormalMapPath, 0xfc, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_matNormalMapTexMatrix, 0x100, 64)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_u32SecondNormalMapChannel, 0x140, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_strSecondNormalMapPath, 0x144, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_matSecondNormalMapTexMatrix, 0x148, 64)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_u32DiffuseMapChannel, 0x188, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_strDiffuseMapPath, 0x18c, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_matDiffuseMapTexMatrix, 0x190, 64)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_u32DetailMapChannel, 0x1d0, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_strDetailMapPath, 0x1d4, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_matDetailMapTexMatrix, 0x1d8, 64)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_u32SecondDiffuseMapChannel, 0x218, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_strSecondDiffuseMapPath, 0x21c, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_matSecondDiffuseMapTexMatrix, 0x220, 64)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_u32SecondDetailMapChannel, 0x260, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_strSecondDetailMapPath, 0x264, 4)
GE_ASSERT_PROPERTY(eCResourceMaterialObject_PS, m_matSecondDetailMapTexMatrix, 0x268, 64)
