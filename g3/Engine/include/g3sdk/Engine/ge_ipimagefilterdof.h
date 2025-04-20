#pragma once

#include <Engine/ge_ipimagefilterbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIPImageFilterDOF : public eCIPImageFilterBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt, GEInt);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPImageFilterDOF() override;
    protected: void OnParseEffectParam(eCGfxShared::eSGfxParameterDesc const &) override;
    protected: void OnParseEffectTechnique(GEInt, eCGfxShared::eSGfxTechniqueDesc const &) override;
    public: bEResult PreExecuteFilterShader(GEInt) override;
    public: bEResult UpdateVertexData(GEInt) override;
    public: bEResult UpdateTargetSize() override;
    // clang-format on

  public:
    eCIPImageFilterDOF(eCIPImageFilterDOF const &);
    eCIPImageFilterDOF();

  public:
    bCVector2 const &GetFocalDepthOffset() const;
    GEFloat GetMaxBlur() const;
    void SetFocalDepthOffset(bCVector2 const &);
    void SetMaxBlur(GEFloat);

  protected:
    eCIPImageFilterDOF const &operator=(eCIPImageFilterDOF const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
