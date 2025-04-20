#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCColorScale
{
  public:
    struct SItem
    {
      public:
        SItem &operator=(SItem const &);
    };

  public:
    eCColorScale(eCColorScale const &);
    eCColorScale();
    ~eCColorScale();

  public:
    eCColorScale &operator=(eCColorScale const &);

  public:
    void CalcValue(GEFloat, bCFloatAlphaColor &) const;
    GEBool GetItem(GEInt, GEFloat &, bCFloatAlphaColor &) const;
    GEInt GetItemCount() const;
    GEInt InsertItem(GEFloat, bCFloatAlphaColor const &);
    void Read(bCIStream &);
    void RemoveAllItems();
    GEBool RemoveItem(GEInt);
    void Write(bCOStream &);
};
