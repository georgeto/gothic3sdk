#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCWrapper_emfx2Services : public bCObjectBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCWrapper_emfx2Services() override;
    // clang-format on

  public:
    static GEU32 GE_STDCALL GetAllocatedMem();
    static GEU32 GE_STDCALL GetAllocatedNumObjects();

  public:
    eCWrapper_emfx2Services(eCWrapper_emfx2Services const &);
    eCWrapper_emfx2Services();

  protected:
    eCWrapper_emfx2Services const &operator=(eCWrapper_emfx2Services const &);

  protected:
    void Invalidate();
};
