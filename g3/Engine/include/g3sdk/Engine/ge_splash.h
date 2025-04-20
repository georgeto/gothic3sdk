#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCSplash
{
    // clang-format off
    public: virtual ~eCSplash();
    // clang-format on

  public:
    eCSplash(eCSplash const &);
    eCSplash(bCString const &, GEU32);
    eCSplash();

  public:
    eCSplash &operator=(eCSplash const &);

  public:
    GEInt Close();
    GEInt DoLoop();
    GEU32 SetBitmap(bCString const &);
    GEU32 SetBitmap(HBITMAP);
    GEBool SetTransparentColor(GEU32);
    void Show();
    GEI32 GE_STDCALL WindowProc(HWND, GEUInt, GEUInt, GEI32);

  private:
    void FreeResources();
    void Invalidate();
    GEBool MakeTransparent();
    void OnPaint(HWND);
    HWND RegAndCreateWindow();
};
