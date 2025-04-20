#pragma once

#include <Engine/ge_ipimagefilterbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIPImageFilterEdgeBlur : public eCIPImageFilterBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt, GEInt);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPImageFilterEdgeBlur() override;
    protected: void OnParseEffectParam(eCGfxShared::eSGfxParameterDesc const &) override;
    protected: void OnParseEffectTechnique(GEInt, eCGfxShared::eSGfxTechniqueDesc const &) override;
    protected: bEResult PreExecuteFilterShader(GEInt) override;
    protected: bEResult UpdateVertexData(GEInt) override;
    protected: bEResult UpdateTargetSize() override;
    // clang-format on

  public:
    eCIPImageFilterEdgeBlur(eCIPImageFilterEdgeBlur const &);
    eCIPImageFilterEdgeBlur();

  protected:
    eCIPImageFilterEdgeBlur const &operator=(eCIPImageFilterEdgeBlur const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
