#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT CFFGFCDialog : public CFFGFCWnd
{
    // clang-format off
    public: virtual GEInt DoModal();
    public: virtual GEBool OnInitDialog();
    public: virtual void OnOK();
    public: virtual void OnCancel();
    protected: GEInt WindowProc(GEUInt, GEUInt, GEUInt) override;
    public: ~CFFGFCDialog() override;
    // clang-format on

  public:
    CFFGFCDialog(CFFGFCDialog const &);
    CFFGFCDialog(GEInt, CFFGFCWnd *);
    CFFGFCDialog(GELPCChar, CFFGFCWnd *);
    CFFGFCDialog();

  public:
    CFFGFCDialog &operator=(CFFGFCDialog const &);

  public:
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    void EndDialog(GEInt);

  private:
    void PostModal();
    void PreModal();
};
