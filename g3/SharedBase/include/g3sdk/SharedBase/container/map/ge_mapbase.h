#pragma once

#include <SharedBase/container/array/ge_ptrarray.h>

template <typename T>
inline GEU32 GE_STDCALL g_GetHashValue(T const &_e)
{
    // Use C-style cast to support pointers as well as type conversions
    return ((GEU32)_e) >> 4;
}

#define GE_DECLARE_MAP_ITERATORS()                                                                                     \
  public:                                                                                                              \
    class bCConstIterator;                                                                                             \
    class bCIterator;                                                                                                  \
    friend class bCConstIterator;                                                                                      \
    friend class bCIterator;                                                                                           \
    class bCConstIterator                                                                                              \
    {                                                                                                                  \
      protected:                                                                                                       \
        bTPtrArray<bSNode *> *m_parrNodes;                                                                             \
        GEInt m_iHash;                                                                                                 \
        bSNode *m_pNode;                                                                                               \
                                                                                                                       \
      public:                                                                                                          \
        GEInt GetHash() const                                                                                          \
        {                                                                                                              \
            return this->m_iHash;                                                                                      \
        }                                                                                                              \
        K const &GetKey() const                                                                                        \
        {                                                                                                              \
            return this->m_pNode->m_Key;                                                                               \
        }                                                                                                              \
        bSNode const *GetNode() const                                                                                  \
        {                                                                                                              \
            return this->m_pNode;                                                                                      \
        }                                                                                                              \
        T const &operator*() const                                                                                     \
        {                                                                                                              \
            return this->m_pNode->m_Element;                                                                           \
        }                                                                                                              \
        T const *operator->() const                                                                                    \
        {                                                                                                              \
            return &**this;                                                                                            \
        }                                                                                                              \
        bCConstIterator operator++(GEInt)                                                                              \
        {                                                                                                              \
            bCConstIterator _x = *this;                                                                                \
            ++*this;                                                                                                   \
            return _x;                                                                                                 \
        }                                                                                                              \
        bCConstIterator &operator++()                                                                                  \
        {                                                                                                              \
            this->m_pNode = this->m_pNode->m_pNext;                                                                    \
            while (!this->m_pNode && (++this->m_iHash < this->m_parrNodes->GetCount()))                                \
                this->m_pNode = (*this->m_parrNodes)[this->m_iHash];                                                   \
            return *this;                                                                                              \
        }                                                                                                              \
        GEBool operator==(bCConstIterator const &_x) const                                                             \
        {                                                                                                              \
            return (_x.m_parrNodes == this->m_parrNodes) && (_x.m_iHash == this->m_iHash)                              \
                && (_x.m_pNode == this->m_pNode);                                                                      \
        }                                                                                                              \
        GEBool operator!=(bCConstIterator const &_x) const                                                             \
        {                                                                                                              \
            return !(_x == *this);                                                                                     \
        }                                                                                                              \
        bCConstIterator(bTPtrArray<bSNode *> const *_a, GEInt _h, bSNode const *_p)                                    \
            : m_parrNodes(const_cast<bTPtrArray<bSNode *> *>(_a)), m_iHash(_h), m_pNode(const_cast<bSNode *>(_p))      \
        {}                                                                                                             \
        bCConstIterator(bCIterator const &_x) : m_parrNodes(_x.m_parrNodes), m_iHash(_x.m_iHash), m_pNode(_x.m_pNode)  \
        {}                                                                                                             \
        bCConstIterator() : m_parrNodes(0), m_iHash(-1), m_pNode(0)                                                    \
        {}                                                                                                             \
    };                                                                                                                 \
    class bCIterator : public bCConstIterator                                                                          \
    {                                                                                                                  \
      public:                                                                                                          \
        bSNode *GetNode() const                                                                                        \
        {                                                                                                              \
            return this->m_pNode;                                                                                      \
        }                                                                                                              \
        T &operator*() const                                                                                           \
        {                                                                                                              \
            return this->m_pNode->m_Element;                                                                           \
        }                                                                                                              \
        T *operator->() const                                                                                          \
        {                                                                                                              \
            return &**this;                                                                                            \
        }                                                                                                              \
        bCIterator operator++(GEInt)                                                                                   \
        {                                                                                                              \
            bCIterator _x = *this;                                                                                     \
            ++*this;                                                                                                   \
            return _x;                                                                                                 \
        }                                                                                                              \
        bCIterator &operator++()                                                                                       \
        {                                                                                                              \
            this->m_pNode = this->m_pNode->m_pNext;                                                                    \
            while (!this->m_pNode && (++this->m_iHash < this->m_parrNodes->GetCount()))                                \
                this->m_pNode = (*this->m_parrNodes)[this->m_iHash];                                                   \
            return *this;                                                                                              \
        }                                                                                                              \
        GEBool operator==(bCIterator const &_x) const                                                                  \
        {                                                                                                              \
            return (_x.m_parrNodes == this->m_parrNodes) && (_x.m_iHash == this->m_iHash)                              \
                && (_x.m_pNode == this->m_pNode);                                                                      \
        }                                                                                                              \
        GEBool operator!=(bCIterator const &_x) const                                                                  \
        {                                                                                                              \
            return !(_x == *this);                                                                                     \
        }                                                                                                              \
        bCIterator(bTPtrArray<bSNode *> *_a, GEInt _h, bSNode *_p) : bCConstIterator(_a, _h, _p)                       \
        {}                                                                                                             \
        bCIterator()                                                                                                   \
        {}                                                                                                             \
    };                                                                                                                 \
    using bCForwardIterator = bCIterator;                                                                              \
    using bCConstForwardIterator = bCConstIterator;

