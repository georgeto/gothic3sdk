#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT CFFGFCProgressBar : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCProgressBar() override;
    // clang-format on

  public:
    CFFGFCProgressBar(CFFGFCProgressBar const &);
    CFFGFCProgressBar();

  public:
    CFFGFCProgressBar &operator=(CFFGFCProgressBar const &);

  public:
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    GEU32 GetBarColor() const;
    GEU32 GetBkColor() const;
    GEInt GetPos() const;
    void GetRange(GEInt &, GEInt &) const;
    void OffsetPos(GEInt);
    void SetBarColor(bCByteAlphaColor const &);
    void SetBarColor(GEU32);
    void SetBkColor(bCByteAlphaColor const &);
    void SetBkColor(GEU32);
    void SetPos(GEInt);
    void SetRange(GEInt, GEInt);
    void SetStep(GEInt);
    void StepIt();
};
