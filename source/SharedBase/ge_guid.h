#ifndef GE_GUID_H_INCLUDED
#define GE_GUID_H_INCLUDED

class GE_DLLIMPORT bCGuid
{
    private:
        _GUID  mGuid;
        GEBool mValid;
        GE_PADDING( 3 )

    public:
        static bCGuid const & GE_STDCALL GetInvalidGuid( void );
        static bCGuid const & GE_STDCALL GetNullGuid( void );

    public:
         bCGuid( _GUID const & );
         bCGuid( bCGuid const & );
         bCGuid( bCString const & );
         bCGuid( _GUID const * );
         bCGuid( void );
        ~bCGuid( void );

    public:
        bCGuid & operator =             ( _GUID const & );
        bCGuid & operator =             ( bCGuid const & );
        bCGuid & operator =             ( bCString const & );
        bCGuid & operator =             ( _GUID const * );
        GEBool   operator ==            ( bCGuid const & ) const;
        GEBool   operator !=            ( bCGuid const & ) const;
                 operator _GUID &       ( void );
                 operator _GUID *       ( void );
                 operator _GUID const & ( void ) const;
                 operator _GUID const * ( void ) const;
        GEBool   operator <             ( bCGuid const & ) const;
        GEBool   operator <=            ( bCGuid const & ) const;
        GEBool   operator >             ( bCGuid const & ) const;
        GEBool   operator >=            ( bCGuid const & ) const;

    public:
        void          CopyFrom( bCGuid const & );
        void          CopyTo( bCGuid & ) const;
        void          Generate( void );
        _GUID *       GetGuid( void );
        _GUID const * GetGuid( void ) const;
        bCString      GetText( void ) const;
        GEBool        IsNull( void ) const;
        GEBool        IsValid( void ) const;
        void          MakeInvalidGuid( void );
        void          MakeNullGuid( void );
        void          SetGuid( _GUID const & );
        void          SetGuid( bCString const & );
        void          SetGuid( _GUID const * );
        GEBool        SetText( bCString const & );

    protected:
        void   Clear( void );
        GEInt  Compare( bCGuid const & ) const;
        void   Init( void );
        GEBool IsEqualTo( bCGuid const & ) const;
        GEBool IsGreaterThan( bCGuid const & ) const;
        GEBool IsLessThan( bCGuid const & ) const;

};

GE_ASSERT_SIZEOF( bCGuid, 20 );

template<>
GE_DLLIMPORT GEU32 GE_STDCALL g_GetHashValue< bCGuid >( bCGuid const & );

#endif
