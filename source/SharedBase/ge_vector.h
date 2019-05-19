#ifndef GE_VECTOR_H_INCLUDED
#define GE_VECTOR_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4201 )// nonstandard extension used : nameless struct/union

class GE_DLLIMPORT bCVector
{
    public:
        enum bECoordinate
        {
            bECoordinate_X,
            bECoordinate_Y,
            bECoordinate_Z,
            bECoordinate_Count,
            bECoordinate_ForceDWORD = GE_FORCE_DWORD
        };
    public:
        union
        {
            GEFloat m_fCoordinates[ bECoordinate_Count ];
            struct
            {
                GEFloat m_fX;
                GEFloat m_fY;
                GEFloat m_fZ;
            };
        };

    public:
        static bCVector GE_STDCALL         CrossProduct( bCVector const &, bCVector const & );
        static GEFloat GE_STDCALL          DotProduct( bCVector const &, bCVector const & );
        static bCVector const & GE_STDCALL GetForward( void );
        static bCVector const & GE_STDCALL GetRight( void );
        static bCVector const & GE_STDCALL GetUnit( void );
        static bCVector const & GE_STDCALL GetUp( void );
        static bCVector const & GE_STDCALL GetZero( void );

    public:
         bCVector( bCVector const & );
         bCVector( NxVec3 const & );
         bCVector( GEFloat );
         bCVector( GEFloat const * const );
         bCVector( void );
        ~bCVector( void );

    public:
        bCVector &      operator =              ( bCVector const & );
        bCOStream &     operator >>             ( bCOStream & ) const;
        bCIStream &     operator <<             ( bCIStream & );
        GEBool          operator ==             ( bCVector const & ) const;
        GEBool          operator !=             ( bCVector const & ) const;
        GEFloat &       operator []             ( GEInt );
        GEFloat const & operator []             ( GEInt ) const;
                        operator NxVec3 &       ( void );
                        operator NxVec3 const & ( void ) const;
        bCVector        operator *              ( bCMatrix const & ) const;
        bCVector        operator *              ( GEFloat ) const;
        bCVector        operator -              ( bCVector const & ) const;
        bCVector        operator -              ( void ) const;
        bCVector        operator +              ( bCVector const & ) const;
        bCVector        operator /              ( bCMatrix const & ) const;
        bCVector        operator /              ( GEFloat ) const;
        bCVector &      operator *=             ( bCMatrix3 const & );
        bCVector &      operator *=             ( bCMatrix const & );
        bCVector &      operator *=             ( GEFloat );
        bCVector &      operator +=             ( bCVector const & );
        bCVector &      operator -=             ( bCVector const & );
        bCVector &      operator /=             ( bCMatrix3 const & );
        bCVector &      operator /=             ( bCMatrix const & );
        bCVector &      operator /=             ( GEFloat );

