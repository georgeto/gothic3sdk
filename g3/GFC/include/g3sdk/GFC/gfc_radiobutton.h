#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT CFFGFCRadioButton : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCRadioButton() override;
    // clang-format on

  public:
    CFFGFCRadioButton(CFFGFCRadioButton const &);
    CFFGFCRadioButton();

  public:
    CFFGFCRadioButton &operator=(CFFGFCRadioButton const &);

  public:
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
};
