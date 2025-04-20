#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

struct SFFGUIScrollInfo
{
    GEUInt fMask;
    GEInt nMin;
    GEInt nMax;
    GEUInt nPage;
    GEInt nPos;
    GEInt nTrackPos;
};

struct SFFGUIScrollBarInfo
{
    GE_UNIMPL_STRUCT(SFFGUIScrollBarInfo)
};

class GE_DLLIMPORT CFFGFCScrollBar : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCScrollBar() override;
    // clang-format on

  public:
    CFFGFCScrollBar(CFFGFCScrollBar const &);
    CFFGFCScrollBar();

  public:
    CFFGFCScrollBar &operator=(CFFGFCScrollBar const &);

  public:
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    GEBool EnableScrollBar(GEU32);
    GEBool GetScrollBarInfo(SFFGUIScrollBarInfo &) const;
    GEBool GetScrollInfo(SFFGUIScrollInfo &) const;
    GEInt GetScrollLimit() const;
    GEInt GetScrollPos() const;
    void GetScrollRange(GEInt *, GEInt *) const;
    void SetScrollInfo(SFFGUIScrollInfo &);
    void SetScrollPos(GEInt);
    void SetScrollRange(GEInt, GEInt);
    void ShowScrollBar(GEBool);
};
