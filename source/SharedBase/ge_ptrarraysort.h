#ifndef GE_PTRARRAYSORT_H_INCLUDED
#define GE_PTRARRAYSORT_H_INCLUDED

template< typename T >
class bTPtrArraySort :
    public bTPtrArray< T >
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
        void  CopyFrom( bTPtrArraySort< T > const & _s );
        GEInt InsertSort( T const & _e );
        GEInt Search( T const & _e );
        void  Sort( void );

    public:
        bTPtrArraySort< T > & operator = ( bTPtrArraySort< T > const & _s );
    public:
                 bTPtrArraySort( bTPtrArraySort< T > const & _s );
        explicit bTPtrArraySort( GEInt _n );
                 bTPtrArraySort( void );
                ~bTPtrArraySort( void );
};

GE_ASSERT_SIZEOF( bTPtrArraySort<GEInt>, 0x14 )

#include "ge_ptrarraysort.inl"

#endif
