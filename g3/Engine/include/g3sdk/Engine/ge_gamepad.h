#pragma once

#include <Engine/io/ge_inpshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCGamepad : public bCObjectRefBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCGamepad() override;
    // clang-format on

  public:
    eCGamepad(eCGamepad const &);
    eCGamepad();

  public:
    eCGamepad &operator=(eCGamepad const &);

  public:
    bEResult Create(HWND, _GUID, eCInpShared::eECoopLevel);
    bEResult Execute();
    bEResult GetBufferSize(GEU32 &) const;
    bEResult GetBufferedData(GEU32 &, eCInpShared::eSInpBufferedData *, GEBool &) const;
    bEResult GetMode(eCInpShared::eEAxisMode &) const;
    bEResult GetState(eCInpShared::eSInpGamepadState &) const;
    void Invalidate();
    bEResult SetBufferSize(GEU32);
    bEResult SetMode(eCInpShared::eEAxisMode);
};
