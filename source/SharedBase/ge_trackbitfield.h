#ifndef GE_TRACKBITFIELD_H_INCLUDED
#define GE_TRACKBITFIELD_H_INCLUDED

class GE_DLLIMPORT bCTrackBitField
{

    protected:
        static GEU32 const bEBits_All;

    public:
         bCTrackBitField( bCTrackBitField const & );
         bCTrackBitField( GEInt );
        ~bCTrackBitField( void );

    public:
        bCTrackBitField &       operator =   ( bCTrackBitField const & );
        bCOStream &             operator >>  ( bCOStream & ) const;
        bCTrackBitField const & operator >>  ( GEI32 ) const;
        bCIStream &             operator <<  ( bCIStream & );
        bCTrackBitField const & operator <<  ( GEI32 ) const;
        GEBool                  operator ==  ( bCTrackBitField const & ) const;
        GEBool                  operator !=  ( bCTrackBitField const & ) const;
        GEBool                  operator []  ( GEInt ) const;
        bCTrackBitField const & operator &   ( bCTrackBitField const & ) const;
        bCTrackBitField const & operator ~   ( void ) const;
        bCTrackBitField const & operator ^   ( bCTrackBitField const & ) const;
        bCTrackBitField const & operator |   ( bCTrackBitField const & ) const;
        bCTrackBitField &       operator >>= ( GEI32 );
        bCTrackBitField &       operator <<= ( GEI32 );
        bCTrackBitField &       operator &=  ( bCTrackBitField const & );
        bCTrackBitField &       operator |=  ( bCTrackBitField const & );
        bCTrackBitField &       operator ^=  ( bCTrackBitField const & );

    public:
        GEU32 * AccessBitField( void );
        void    And( bCTrackBitField const & );
        void    CopyFrom( bCTrackBitField const & );
        void    CopyTo( bCTrackBitField & ) const;
        void    Disable( GEInt );
        void    DisableAll( void );
        void    Enable( GEInt );
        void    EnableAll( void );
        void    ExpandAnd( bCTrackBitField const & );
        void    ExpandOr( bCTrackBitField const & );
        void    ExpandXor( bCTrackBitField const & );
        GEBool  GetAt( GEInt ) const;
        GEInt   GetCapacity( void ) const;
        GEInt   GetCount( void ) const;
        GEInt   GetCountDisabled( void ) const;
        GEInt   GetCountEnabled( void ) const;
        GEInt   GetFirstDisabled( void ) const;
        GEInt   GetFirstEnabled( void ) const;
        GEInt   GetNextDisabled( void ) const;
        GEInt   GetNextEnabled( void ) const;
        GEInt   GetUpperBound( void ) const;
        void    Invert( void );
        GEBool  IsAnyDisabled( void ) const;
        GEBool  IsAnyEnabled( void ) const;
        GEBool  IsDisabled( GEInt ) const;
        GEBool  IsEmpty( void ) const;
        GEBool  IsEnabled( GEInt ) const;
        GEBool  IsValidIndex( GEInt ) const;
        void    Or( bCTrackBitField const & );
        void    SetAt( GEInt, GEBool );
        void    SetCount( GEInt );
        void    ShiftLeft( GEI32 );
        void    ShiftRight( GEI32 );
        void    Toggle( GEInt );
        void    Xor( bCTrackBitField const & );

    protected:
        GEU32 GetMask( GEInt ) const;
        GEInt GetOffset( GEInt ) const;
        GEInt GetSlotIndex( GEInt ) const;

};

#endif
