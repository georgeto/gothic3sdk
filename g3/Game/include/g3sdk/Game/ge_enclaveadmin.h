#pragma once

#include <Engine.h>

class gCEnclave_PS;

class GE_DLLIMPORT gCEnclaveAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: ~gCEnclaveAdmin() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEnclaveAdmin, eCEngineComponentBase)

  public:
    static gCEnclaveAdmin &GE_STDCALL GetInstance();

  public:
    bEResult AddEnclave(gCEnclave_PS *);
    bTValArray<gCEnclave_PS *> const &GetEnclaves();
    void Invalidate();
    void RefreshEnclaveMembers(GEBool);
    bEResult RemoveEnclave(gCEnclave_PS *);

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(gCEnclaveAdmin, 0x20)
