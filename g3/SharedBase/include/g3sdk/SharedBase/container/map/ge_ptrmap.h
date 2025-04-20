#pragma once

#include "ge_valmap.h"

template <typename K, typename T>
class bTPtrMap : public bTValMap<K, T>
{
    GE_DECLARE_MAP_ITERATORS()
};
