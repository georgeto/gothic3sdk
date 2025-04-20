#pragma once

#include <GFC/gfc_wnd.h>

#include <GUI.h>

class GE_DLLIMPORT CFFGFCButton : public virtual CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCButton() override;
    // clang-format on

  public:
    CFFGFCButton(CFFGFCButton const &);
    CFFGFCButton();

  public:
    CFFGFCButton &operator=(CFFGFCButton const &);

  public:
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    IFFGUIBitmap *GetBitmap() const;
    GEU32 GetState() const;
    IFFGUIBitmap *SetBitmap(IFFGUIBitmap *);
};

GE_ASSERT_SIZEOF(CFFGFCButton, 0x14)
