#pragma once

#include <Engine.h>

class gCNPC_PS;

class GE_DLLIMPORT gCNPCAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: ~gCNPCAdmin() override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCNPCAdmin, eCEngineComponentBase)

  public:
    GEBool AddTickedNPC(gCNPC_PS *);
    void Invalidate();
    GEBool RemoveTickedNPC(gCNPC_PS *);

  protected:
    void TickNPCs();

  private:
    GE_UNIMPL_MEMBERS(20)
};

GE_ASSERT_SIZEOF(gCNPCAdmin, 0x28)
