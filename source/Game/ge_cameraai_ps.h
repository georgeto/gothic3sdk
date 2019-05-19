#ifndef GE_CAMERAAI_PS_H_INCLUDED
#define GE_CAMERAAI_PS_H_INCLUDED

enum gECameraMode;
class gCCameraModeParams;

class GE_DLLIMPORT gCCameraAI_PS :
    public eCEntityPropertySet
{
    public:    virtual void              SetTarget( eCEntity * );
    public:    virtual eCEntity *        GetTarget( void );
    public:    virtual eCEntity const *  GetTarget( void ) const;
    public:    virtual void              SetMode( gECameraMode, GEBool, GEBool );
    public:    virtual gECameraMode      GetMode( void );
    public:    virtual gECameraMode      GetLastMode( void );
    public:    virtual GEBool            IsLookingBack( void ) const;
    public:    virtual GEBool            IsInFirstPerson( void ) const;
    public:    virtual GEBool            IsInTempFirstPerson( void ) const;
    public:    virtual void              EnableTempFirstPerson( GEBool );
    public:    virtual GEBool            IsInSpecialBowMode( void ) const;
    public:    virtual void              EnableSpecialBowMode( GEBool );
    protected: virtual void              DrawRay( bCUnitedRay const &, GEFloat );
    public:    virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult          Write( bCOStream & );
    public:    virtual bEResult          Read( bCIStream & );
    public:    virtual void              Destroy( void );
    public:    virtual bEResult          Create( void );
    public:    virtual bEResult          CopyFrom( bCObjectBase const & );
    public:    virtual                  ~gCCameraAI_PS( void );
    public:    virtual bEResult          PostInitializeProperties( void );
    public:    virtual GEBool            OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    public:    virtual GEBool            CanBePaused( void ) const;
    protected: virtual GEBool            IsProcessable( void ) const;
    public:    virtual GEInt             OnAction( eCInpShared::eSGameKeyMessage const & );
    protected: virtual void              OnEnterProcessingRange( void );
    protected: virtual void              OnExitProcessingRange( void );
    protected: virtual void              OnUpdatedWorldMatrix( void );
    public:    virtual void              GetBoundary( bCBox &, GEBool );
    protected: virtual void              OnProcess( void );

    protected:
        static eCEntity * ms_pRayTargetEntity;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static GEBool GE_STDCALL                       S_FilterShape( eCEntity *, eCCollisionShape * );
        static eCEntity * GE_STDCALL                   S_GetRayTargetEntity( void );

    public:
        gCCameraAI_PS( gCCameraAI_PS const & );
        gCCameraAI_PS( void );

    public:
        gCCameraAI_PS const & operator = ( gCCameraAI_PS const & );

    public:
        void            AddTremor( bCVector const &, GEFloat, GEFloat, GEFloat, bCVector const & );
        void            Disable( GEBool const & );
        void            EntityMovedBigDistance( void );
        GEBool          GetDebugMode( void ) const;
        GEBool          GetInvertXAxis( void ) const;
        GEBool          GetInvertYAxis( void ) const;
        bCVector        GetListenerPosition( void ) const;
        GEFloat         GetMouseSensitivityX( void ) const;
        GEFloat         GetMouseSensitivityY( void ) const;
        GEFloat         GetMouseSmoothingX( void ) const;
        GEFloat         GetMouseSmoothingY( void ) const;
        bCVector        GetSpeakerPosition( void ) const;
        GEBool          IsDialogCameraActive( void ) const;
        GEBool          IsDisabled( void ) const;
        void GE_STDCALL OnConsoleCommand( bCObjectRefBase *, bCEvent * );
        void            SetDebugMode( GEBool );
        void            SetDialogRoles( eCEntity *, eCEntity * );
        void            SetInvertXAxis( GEBool );
        void            SetInvertYAxis( GEBool );
        void            SetLookAtTarget( bCVector & );
        void            SetMouseSensitivityX( GEFloat );
        void            SetMouseSensitivityY( GEFloat );
        void            SetMouseSmoothingX( GEFloat );
        void            SetMouseSmoothingY( GEFloat );
        void            SetMoveSpeed( GEFloat );
        void            SetMoveSpeedAccelerator( GEFloat );
        void            SetMoveSpeedDeccelerator( GEFloat );
        void            StartDialogCamera( GEBool );
        void            StopDialogCamera( void );
        void            StopTremor( void );

    protected:
        void                 ApplyTremor( bCMatrix & );
        GEBool               CorrectCameraPosition( bCVector &, GEFloat, GEFloat, GEFloat, GEBool, bCVector * );
        GEBool               DialogPresetIsValid( gCCameraModeParams &, GEBool );
        void                 EnableItemRendering( GEBool );
        gCCameraModeParams * FindPreset( GEBool, GEBool );
        GEFloat              GetAzimuth( bCVector const & ) const;
        GEFloat              GetCurrentDistance( void ) const;
        GEFloat              GetCurrentWishedDistance( void );
        bCMatrix             GetCurrentWishedRotation( void );
        bCVector             GetCurrentWishedTranslation( void );
        GEFloat              GetElevation( bCVector const & ) const;
        bCMatrix             GetFirstPersonMat( void ) const;
        bCMatrix             GetHeadMat( eCEntityProxy const & ) const;
        void                 Invalidate( void );
        void                 MaintainWallDistance( bCVector & );
        void                 ProcessCurrentMode( void );
        void                 RegisterConsoleCommands( void );
        void                 SetChildrenRenderAlphaValue( eCEntity *, GEFloat );
        void                 ShowDebug( void );
        void                 UpdateCameraPosition( bCVector const & );
        void                 UpdateDeltaRotX( GEFloat );
        void                 UpdateDeltaRotY( GEFloat );
        void                 UpdateDistance( GEFloat, GEFloat );
        void                 UpdateFOV( GEFloat );
        void                 UpdateListenerPosition( GEBool );
        void                 UpdatePlayerPosition( void );
        void                 UpdateSpeakerPosition( GEBool );

};

#endif
