#pragma once

#include <Engine/ge_illuminationadmin.h>

#include <SharedBase.h>

class eCGfxShader;
class eCResourceMaterialObjectExtended_PS;
class eCResourceMaterialObject_PS;

class GE_DLLIMPORT eCMaterialEffect
{
  public:
    enum eEMaterialEffectResult
    {
        // TODO: Enumerator values
    };

    struct eSTexCoordIndices
    {
        GE_UNIMPL_STRUCT(eSTexCoordIndices)
    };

    // clang-format off
    public: virtual ~eCMaterialEffect();
    // clang-format on

  public:
    eCMaterialEffect(eCMaterialEffect const &);
    eCMaterialEffect();

  public:
    eCMaterialEffect &operator=(eCMaterialEffect const &);

  public:
    bEResult ActivatePass(GEUInt);
    eEMaterialEffectResult BeginEffectApplication(eCGfxShader *, GEU32, eCResourceMaterialObject_PS *,
                                                  eCResourceMaterialObjectExtended_PS *,
                                                  eCIlluminationAdmin::eSIllumination const &, eSTexCoordIndices &,
                                                  GEFloat);
    bEResult Create(GELPVoid, GEUInt);
    void Destroy();
    bEResult EndEffectApplication();
    bEResult GetNumberOfPasses(GEUInt &) const;
    bEResult OnLostDevice();
    bEResult OnResetDevice();
};
