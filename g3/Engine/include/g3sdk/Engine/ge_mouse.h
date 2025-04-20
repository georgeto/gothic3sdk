#pragma once

#include <Engine/io/ge_inpshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCMouse : public bCObjectRefBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCMouse() override;
    // clang-format on

  public:
    eCMouse(eCMouse const &);
    eCMouse();

  public:
    eCMouse &operator=(eCMouse const &);

  public:
    GEBool ButtonPressed(eCInpShared::eEMouseOffset) const;
    GEBool ButtonToggled(eCInpShared::eEMouseOffset) const;
    void ClearBuffer();
    bEResult Create(HWND, eCInpShared::eECoopLevel);
    bEResult Execute();
    bEResult GetBufferSize(GEU32 &) const;
    bEResult GetBufferedData(GEU32 &, eCInpShared::eSInpBufferedData *, GEBool &) const;
    bCUnicodeString GetLocalizedStateName(eCInpShared::eEMouseOffset &);
    bEResult GetMode(eCInpShared::eEAxisMode &) const;
    GEU32 const GetMouseClickDelay() const;
    bCPoint3 const GetMouseDelta() const;
    bCPoint const &GetMousePointerDelta() const;
    bCPoint const &GetMousePointerPos() const;
    GEU32 GetNumOccuredEvents();
    eCInpShared::eSInputMessage const &GetOccuredEvent(GEU32) const;
    bEResult GetState(eCInpShared::eSInpMouseState &) const;
    eCInpShared::eEMouseOffset GetStateByName(bCString const &);
    bCString GetStateName(eCInpShared::eEMouseOffset &);
    void Invalidate();
    bEResult SetBufferSize(GEU32);
    bEResult SetMode(eCInpShared::eEAxisMode);
    bEResult SetMouseClickDelay(GEU32);
    void SetMousePointerDelta(bCPoint const &);
    void SetMousePointerPos(bCPoint const &);
    GEBool StateOccured(eCInpShared::eEMouseOffset, GEInt &) const;

  private:
    void CreateOccuredEvents();
    void HandleBufferOverflow(bTObjArray<eCInpShared::eSInputMessage> &);
    void UpdateMousePointer();
};
