#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT CFFGFCToolBarCtrl : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCToolBarCtrl() override;
    // clang-format on

  public:
    CFFGFCToolBarCtrl(CFFGFCToolBarCtrl const &);
    CFFGFCToolBarCtrl();

  public:
    CFFGFCToolBarCtrl &operator=(CFFGFCToolBarCtrl const &);

  public:
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
};
