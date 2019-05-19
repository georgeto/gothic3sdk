#ifndef GE_LINE_H_INCLUDED
#define GE_LINE_H_INCLUDED

class GE_DLLIMPORT bCLine
{

    protected:
        static GEFloat m_fDummy;

    public:
         bCLine( bCLine const & );
         bCLine( void );
        ~bCLine( void );

    public:
        bCLine &    operator =  ( bCLine const & );
        bCOStream & operator >> ( bCOStream & ) const;
        bCIStream & operator << ( bCIStream & );
        bCLine      operator *  ( bCMatrix3 const & ) const;
        bCLine      operator *  ( bCMatrix const & ) const;
        bCLine      operator -  ( bCVector const & ) const;
        bCLine      operator +  ( bCVector const & ) const;
        bCLine      operator /  ( bCMatrix3 const & ) const;
        bCLine      operator /  ( bCMatrix const & ) const;
        bCLine &    operator += ( bCVector const & );
        bCLine &    operator -= ( bCVector const & );

    public:
        bCVector &       AccessDirection( void );
        bCVector &       AccessOrigin( void );
        void             Clear( void );
        void             CopyFrom( bCLine const & );
        void             CopyTo( bCLine & ) const;
        bCVector const & GetDirection( void ) const;
        void             GetDirection( bCVector & ) const;
        GEFloat          GetIntersectionDistance( bCBox const & ) const;
        GEFloat          GetIntersectionDistance( bCPlane const & ) const;
        GEFloat          GetIntersectionDistance( bCSphere const & ) const;
        GEFloat          GetIntersectionDistance( bCTriangle const & ) const;
        bCLine           GetInvTransformed( bCMatrix3 const & ) const;
        bCLine           GetInvTransformed( bCMatrix const & ) const;
        void             GetInvTransformed( bCLine &, bCMatrix3 const & ) const;
        void             GetInvTransformed( bCLine &, bCMatrix3 ) const;
        bCLine           GetInvTranslated( bCVector const & ) const;
        void             GetInvTranslated( bCLine &, bCVector const & ) const;
        bCVector const & GetOrigin( void ) const;
        void             GetOrigin( bCVector & ) const;
        bCLine           GetTransformed( bCMatrix3 const & ) const;
        bCLine           GetTransformed( bCMatrix const & ) const;
        void             GetTransformed( bCLine &, bCMatrix3 const & ) const;
        void             GetTransformed( bCLine &, bCMatrix3 ) const;
        bCLine           GetTranslated( bCVector const & ) const;
        void             GetTranslated( bCLine &, bCVector const & ) const;
        GEBool           Intersects( bCBox const &, GEFloat & ) const;
        GEBool           Intersects( bCFrustum const &, GEFloat & ) const;
        GEBool           Intersects( bCPlane const &, GEFloat & ) const;
        GEBool           Intersects( bCSphere const &, GEFloat & ) const;
        GEBool           Intersects( bCTriangle const &, GEFloat & ) const;
        GEBool           Intersects( bCTriangle const &, bCTriangle::bESides, GEFloat & ) const;
        GEBool           Intersects( bCVector const * const, GEFloat & ) const;
        GEBool           Intersects( bCVector const * const, bCTriangle::bESides, GEFloat & ) const;
        void             InvTransform( bCMatrix3 const & );
        void             InvTransform( bCMatrix const & );
        void             InvTranslate( bCVector const & );
        void             SetDirection( bCVector const & );
        void             SetLine( bCLine const & );
        void             SetLine( bCVector const &, bCVector const & );
        void             SetOrigin( bCVector const & );
        void             Transform( bCMatrix3 const & );
        void             Transform( bCMatrix const & );
        void             Translate( bCVector const & );

};

#endif
