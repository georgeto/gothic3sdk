#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCAPICubeMap;
class eCAPITexture;
class eCAPIVolume;

class GE_DLLIMPORT eCAPIEffect
{
    // clang-format off
    public: virtual bEResult OnResetDevice() = 0;
    public: virtual bEResult OnLostDevice() = 0;
    public: virtual bEResult SetTexture(GELPVoid const, eCAPITexture *) = 0;
    public: virtual bEResult SetCubeMap(GELPVoid const, eCAPICubeMap *) = 0;
    public: virtual bEResult SetVolume(GELPVoid const, eCAPIVolume *) = 0;
    public: virtual bEResult SetParameter(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult GetParameter(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult SetBoolArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult GetBoolArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult SetFloatArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult GetFloatArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult SetIntArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult GetIntArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult SetMatrixArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult GetMatrixArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult SetMatrixTransposeArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult GetMatrixTransposeArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult SetVectorArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult GetVectorArray(GELPVoid const, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult GetEffectDescription(eCGfxShared::eSGfxEffectDesc &) = 0;
    public: virtual bEResult GetParameterDescription(GEUInt, eCGfxShared::eSGfxParameterDesc &) = 0;
    public: virtual bEResult GetTechniqueDescription(GEUInt, eCGfxShared::eSGfxTechniqueDesc &) = 0;
    public: virtual bEResult IsParameterUsed(GELPVoid const, GELPVoid const, GEBool &) = 0;
    public: virtual bEResult SetTechnique(GELPVoid const) = 0;
    public: virtual bEResult SetPassNumber(GEUInt) = 0;
    public: virtual bEResult BeginTechnique() = 0;
    public: virtual bEResult EndTechnique() = 0;
    public: virtual ~eCAPIEffect();
    // clang-format on

  public:
    eCAPIEffect(eCAPIEffect const &);

  public:
    eCAPIEffect &operator=(eCAPIEffect const &);

  public:
    GEU32 AddRef();
    GEU32 Release();

  protected:
    eCAPIEffect();

  private:
    GEU32 m_u32ReferenceCount;
};
