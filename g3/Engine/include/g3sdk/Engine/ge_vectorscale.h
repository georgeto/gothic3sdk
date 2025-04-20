#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCVectorScale
{
  public:
    eCVectorScale(eCVectorScale const &);
    eCVectorScale();
    ~eCVectorScale();

  public:
    eCVectorScale &operator=(eCVectorScale const &);

  public:
    void CalcValue(GEFloat, bCVector &) const;
    GEBool GetItem(GEInt, GEFloat &, bCVector &) const;
    GEInt GetItemCount() const;
    GEInt InsertItem(GEFloat, bCVector const &);
    void Read(bCIStream &);
    void RemoveAllItems();
    GEBool RemoveItem(GEInt);
    void Write(bCOStream &);

  protected:
    void CalcValueBinary(GEFloat, bCVector &) const;
    void CalcValueLinear(GEFloat, bCVector &) const;
};
