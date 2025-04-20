#pragma once

#include <GFC.h>

class GE_DLLIMPORT eCGUIConsoleEdit : public CFFGFCEdit
{
  public:
    enum EMode
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: void OnKeyDown(GEUInt, GEUInt, GEUInt) override;
    public: void OnKeyUp(GEUInt, GEUInt, GEUInt) override;
    public: ~eCGUIConsoleEdit() override;
    // clang-format on

  public:
    eCGUIConsoleEdit(eCGUIConsoleEdit const &);
    eCGUIConsoleEdit();

  public:
    eCGUIConsoleEdit &operator=(eCGUIConsoleEdit const &);

  public:
    bTObjArray<bCUnicodeString> const &GetHistory() const;
    EMode GetMode() const;
    void SetHistoryCapacity(GEInt);
    void SetMode(EMode);

  protected:
    void Complete();
    void Execute();
    void Goto(GEInt);
    void GotoNext();
    void GotoPrev();
};
