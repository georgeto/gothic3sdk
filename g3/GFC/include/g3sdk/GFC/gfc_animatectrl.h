#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT CFFGFCAnimateCtrl : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCAnimateCtrl() override;
    // clang-format on

  public:
    CFFGFCAnimateCtrl(CFFGFCAnimateCtrl const &);
    CFFGFCAnimateCtrl();

  public:
    CFFGFCAnimateCtrl &operator=(CFFGFCAnimateCtrl const &);

  public:
    GEBool Close();
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    GEBool Open(bCString const &);
    GEBool Play(GEInt, GEInt, GEInt);
    GEBool Seek(GEInt);
    GEBool Stop();
};
