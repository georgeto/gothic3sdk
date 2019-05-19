#ifndef GE_FLOATALPHACOLOR_H_INCLUDED
#define GE_FLOATALPHACOLOR_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )// class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT bCFloatAlphaColor :
    public bCFloatColor
{
    public: virtual void        Clear( void );
    public: virtual bCIStream & operator << ( bCIStream & );
    public: virtual bCOStream & operator >> ( bCOStream & ) const;

    private:
        GEFloat m_fAlpha;

    public:
         bCFloatAlphaColor( bCByteColor const &, GEFloat );
         bCFloatAlphaColor( bCFloatColor const &, GEFloat );
         bCFloatAlphaColor( bCFloatColorHSV const &, GEFloat );
         bCFloatAlphaColor( GEFloat, GEFloat, GEFloat, GEFloat );
         bCFloatAlphaColor( bCColorBase::bEColor );
         bCFloatAlphaColor( bCFloatAlphaColor const & );
         bCFloatAlphaColor( bCByteAlphaColor const & );
         bCFloatAlphaColor( bCVector4 const & );
         bCFloatAlphaColor( void );
        ~bCFloatAlphaColor( void );

    public:
        bCFloatAlphaColor & operator =  ( bCFloatAlphaColor const & );
        GEBool              operator == ( bCFloatAlphaColor const & ) const;
        GEBool              operator != ( bCFloatAlphaColor const & ) const;
        bCFloatAlphaColor   operator *  ( bCFloatAlphaColor const & ) const;
        bCFloatAlphaColor   operator *  ( GEFloat ) const;
        bCFloatAlphaColor   operator -  ( bCFloatAlphaColor const & ) const;
        bCFloatAlphaColor   operator -  ( void ) const;
        bCFloatAlphaColor   operator +  ( bCFloatAlphaColor const & ) const;
        bCFloatAlphaColor   operator /  ( GEFloat ) const;
        bCFloatAlphaColor   operator ~  ( void ) const;
        bCFloatAlphaColor & operator *= ( bCFloatAlphaColor const & );
        bCFloatAlphaColor & operator *= ( GEFloat );
        bCFloatAlphaColor & operator += ( bCFloatAlphaColor const & );
        bCFloatAlphaColor & operator -= ( bCFloatAlphaColor const & );
        bCFloatAlphaColor & operator /= ( GEFloat );

    public:
        GEFloat &         AccessAlpha( void );
        void              Add( bCFloatAlphaColor const & );
        void              AddClamped( bCFloatAlphaColor const & );
        void              Clamp( void );
        GEFloat           GetAlpha( void ) const;
        void              GetAlpha( GEFloat & ) const;
        bCFloatAlphaColor GetClamped( void ) const;
        void              GetClamped( bCFloatAlphaColor & ) const;
        bCFloatAlphaColor GetDifference( bCFloatAlphaColor const & ) const;
        void              GetDifference( bCFloatAlphaColor &, bCFloatAlphaColor const & ) const;
        bCFloatAlphaColor GetInverted( void ) const;
        void              GetInverted( bCFloatAlphaColor & ) const;
        bCFloatAlphaColor GetNormalized( void ) const;
        void              GetNormalized( bCFloatAlphaColor & ) const;
        bCFloatAlphaColor GetProduct( bCFloatAlphaColor const & ) const;
        bCFloatAlphaColor GetProduct( GEFloat ) const;
        void              GetProduct( bCFloatAlphaColor &, bCFloatAlphaColor const & ) const;
        void              GetProduct( bCFloatAlphaColor &, GEFloat ) const;
        bCFloatAlphaColor GetSum( bCFloatAlphaColor const & ) const;
        void              GetSum( bCFloatAlphaColor &, bCFloatAlphaColor const & ) const;
        void              Invert( void );
        GEBool            IsEqual( bCFloatAlphaColor const & ) const;
        void              Multiply( bCFloatAlphaColor const & );
        void              Multiply( GEFloat );
        void              Normalize( void );
        void              SetAlpha( GEFloat );
        void              SetColor( bCFloatAlphaColor const & );
        void              SetColor( bCByteAlphaColor const & );
        void              SetColor( bCByteColor const &, GEFloat );
        void              SetColor( bCFloatColor const &, GEFloat );
        void              SetColor( bCFloatColorHSV const &, GEFloat );
        void              SetColor( bCVector4 const & );
        void              SetColor( GEFloat, GEFloat, GEFloat, GEFloat );
        void              Sub( bCFloatAlphaColor const & );
        void              SubClamped( bCFloatAlphaColor const & );

};

#pragma warning( pop )

#endif
