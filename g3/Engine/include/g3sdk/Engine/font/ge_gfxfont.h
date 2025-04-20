#pragma once

#include <Engine/api/ge_apidevice.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCGfxImageData;

class GE_DLLIMPORT eCGfxFont : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult Create(eCGfxShared::eSFontDesc const &);
    public: virtual bEResult CopyFrom(eCGfxFont const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxFont() override;
    // clang-format on

  public:
    eCGfxFont(eCGfxFont const &);
    eCGfxFont();

  public:
    eCGfxFont &operator=(eCGfxFont const &);

  public:
    bEResult Execute();
    bEResult GetDeviceContext(HDC &);
    bEResult GetFontDescription(eCGfxShared::eSFontDesc &) const;
    bEResult GetGlyphData(GEUInt, bCRect &, bCVector2 &, eCGfxImageData *&);
    bEResult GetTextIndices(bCString const &, GEU16 *&, GEU16 &);
    bEResult GetTextIndices(bCUnicodeString const &, GEU16 *&, GEU16 &);
    void Invalidate();
    bEResult SetText(bCUnicodeString, bCRect const *, GEU32, GEU32);

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxFont *ms_pActiveFont;
    static eCGfxFont *ms_pMasterFont;
    static void(GE_STDCALL *ms_pRegisterFontExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxFont *GE_STDCALL sGetActiveFont();
    static eCGfxFont *GE_STDCALL sGetMasterFont();
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetFontExecuteCallback(void(GE_STDCALL *)());
    static void GE_STDCALL sSetMasterFont(eCGfxFont *);

  protected:
    bEResult CreateFontA(eCGfxShared::eSFontDesc const &);
    bEResult DestroyFont();
    eCAPIFont *GetHandle() const;

  private:
    eCAPIDevice *m_pAPIDevice;
    eCGfxShared::eSFontDesc m_FontDest;
    eCAPIFont *m_pAPIFont;
    bCUnicodeString m_strText;
    bCRect m_TextRect;
    GEBool m_bHasTextRect;
    GE_PADDING(0x3)
    GEUInt m_SetTextParam4;
    GEUInt m_SetTextParam5;
    GEBool m_bUnk1;
    GE_PADDING(0x3)
    bTAutoPtrArray<GELPVoid> m_arrGlyphData;
};

GE_ASSERT_SIZEOF(eCGfxFont, 0x6c)
