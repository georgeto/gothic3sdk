#pragma once

#include <Engine/api/ge_apisprite.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCDX9Device;
struct IDirect3DDevice9;

class GE_DLLIMPORT eCDX9Sprite : public eCAPISprite
{
    // clang-format off
    public: bEResult Begin(GEU32) override;
    public: bEResult Draw(eCAPITexture *, bCRect const *, bCVector const *, bCVector const *, GEU32) override;
    public: bEResult DrawTextA(eCAPIFont *, GELPCChar, GEInt, bCRect *, GEU32, GEU32) override;
    public: bEResult DrawTextA(eCAPIFont *, GELPCUnicodeChar, GEInt, bCRect *, GEU32, GEU32) override;
    public: bEResult Flush() override;
    public: bEResult End() override;
    public: bEResult GetTransform(bCMatrix *) override;
    public: bEResult SetTransform(bCMatrix const *) override;
    public: bEResult SetWorldViewLH(bCMatrix const *, bCMatrix const *) override;
    public: bEResult SetWorldViewRH(bCMatrix const *, bCMatrix const *) override;
    public: ~eCDX9Sprite() override;
    // clang-format on

  public:
    eCDX9Sprite(eCDX9Sprite const &);

  public:
    eCDX9Sprite &operator=(eCDX9Sprite const &);

  protected:
    static GEBool ms_bOptimize;

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();

  protected:
    eCDX9Sprite(eCGfxShared::eSSpriteDesc &, IDirect3DDevice9 *, eCDX9Device *, GEBool &);

  protected:
    bEResult OnLostDevice();
    bEResult OnResetDevice();
};
