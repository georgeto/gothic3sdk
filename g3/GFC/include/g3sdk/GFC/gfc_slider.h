#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT CFFGFCSlider : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCSlider() override;
    // clang-format on

  public:
    CFFGFCSlider(CFFGFCSlider const &);
    CFFGFCSlider();

  public:
    CFFGFCSlider &operator=(CFFGFCSlider const &);

  public:
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    GEInt GetPos() const;
    void GetRange(GEInt &, GEInt &) const;
    GEInt GetRangeMax() const;
    GEInt GetRangeMin() const;
    void GetThumbRect(bCRect &) const;
    void SetPos(GEInt);
    void SetRange(GEInt, GEInt);
    void SetRangeMax(GEInt);
    void SetRangeMin(GEInt);
};
