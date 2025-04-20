#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCAPIFont;
class eCAPITexture;
class eCGfxFont;
class eCGfxImageData;

class GE_DLLIMPORT eCGfxSprite : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult Begin(GEU32);
    public: virtual bEResult Draw(eCAPITexture *, bCRect const *, bCVector const *, bCVector const *, GEU32);
    public: virtual bEResult DrawTextA(eCAPIFont *, GELPCChar, GEInt, bCRect *, GEU32, GEU32);
    public: virtual bEResult DrawTextA(eCAPIFont *, GELPCUnicodeChar, GEInt, bCRect *, GEU32, GEU32);
    public: virtual bEResult Flush();
    public: virtual bEResult End();
    public: virtual bEResult GetTransform(bCMatrix *);
    public: virtual bEResult SetTransform(bCMatrix const *);
    public: virtual bEResult SetWorldViewLH(bCMatrix const *, bCMatrix const *);
    public: virtual bEResult SetWorldViewRH(bCMatrix const *, bCMatrix const *);
    public: virtual bEResult Create(eCGfxShared::eSSpriteDesc const &);
    public: virtual bEResult CopyFrom(eCGfxSprite const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxSprite() override;
    // clang-format on

  public:
    eCGfxSprite(eCGfxSprite const &);
    eCGfxSprite();

  public:
    eCGfxSprite &operator=(eCGfxSprite const &);

  public:
    bEResult Draw(eCGfxImageData *, bCRect const *, bCVector const *, bCVector const *, GEU32);
    bEResult DrawTextA(eCGfxFont *, GELPCChar, GEInt, bCRect *, GEU32, GEU32);
    bEResult DrawTextA(eCGfxFont *, GELPCUnicodeChar, GEInt, bCRect *, GEU32, GEU32);
    void Invalidate();

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxSprite *ms_pActiveSprite;
    static eCGfxSprite *ms_pMasterSprite;
    static void(GE_STDCALL *ms_pRegisterSpriteExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxSprite *GE_STDCALL sGetActiveSprite();
    static eCGfxSprite *GE_STDCALL sGetMasterSprite();
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetMasterSprite(eCGfxSprite *);
    static void GE_STDCALL sSetSpriteExecuteCallback(void(GE_STDCALL *)());

  protected:
    bEResult CreateSprite(eCGfxShared::eSSpriteDesc const &);
    bEResult DestroySprite();
};
