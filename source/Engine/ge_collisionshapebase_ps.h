#ifndef GE_COLLISIONSHAPEBASE_PS_H_INCLUDED
#define GE_COLLISIONSHAPEBASE_PS_H_INCLUDED

class GE_DLLIMPORT eCCollisionShapeBase_PS :
    public eCEntityPropertySet
{
    public: virtual bEResult           SetShape( eCCollisionShape * );
    public: virtual bEResult           SetShape( bCString const & );
    public: virtual bEResult           AddShape( eCCollisionShape * );
    public: virtual bEResult           AddShape( bCString const & );
    public: virtual GEU32              GetNumShapes( void ) const;
    public: virtual eCCollisionShape * GetShapeAtIndex( GEU32 ) const;
    public: virtual GEU16              GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult           Write( bCOStream & );
    public: virtual bEResult           Read( bCIStream & );
    public: virtual void               Destroy( void );
    public: virtual bEResult           Create( void );
    public: virtual                   ~eCCollisionShapeBase_PS( void );
    public: virtual bEResult           PostInitializeProperties( void );
    public: virtual eEPropertySetType  GetPropertySetType( void ) const;
    public: virtual GEBool             IsEditorRelevant( void ) const;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCCollisionShapeBase_PS( eCCollisionShapeBase_PS const & );
        eCCollisionShapeBase_PS( void );

    public:
        eCCollisionShapeBase_PS const & operator = ( eCCollisionShapeBase_PS const & );

    protected:
        void Invalidate( void );

};

#endif
