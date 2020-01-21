#ifndef GE_SET_H_INCLUDED
#define GE_SET_H_INCLUDED

template< typename T >
class bTSet
{
    public:
        void   Add( T const & _e );
        void   Clear( void );
        GEBool Contains( T const & _e ) const;
        GEInt  GetCount( void ) const;
        void   Init( GEU32 _n );
        GEBool IsEmpty( void ) const;
        GEBool Remove( T const & _e );

        bCOStream & operator >> ( bCOStream & _os ) const;
        bCIStream & operator << ( bCIStream & _is );

    protected:
        bTValMap<T, GEInt> m_Map;
};

#include "ge_set.inl"

#endif