#define _GE_NODE_TYPE(MAP) typename Genome::remove_reference_t<decltype(MAP)>::bSNode

#define _GE_MLV_EAT(...)
#define _GE_MLV_EXPAND(...) __VA_ARGS__
#define _GE_MLV_CHECK_N(x, n, ...) n
#define _GE_MLV_CHECK(...) _GE_MLV_CHECK_N(__VA_ARGS__, _GE_MLV_EXPAND, )
#define _GE_MLV_WHEN(x, ...) _GE_MLV_CHECK(GE_PASTE_TOKENS(_GE_MLV_WHEN_, x))(__VA_ARGS__)
#define _GE_MLV_WHEN__ x, _GE_MLV_EAT,
#define _GE_MAP_LOCAL_VAR(NAME, VALUE) _GE_MLV_WHEN(NAME, if (auto &NAME = VALUE; GETrue))

#define GE_MAP_FOR_EACH(KEY_NAME, VALUE_NAME, MAP)                                                                     \
    if (auto &__NODES = MAP.GetNodes(); GETrue)                                                                        \
        if (_GE_NODE_TYPE(MAP) *__NODE = 0; GETrue)                                                                    \
            for (GEInt i = 0; i < __NODES.GetCount(); i++)                                                             \
                for (__NODE = __NODES[i]; __NODE != nullptr; __NODE = __NODE->m_pNext)                                 \
                    _GE_MAP_LOCAL_VAR(KEY_NAME, __NODE->m_Key)                                                         \
    _GE_MAP_LOCAL_VAR(VALUE_NAME, __NODE->m_Element)

#define GE_MAP_FOR_EACH_KEY(KEY_NAME, MAP) GE_MAP_FOR_EACH (KEY_NAME, _, MAP)
#define GE_MAP_FOR_EACH_VAL(VALUE_NAME, MAP) GE_MAP_FOR_EACH (_, VALUE_NAME, MAP)

#define GE_MAP_NODES_FOR_HASH(KEY_NAME, VALUE_NAME, HASH, MAP)                                                         \
    if (auto &__NODES = MAP.GetNodes(); GETrue)                                                                        \
        for (_GE_NODE_TYPE(MAP) *__NODE =                                                                              \
                 static_cast<GEInt>(HASH) < __NODES.GetCount() ? __NODES[static_cast<GEInt>(HASH)] : nullptr;          \
             __NODE != nullptr; __NODE = __NODE->m_pNext)                                                              \
            _GE_MAP_LOCAL_VAR(KEY_NAME, __NODE->m_Key)                                                                 \
    _GE_MAP_LOCAL_VAR(VALUE_NAME, __NODE->m_Element)
