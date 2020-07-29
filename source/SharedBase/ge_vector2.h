#ifndef GE_VECTOR2_H_INCLUDED
#define GE_VECTOR2_H_INCLUDED

class GE_DLLIMPORT bCVector2
{

    public:
        static bCVector2 GE_STDCALL CrossProduct( bCVector2 const &, bCVector2 const & );
        static GEFloat GE_STDCALL   DotProduct( bCVector2 const &, bCVector2 const & );

    public:
         bCVector2( bCVector2 const & );
         bCVector2( GEFloat );
         bCVector2( GEFloat const * const );
         bCVector2( void );
        ~bCVector2( void );

    public:
        bCVector2 &     operator =  ( bCVector2 const & );
        bCOStream &     operator >> ( bCOStream & ) const;
        bCIStream &     operator << ( bCIStream & );
        GEBool          operator == ( bCVector2 const & ) const;
        GEBool          operator != ( bCVector2 const & ) const;
        GEFloat &       operator [] ( GEInt );
        GEFloat const & operator [] ( GEInt ) const;
        bCVector2       operator *  ( GEFloat ) const;
        bCVector2       operator -  ( bCVector2 const & ) const;
        bCVector2       operator -  ( void ) const;
        bCVector2       operator +  ( bCVector2 const & ) const;
        bCVector2       operator /  ( GEFloat ) const;
        bCVector2 &     operator *= ( bCMatrix2 const & );
        bCVector2 &     operator *= ( GEFloat );
        bCVector2 &     operator += ( bCVector2 const & );
        bCVector2 &     operator -= ( bCVector2 const & );
        bCVector2 &     operator /= ( bCMatrix2 const & );
        bCVector2 &     operator /= ( GEFloat );

    public:
                  bCVector2( GEFloat, GEFloat );
        GEFloat & AccessCoordinate( GEInt );
        GEFloat ( &AccessCoordinates( void ))[2];
        GEFloat &       AccessX( void );
        GEFloat &       AccessY( void );
        void            Clear( void );
        void            CrossProduct( bCVector2 const & );
        GEFloat const & GetCoordinate( GEInt ) const;
        void            GetCoordinate( GEInt, GEFloat & ) const;
        GEFloat const (&GetCoordinates( void ) const )[2];
        void              GetCoordinates( GEFloat &, GEFloat & ) const;
        void              GetCoordinates( GEFloat * const ) const;
        bCVector2         GetCrossProduct( bCVector2 const & ) const;
        GEFloat           GetDotProduct( bCVector2 const & ) const;
        bCVector2         GetInvScaled( bCVector2 const & ) const;
        bCVector2         GetInvScaled( GEFloat ) const;
        bCVector2         GetInvTransformed( bCMatrix2 const & ) const;
        bCVector2         GetInvTranslated( bCVector2 const & ) const;
        bCVector2         GetInvTranslated( GEFloat ) const;
        bCVector2         GetInverted( void ) const;
        GEFloat           GetMagnitude( void ) const;
        GEFloat           GetMagnitudeApprox( void ) const;
        GEFloat           GetMagnitudeNormalize( void );
        bCVector2         GetNormalized( void ) const;
        bCVector2         GetScaled( bCVector2 const & ) const;
        bCVector2         GetScaled( GEFloat ) const;
        GEFloat           GetSquareMagnitude( void ) const;
        bCVector2         GetTransformed( bCMatrix2 const & ) const;
        bCVector2         GetTranslated( bCVector2 const & ) const;
        bCVector2         GetTranslated( GEFloat ) const;
        GEFloat           GetX( void ) const;
        void              GetX( GEFloat & ) const;
        GEFloat           GetY( void ) const;
        void              GetY( GEFloat & ) const;
        void              InvScale( bCVector2 const & );
        void              InvScale( GEFloat );
        void              InvTransform( bCMatrix2 const & );
        void              InvTranslate( bCVector2 const & );
        void              InvTranslate( GEFloat );
        void              Invert( void );
        GEBool            IsEqual( bCVector2 const & ) const;
        bCVector2 const & Normalize( void );
        bCVector2 const & NormalizeApprox( void );
        bCVector2 const & NormalizeSafe( void );
        void              Scale( bCVector2 const & );
        void              Scale( GEFloat );
        void              SetCoordinate( GEInt, GEFloat );
        void              SetCoordinates( GEFloat, GEFloat );
        void              SetCoordinates( GEFloat const * const );
        void              SetCrossProduct( bCVector2 const &, bCVector2 const & );
        void              SetTransformed( bCVector2 const &, bCMatrix2 const & );
        void              SetTransposedTransformed( bCVector2 const &, bCMatrix2 const & );
        void              SetVector( bCVector2 const & );
        void              SetVector( GEFloat );
        void              SetVector( GEFloat, GEFloat );
        void              SetX( GEFloat const & );
        void              SetY( GEFloat const & );
        void              Transform( bCMatrix2 const & );
        void              Translate( bCVector2 const & );
        void              Translate( GEFloat );
        void              TransposedTransform( bCMatrix2 const & );

    public:
        GEFloat m_fX;
        GEFloat m_fY;
};

GE_ASSERT_SIZEOF( bCVector2, 0x08 )

#endif
