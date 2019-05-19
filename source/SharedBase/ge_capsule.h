#ifndef GE_CAPSULE_H_INCLUDED
#define GE_CAPSULE_H_INCLUDED

class GE_DLLIMPORT bCCapsule
{
    private:
        GEFloat   m_fHeight;
        GEFloat   m_fRadius;
        bCMatrix3 m_matOrientation;
        bCVector  m_vecCenter;

    public:
         bCCapsule( bCCapsule const & );
         bCCapsule( void );
        ~bCCapsule( void );

    public:
        bCCapsule const & operator =  ( bCCapsule const & );
        bCOStream &       operator >> ( bCOStream & ) const;
        bCIStream &       operator << ( bCIStream & );
        GEBool            operator == ( bCCapsule const & ) const;
        GEBool            operator != ( bCCapsule const & ) const;

    public:
        bEResult          Create( void );
        void              Destroy( void );
        bCVector &        GetCenter( void );
        bCVector const &  GetCenter( void ) const;
        GEFloat           GetHeight( void );
        GEFloat const     GetHeight( void ) const;
        bCMatrix3 &       GetOrientation( void );
        bCMatrix3 const & GetOrientation( void ) const;
        GEFloat           GetRadius( void );
        GEFloat const     GetRadius( void ) const;
        GEBool            IsEqual( bCCapsule const & ) const;
        void              SetCapsule( bCCapsule const & );
        void              SetCapsule( GEFloat, GEFloat, bCVector &, bCMatrix3 & );
        void              SetCenter( bCVector const & );
        void              SetHeight( GEFloat );
        void              SetOrientation( bCMatrix3 const & );
        void              SetRadius( GEFloat );

    protected:
        void Invalidate( void );

};

#endif
