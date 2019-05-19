#ifndef GE_SMALLARRAY_H_INCLUDED
#define GE_SMALLARRAY_H_INCLUDED

template< typename T >
class bTSmallArray
{
    public:
        enum bEIndex
        {
            bEIndex_Invalid = 0xFFFFFFFFL
        };
    protected:
        GEU16 m_u16Capacity;
        GEU16 m_u16Count;
        T *   m_pArray;
    protected:
        static void GE_STDCALL Copy( T * _d, T const * _s, GEU16 _n );
        static void GE_STDCALL Move( T * _d, T const * _s, GEU16 _n );
    protected:
        void Init( void );
    public:
        T *       AccessArray( void );
        T &       AccessAt( GEU16 _i );
        void      Add( T const & _e );
        T &       AddNew( void );
        void      Clear( void );
        void      CopyFrom( bTSmallArray< T > const & _s );
        void      CopyTo( bTSmallArray< T > & _d ) const;
        T const * GetArray( void ) const;
        T const & GetAt( GEU16 _i ) const;
        void      GetAt( GEU16 _i, T & _e ) const;
        GEU16     GetCapacity( void ) const;
        GEU16     GetCount( void ) const;
        GEU16     IndexOf( T const & _e ) const;
        void      InsertAt( GEU16 _i, T const & _e );
        T &       InsertNewAt( GEU16 _i );
        GEBool    IsEmpty( void ) const;
        void      Remove( T const & _e );
        void      RemoveAll( void );
        void      RemoveAt( GEU16 _i );
        void      Reserve( GEU16 _n );
        void      SetAt( GEU16 _i, T const & _e );
        void      SetCount( GEU16 _n );
    public:
        T &       operator [] ( GEU16 _i );
        T const & operator [] ( GEU16 _i ) const;
    public:
        bTSmallArray< T > & operator = ( bTSmallArray< T > const & _s );
    public:
                 bTSmallArray( bTSmallArray< T > const & _s );
        explicit bTSmallArray( GEU16 _n );
                 bTSmallArray( void );
                ~bTSmallArray( void );
};

#include "ge_smallarray.inl"

GE_ASSERT_SIZEOF(bTSmallArray<GEInt>, 0x08);

#endif
