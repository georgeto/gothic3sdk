#ifndef GE_MOVEMENTBASE_PS_H_INCLUDED
#define GE_MOVEMENTBASE_PS_H_INCLUDED

class GE_DLLIMPORT gCMovementBase_PS :
    public eCEntityPropertySet
{
    public:    virtual void              MoveLocal( bCVector const & );
    public:    virtual void              MoveLocal( GEFloat, GEFloat, GEFloat );
    public:    virtual void              MoveWorld( bCVector const & );
    public:    virtual void              MoveWorld( GEFloat, GEFloat, GEFloat );
    public:    virtual void              RotateLocal( bCVector const &, GEFloat );
    public:    virtual void              RotateWorld( GEFloat, GEFloat, GEFloat, GEFloat );
    public:    virtual void              RotateLocalX( GEFloat );
    public:    virtual void              RotateLocalZ( GEFloat );
    public:    virtual void              RotateWorld( bCQuaternion const & );
    public:    virtual void              RotateWorldX( GEFloat );
    public:    virtual void              RotateWorld( bCVector const &, GEFloat );
    public:    virtual void              RotateLocal( GEFloat, GEFloat, GEFloat, GEFloat );
    public:    virtual void              RotateWorldY( GEFloat );
    public:    virtual void              RotateLocalY( GEFloat );
    public:    virtual void              SetHeadingAtLocal( bCVector const & );
    public:    virtual bCVector const &  GetAtVectorWorld( void ) const;
    public:    virtual bCVector const &  GetUpVectorWorld( void ) const;
    public:    virtual bCVector const &  GetRightVectorWorld( void ) const;
    public:    virtual void              ResetRotationsLocal( void );
    public:    virtual void              ResetRotationsWorld( void );
    public:    virtual void              ResetXZRotationsLocal( void );
    public:    virtual void              ResetXZRotationsWorld( void );
    public:    virtual void              SetHeadingAtWorld( bCVector const & );
    public:    virtual void              SetHeadingLocal( bCVector const & );
    public:    virtual void              SetHeadingWorld( bCVector const & );
    public:    virtual void              SetHeadingWorld( eCEntity * );
    public:    virtual void              SetHeadingYLocal( bCVector const & );
    public:    virtual void              SetHeadingYWorld( bCVector const & );
    public:    virtual void              SetHeadingYWorld( eCEntity * );
    public:    virtual void              RotateWorldZ( GEFloat );
    public:    virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult          Write( bCOStream & );
    public:    virtual bEResult          Read( bCIStream & );
    public:    virtual void              Destroy( void );
    public:    virtual bEResult          Create( void );
    public:    virtual bEResult          CopyFrom( bCObjectBase const & );
    public:    virtual                  ~gCMovementBase_PS( void );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    public:    virtual GEBool            IsEditorRelevant( void ) const;
    public:    virtual GEInt             OnMouse( eCInpShared::eSInputMessage const & );
    public:    virtual GEInt             OnAction( eCInpShared::eSGameKeyMessage const & );
    protected: virtual void              OnProcess( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCMovementBase_PS( gCMovementBase_PS const & );
        gCMovementBase_PS( void );

    public:
        gCMovementBase_PS const & operator = ( gCMovementBase_PS const & );

    protected:
        void Invalidate( void );

};

#endif
