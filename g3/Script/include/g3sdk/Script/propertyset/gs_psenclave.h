#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSEnclave : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSEnclave, gCEnclave_PS)
    GS_PROPERTY(bTValArray<GEI32>, CrimeCount)
    GS_PROPERTY(gEPlayerCrime, KnownPlayerCrime)
    GS_PROPERTY(GEBool, MusicPlayed)
    GS_PROPERTY(GEI32, PlayerFame)
    GS_PROPERTY(gEPoliticalAlignment, PoliticalAlignment)
    GS_PROPERTY(GEBool, Raid)
    GS_PROPERTY(GEBool, Revolution)
    GS_PROPERTY(gEEnclaveStatus, Status)
    GS_PROPERTY(bTValArray<GEI32>, SuspectComment)
    GS_PROPERTY(GEBool, Switched)

  public:
    static Entity GE_STDCALL GetEnclave(bCString const &);
    static Entity GE_STDCALL GetEnclaveAt(GEInt);
    static GEInt GE_STDCALL GetEnclaveCount();

  public:
    GEI32 GetCrimeCount(gEPlayerCrime);
    bCUnicodeString GetDisplayName();
    bTValArray<eCEntity *> const GetMembers() const;
    GEI32 GetSuspectComment(gEPlayerCrime);
    void SetCrimeCount(gEPlayerCrime, GEI32);
    void SetSuspectComment(gEPlayerCrime, GEI32);
};
