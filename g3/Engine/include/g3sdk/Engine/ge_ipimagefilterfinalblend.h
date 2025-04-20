#pragma once

#include <Engine/ge_gfxshared.h>
#include <Engine/ge_ipimagefilterbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIPImageFilterFinalBlend : public eCIPImageFilterBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt);
    public: virtual bEResult Create(eCGfxShared::eEBlending, eCGfxShared::eEBlending, GEInt, bCString const *);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPImageFilterFinalBlend() override;
    protected: bEResult PreExecuteFilterShader(GEInt) override;
    protected: bEResult UpdateVertexData(GEInt) override;
    // clang-format on

  public:
    eCIPImageFilterFinalBlend(eCIPImageFilterFinalBlend const &);
    eCIPImageFilterFinalBlend();

  public:
    eCGfxShared::eEBlending GetDstBlending() const;
    eCGfxShared::eEBlending GetSrcBlending() const;
    void SetDstBlending(eCGfxShared::eEBlending);
    void SetSrcBlending(eCGfxShared::eEBlending);

  protected:
    eCIPImageFilterFinalBlend const &operator=(eCIPImageFilterFinalBlend const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
