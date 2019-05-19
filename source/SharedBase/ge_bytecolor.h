#ifndef GE_BYTECOLOR_H_INCLUDED
#define GE_BYTECOLOR_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )// class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT bCByteColor :
    public bCColorBase
{
    public: virtual void        Clear( void );
    public: virtual bCIStream & operator << ( bCIStream & );
    public: virtual bCOStream & operator >> ( bCOStream & ) const;

    private:
        GEU8 m_u8Red;
        GEU8 m_u8Green;
        GEU8 m_u8Blue;
        GE_PADDING( 1 )

    public:
         bCByteColor( bCByteColor const & );
         bCByteColor( bCByteAlphaColor const & );
         bCByteColor( bCFloatAlphaColor const & );
         bCByteColor( bCFloatColor const & );
         bCByteColor( bCFloatColorHSV const & );
         bCByteColor( void );
        ~bCByteColor( void );

    public:
        bCByteColor & operator =  ( bCByteColor const & );
        GEBool        operator == ( bCByteColor const & ) const;
        GEBool        operator != ( bCByteColor const & ) const;
        bCByteColor   operator *  ( bCByteColor const & ) const;
        bCByteColor   operator *  ( GEU8 ) const;
        bCByteColor   operator -  ( bCByteColor const & ) const;
        bCByteColor   operator -  ( void ) const;
        bCByteColor   operator +  ( bCByteColor const & ) const;
        bCByteColor   operator /  ( GEU8 ) const;
        bCByteColor   operator ~  ( void ) const;
        bCByteColor & operator *= ( bCByteColor const & );
        bCByteColor & operator *= ( GEU8 );
        bCByteColor & operator += ( bCByteColor const & );
        bCByteColor & operator -= ( bCByteColor const & );
        bCByteColor & operator /= ( GEU8 );

    public:
                    bCByteColor( GEU8, GEU8, GEU8 );
                    bCByteColor( bCColorBase::bEColor );
        GEU8 &      AccessBlue( void );
        GEU8 &      AccessGreen( void );
        GEU8 &      AccessRed( void );
        void        Add( bCByteColor const & );
        void        AddClamped( bCByteColor const & );
        void        Clamp( void );
        GEU8        GetBlue( void ) const;
        void        GetBlue( GEU8 & ) const;
        bCByteColor GetClamped( void ) const;
        void        GetClamped( bCByteColor & ) const;
        GEU16       GetColor_RGB_555( void ) const;
        void        GetColor_RGB_555( GEU16 & ) const;
        GEU16       GetColor_RGB_565( void ) const;
        void        GetColor_RGB_565( GEU16 & ) const;
        bCByteColor GetDifference( bCByteColor const & ) const;
        void        GetDifference( bCByteColor &, bCByteColor const & ) const;
        GEU8        GetGreen( void ) const;
        void        GetGreen( GEU8 & ) const;
        bCByteColor GetInverted( void ) const;
        void        GetInverted( bCByteColor & ) const;
        bCByteColor GetProduct( bCByteColor const & ) const;
        bCByteColor GetProduct( GEU8 ) const;
        void        GetProduct( bCByteColor &, bCByteColor const & ) const;
        void        GetProduct( bCByteColor &, GEU8 ) const;
        GEU8        GetRed( void ) const;
        void        GetRed( GEU8 & ) const;
        bCByteColor GetSum( bCByteColor const & ) const;
        void        GetSum( bCByteColor &, bCByteColor const & ) const;
        void        Invert( void );
        GEBool      IsEqual( bCByteColor const & ) const;
        void        Multiply( bCByteColor const & );
        void        Multiply( GEU8 );
        void        SetBlend( bCByteColor const &, bCByteColor const &, GEInt, GEInt );
        void        SetBlue( GEU8 );
        void        SetColor( bCByteColor const & );
        void        SetColor( bCByteAlphaColor const & );
        void        SetColor( bCFloatAlphaColor const & );
        void        SetColor( bCFloatColor const & );
        void        SetColor( bCFloatColorHSV const & );
        void        SetColor( GEU8, GEU8, GEU8 );
        void        SetColor_RGB_555( GEU16 );
        void        SetColor_RGB_565( GEU16 );
        void        SetGreen( GEU8 );
        void        SetRed( GEU8 );
        void        Sub( bCByteColor const & );
        void        SubClamped( bCByteColor const & );

};

#pragma warning( pop )

#endif
