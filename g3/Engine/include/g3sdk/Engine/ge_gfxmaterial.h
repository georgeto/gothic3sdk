#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCGfxTextureBlock;

class GE_DLLIMPORT eCGfxMaterial : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxMaterial const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxMaterial() override;
    // clang-format on

  public:
    eCGfxMaterial(eCGfxMaterial const &);
    eCGfxMaterial();

  public:
    eCGfxMaterial &operator=(eCGfxMaterial const &);

  public:
    bEResult AttachTextureBlock(GEU32, eCGfxTextureBlock *);
    bEResult Execute();
    bEResult GetAlphaTesting(eCGfxShared::eEAlphaTest &, eCGfxShared::eSGfxAlphaTestData &) const;
    bEResult GetAmbientMaterialSrc(eCGfxShared::eEMaterialColorSrc &) const;
    bEResult GetAmbientReflection(bCFloatAlphaColor &) const;
    bEResult GetAttachedTextureBlock(GEU32, eCGfxTextureBlock *&) const;
    bEResult GetBlending(eCGfxShared::eEBlending &, eCGfxShared::eEBlending &) const;
    bEResult GetColorFactor(GEU32 &) const;
    bEResult GetDiffuseMaterialSrc(eCGfxShared::eEMaterialColorSrc &) const;
    bEResult GetDiffuseReflection(bCFloatAlphaColor &) const;
    bEResult GetEmission(bCFloatAlphaColor &) const;
    bEResult GetEmissiveMaterialSrc(eCGfxShared::eEMaterialColorSrc &) const;
    bEResult GetSpecularEffect(GEBool &) const;
    bEResult GetSpecularMaterialSrc(eCGfxShared::eEMaterialColorSrc &) const;
    bEResult GetSpecularReflection(bCFloatAlphaColor &, GEFloat &) const;
    void Invalidate();
    bEResult SetAlphaTesting(eCGfxShared::eEAlphaTest, eCGfxShared::eSGfxAlphaTestData const &);
    bEResult SetAmbientMaterialSrc(eCGfxShared::eEMaterialColorSrc);
    bEResult SetAmbientReflection(bCFloatAlphaColor const &);
    bEResult SetBlending(eCGfxShared::eEBlending, eCGfxShared::eEBlending);
    bEResult SetColorFactor(GEU32);
    bEResult SetDiffuseMaterialSrc(eCGfxShared::eEMaterialColorSrc);
    bEResult SetDiffuseReflection(bCFloatAlphaColor const &);
    bEResult SetEmission(bCFloatAlphaColor const &);
    bEResult SetEmissiveMaterialSrc(eCGfxShared::eEMaterialColorSrc);
    bEResult SetSpecularEffect(GEBool);
    bEResult SetSpecularMaterialSrc(eCGfxShared::eEMaterialColorSrc);
    bEResult SetSpecularReflection(bCFloatAlphaColor const &, GEFloat);

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxMaterial *ms_pActiveMaterial;
    static eCGfxMaterial *ms_pMasterMaterial;
    static void(GE_STDCALL *ms_pRegisterMaterialExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxMaterial *GE_STDCALL sGetActiveMaterial();
    static eCGfxMaterial *GE_STDCALL sGetMasterMaterial();
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetMasterMaterial(eCGfxMaterial *);
    static void GE_STDCALL sSetMaterialExecuteCallback(void(GE_STDCALL *)());
};
