#pragma once

#include "ge_mapbase.h"

template <typename K, typename T>
class bTValMap
{
  public:
    struct bSNode
    {
        K m_Key;
        T m_Element;
        bSNode *m_pNext;
    };
    GE_DECLARE_MAP_ITERATORS()
  protected:
    bTPtrArray<bSNode *> m_arrNodes;
    GEU32 m_u32Count;

  protected:
    bSNode *AccessNode(K const &_k, GEU32 &_h);
    bSNode const *GetNode(K const &_k, GEU32 &_h) const;
    void Init();

  public:
    T &AccessAt(K const &_k);
    T &AccessAt(K const &_k, GEU32 &_h);
    bCConstIterator Begin() const;
    bCIterator Begin();
    bCConstIterator begin() const
    {
        return Begin();
    };
    bCIterator begin()
    {
        return Begin();
    };
    void Clear();
    void CopyFrom(bTValMap<K, T> const &_s);
    void CopyTo(bTValMap<K, T> &_d) const;
    bCConstIterator End() const;
    bCIterator End();
    bCConstIterator end() const
    {
        return End();
    };
    bCIterator end()
    {
        return End();
    };
    T const &GetAt(K const &_k) const;
    GEBool GetAt(K const &_k, T &_e) const;
    GEInt GetCount() const;
    bTPtrArray<bSNode *> const &GetNodes() const;
    void InitHashTable(GEU32 _n);
    GEBool IsEmpty() const;
    GEBool IsValidKey(K const &_k) const;
    void SetAt(K const &_k, T const &_e);
    GEBool RemoveAt(K const &_k);

  public:
    T &operator[](K const &_k);
    T const &operator[](K const &_k) const;
    bTValMap<K, T> const &operator=(bTValMap<K, T> const &_s);

  public:
    bTValMap(bTValMap<K, T> const &_s);
    bTValMap();
    ~bTValMap();
};

#include "ge_valmap.inl"
