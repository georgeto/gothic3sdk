#ifndef GE_CLASSNAMEBASE_H_INCLUDED
#define GE_CLASSNAMEBASE_H_INCLUDED

class GE_DLLIMPORT bCClassNameBase
{

    public:
        static bCString GE_STDCALL UnMangle( GELPCChar );

    public:
        bCClassNameBase & operator = ( bCClassNameBase const & );

};

template< typename T >
class bTClassName
{
    public:
        static bCString const & GetUnmangled( void );

    private:
        bTClassName( void );
};

#include "ge_classnamebase.inl"

#endif
