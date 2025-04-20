#pragma once

#include <Engine.h>

class gCTreasureSet_PS;

class GE_DLLIMPORT gCTreasureSetAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: ~gCTreasureSetAdmin() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCTreasureSetAdmin, eCEngineComponentBase)

  public:
    static gCTreasureSetAdmin &GE_STDCALL GetInstance();

  public:
    gCTreasureSet_PS *GetTreasureSet(bCString const &);
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCTreasureSetAdmin, 0x14)
