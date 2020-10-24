#ifndef PROPERTY_COMPARE_H_INCLUDED
#define PROPERTY_COMPARE_H_INCLUDED

#include "SharedBase.h"
#include "Logging.h"

enum mEPropertyCompareOperator
{
    mEPropertyCompareOperator_Equals,
    mEPropertyCompareOperator_NotEquals,
    mEPropertyCompareOperator_GreaterThan,
    mEPropertyCompareOperator_LessThan,
    mEPropertyCompareOperator_EqualsIgnoreCase,
    mEPropertyCompareOperator_Contains,
    mEPropertyCompareOperator_IsContained,
    mEPropertyCompareOperator_BitwiseAnd,
    mEPropertyCompareOperator_BitwiseAndEquals,
};

class mCPropertyComparator
{
    public:
        static mCPropertyComparator * FindComparator(bCPropertyTypeBase * a_Property, mEPropertyCompareOperator a_Operator);

        GEBool Compare(bCPropertyTypeBase * a_Property, bCPropertyObjectBase const * a_pObject1, bCPropertyObjectBase const * a_pObject2) const;

    protected:
        virtual GEBool Compare(GELPCVoid a_pValue1, GELPCVoid a_pValue2) const = 0;
};

#endif