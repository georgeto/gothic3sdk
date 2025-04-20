#pragma once

#include <SharedBase.h>

struct GE_DLLIMPORT eSParticleSound
{
  public:
    eSParticleSound(eSParticleSound const &);
    eSParticleSound();
    ~eSParticleSound();

  public:
    eSParticleSound &operator=(eSParticleSound const &);

  private:
    bCString field_0;
    GEU32 field_4;
    GEU32 field_8;
    GEU32 field_C;
    GEU32 field_10;
    GEU32 field_14;
    GEU32 field_18;
    GEU32 field_1C;
    GEU32 field_20;
};
