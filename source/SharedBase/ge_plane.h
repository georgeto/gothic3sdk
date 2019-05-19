#ifndef GE_PLANE_H_INCLUDED
#define GE_PLANE_H_INCLUDED

class GE_DLLIMPORT bCPlane
{

    protected:
        static GEFloat m_fDummy;

    public:
         bCPlane( bCPlane const & );
         bCPlane( void );
        ~bCPlane( void );

    public:
        bCPlane &     operator =  ( bCPlane const & );
        bCOStream &   operator >> ( bCOStream & ) const;
        bCIStream &   operator << ( bCIStream & );
        bCPlane const operator *  ( bCMatrix3 const & ) const;
        bCPlane const operator *  ( bCMatrix const & ) const;
        bCPlane const operator *  ( GEFloat ) const;
        bCPlane const operator -  ( bCVector const & ) const;
        bCPlane const operator -  ( void ) const;
        bCPlane const operator +  ( bCVector const & ) const;
        bCPlane const operator /  ( bCMatrix3 const & ) const;
        bCPlane const operator /  ( bCMatrix const & ) const;
        bCPlane const operator /  ( GEFloat ) const;
        bCPlane &     operator *= ( GEFloat );
        bCPlane &     operator += ( bCVector const & );
        bCPlane &     operator -= ( bCVector const & );
        bCPlane &     operator /= ( GEFloat );

    public:
                         bCPlane( bCVector const &, bCVector const &, bCVector const & );
                         bCPlane( bCVector const &, bCVector const & );
                         bCPlane( GEFloat, GEFloat, GEFloat, GEFloat );
        GEFloat &        AccessDistance( void );
        bCVector &       AccessNormal( void );
        GEFloat          ClassifyPoint( bCVector const & ) const;
        GEFloat          ClassifyVector( bCVector const & ) const;
        void             Clear( void );
        GEFloat          GetDistance( void ) const;
        void             GetDistance( GEFloat & ) const;
        GEFloat          GetIntersectionDistance( bCRay const & ) const;
        bCPlane          GetInvRotated( bCQuaternion const & ) const;
        void             GetInvRotated( bCPlane &, bCQuaternion const & ) const;
        bCPlane          GetInvScaled( GEFloat ) const;
        void             GetInvScaled( bCPlane &, GEFloat ) const;
        bCPlane          GetInvTransformed( bCMatrix3 const & ) const;
        bCPlane          GetInvTransformed( bCMatrix const & ) const;
        void             GetInvTransformed( bCPlane &, bCMatrix3 const & ) const;
        void             GetInvTransformed( bCPlane &, bCMatrix const & ) const;
        bCPlane          GetInvTranslated( bCVector const & ) const;
        void             GetInvTranslated( bCPlane &, bCVector const & ) const;
        bCPlane          GetInverted( void ) const;
        void             GetInverted( bCPlane & ) const;
        bCPlane          GetNegated( void ) const;
        void             GetNegated( bCPlane & ) const;
        bCVector const & GetNormal( void ) const;
        void             GetNormal( bCVector & ) const;
        bCPlane          GetNormalized( void ) const;
        bCPlane          GetRotated( bCQuaternion const & ) const;
        void             GetRotated( bCPlane &, bCQuaternion const & ) const;
        bCPlane          GetScaled( GEFloat ) const;
        void             GetScaled( bCPlane &, GEFloat ) const;
        bCPlane          GetTransformed( bCMatrix3 const & ) const;
        bCPlane          GetTransformed( bCMatrix const & ) const;
        void             GetTransformed( bCPlane &, bCMatrix3 const & ) const;
        void             GetTransformed( bCPlane &, bCMatrix const & ) const;
        bCPlane          GetTranslated( bCVector const & ) const;
        void             GetTranslated( bCPlane &, bCVector const & ) const;
        GEBool           Intersects( bCBox const & ) const;
        void             InvRotate( bCQuaternion const & );
        void             InvScale( GEFloat );
        void             InvTransform( bCMatrix3 const & );
        void             InvTransform( bCMatrix const & );
        void             InvTranslate( bCVector const & );
        void             Invert( void );
        void             Negate( void );
        void             Normalize( void );
        void             Rotate( bCQuaternion const & );
        void             Scale( GEFloat );
        void             SetDistance( GEFloat );
        void             SetNormal( bCVector const & );
        void             SetPlane( bCPlane const & );
        void             Transform( bCMatrix3 const & );
        void             Transform( bCMatrix const & );
        void             Translate( bCVector const & );

};

#endif