    public:
                  bCVector( GEFloat, GEFloat, GEFloat );
        GEFloat & AccessCoordinate( GEInt );
        GEFloat ( &AccessCoordinates( void ))[3];
        GEFloat &       AccessX( void );
        GEFloat &       AccessY( void );
        GEFloat &       AccessZ( void );
        void            Clear( void );
        void            CrossProduct( bCVector const & );
        void            Decompose( bCVector const &, bCVector &, bCVector & ) const;
        GEFloat         GetAngleDeg( bCVector const & ) const;
        GEFloat         GetAngleRad( bCVector const & ) const;
        GEFloat         GetAngleUnitDeg( bCVector const & ) const;
        GEFloat         GetAngleUnitRad( bCVector const & ) const;
        void            GetAziElev( GEFloat &, GEFloat & ) const;
        void            GetAziElevApprox( GEFloat &, GEFloat & ) const;
        void            GetAziElevUnit( GEFloat &, GEFloat & ) const;
        GEFloat const & GetCoordinate( GEInt ) const;
        void            GetCoordinate( GEInt, GEFloat & ) const;
        GEFloat const (&GetCoordinates( void ) const )[3];
        void             GetCoordinates( GEFloat &, GEFloat &, GEFloat & ) const;
        void             GetCoordinates( GEFloat * const ) const;
        bCVector         GetCrossProduct( bCVector const & ) const;
        GEFloat          GetDotProduct( bCVector const & ) const;
        bCVector         GetInvScaled( bCVector const & ) const;
        bCVector         GetInvScaled( GEFloat ) const;
        bCVector         GetInvTransformed( bCMatrix3 const & ) const;
        bCVector         GetInvTransformed( bCMatrix const & ) const;
        bCVector         GetInvTransformedDirection( bCMatrix const & ) const;
        bCVector         GetInvTranslated( bCVector const & ) const;
        bCVector         GetInvTranslated( GEFloat ) const;
        bCVector         GetInverted( void ) const;
        bCVector         GetLerp( bCVector const &, GEFloat ) const;
        GEFloat          GetMagnitude2D( bECoordinate ) const;
        GEFloat          GetMagnitude( void ) const;
        GEFloat          GetMagnitudeApprox( void ) const;
        GEFloat          GetMagnitudeNormalize( void );
        bCVector         GetNormalized( void ) const;
        bCVector         GetNormalizedSafe( void ) const;
        bCVector         GetRemovedByDimension( bECoordinate ) const;
        bCVector         GetRemovedByDimensionKeepMagnitude( bECoordinate ) const;
        bCVector         GetRemovedByDimensionNormalize( bECoordinate ) const;
        bCVector         GetScaled( bCVector const & ) const;
        bCVector         GetScaled( GEFloat ) const;
        bCVector         GetSlerp( bCVector const &, GEFloat ) const;
        GEFloat          GetSquareMagnitude2D( bECoordinate ) const;
        GEFloat          GetSquareMagnitude( void ) const;
        bCVector         GetTransformed( bCMatrix3 const & ) const;
        bCVector         GetTransformed( bCMatrix const & ) const;
        bCVector         GetTransformedDirection( bCMatrix const & ) const;
        bCVector         GetTranslated( bCVector const & ) const;
        bCVector         GetTranslated( GEFloat ) const;
        GEFloat          GetX( void ) const;
        void             GetX( GEFloat & ) const;
        GEFloat          GetY( void ) const;
        void             GetY( GEFloat & ) const;
        GEFloat          GetZ( void ) const;
        void             GetZ( GEFloat & ) const;
        GEBool           HasZeroMagnitude2D( bECoordinate ) const;
        GEBool           HasZeroMagnitude2DApprox( bECoordinate ) const;
        GEBool           HasZeroMagnitude( void ) const;
        GEBool           HasZeroMagnitudeApprox( void ) const;
        void             InvScale( bCVector const & );
        void             InvScale( GEFloat );
        void             InvTransform( bCMatrix3 const & );
        void             InvTransform( bCMatrix const & );
        void             InvTransformDirection( bCMatrix const & );
        void             InvTranslate( bCVector const & );
        void             InvTranslate( GEFloat );
        void             Invert( void );
        GEBool           IsEqual( bCVector const & ) const;
        GEBool           IsValid( bCString const & ) const;
        bCVector const & Normalize( void );
        bCVector const & NormalizeApprox( void );
        bCVector const & NormalizeSafe( void );
        void             PrintDebug( bCString const & ) const;
        bCVector         Reflect( bCVector const & ) const;
        void             RemoveDimension( bECoordinate );
        GEBool           RemoveDimensionKeepMagnitude( bECoordinate );
        void             RemoveDimensionNormalize( bECoordinate );
        void             Scale( bCVector const & );
        void             Scale( GEFloat );
        void             SetCoordinate( GEInt, GEFloat );
        void             SetCoordinates( GEFloat, GEFloat, GEFloat );
        void             SetCoordinates( GEFloat const * const );
        void             SetCrossProduct( bCVector const &, bCVector const & );
        void             SetLerp( bCVector const &, bCVector const &, GEFloat );
        void             SetSlerp( bCVector, bCVector, GEFloat );
        void             SetTransformed( bCVector const &, bCMatrix3 const & );
        void             SetTransformed( bCVector const &, bCMatrix const & );
        void             SetTransformedDirection( bCVector const &, bCMatrix const & );
        void             SetTransposedTransformed( bCVector const &, bCMatrix3 const & );
        void             SetVector( bCVector const & );
        void             SetVector( NxVec3 const & );
        void             SetVector( GEFloat );
        void             SetVector( GEFloat, GEFloat, GEFloat );
        void             SetX( GEFloat const & );
        void             SetY( GEFloat const & );
        void             SetZ( GEFloat const & );
        void             Transform( bCMatrix3 const & );
        void             Transform( bCMatrix const & );
        void             TransformDirection( bCMatrix const & );
        void             Translate( bCVector const & );
        void             Translate( GEFloat );
        void             TransposedTransform( bCMatrix3 const & );

};

GE_ASSERT_SIZEOF( bCVector, 0x000C )

#pragma warning( pop )

#endif
