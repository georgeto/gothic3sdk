#pragma once

#include <SharedBase.h>

class gCTraitDesc;

class GE_DLLIMPORT gCTrait
{
  public:
    gCTrait();
    ~gCTrait();

  public:
    gCTrait &operator=(gCTrait const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    GEBool Create(GEInt);
    GEInt Decrement();
    GEInt GetCount() const;
    gCTraitDesc *GetDesc() const;
    GEInt GetID() const;
    GEInt Increment();
    GEBool IsLearned() const;
    GEInt Learn();
};
