#pragma once

#include <Engine/ge_ipimagefilterbase.h>

#include <SharedBase.h>

class eCEntityPropertySet;
class eCLightmap;
class eCShadowMapBase;

class GE_DLLIMPORT eCIPImageFilterLightmapLight : public eCIPImageFilterBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt, GEInt);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPImageFilterLightmapLight() override;
    protected: void OnParseEffectParam(eCGfxShared::eSGfxParameterDesc const &) override;
    protected: void OnParseEffectTechnique(GEInt, eCGfxShared::eSGfxTechniqueDesc const &) override;
    protected: GEBool CreateFilterVertexData() override;
    protected: void DestroyFilterVertexData() override;
    protected: bEResult PreExecuteFilterShader(GEInt) override;
    protected: bEResult UpdateVertexData(GEInt) override;
    public: bEResult Execute() override;
    // clang-format on

  public:
    eCIPImageFilterLightmapLight(eCIPImageFilterLightmapLight const &);
    eCIPImageFilterLightmapLight();

  public:
    void FlushResults();
    eCLightmap *GetLightmap() const;
    bCMatrix const &GetWorldMatrix() const;
    void SetLight(eCEntityPropertySet *, eCShadowMapBase *);
    GEBool SetLightmap(eCLightmap *);
    void SetWorldMatrix(bCMatrix const &);

  protected:
    eCIPImageFilterLightmapLight const &operator=(eCIPImageFilterLightmapLight const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
