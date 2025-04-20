#pragma once

#include <Engine/ge_gfxshared.h>
#include <Engine/ge_ipsourcebase.h>

#include <SharedBase.h>

class eCGfxTextureBlock;

struct eSImageFilterDesc
{
    GE_UNIMPL_STRUCT(eSImageFilterDesc)
};

class GE_DLLIMPORT eCIPImageFilterBase : public eCIPSourceBase
{
    // clang-format off
    protected: virtual void SetSourceCount(GEInt);
    public: virtual GEBool IsSourceDirty() const;
    public: virtual void SetSourceDirty();
    public: virtual GEInt GetSourceCount() const;
    public: virtual eCIPSourceBase * GetSource(GEInt) const;
    public: virtual void SetSource(GEInt, eCIPSourceBase *);
    protected: virtual void OnInitVertexDecl(bTValArray<eCGfxShared::eSGfxDclElement> &, GEU32 &);
    protected: virtual void OnInitTextureBlock(eCGfxTextureBlock *);
    protected: virtual void OnParseEffect(eCGfxShared::eSGfxEffectDesc const &);
    protected: virtual void OnParseEffectParam(eCGfxShared::eSGfxParameterDesc const &);
    protected: virtual void OnParseEffectTechnique(GEInt, eCGfxShared::eSGfxTechniqueDesc const &);
    protected: virtual GEBool CreateOutputImage();
    protected: virtual void DestroyOutputImage();
    protected: virtual GEBool CreateFilterShader();
    protected: virtual void DestroyFilterShader();
    protected: virtual GEBool CreateFilterVertexData();
    protected: virtual void DestroyFilterVertexData();
    public: virtual bEResult Create(eSImageFilterDesc const &);
    protected: virtual bEResult UpdateSources();
    protected: virtual bEResult PreExecuteFilterShader(GEInt) = 0;
    protected: virtual bEResult UpdateVertexData(GEInt) = 0;
    protected: virtual bEResult UpdateTargetSize();
    public: virtual bEResult Execute();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPImageFilterBase() override;
    public: eCGfxImageData * GetImage() const override;
    public: void GetImageRect(bCRect &) const override;
    public: void GetImageSize(GEInt &, GEInt &) const override;
    public: GEBool IsDirty() const override;
    public: void SetDirty() override;
    public: bEResult OnResetResources(GEBool) override;
    public: bEResult OnRestoreResources(GEBool) override;
    protected: bEResult Update() override;
    // clang-format on

  public:
    eCIPImageFilterBase(eCIPImageFilterBase const &);
    eCIPImageFilterBase();

  public:
    void ClearImage();

  protected:
    eCIPImageFilterBase const &operator=(eCIPImageFilterBase const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
