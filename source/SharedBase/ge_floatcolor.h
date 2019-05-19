#ifndef GE_FLOATCOLOR_H_INCLUDED
#define GE_FLOATCOLOR_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )// class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT bCFloatColor :
    public bCColorBase
{
    public: virtual void        Clear( void );
    public: virtual bCIStream & operator << ( bCIStream & );
    public: virtual bCOStream & operator >> ( bCOStream & ) const;

    private:
        GEFloat m_fRed;
        GEFloat m_fGreen;
        GEFloat m_fBlue;

    public:
         bCFloatColor( GEFloat, GEFloat, GEFloat );
         bCFloatColor( bCColorBase::bEColor );
         bCFloatColor( bCFloatColor const & );
         bCFloatColor( bCByteAlphaColor const & );
         bCFloatColor( bCByteColor const & );
         bCFloatColor( bCFloatAlphaColor const & );
         bCFloatColor( bCFloatColorHSV const & );
         bCFloatColor( void );
        ~bCFloatColor( void );

    public:
        bCFloatColor & operator =  ( bCFloatColor const & );
        GEBool         operator == ( bCFloatColor const & ) const;
        GEBool         operator != ( bCFloatColor const & ) const;
        bCFloatColor   operator *  ( bCFloatColor const & ) const;
        bCFloatColor   operator *  ( GEFloat ) const;
        bCFloatColor   operator -  ( bCFloatColor const & ) const;
        bCFloatColor   operator -  ( void ) const;
        bCFloatColor   operator +  ( bCFloatColor const & ) const;
        bCFloatColor   operator /  ( GEFloat ) const;
        bCFloatColor   operator ~  ( void ) const;
        bCFloatColor & operator *= ( bCFloatColor const & );
        bCFloatColor & operator *= ( GEFloat );
        bCFloatColor & operator += ( bCFloatColor const & );
        bCFloatColor & operator -= ( bCFloatColor const & );
        bCFloatColor & operator /= ( GEFloat );

    public:
        GEFloat &    AccessBlue( void );
        GEFloat &    AccessGreen( void );
        GEFloat &    AccessRed( void );
        void         Add( bCFloatColor const & );
        void         AddClamped( bCFloatColor const & );
        void         Clamp( void );
        GEFloat      GetBlue( void ) const;
        void         GetBlue( GEFloat & ) const;
        bCFloatColor GetClamped( void ) const;
        void         GetClamped( bCFloatColor & ) const;
        bCFloatColor GetDifference( bCFloatColor const & ) const;
        void         GetDifference( bCFloatColor &, bCFloatColor const & ) const;
        GEFloat      GetGreen( void ) const;
        void         GetGreen( GEFloat & ) const;
        bCFloatColor GetInverted( void ) const;
        void         GetInverted( bCFloatColor & ) const;
        bCFloatColor GetNormalized( void ) const;
        void         GetNormalized( bCFloatColor & ) const;
        bCFloatColor GetProduct( bCFloatColor const & ) const;
        bCFloatColor GetProduct( GEFloat ) const;
        void         GetProduct( bCFloatColor &, bCFloatColor const & ) const;
        void         GetProduct( bCFloatColor &, GEFloat ) const;
        GEFloat      GetRed( void ) const;
        void         GetRed( GEFloat & ) const;
        bCFloatColor GetSum( bCFloatColor const & ) const;
        void         GetSum( bCFloatColor &, bCFloatColor const & ) const;
        void         Invert( void );
        GEBool       IsEqual( bCFloatColor const & ) const;
        void         Multiply( bCFloatColor const & );
        void         Multiply( GEFloat );
        void         Normalize( void );
        void         SetBlue( GEFloat );
        void         SetColor( bCFloatColor const & );
        void         SetColor( bCByteAlphaColor const & );
        void         SetColor( bCByteColor const & );
        void         SetColor( bCFloatAlphaColor const & );
        void         SetColor( bCFloatColorHSV const & );
        void         SetColor( GEFloat, GEFloat, GEFloat );
        void         SetGreen( GEFloat );
        void         SetRed( GEFloat );
        void         Sub( bCFloatColor const & );
        void         SubClamped( bCFloatColor const & );

};

#pragma warning( pop )

#endif
