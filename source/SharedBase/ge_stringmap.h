#ifndef GE_STRINGMAP_H_INCLUDED
#define GE_STRINGMAP_H_INCLUDED

template<>
GE_DLLIMPORT GEU32 GE_STDCALL g_GetHashValue< GELPChar >( GELPChar const & );
template<>
GE_DLLIMPORT GEU32 GE_STDCALL g_GetHashValue< bCString >( bCString const & );

template< typename T >
class bTStringValMap :
    public bTValMap< bCString, T >
{
};

template< typename T >
class bTStringObjMap :
    public bTObjMap< bCString, T >
{
};

#endif
