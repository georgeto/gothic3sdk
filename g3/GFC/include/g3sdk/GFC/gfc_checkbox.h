#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT CFFGFCCheckBox : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCCheckBox() override;
    // clang-format on

  public:
    CFFGFCCheckBox(CFFGFCCheckBox const &);
    CFFGFCCheckBox();

  public:
    CFFGFCCheckBox &operator=(CFFGFCCheckBox const &);

  public:
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    GEBool GetCheck() const;
    void SetCheck(GEBool);
};
