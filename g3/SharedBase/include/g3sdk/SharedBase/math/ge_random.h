#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCRandom
{
  public:
    static bCRandom const &GE_STDCALL GetRandom();

  public:
    ~bCRandom();

  public:
    GEDouble DRand48(GEDouble, GEDouble) const;
    GEDouble DRand48() const;
    GEFloat FRand48(GEFloat, GEFloat) const;
    GEFloat FRand48() const;
    GEInt GetValue(GEInt, GEInt) const;
    GEInt GetValue() const;
    GEFloat GetValue(GEFloat, GEFloat) const;
    void SetSeed(GEInt) const;
    void SetTimedSeed() const;

  protected:
    bCRandom(bCRandom const &);
    bCRandom();

  protected:
    bCRandom &operator=(bCRandom const &);

  protected:
    void Invalidate();
};
