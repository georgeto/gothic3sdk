#pragma once

#include <Engine/ge_ipimagefilterbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIPImageFilterLightmapBorders : public eCIPImageFilterBase
{
    // clang-format off
    public: virtual bEResult Create(eCIPSourceBase *);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPImageFilterLightmapBorders() override;
    protected: void OnParseEffectParam(eCGfxShared::eSGfxParameterDesc const &) override;
    protected: void OnParseEffectTechnique(GEInt, eCGfxShared::eSGfxTechniqueDesc const &) override;
    protected: bEResult UpdateSources() override;
    protected: bEResult PreExecuteFilterShader(GEInt) override;
    protected: bEResult UpdateVertexData(GEInt) override;
    protected: bEResult UpdateTargetSize() override;
    // clang-format on

  protected:
    eCIPImageFilterLightmapBorders(eCIPImageFilterLightmapBorders const &);
    eCIPImageFilterLightmapBorders();

  protected:
    eCIPImageFilterLightmapBorders const &operator=(eCIPImageFilterLightmapBorders const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
