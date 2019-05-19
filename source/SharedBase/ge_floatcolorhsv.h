#ifndef GE_FLOATCOLORHSV_H_INCLUDED
#define GE_FLOATCOLORHSV_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )// class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT bCFloatColorHSV :
    public bCColorBase
{
    public: virtual void        Clear( void );
    public: virtual bCIStream & operator << ( bCIStream & );
    public: virtual bCOStream & operator >> ( bCOStream & ) const;

    public:
         bCFloatColorHSV( bCFloatColorHSV const & );
         bCFloatColorHSV( bCByteAlphaColor const & );
         bCFloatColorHSV( bCByteColor const & );
         bCFloatColorHSV( bCFloatAlphaColor const & );
         bCFloatColorHSV( bCFloatColor const & );
         bCFloatColorHSV( void );
        ~bCFloatColorHSV( void );

    public:
        bCFloatColorHSV & operator =  ( bCFloatColorHSV const & );
        GEBool            operator == ( bCFloatColorHSV const & ) const;
        GEBool            operator != ( bCFloatColorHSV const & ) const;
        bCFloatColorHSV   operator *  ( bCFloatColorHSV const & ) const;
        bCFloatColorHSV   operator *  ( GEFloat ) const;
        bCFloatColorHSV   operator -  ( bCFloatColorHSV const & ) const;
        bCFloatColorHSV   operator -  ( void ) const;
        bCFloatColorHSV   operator +  ( bCFloatColorHSV const & ) const;
        bCFloatColorHSV   operator /  ( GEFloat ) const;
        bCFloatColorHSV   operator ~  ( void ) const;
        bCFloatColorHSV & operator *= ( bCFloatColorHSV const & );
        bCFloatColorHSV & operator *= ( GEFloat );
        bCFloatColorHSV & operator += ( bCFloatColorHSV const & );
        bCFloatColorHSV & operator -= ( bCFloatColorHSV const & );
        bCFloatColorHSV & operator /= ( GEFloat );

    public:
                        bCFloatColorHSV( GEFloat, GEFloat, GEFloat );
                        bCFloatColorHSV( bCColorBase::bEColor );
        GEFloat &       AccessHue( void );
        GEFloat &       AccessSaturation( void );
        void            Add( bCFloatColorHSV const & );
        void            AddClamped( bCFloatColorHSV const & );
        void            Clamp( void );
        bCFloatColorHSV GetClamped( void ) const;
        void            GetClamped( bCFloatColorHSV & ) const;
        bCFloatColorHSV GetDifference( bCFloatColorHSV const & ) const;
        void            GetDifference( bCFloatColorHSV &, bCFloatColorHSV const & ) const;
        GEFloat         GetHue( void ) const;
        void            GetHue( GEFloat & ) const;
        bCFloatColorHSV GetInverted( void ) const;
        void            GetInverted( bCFloatColorHSV & ) const;
        bCFloatColorHSV GetProduct( bCFloatColorHSV const & ) const;
        bCFloatColorHSV GetProduct( GEFloat ) const;
        void            GetProduct( bCFloatColorHSV &, bCFloatColorHSV const & ) const;
        void            GetProduct( bCFloatColorHSV &, GEFloat ) const;
        GEFloat         GetSaturation( void ) const;
        void            GetSaturation( GEFloat & ) const;
        bCFloatColorHSV GetSum( bCFloatColorHSV const & ) const;
        void            GetSum( bCFloatColorHSV &, bCFloatColorHSV const & ) const;
        GEFloat &       GetValue( void );
        GEFloat         GetValue( void ) const;
        void            GetValue( GEFloat & ) const;
        void            Invert( void );
        GEBool          IsEqual( bCFloatColorHSV const & ) const;
        void            Multiply( bCFloatColorHSV const & );
        void            Multiply( GEFloat );
        void            SetColor( bCFloatColorHSV const & );
        void            SetColor( bCByteAlphaColor const & );
        void            SetColor( bCByteColor const & );
        void            SetColor( bCFloatAlphaColor const & );
        void            SetColor( bCFloatColor const & );
        void            SetColor( GEFloat, GEFloat, GEFloat );
        void            SetHue( GEFloat );
        void            SetSaturation( GEFloat );
        void            SetValue( GEFloat );
        void            Sub( bCFloatColorHSV const & );
        void            SubClamped( bCFloatColorHSV const & );

};

#pragma warning( pop )

#endif
