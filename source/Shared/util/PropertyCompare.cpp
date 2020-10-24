#include "PropertyCompare.h"

namespace
{
    template<typename T, mEPropertyCompareOperator Op>
    class mTPropertyComparator
        : public mCPropertyComparator
    {
        public:
            virtual GEBool Compare(GELPCVoid a_pValue1, GELPCVoid a_pValue2) const
            {
                return CompareTyped(*static_cast<T const *>(a_pValue1), *static_cast<T const *>(a_pValue2));
            }

            GEBool CompareTyped(T const & a_pValue1, T const & a_pValue2) const;
    };

    static bTObjMap<bCString, bTPtrMap<mEPropertyCompareOperator, mCPropertyComparator *>> s_Comparators;

    #define SPECIALIZE_COMPARATOR( TYPE, OP, EXP )                                          \
    template<>                                                                              \
    GEBool mTPropertyComparator<TYPE, OP>::CompareTyped(TYPE const & a_pValue1, TYPE const & a_pValue2) const \
    {                                                                                       \
        return EXP;                                                                         \
    }                                                                                       \
    GE_STATIC_BLOCK { s_Comparators[bTClassName<TYPE>::GetUnmangled()].SetAt(OP, GE_NEW((mTPropertyComparator<TYPE, OP>))); }

    #define SPECIALIZE_COMPARATOR_EQUALS( TYPE ) \
        SPECIALIZE_COMPARATOR(TYPE, mEPropertyCompareOperator_Equals, a_pValue1 == a_pValue2) \
        SPECIALIZE_COMPARATOR(TYPE, mEPropertyCompareOperator_NotEquals, a_pValue1 != a_pValue2)

    #define SPECIALIZE_COMPARATOR_NUMERIC( TYPE ) \
        SPECIALIZE_COMPARATOR_EQUALS(TYPE) \
        SPECIALIZE_COMPARATOR(TYPE, mEPropertyCompareOperator_GreaterThan, a_pValue1 > a_pValue2) \
        SPECIALIZE_COMPARATOR(TYPE, mEPropertyCompareOperator_LessThan, a_pValue1 < a_pValue2)

    #define SPECIALIZE_COMPARATOR_INT( TYPE ) \
        SPECIALIZE_COMPARATOR_NUMERIC(TYPE) \
        SPECIALIZE_COMPARATOR(TYPE, mEPropertyCompareOperator_BitwiseAnd, (a_pValue1 & a_pValue2) != 0) \
        SPECIALIZE_COMPARATOR(TYPE, mEPropertyCompareOperator_BitwiseAndEquals, (a_pValue1 & a_pValue2) == a_pValue2)

    SPECIALIZE_COMPARATOR_EQUALS(bCString)
    SPECIALIZE_COMPARATOR(bCString, mEPropertyCompareOperator_EqualsIgnoreCase, a_pValue1.CompareNoCaseFast(a_pValue2))
    SPECIALIZE_COMPARATOR(bCString, mEPropertyCompareOperator_Contains, a_pValue1.Contains(a_pValue2))
    SPECIALIZE_COMPARATOR(bCString, mEPropertyCompareOperator_IsContained, a_pValue2.Contains(a_pValue1))
    SPECIALIZE_COMPARATOR_INT(GEInt)
    SPECIALIZE_COMPARATOR_INT(GEI8)
    SPECIALIZE_COMPARATOR_INT(GEI16)
    SPECIALIZE_COMPARATOR_INT(GEI32)
    SPECIALIZE_COMPARATOR_INT(GEI64)
    SPECIALIZE_COMPARATOR_INT(GEUInt)
    SPECIALIZE_COMPARATOR_INT(GEU8)
    SPECIALIZE_COMPARATOR_INT(GEU16)
    SPECIALIZE_COMPARATOR_INT(GEU32)
    SPECIALIZE_COMPARATOR_INT(GEU64)
    SPECIALIZE_COMPARATOR_NUMERIC(GEBool)
    SPECIALIZE_COMPARATOR_NUMERIC(GEFloat)
    SPECIALIZE_COMPARATOR_NUMERIC(GEDouble)
    SPECIALIZE_COMPARATOR_EQUALS(bTPropertyContainer<GEU32>) // Dummy for all property containers
}

mCPropertyComparator * mCPropertyComparator::FindComparator(bCPropertyTypeBase * a_Property, mEPropertyCompareOperator a_Operator)
{
    bCString ClassName = a_Property->GetPropertyClassName();
    if(a_Property->GetPropertyType() == bEPropertyType_PropertyContainer)
        ClassName = bTClassName<bTPropertyContainer<GEU32>>::GetUnmangled();  // Dummy for all property containers

    if(s_Comparators.IsValidKey(ClassName) && s_Comparators[ClassName].IsValidKey(a_Operator))
        return s_Comparators[ClassName][a_Operator];
    else
        return nullptr;
}

GEBool mCPropertyComparator::Compare(bCPropertyTypeBase * a_Property, bCPropertyObjectBase const * a_pObject1, bCPropertyObjectBase const * a_pObject2) const
{
    return Compare(a_Property->PropertyGet(a_pObject1), a_Property->PropertyGet(a_pObject2));
};
