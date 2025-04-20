#pragma once

#include <Engine/io/ge_inpshared.h>

#include <SharedBase.h>

struct DIDEVICEINSTANCEA;

class GE_DLLIMPORT eCInpContextAdmin : public bCObjectRefBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCInpContextAdmin() override;
    // clang-format on

  public:
    eCInpContextAdmin(eCInpContextAdmin const &);

  public:
    eCInpContextAdmin &operator=(eCInpContextAdmin const &);

  public:
    bEResult Create(HWND);
    bEResult EnumGamepads(GEU32, eCInpShared::eSInpGamepadDesc &) const;
    bEResult GetGamepadCount(GEU32 &) const;
    void Invalidate();

  protected:
    static GELPVoid ms_pInputObject;

  protected:
    static GEInt GE_STDCALL sGamepadEnumerationCB(DIDEVICEINSTANCEA const *, GELPVoid);
    static GELPVoid GE_STDCALL sGetInputObject();

  protected:
    eCInpContextAdmin();
};
