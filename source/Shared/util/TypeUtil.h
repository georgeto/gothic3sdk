#ifndef TYPE_UTIL_H_INCLUDED
#define TYPE_UTIL_H_INCLUDED

#include "Game.h"

bCString GetTemplateRawType( bCString const & a_strTypeName );
bCString GetTemplateArg( bCString const & a_strTypeName );
bCString UnMangle( bCString const & a_strTypeName );
bCString StripScope( bCString const & a_strTypeName );
bCString StripPointer( bCString const & a_strTypeName );

GEBool IsArrayType( bCString const & a_strTypeName );
GEBool IsSimplePointer( bCString const & a_strTypeName );

#endif