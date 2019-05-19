#ifndef GE_OBJARRAYSORT_H_INCLUDED
#define GE_OBJARRAYSORT_H_INCLUDED

template< typename T >
class bTObjArraySort :
    public bTObjArray< T >
{
    protected:
        gFCompare m_fComparator;
        GEBool    m_bSorted;
        GE_PADDING( 3 )

    private: // not defined
        void  Add( T const & _e );
        T &   AddNew( void );
        void  InsertAt( GEInt _i, T const & _e );
        T &   InsertNewAt( GEInt _i );
        void  SetAt( GEInt _i, T const & _e );

    public:
        void  CopyFrom( bTObjArraySort< T > const & _s );
        GEInt InsertSort( T const & _e );
        GEInt Search( T const & _e );
        void  Sort( void );

    public:
        bTObjArraySort< T > & operator = ( bTObjArraySort< T > const & _s );
    public:
                 bTObjArraySort( bTObjArraySort< T > const & _s );
        explicit bTObjArraySort( GEInt _n );
                 bTObjArraySort( void );
                ~bTObjArraySort( void );
};

GE_ASSERT_SIZEOF( bTObjArraySort<GEInt>, 0x14 )

#include "ge_objarraysort.inl"

#endif
