#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class CFFGFCToolInfo
{
    GE_UNIMPL_STRUCT(CFFGFCToolInfo)
};

struct SFFGUIToolTipTool
{
    GE_UNIMPL_STRUCT(SFFGUIToolTipTool)
};

class GE_DLLIMPORT CFFGFCToolTipCtrl : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCToolTipCtrl() override;
    // clang-format on

  public:
    CFFGFCToolTipCtrl(CFFGFCToolTipCtrl const &);
    CFFGFCToolTipCtrl();

  public:
    CFFGFCToolTipCtrl &operator=(CFFGFCToolTipCtrl const &);

  public:
    void Activate(GEBool);
    GEBool AddTool(CFFGFCWnd *, GELPCUnicodeChar, bCRect const *, GEU32);
    GEBool AdjustRect(bCRect &, GEBool);
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    void DelTool(CFFGFCWnd *, GEU32);
    bCPoint GetBubbleSize(SFFGUIToolTipTool &) const;
    GEInt GetDelayTime(GEU32) const;
    void GetMargin(bCRect &) const;
    GEInt GetMaxTipWidth() const;
    void GetText(bCUnicodeString &, CFFGFCWnd *, GEU32) const;
    bCByteAlphaColor GetTipBkColor() const;
    bCByteAlphaColor GetTipTextColor() const;
    GEInt GetToolCount() const;
    GEBool GetToolInfo(CFFGFCToolInfo &, CFFGFCWnd *, GEU32) const;
    void Pop();
    void SetDelayTime(GEInt);
    void SetDelayTime(GEU32, GEInt);
    void SetMargin(bCRect const &);
    void SetMaxTipWidth(GEInt);
    void SetTipBkColor(bCByteAlphaColor const &);
    void SetTipTextColor(bCByteAlphaColor const &);
    GEBool SetTitle(GEU32, bCUnicodeString const &);
    void SetToolInfo(SFFGUIToolTipTool const &);
    void SetToolRect(CFFGFCWnd *, GEU32, bCRect const &);
    void SetWindowTheme(bCString const &);
    void Update();
    void UpdateTipText(bCUnicodeString const &, CFFGFCWnd *, GEU32);
};
