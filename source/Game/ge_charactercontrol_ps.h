#ifndef GE_CHARACTERCONTROL_PS_H_INCLUDED
#define GE_CHARACTERCONTROL_PS_H_INCLUDED

class GE_DLLIMPORT gCCharacterControl_PS :
    public eCEntityPropertySet
{
    protected: virtual void              ProcessMovements( void );
    public:    virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult          Write( bCOStream & );
    public:    virtual bEResult          Read( bCIStream & );
    public:    virtual void              Destroy( void );
    public:    virtual bEResult          Create( void );
    public:    virtual bEResult          CopyFrom( bCObjectBase const & );
    public:    virtual                  ~gCCharacterControl_PS( void );
    public:    virtual bEResult          PostInitializeProperties( void );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    public:    virtual void              SetEntity( eCEntity * );
    public:    virtual GEInt             OnAction( eCInpShared::eSGameKeyMessage const & );
    protected: virtual void              OnPreProcess( void );
    protected: virtual void              OnPostProcess( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCCharacterControl_PS( gCCharacterControl_PS const & );
        gCCharacterControl_PS( void );

    public:
        gCCharacterControl_PS const & operator = ( gCCharacterControl_PS const & );

    public:
        bTPropertyContainer<gECharacterControlFOR> &       AccessControlFrameOfReference( void );
        GEU32 &                                            AccessDurationPressedMSecs( void );
        GEBool &                                           AccessIsPressed( void );
        GEBool &                                           AccessIsPressedBefore( void );
        bTPropertyContainer<gESessionKey> &                AccessPressedKey( void );
        GEBool                                             GetAnyControlPressed( void ) const;
        bTPropertyContainer<gECharacterControlFOR> const & GetControlFrameOfReference( void ) const;
        GEU32 const &                                      GetDurationPressedMSecs( void ) const;
        GEBool const &                                     GetIsPressed( void ) const;
        GEBool const &                                     GetIsPressedBefore( void ) const;
        bTPropertyContainer<gESessionKey> const &          GetPressedKey( void ) const;
        bCVector const &                                   GetWishedDirection( void );
        void                                               SetControlFrameOfReference( bTPropertyContainer<gECharacterControlFOR> const & );
        void                                               SetDurationPressedMSecs( GEU32 const & );
        void                                               SetIsPressed( GEBool const & );
        void                                               SetIsPressedBefore( GEBool const & );
        void                                               SetMovementConstraints( GEFloat );
        void                                               SetPressedKey( bTPropertyContainer<gESessionKey> const & );
        void                                               SetWishedMovementMode( gECharMovementMode );

    protected:
        void ClearVolatileFrameStates( void );
        void Invalidate( void );

};

#endif
