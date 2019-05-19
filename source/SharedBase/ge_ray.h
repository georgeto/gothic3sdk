#ifndef GE_RAY_H_INCLUDED
#define GE_RAY_H_INCLUDED

class GE_DLLIMPORT bCRay
{

    protected:
        static GEFloat m_fDummy;

    public:
         bCRay( bCRay const & );
         bCRay( bCRay const * );
         bCRay( void );
        ~bCRay( void );

    public:
        bCRay const & operator =  ( bCRay const & );
        bCOStream &   operator >> ( bCOStream & ) const;
        bCIStream &   operator << ( bCIStream & );
        bCRay         operator *  ( bCMatrix const & ) const;
        bCRay         operator -  ( bCVector const & ) const;
        bCRay         operator +  ( bCVector const & ) const;
        bCRay &       operator *= ( bCMatrix const & );
        bCRay &       operator += ( bCVector const & );
        bCRay &       operator -= ( bCVector const & );

    public:
                         bCRay( bCVector const &, bCVector const & );
        bCVector &       AccessOrigin( void );
        bCVector const & GetDirection( void ) const;
        void             GetDirection( bCVector & ) const;
        GEFloat          GetIntersectionDistance( bCBox const & ) const;
        GEFloat          GetIntersectionDistance( bCPlane const & ) const;
        GEFloat          GetIntersectionDistance( bCTriangle const & ) const;
        GEFloat          GetIntersectionDistance( bCVector const * const ) const;
        bCVector const & GetOrigin( void ) const;
        void             GetOrigin( bCVector & ) const;
        bCVector         GetPoint( GEFloat ) const;
        void             GetPoint( bCVector &, GEFloat ) const;
        GEBool           Intersects( bCBox const &, GEFloat & ) const;
        GEBool           Intersects( bCFrustum const &, GEFloat & ) const;
        GEBool           Intersects( bCPlane const &, GEFloat & ) const;
        GEBool           Intersects( bCSphere const &, GEFloat & ) const;
        GEBool           Intersects( bCTriangle const &, GEFloat & ) const;
        GEBool           Intersects( bCTriangle const &, bCTriangle::bESides, GEFloat & ) const;
        GEBool           Intersects( bCVector const * const, GEFloat & ) const;
        GEBool           Intersects( bCVector const * const, bCTriangle::bESides, GEFloat & ) const;
        void             InvTransform( bCMatrix const & );
        void             InvTranslate( bCVector const & );
        void             SetDirection( bCVector const & );
        void             SetOrigin( bCVector const & );
        void             SetRay( bCRay const & );
        void             SetRay( bCVector const &, bCVector const & );
        void             SetRay( bCRay const * );
        void             Transform( bCMatrix const & );
        void             Translate( bCVector const & );

    protected:
        bCVector & AccessDirection( void );

};

#endif
