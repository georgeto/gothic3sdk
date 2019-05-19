#ifndef GE_SPHERE_H_INCLUDED
#define GE_SPHERE_H_INCLUDED

class GE_DLLIMPORT bCSphere
{

    protected:
        static GEFloat m_fDummy;

    public:
         bCSphere( bCSphere const & );
         bCSphere( void );
        ~bCSphere( void );

    public:
        bCSphere const & operator =  ( bCSphere const & );
        bCOStream &      operator >> ( bCOStream & ) const;
        bCIStream &      operator << ( bCIStream & );
        GEBool           operator == ( bCSphere const & ) const;
        GEBool           operator != ( bCSphere const & ) const;
        bCSphere         operator *  ( bCMatrix3 const & ) const;
        bCSphere         operator *  ( bCMatrix const & ) const;
        bCSphere         operator *  ( GEFloat ) const;
        bCSphere         operator -  ( bCVector const & ) const;
        bCSphere         operator +  ( bCVector const & ) const;
        bCSphere         operator /  ( GEFloat ) const;
        bCSphere &       operator *= ( bCMatrix3 const & );
        bCSphere &       operator *= ( bCMatrix const & );
        bCSphere &       operator *= ( GEFloat );
        bCSphere &       operator += ( bCVector const & );
        bCSphere &       operator -= ( bCVector const & );
        bCSphere &       operator /= ( GEFloat );
        bCSphere &       operator &= ( bCSphere const & );
        bCSphere &       operator |= ( bCSphere const & );
        bCSphere &       operator |= ( bCVector const & );

    public:
                         bCSphere( bCVector const &, GEFloat );
        bCVector &       AccessPosition( void );
        GEFloat &        AccessRadius( void );
        void             Clear( void );
        GEBool           Contains( bCSphere const & ) const;
        GEBool           Contains( bCBox const & ) const;
        GEBool           Contains( bCFrustum const & ) const;
        GEBool           Contains( bCStretch const & ) const;
        GEBool           Contains( bCTriangle const & ) const;
        GEBool           Contains( bCUnitedRay const & ) const;
        GEBool           Contains( bCVector const & ) const;
        GEBool           Contains( bCVector const * const ) const;
        GEBool           Cull( bCSphere const & ) const;
        GEBool           Cull( bCBox const & ) const;
        GEBool           Cull( bCFrustum const & ) const;
        GEBool           Cull( bCLine const & ) const;
        GEBool           Cull( bCPlane const & ) const;
        GEBool           Cull( bCRay const & ) const;
        GEBool           Cull( bCStretch const & ) const;
        GEBool           Cull( bCTriangle const & ) const;
        GEBool           Cull( bCUnitedRay const & ) const;
        GEBool           Cull( bCVector const &, bCVector const &, bCVector const & ) const;
        GEBool           Cull( bCVector const & ) const;
        GEBool           Cull( bCVector const * const ) const;
        bCSphere         GetIntersected( bCSphere const & ) const;
        GEFloat          GetIntersectionDistance( bCRay const & ) const;
        bCSphere         GetInvScaled( GEFloat ) const;
        bCSphere         GetInvTranslated( bCVector const & ) const;
        bCSphere         GetInvTranslated( GEFloat ) const;
        bCSphere         GetMerged( bCSphere const & ) const;
        bCSphere         GetMerged( bCVector const & ) const;
        bCVector const & GetPosition( void ) const;
        void             GetPosition( bCVector & ) const;
        GEFloat          GetRadius( void ) const;
        void             GetRadius( GEFloat & ) const;
        bCSphere         GetScaled( GEFloat ) const;
        bCSphere         GetShrunk( GEFloat ) const;
        bCSphere         GetTransformed( bCMatrix3 const & ) const;
        bCSphere         GetTransformed( bCMatrix const & ) const;
        bCSphere         GetTranslated( bCVector const & ) const;
        bCSphere         GetTranslated( GEFloat ) const;
        GEFloat          GetVolume( void ) const;
        bCSphere         GetWidened( GEFloat ) const;
        void             Intersect( bCSphere const & );
        GEBool           Intersects( bCSphere const & ) const;
        GEBool           Intersects( bCBox const & ) const;
        GEBool           Intersects( bCFrustum const & ) const;
        GEBool           Intersects( bCLine const &, GEFloat & ) const;
        GEBool           Intersects( bCPlane const & ) const;
        GEBool           Intersects( bCRay const &, GEFloat & ) const;
        GEBool           Intersects( bCStretch const &, GEFloat & ) const;
        GEBool           Intersects( bCTriangle const & ) const;
        GEBool           Intersects( bCUnitedRay const &, GEFloat & ) const;
        GEBool           Intersects( bCVector const &, bCVector const &, bCVector const & ) const;
        GEBool           Intersects( bCVector const & ) const;
        GEBool           Intersects( bCVector const * const ) const;
        void             InvScale( GEFloat );
        void             InvTranslate( bCVector const & );
        void             InvTranslate( GEFloat );
        void             Invalidate( void );
        GEBool           IsEqual( bCSphere const & ) const;
        GEBool           IsValid( void ) const;
        void             Merge( bCSphere const & );
        void             Merge( bCVector const & );
        void             Scale( GEFloat );
        GEBool           Separates( bCBox const &, bCVector const & ) const;
        GEBool           Separates( bCVector const *, GEInt, bCVector const & ) const;
        void             SetPosition( bCVector const & );
        void             SetRadius( GEFloat );
        void             SetSphere( bCSphere const & );
        void             SetSphere( bCVector const &, GEFloat );
        void             Shrink( GEFloat );
        void             Transform( bCMatrix3 const & );
        void             Transform( bCMatrix const & );
        void             Translate( bCVector const & );
        void             Translate( GEFloat );
        void             Widen( GEFloat );

};

#endif
