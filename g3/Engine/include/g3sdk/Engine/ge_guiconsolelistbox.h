#pragma once

#include <GFC.h>

class GE_DLLIMPORT eCGUIConsoleListBox : public CFFGFCListBox
{
  public:
    enum EItemAlign
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: GEBool PreCreateWindow(CFFGFCWnd::SCreateWnd &) override;
    public: void OnDeleteItem(GEU32, SFFGUIDeleteItem &) override;
    public: void OnDrawItem(GEU32, SFFGUIDrawItem &) override;
    public: ~eCGUIConsoleListBox() override;
    // clang-format on

  public:
    eCGUIConsoleListBox(eCGUIConsoleListBox const &);
    eCGUIConsoleListBox();

  public:
    eCGUIConsoleListBox &operator=(eCGUIConsoleListBox const &);

  public:
    GEInt AddString(bCUnicodeString const &);
    GEInt AddString(bCUnicodeString const &, bCByteAlphaColor const &, EItemAlign);
    GEInt InsertString(GEInt, bCUnicodeString const &);
    GEInt InsertString(GEInt, bCUnicodeString const &, bCByteAlphaColor const &, EItemAlign);
    GEInt SetCapacity(GEInt);
};
