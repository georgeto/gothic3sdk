#pragma once

#include <SharedBase/container/map/ge_valmap.h>

template <typename T>
class bTSet
{
  public:
    void Add(T const &_e);
    void Clear();
    GEBool Contains(T const &_e) const;
    GEInt GetCount() const;
    void Init(GEU32 _n);
    GEBool IsEmpty() const;
    GEBool Remove(T const &_e);

    bCOStream &operator>>(bCOStream &_os) const;
    bCIStream &operator<<(bCIStream &_is);

  protected:
    bTValMap<T, GEInt> m_Map;
};

#include "ge_set.inl"
