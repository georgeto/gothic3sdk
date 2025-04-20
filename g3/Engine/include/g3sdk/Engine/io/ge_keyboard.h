#pragma once

#include <Engine/io/ge_inpshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCKeyboard : public bCObjectRefBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCKeyboard() override;
    // clang-format on

  public:
    eCKeyboard(eCKeyboard const &);
    eCKeyboard();

  public:
    eCKeyboard &operator=(eCKeyboard const &);

  public:
    GEBool AnyKeyPressed() const;
    void ClearKeyBuffer();
    bEResult Create(HWND, eCInpShared::eECoopLevel);
    bEResult Execute();
    bEResult GetBufferSize(GEU32 &) const;
    bEResult GetBufferedData(GEU32 &, eCInpShared::eSInpBufferedData *, GEBool &) const;
    GEBool GetCapsLock() const;
    eCInpShared::eEKeyboardStateOffset const &GetKeyByName(bCString const &);
    bCString GetKeyName(eCInpShared::eEKeyboardStateOffset &);
    bCUnicodeString GetLocalizedKeyName(eCInpShared::eEKeyboardStateOffset &);
    GEBool GetNumLock() const;
    GEU32 GetNumOccuredEvents();
    eCInpShared::eSInputMessage const &GetOccuredEvent(GEU32) const;
    bEResult GetState(eCInpShared::eSInpKeyboardState &) const;
    void Invalidate();
    GEBool KeyPressed(eCInpShared::eEKeyboardStateOffset) const;
    GEBool KeyToggled(eCInpShared::eEKeyboardStateOffset) const;
    void ResetRepeatKey(GEBool);
    bEResult SetBufferSize(GEU32);
    void SetCapsLock(GEBool);
    void SetNumLock(GEBool);
    void ToggleCapsLock();
    void ToggleNumLock();

  protected:
    void CreateKeyNames();
    void CreateOccuredKeyList();
    GEChar GetCharacter(eCInpShared::eSInputMessage &);
    void HandleAutoRepeat();
    void HandleBufferOverflow(bTObjArray<eCInpShared::eSInputMessage> &);
};
