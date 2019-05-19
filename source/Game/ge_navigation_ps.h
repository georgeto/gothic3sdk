#ifndef GE_NAVIGATION_PS_H_INCLUDED
#define GE_NAVIGATION_PS_H_INCLUDED

struct gSObstacleEvadeSwitch;
enum gEGotoStatus;
class gCPrefPath_PSObj;

class GE_DLLIMPORT gCNavigation_PS :
    public eCEntityPropertySet
{
    public:    virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                                   Write( bCOStream & );
    public:    virtual bEResult                                   Read( bCIStream & );
    public:    virtual void                                       Destroy( void );
    public:    virtual bEResult                                   Create( void );
    public:    virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public:    virtual                                           ~gCNavigation_PS( void );
    public:    virtual GEBool                                     OnNotifyPropertyValueChangedEnterEx( GELPCChar, GEBool );
    public:    virtual GEBool                                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
    public:    virtual GEBool                                     SupportsRenderDebugOutput( void ) const;
    public:    virtual bEResult                                   ReadSaveGame( bCIStream & );
    public:    virtual bEResult                                   WriteSaveGame( bCOStream & );
    public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public:    virtual void                                       OnSaveGameEntityPostRead( void );
    protected: virtual void                                       OnTouch( eCEntity *, eCContactIterator & );
    protected: virtual void                                       OnIntersect( eCEntity *, eCContactIterator & );
    protected: virtual void                                       OnUntouch( eCEntity *, eCContactIterator & );
    protected: virtual void                                       OnEnterProcessingRange( void );
    protected: virtual void                                       OnExitProcessingRange( void );
    public:    virtual void                                       OnRenderDebug( void );
    public:    virtual void                                       GetBoundary( bCBox &, GEBool );
    public:    virtual void                                       OnPreProcess( void );
    public:    virtual void                                       OnPostRead( void );
    public:    virtual void                                       OnPostCopy( eCEntityPropertySet const & );
    public:    virtual void                                       OnPropertySetAdded( void );
    public:    virtual void                                       OnPropertySetRemoved( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCNavigation_PS( gCNavigation_PS const & );
        gCNavigation_PS( void );

    public:
        gCNavigation_PS const & operator = ( gCNavigation_PS const & );

    public:
        gEDirection &                      AccessCurrentAniDirection( void );
        bTValArray<bCVector> &             AccessCurrentDestination( void );
        bTValArray<bCPropertyID> &         AccessCurrentDestinationID( void );
        eCEntityProxy &                    AccessCurrentDestinationPointProxy( void );
        bTValArray<bCMotion> &             AccessCurrentInterPose( void );
        bTValArray<gCNavPath_PS *> &       AccessCurrentNavPath( void );
        eCEntityProxy &                    AccessCurrentZoneEntityProxy( void );
        bTValArray<bCMotion> &             AccessDestination( void );
        bTValArray<bCVector> &             AccessEvade( void );
        GEU32 &                            AccessIsOnDestinationTimeStamp( void );
        bCPropertyID &                     AccessLastObstacleID( void );
        bCVector &                         AccessLastUseableNavigationPosition( void );
        bCPropertyID &                     AccessLastUseableNavigationZoneID( void );
        GEBool &                           AccessLastUseableNavigationZoneIsPath( void );
        eCEntityProxy &                    AccessLastZoneEntityProxy( void );
        gSObstacleEvadeSwitch &            AccessNPCEvadeSwitch( void );
        bTValArray<bCMotion> &             AccessNext( void );
        gSObstacleEvadeSwitch &            AccessObstacleEvadeSwitch( void );
        bTValArray<bCVector> &             AccessPassed( void );
        eCEntityProxy &                    AccessReachedTargetEntityProxy( void );
        bCPropertyID &                     AccessRelaxingPoint( void );
        bTValArray<bCPropertyID> &         AccessRelaxingPoints( void );
        bCString &                         AccessRoutine( void );
        bTObjArray<bCString> &             AccessRoutineNames( void );
        bCPropertyID &                     AccessSleepingPoint( void );
        bTValArray<bCPropertyID> &         AccessSleepingPoints( void );
        bCVector &                         AccessStartPosition( void );
        GEFloat &                          AccessUnderWaterDepth( void );
        eCEntityProxy &                    AccessWishedTargetEntityProxy( void );
        bCPropertyID &                     AccessWorkingPoint( void );
        bTValArray<bCPropertyID> &         AccessWorkingPoints( void );
        GEBool                             CanCorrectTarget( bCVector const & );
        GEBool                             FillNextForNavigationPath( bCVector const &, bCVector const & );
        GEBool                             FillNextForPreferredPath( void );
        gCCharacterMovement_PS *           GetCharacterMovement( void );
        gEDirection                        GetCurrentAniDirection( void ) const;
        bTValArray<bCVector> const &       GetCurrentDestination( void ) const;
        bTValArray<bCPropertyID> const &   GetCurrentDestinationID( void ) const;
        eCEntityProxy const &              GetCurrentDestinationPointProxy( void ) const;
        bTValArray<bCMotion> const &       GetCurrentInterPose( void ) const;
        bTValArray<gCNavPath_PS *> const & GetCurrentNavPath( void ) const;
        bCVector const &                   GetCurrentTarget( void ) const;
        eCEntityProxy const &              GetCurrentZoneEntityProxy( void ) const;
        gCDynamicCollisionCircle_PS *      GetDCC( void ) const;
        bTValArray<bCMotion> const &       GetDestination( void ) const;
        GEBool                             GetDontUseLimitedNavPaths( void );
        GEBool                             GetEnabled( void ) const;
        bTValArray<bCVector> const &       GetEvade( void ) const;
        GEBool const                       GetFinalTargetDetected( void ) const;
        bCMotion const &                   GetGoalPose( void );
        GEBool                             GetGoalReached( void );
        gEGotoStatus                       GetGotoStatus( void ) const;
        GEBool                             GetHasFinalTarget( void ) const;
        eCEntity *                         GetInteractObject( void ) const;
        GEBool                             GetIsOnDestination( void ) const;
        GEU32                              GetIsOnDestinationTimeStamp( void ) const;
        GEBool                             GetKilledByDeadlock( void ) const;
        GEInt const                        GetLastNegZoneStake( void ) const;
        bCPropertyID const &               GetLastObstacleID( void ) const;
        bCVector const &                   GetLastUseableNavPosition( void ) const;
        GEBool                             GetLastUseableNavZoneID( bCPropertyID & ) const;
        bCVector const &                   GetLastUseableNavigationPosition( void ) const;
        bCPropertyID const &               GetLastUseableNavigationZoneID( void ) const;
        GEBool const &                     GetLastUseableNavigationZoneIsPath( void ) const;
        eCEntityProxy const &              GetLastZoneEntityProxy( void ) const;
        gCNavPath_PS *                     GetNavigationPath( void ) const;
        GEBool                             GetNewInterPose( void );
        bTValArray<bCMotion> const &       GetNext( void ) const;
        gEDirection const                  GetNextAniDirection( void ) const;
        GEBool const                       GetOnTheWay( void ) const;
        bTValArray<bCVector> const &       GetPassed( void ) const;
        gCPrefPath_PSObj *                 GetPreferredPathPSObject( void ) const;
        eCEntityProxy const &              GetReachedTargetEntityProxy( void ) const;
        bCPropertyID const &               GetRelaxingPoint( void ) const;
        eCEntityProxy &                    GetRelaxingPointProxy( void );
        bTValArray<bCPropertyID> const &   GetRelaxingPoints( void ) const;
        bCString const &                   GetRoutine( void ) const;
        bTObjArray<bCString> const &       GetRoutineNames( void ) const;
        bCPropertyID const &               GetSleepingPoint( void ) const;
        eCEntityProxy &                    GetSleepingPointProxy( void );
        bTValArray<bCPropertyID> const &   GetSleepingPoints( void ) const;
        bCVector const &                   GetStartPosition( void ) const;
        GEFloat                            GetUnderWaterDepth( void ) const;
        gECharMovementMode                 GetWishedMovementMode( void ) const;
        eCEntityProxy const &              GetWishedTargetEntityProxy( void ) const;
        bCPropertyID const &               GetWorkingPoint( void ) const;
        eCEntityProxy &                    GetWorkingPointProxy( void );
        bTValArray<bCPropertyID> const &   GetWorkingPoints( void ) const;
        GEBool                             HasRoutinePointRoamOrPatrol( void );
        GEBool                             IsFoorDetectionFailed( void );
        GEBool                             IsInProcessingRange( void );
        void                               Reset( GEBool, GEBool, GEBool );
        GEBool                             RunSimpleMovement( void );
        void                               SetCharacterMovement( gCCharacterMovement_PS * );
        void                               SetCurrentAniDirection( gEDirection );
        void                               SetCurrentDestinationPointProxy( eCEntityProxy const & );
        void                               SetCurrentTarget( bCVector const & );
        void                               SetCurrentZoneEntityProxy( eCEntityProxy const & );
        void                               SetDCC( gCDynamicCollisionCircle_PS * );
        void                               SetEnabled( GEBool );
        void                               SetFinalTargetDetected( GEBool );
        void                               SetGoalPose( bCMotion const &, GEBool );
        void                               SetGoalReached( void );
        void                               SetGotoStatus( gEGotoStatus );
        void                               SetHasFinalTarget( GEBool );
        void                               SetInteractObject( eCEntity * );
        void                               SetIsOnDestination( GEBool );
        void                               SetIsOnDestinationTimeStamp( GEU32 );
        void                               SetKilledByDeadlock( GEBool );
        void                               SetLastNegZoneStake( GEInt );
        void                               SetLastUseableNavPosition( bCVector const & );
        void                               SetLastUseableNavZoneID( bCPropertyID const &, GEBool );
        void                               SetLastUseableNavigationPosition( bCVector const & );
        void                               SetLastUseableNavigationZoneID( bCPropertyID const & );
        void                               SetLastUseableNavigationZoneIsPath( GEBool const & );
        void                               SetLastZoneEntityProxy( eCEntityProxy const & );
        void                               SetNavigationPath( gCNavPath_PS * );
        void                               SetNewInterPose( GEBool );
        void                               SetNextAniDirection( gEDirection );
        void                               SetOnTheWay( GEBool );
        void                               SetPreferredPathPSObject( gCPrefPath_PSObj * );
        void                               SetReachedTargetEntityProxy( eCEntityProxy const & );
        void                               SetRelaxingPoint( bCPropertyID const & );
        void                               SetRelaxingPoints( bTValArray<bCPropertyID> const & );
        void                               SetRoutine( bCString const & );
        void                               SetRoutineNames( bTObjArray<bCString> const & );
        void                               SetSleepingPoint( bCPropertyID const & );
        void                               SetSleepingPoints( bTValArray<bCPropertyID> const & );
        void                               SetStartPosition( bCVector const & );
        void                               SetUnderWaterDepth( GEFloat );
        void                               SetWishedMovementMode( gECharMovementMode );
        void                               SetWishedTargetEntityProxy( eCEntityProxy const & );
        void                               SetWorkingPoint( bCPropertyID const & );
        void                               SetWorkingPoints( bTValArray<bCPropertyID> const & );
        GEBool                             TestNextOnPreferredPath( void );
        GEFloat                            TestPreferredPathUse( gCPrefPath_PSObj * );
        void                               UpdateInteractObject( void );
        void                               UpdateSimpleMovementTime( GEFloat, GEBool );
        void                               UpdateZoneIDs( void );

    protected:
        void GameReset( void );
        void Invalidate( void );

};

#endif
