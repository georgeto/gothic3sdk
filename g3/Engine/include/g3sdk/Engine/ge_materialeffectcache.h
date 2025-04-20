#pragma once

#include <Engine/ge_depthmap.h>
#include <Engine/ge_illuminationadmin.h>

#include <SharedBase.h>

class eCGfxImageData;
class eCGfxVisual;
class eCResourceMaterialObjectExtended_PS;
class eCResourceMaterialObject_PS;

enum eEShadowMapLightType
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCMaterialEffectCache
{
  public:
    enum eEColorMixingType
    {
        // TODO: Enumerator values
    };

    enum eEMatStaticLightingType
    {
        // TODO: Enumerator values
    };

    enum eEShadowMapTextureAlpha
    {
        // TODO: Enumerator values
    };

    enum eETransformAniType
    {
        // TODO: Enumerator values
    };

    // clang-format off
    protected: virtual ~eCMaterialEffectCache();
    // clang-format on

  public:
    eCMaterialEffectCache(eCMaterialEffectCache const &);

  public:
    eCMaterialEffectCache &operator=(eCMaterialEffectCache const &);

  protected:
    eCMaterialEffectCache();

  protected:
    GEInt Exec_SimpleLighting(eCGfxVisual *, eCIlluminationAdmin::eSIllumination *);
    GEInt Execute_ParticlePoolEffect(GEUInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                     eCResourceMaterialObjectExtended_PS *, eCIlluminationAdmin::eSIllumination *);
    GEInt Execute_ShadowMapPoolEffect(GEUInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                      eCResourceMaterialObjectExtended_PS *, eEShadowMapTextureAlpha, eEColorMixingType,
                                      eETransformAniType, eEDepthMapFormat, eEShadowMapLightType, GEU32, GEU32, GEU32,
                                      GEU32);
    GEInt Execute_SkydomePoolEffect(GEUInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                    eCResourceMaterialObjectExtended_PS *);
    GEInt Execute_StandardPoolEffect(GEUInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                     eCResourceMaterialObjectExtended_PS *, eEColorMixingType, eEMatStaticLightingType,
                                     eETransformAniType, eCIlluminationAdmin::eSIllumination *, GEU32, GEU32, GEU32,
                                     GEU32);
    GEInt Execute_VegetationPoolEffect(GEUInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                       eCResourceMaterialObjectExtended_PS *, eCIlluminationAdmin::eSIllumination *);
    GEInt Execute_WaterPoolEffect(GEUInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                  eCResourceMaterialObjectExtended_PS *, eCIlluminationAdmin::eSIllumination *);
    bEResult FillNormalizationCubeMap();
    bEResult LoadPoolEffects_Particle();
    bEResult LoadPoolEffects_ShadowMap_P(GEBool);
    bEResult LoadPoolEffects_ShadowMap_V(GEBool);
    bEResult LoadPoolEffects_Skydome_0();
    bEResult LoadPoolEffects_Skydome_1();
    bEResult LoadPoolEffects_Standard_0();
    bEResult LoadPoolEffects_Standard_1();
    bEResult LoadPoolEffects_Standard_2(GEBool);
    bEResult LoadPoolEffects_Standard_3(GEBool);
    bEResult LoadPoolEffects_Standard_4(GEBool);
    bEResult LoadPoolEffects_Standard_5(GEBool);
    bEResult LoadPoolEffects_Standard_6(GEBool);
    bEResult LoadPoolEffects_Standard_7(GEBool);
    bEResult LoadPoolEffects_Vegetation();
    bEResult LoadPoolEffects_Water();
    GEInt SetParticleMaterialParameters(GEInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                        eCResourceMaterialObjectExtended_PS *, eCIlluminationAdmin::eSIllumination *);
    GEInt SetShadowMapMaterialParameters(eEColorMixingType, GEInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                         eCResourceMaterialObjectExtended_PS *, eEDepthMapFormat, eEShadowMapLightType,
                                         eETransformAniType);
    GEInt SetSkydomeMaterialParameters(GEInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                       eCResourceMaterialObjectExtended_PS *);
    GEInt SetStandardMaterialParameters(eEColorMixingType, GEInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                        eCResourceMaterialObjectExtended_PS *, eETransformAniType,
                                        eCIlluminationAdmin::eSIllumination *, eCGfxImageData *);
    GEInt SetVegetationMaterialParameters(GEInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                          eCResourceMaterialObjectExtended_PS *, eCIlluminationAdmin::eSIllumination *);
    GEInt SetWaterMaterialParameters(GEInt, eCGfxVisual *, eCResourceMaterialObject_PS *,
                                     eCResourceMaterialObjectExtended_PS *, eCIlluminationAdmin::eSIllumination *);
};
