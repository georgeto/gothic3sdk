#pragma once

#include <Engine/ge_ipimagefilterbase.h>

#include <SharedBase.h>

enum eEIPBlurDirection
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCIPImageFilterBlur : public eCIPImageFilterBase
{
    // clang-format off
    public: virtual GEFloat GetBlurSize() const;
    public: virtual void SetBlurSize(GEFloat);
    public: virtual bEResult Create(GEInt, GEInt, eEIPBlurDirection, GEFloat);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPImageFilterBlur() override;
    protected: void OnParseEffectParam(eCGfxShared::eSGfxParameterDesc const &) override;
    protected: void OnParseEffectTechnique(GEInt, eCGfxShared::eSGfxTechniqueDesc const &) override;
    protected: bEResult PreExecuteFilterShader(GEInt) override;
    protected: bEResult UpdateVertexData(GEInt) override;
    protected: bEResult UpdateTargetSize() override;
    // clang-format on

  public:
    eCIPImageFilterBlur(eCIPImageFilterBlur const &);
    eCIPImageFilterBlur();

  protected:
    eCIPImageFilterBlur const &operator=(eCIPImageFilterBlur const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
