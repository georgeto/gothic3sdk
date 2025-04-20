#include "TypeUtil.h"

#include <g3sdk/util/Util.h>

bCString GetTemplateRawType(bCString const &a_strTypeName)
{
    return a_strTypeName.Left(a_strTypeName.Find("<"));
}

bCString GetTemplateArg(bCString const &a_strTypeName)
{
    GEInt iStartIndex = a_strTypeName.Find('<') + 1;
    return a_strTypeName.Mid(iStartIndex, a_strTypeName.ReverseFind('>') - iStartIndex);
}

bCString UnMangle(bCString const &a_strTypeName)
{
    return bCClassNameBase::UnMangle(a_strTypeName);
}

bCString StripScope(bCString const &a_strTypeName)
{
    if (a_strTypeName.Contains(":"))
        return a_strTypeName.Mid(a_strTypeName.ReverseFind(':') + 1);
    else
        return a_strTypeName;
}

bCString StripPointer(bCString const &a_strTypeName)
{
    bCString Result = a_strTypeName.Left(a_strTypeName.GetLength() - 1);
    Result.TrimRight();
    return Result;
}

GEBool IsArrayType(bCString const &a_strTypeName)
{
    return StartsWith(a_strTypeName, "bTObjArray") || StartsWith(a_strTypeName, "bTPtrArray")
        || StartsWith(a_strTypeName, "bTValArray");
}

GEBool IsSimplePointer(bCString const &a_strTypeName)
{
    return a_strTypeName.Find("*") == a_strTypeName.GetLength() - 1;
}
