#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT CFFGFCEdit : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCEdit() override;
    // clang-format on

  public:
    CFFGFCEdit(CFFGFCEdit const &);
    CFFGFCEdit();

  public:
    CFFGFCEdit &operator=(CFFGFCEdit const &);

  public:
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
};
