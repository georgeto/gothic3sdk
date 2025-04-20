#pragma once

#include <Engine/api/ge_apifont.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCDX9Device;
struct ID3DXFont;
struct IDirect3DDevice9;

class GE_DLLIMPORT eCDX9Font : public eCAPIFont
{
    // clang-format off
    public: bEResult GetGlyphData(GEUInt, bCRect &, bCVector2 &, eCAPITexture *&, eCGfxShared::eSGfxLayersDesc &) override;
    public: bEResult GetTextIndices(bCString const &, GEU16 *&, GEU16 &) override;
    public: bEResult GetTextIndices(bCUnicodeString const &, GEU16 *&, GEU16 &) override;
    public: bEResult GetDeviceContext(HDC &) override;
    public: bEResult DrawTextA(bCUnicodeString, bCRect *, GEU32, GEU32) override;
    public: ~eCDX9Font() override;
    // clang-format on

  public:
    eCDX9Font(eCDX9Font const &);

  public:
    eCDX9Font &operator=(eCDX9Font const &);

  protected:
    static GEBool ms_bOptimize;

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();

  protected:
    eCDX9Font(eCGfxShared::eSFontDesc &, IDirect3DDevice9 *, eCDX9Device *, GEBool &);

  protected:
    ID3DXFont *GetHandle() const;
    bEResult OnLostDevice();
    bEResult OnResetDevice();
};
