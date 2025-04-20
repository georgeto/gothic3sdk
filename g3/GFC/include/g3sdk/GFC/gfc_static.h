#pragma once

#include <GFC/gfc_wnd.h>

#include <GUI.h>

class GE_DLLIMPORT CFFGFCStatic : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCStatic() override;
    // clang-format on

  public:
    CFFGFCStatic(CFFGFCStatic const &);
    CFFGFCStatic();

  public:
    CFFGFCStatic &operator=(CFFGFCStatic const &);

  public:
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    IFFGUIBitmap *GetBitmap() const;
    IFFGUIBitmap *SetBitmap(IFFGUIBitmap *);
};
