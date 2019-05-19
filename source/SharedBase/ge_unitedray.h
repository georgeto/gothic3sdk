#ifndef GE_UNITEDRAY_H_INCLUDED
#define GE_UNITEDRAY_H_INCLUDED

enum bERayExtension;

class GE_DLLIMPORT bCUnitedRay
{

    protected:
        static GEFloat m_fDummy;

    public:
         bCUnitedRay( bCUnitedRay const & );
         bCUnitedRay( bCLine const & );
         bCUnitedRay( bCRay const & );
         bCUnitedRay( bCStretch const & );
         bCUnitedRay( void );
        ~bCUnitedRay( void );

    public:
        bCUnitedRay & operator =  ( bCUnitedRay const & );
        bCOStream &   operator >> ( bCOStream & ) const;
        bCIStream &   operator << ( bCIStream & );
        bCUnitedRay   operator *  ( bCMatrix3 const & ) const;
        bCUnitedRay   operator *  ( bCMatrix const & ) const;
        bCUnitedRay   operator *  ( GEFloat ) const;
        bCUnitedRay   operator -  ( bCUnitedRay const & ) const;
        bCUnitedRay   operator -  ( bCVector const & ) const;
        bCUnitedRay   operator -  ( void ) const;
        bCUnitedRay   operator +  ( bCUnitedRay const & ) const;
        bCUnitedRay   operator +  ( bCVector const & ) const;
        bCUnitedRay   operator /  ( bCMatrix3 const & ) const;
        bCUnitedRay   operator /  ( bCMatrix const & ) const;
        bCUnitedRay   operator /  ( GEFloat ) const;
        bCUnitedRay & operator *= ( GEFloat );
        bCUnitedRay & operator += ( bCUnitedRay const & );
        bCUnitedRay & operator += ( bCVector const & );
        bCUnitedRay & operator -= ( bCUnitedRay const & );
        bCUnitedRay & operator -= ( bCVector const & );
        bCUnitedRay & operator /= ( GEFloat );

    public:
        bCVector &             AccessDirection( void );
        bERayExtension &       AccessExtensionFlags( void );
        bCVector &             AccessOrigin( void );
        void                   Add( bCUnitedRay const & );
        void                   Clear( void );
        void                   CopyFrom( bCUnitedRay const & );
        void                   CopyTo( bCUnitedRay & ) const;
        bCUnitedRay            GetDifference( bCUnitedRay const & ) const;
        void                   GetDifference( bCUnitedRay &, bCUnitedRay const & ) const;
        bCVector const &       GetDirection( void ) const;
        void                   GetDirection( bCVector & ) const;
        bERayExtension const & GetExtensionFlags( void ) const;
        void                   GetExtensionFlags( bERayExtension & ) const;
        bCUnitedRay            GetInvRotated( bCQuaternion const & ) const;
        void                   GetInvRotated( bCUnitedRay &, bCQuaternion const & ) const;
        bCUnitedRay            GetInvScaled( GEFloat ) const;
        void                   GetInvScaled( bCUnitedRay &, GEFloat ) const;
        bCUnitedRay            GetInvTransformed( bCMatrix3 const & ) const;
        bCUnitedRay            GetInvTransformed( bCMatrix const & ) const;
        void                   GetInvTransformed( bCUnitedRay &, bCMatrix3 const & ) const;
        void                   GetInvTransformed( bCUnitedRay &, bCMatrix const & ) const;
        bCUnitedRay            GetInvTranslated( bCVector const & ) const;
        void                   GetInvTranslated( bCUnitedRay &, bCVector const & ) const;
        bCUnitedRay            GetInverted( void ) const;
        void                   GetInverted( bCUnitedRay & ) const;
        bCUnitedRay            GetNegated( void ) const;
        void                   GetNegated( bCUnitedRay & ) const;
        bCUnitedRay            GetNormalized( void ) const;
        void                   GetNormalized( bCUnitedRay & ) const;
        bCVector const &       GetOrigin( void ) const;
        void                   GetOrigin( bCVector & ) const;
        bCVector               GetPoint( GEFloat ) const;
        void                   GetPoint( bCVector &, GEFloat ) const;
        bCUnitedRay            GetRotated( bCQuaternion const & ) const;
        void                   GetRotated( bCUnitedRay &, bCQuaternion const & ) const;
        bCUnitedRay            GetScaled( GEFloat ) const;
        void                   GetScaled( bCUnitedRay &, GEFloat ) const;
        bCUnitedRay            GetSum( bCUnitedRay const & ) const;
        void                   GetSum( bCUnitedRay &, bCUnitedRay const & ) const;
        bCUnitedRay            GetTransformed( bCMatrix3 const & ) const;
        bCUnitedRay            GetTransformed( bCMatrix const & ) const;
        void                   GetTransformed( bCUnitedRay &, bCMatrix3 const & ) const;
        void                   GetTransformed( bCUnitedRay &, bCMatrix const & ) const;
        bCUnitedRay            GetTranslated( bCVector const & ) const;
        void                   GetTranslated( bCUnitedRay &, bCVector const & ) const;
        GEBool                 Intersects( bCBox const &, GEFloat & ) const;
        GEBool                 Intersects( bCFrustum const &, GEFloat & ) const;
        GEBool                 Intersects( bCPlane const &, GEFloat & ) const;
        GEBool                 Intersects( bCSphere const &, GEFloat & ) const;
        GEBool                 Intersects( bCTriangle const &, GEFloat & ) const;
        GEBool                 Intersects( bCTriangle const &, bCTriangle::bESides, GEFloat & ) const;
        GEBool                 Intersects( bCVector const &, bCVector const &, bCVector const &, GEFloat & ) const;
        GEBool                 Intersects( bCVector const &, bCVector const &, bCVector const &, bCTriangle::bESides, GEFloat & ) const;
        GEBool                 Intersects( bCVector const * const, GEFloat & ) const;
        GEBool                 Intersects( bCVector const * const, bCTriangle::bESides, GEFloat & ) const;
        void                   InvRotate( bCQuaternion const & );
        void                   InvScale( GEFloat );
        void                   InvTransform( bCMatrix3 const & );
        void                   InvTransform( bCMatrix const & );
        void                   InvTranslate( bCVector const & );
        void                   Invert( void );
        void                   Negate( void );
        void                   Normalize( void );
        void                   Rotate( bCQuaternion const & );
        void                   Scale( GEFloat );
        void                   SetDirection( bCVector const & );
        void                   SetExtensionFlags( bERayExtension const & );
        void                   SetOrigin( bCVector const & );
        void                   SetUnitedRay( bCUnitedRay const & );
        void                   Sub( bCUnitedRay const & );
        void                   Transform( bCMatrix3 const & );
        void                   Transform( bCMatrix const & );
        void                   Translate( bCVector const & );

};

#endif
