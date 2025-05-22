#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT CFFGFCView : public CFFGFCWnd
{
    // clang-format off
    public: virtual GEBool OnInitDialog();
    protected: GEInt WindowProc(GEUInt, GEUInt, GEUInt) override;
    public: ~CFFGFCView() override;
    // clang-format on

  public:
    CFFGFCView(CFFGFCView const &);
    CFFGFCView(GEInt, CFFGFCWnd *);
    CFFGFCView(GELPCChar, CFFGFCWnd *);
    CFFGFCView();

  public:
    CFFGFCView &operator=(CFFGFCView const &);

  public:
    using CFFGFCWnd::Create;
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
};
