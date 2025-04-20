#pragma once

#include <GFC.h>

class GE_DLLIMPORT eCGUIConsoleDialog : public CFFGFCDialog
{
  public:
    enum EItemAlign
    {
        // TODO: Enumerator values
    };

    // clang-format off
    protected: virtual GEBool OnExecute(bCString const &, bCString &);
    protected: virtual GEBool OnComplete(bCString &);
    public: void OnCreate() override;
    public: void OnCommand(GEUInt, GEUInt) override;
    public: void OnDesktopSized(GEInt, GEInt) override;
    public: ~eCGUIConsoleDialog() override;
    // clang-format on

  public:
    eCGUIConsoleDialog(eCGUIConsoleDialog const &);
    eCGUIConsoleDialog();

  public:
    eCGUIConsoleDialog &operator=(eCGUIConsoleDialog const &);

  public:
    void ClearOutput();
    void Complete();
    GEBool Create();
    void Execute();
    void PrintHistory();
    void PrintOutput(bCString const &, bCByteAlphaColor const &, EItemAlign);

  protected:
    void CreateControls();
    void PlaceControls();
};
