#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCFloatScale
{
  public:
    eCFloatScale(eCFloatScale const &);
    eCFloatScale();
    ~eCFloatScale();

  public:
    eCFloatScale &operator=(eCFloatScale const &);

  public:
    void CalcValue(GEFloat, GEFloat &) const;
    GEBool GetItem(GEInt, GEFloat &, GEFloat &) const;
    GEInt GetItemCount() const;
    GEInt InsertItem(GEFloat, GEFloat);
    void Read(bCIStream &);
    void RemoveAllItems();
    GEBool RemoveItem(GEInt);
    void Write(bCOStream &);
};
