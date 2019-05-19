#ifndef GE_BITFIELD_H_INCLUDED
#define GE_BITFIELD_H_INCLUDED

class GE_DLLIMPORT bCBitField
{

    protected:
        static GEU32 const bEBits_All;

    public:
         bCBitField( bCBitField const & );
         bCBitField( GEInt );
        ~bCBitField( void );

    public:
        bCBitField &       operator =   ( bCBitField const & );
        bCOStream &        operator >>  ( bCOStream & ) const;
        bCBitField const & operator >>  ( GEI32 ) const;
        bCIStream &        operator <<  ( bCIStream & );
        bCBitField const & operator <<  ( GEI32 ) const;
        GEBool             operator ==  ( bCBitField const & ) const;
        GEBool             operator !=  ( bCBitField const & ) const;
        GEBool             operator []  ( GEInt ) const;
        bCBitField const & operator &   ( bCBitField const & ) const;
        bCBitField const & operator ~   ( void ) const;
        bCBitField const & operator ^   ( bCBitField const & ) const;
        bCBitField const & operator |   ( bCBitField const & ) const;
        bCBitField &       operator >>= ( GEI32 );
        bCBitField &       operator <<= ( GEI32 );
        bCBitField &       operator &=  ( bCBitField const & );
        bCBitField &       operator |=  ( bCBitField const & );
        bCBitField &       operator ^=  ( bCBitField const & );

    public:
        GEU32 * AccessBitField( void );
        void    And( bCBitField const & );
        void    CopyFrom( bCBitField const & );
        void    CopyTo( bCBitField & ) const;
        void    Disable( GEInt );
        void    DisableAll( void );
        void    Enable( GEInt );
        void    EnableAll( void );
        void    ExpandAnd( bCBitField const & );
        void    ExpandOr( bCBitField const & );
        void    ExpandXor( bCBitField const & );
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
        void    Or( bCBitField const & );
        void    SetAt( GEInt, GEBool );
        void    SetCount( GEInt );
        void    ShiftLeft( GEI32 );
        void    ShiftRight( GEI32 );
        void    Toggle( GEInt );
        void    Xor( bCBitField const & );

    protected:
        GEU32 GetMask( GEInt ) const;
        GEInt GetOffset( GEInt ) const;
        GEInt GetSlotIndex( GEInt ) const;

};

#endif
