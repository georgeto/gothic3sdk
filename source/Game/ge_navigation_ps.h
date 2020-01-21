#ifndef GE_NAVIGATION_PS_H_INCLUDED
#define GE_NAVIGATION_PS_H_INCLUDED

enum gEGotoStatus;
class gCPrefPath_PSObj;

GE_IMPORT_PROPERTY_SET( gCNavigation_PS, eCEntityPropertySet )
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
        struct gSObstacleEvadeSwitch
        {
            bCPropertyID m_Evade;
            GEBool m_bValid;
        };

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        GE_IMPORT_DECLARE_PROPERTY( bCVector, StartPosition, m_vecStartPosition )
        GE_IMPORT_DECLARE_PROPERTY( bCPropertyID, WorkingPoint, m_WorkingPoint )
        GE_IMPORT_DECLARE_PROPERTY( bCPropertyID, RelaxingPoint, m_RelaxingPoint )
        GE_IMPORT_DECLARE_PROPERTY( bCPropertyID, SleepingPoint, m_SleepingPoint )
        GE_IMPORT_DECLARE_PROPERTY( bCString, Routine, m_strRoutine )
        GE_IMPORT_DECLARE_PROPERTY( bTValArray<class bCPropertyID>, WorkingPoints, m_arrWorkingPoints )
        GE_IMPORT_DECLARE_PROPERTY( bTValArray<class bCPropertyID>, RelaxingPoints, m_arrRelaxingPoints )
        GE_IMPORT_DECLARE_PROPERTY( bTValArray<class bCPropertyID>, SleepingPoints, m_arrSleepingPoints )
        GE_IMPORT_DECLARE_PROPERTY( bTObjArray<class bCString>, RoutineNames, m_arrRoutineNames )
        GE_IMPORT_DECLARE_PROPERTY( eCEntityProxy, CurrentDestinationPointProxy, m_CurrentDestinationPointProxy )
        GE_IMPORT_DECLARE_PROPERTY( eCEntityProxy, CurrentZoneEntityProxy, m_CurrentZoneEntityProxy )
        GE_IMPORT_DECLARE_PROPERTY( eCEntityProxy, LastZoneEntityProxy, m_LastZoneEntityProxy )
        GE_IMPORT_DECLARE_PROPERTY( bCVector, LastUseableNavigationPosition, m_vecLastUseableNavigationPosition )
        GE_IMPORT_DECLARE_PROPERTY( bCPropertyID, LastUseableNavigationZoneID, m_LastUseableNavigationZoneID )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, LastUseableNavigationZoneIsPath, m_bLastUseableNavigationZoneIsPath )

    public:
        GEBool                   m_bIsOnDestination;
        GE_PADDING( 2 )
        GEInt                    m_IsOnDestinationTimeStamp;
        bTValArray<bCMotion>     m_arrDestination;
        bTValArray<bCVector>     m_arrEvade;
        bCPropertyID             m_LastObstacleID;
        bTValArray<bCMotion>     m_arrNext;
        bTValArray<bCVector>     m_arrPassed;
        eCEntityProxy            m_WishedTargetEntityProxy;
        eCEntityProxy            m_ReachedTargetEntityProxy;
        gEDirection              m_enuCurrentAniDirection;
        GEFloat                  m_fUnderWaterDepth;
        bTValArray<bCVector>     m_arrCurrentDestination;
        bTValArray<bCPropertyID> m_arrCurrentDestinationID;
        bTPtrArray<gCNavPath_PS> m_arrCurrentNavPath;
        bCVector                 m_CurrentTarget;
        bTValArray<bCMotion>     m_arrCurrentInterPose;
        GEInt                    m_iLastNegZoneStake;
        GEBool                   m_bOnTheWay;
        GEBool                   m_bFinalTargetDetected;
        GE_PADDING( 2 )
        gCPrefPath_PSObj *       m_pPreferredPathPSObject;
        GELPVoid                 m_pNavigationPath;
        GELPVoid                 m_DCC;
        gCCharacterMovement_PS * m_pCharacterMovement;
        GEChar                   __UNK_01E4;
        GEBool                   m_bIsInProcessingRange;
        GEBool                   m_bIsFoorDetectionFailed;
        GE_PADDING( 1 )
        GEUInt                   m_uTimeSinceLastRunNPCNavigation;
        bCMotion                 m_GoalPose;
        GEBool                   m_bGoalPoseSet;
        GEBool                   m_bGoalNotReached;
        GE_PADDING( 2 )
        gEDirection              m_enuNextAniDirection;
        GEChar                   __UNK_0210;
        GEBool                   m_bNewInterPose;
        GE_PADDING( 2 )
        GELPVoid                 m_pInteractObject;
        gECharMovementMode       m_enuWishedMovementMode;
        gEGotoStatus             m_enuGotoStatus;
        GEBool                   m_bHasFinalTarget;
        GE_PADDING( 3 )
        gSObstacleEvadeSwitch    m_ObstacleEvadeSwitch;
        gSObstacleEvadeSwitch    m_NPCEvadeSwitch;
        GEBool                   m_bEnabled;
        GEBool                   m_bKilledByDeadlock;
        GE_PADDING( 2 )
        eCEntityProxy            m_WorkingPointProxy;
        eCEntityProxy            m_RelaxingPointProxy;
        eCEntityProxy            m_SleepingPointProxy;

    public:
        gCNavigation_PS( gCNavigation_PS const & );
        gCNavigation_PS( void );

    public:
        gCNavigation_PS const & operator = ( gCNavigation_PS const & );

    public:
        gEDirection &                      AccessCurrentAniDirection( void );
        bTValArray<bCVector> &             AccessCurrentDestination( void );
        bTValArray<bCPropertyID> &         AccessCurrentDestinationID( void );
        bTValArray<bCMotion> &             AccessCurrentInterPose( void );
        bTValArray<gCNavPath_PS *> &       AccessCurrentNavPath( void );
        bTValArray<bCMotion> &             AccessDestination( void );
        bTValArray<bCVector> &             AccessEvade( void );
        GEU32 &                            AccessIsOnDestinationTimeStamp( void );
        bCPropertyID &                     AccessLastObstacleID( void );
        gSObstacleEvadeSwitch &            AccessNPCEvadeSwitch( void );
        bTValArray<bCMotion> &             AccessNext( void );
        gSObstacleEvadeSwitch &            AccessObstacleEvadeSwitch( void );
        bTValArray<bCVector> &             AccessPassed( void );
        eCEntityProxy &                    AccessReachedTargetEntityProxy( void );
        GEFloat &                          AccessUnderWaterDepth( void );
        eCEntityProxy &                    AccessWishedTargetEntityProxy( void );
        GEBool                             CanCorrectTarget( bCVector const & );
        GEBool                             FillNextForNavigationPath( bCVector const &, bCVector const & );
        GEBool                             FillNextForPreferredPath( void );
        gCCharacterMovement_PS *           GetCharacterMovement( void );
        gEDirection                        GetCurrentAniDirection( void ) const;
        bTValArray<bCVector> const &       GetCurrentDestination( void ) const;
        bTValArray<bCPropertyID> const &   GetCurrentDestinationID( void ) const;
        bTValArray<bCMotion> const &       GetCurrentInterPose( void ) const;
        bTValArray<gCNavPath_PS *> const & GetCurrentNavPath( void ) const;
        bCVector const &                   GetCurrentTarget( void ) const;
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
        gCNavPath_PS *                     GetNavigationPath( void ) const;
        GEBool                             GetNewInterPose( void );
        bTValArray<bCMotion> const &       GetNext( void ) const;
        gEDirection const                  GetNextAniDirection( void ) const;
        GEBool const                       GetOnTheWay( void ) const;
        bTValArray<bCVector> const &       GetPassed( void ) const;
        gCPrefPath_PSObj *                 GetPreferredPathPSObject( void ) const;
        eCEntityProxy const &              GetReachedTargetEntityProxy( void ) const;
        eCEntityProxy &                    GetRelaxingPointProxy( void );
        eCEntityProxy &                    GetSleepingPointProxy( void );
        GEFloat                            GetUnderWaterDepth( void ) const;
        gECharMovementMode                 GetWishedMovementMode( void ) const;
        eCEntityProxy const &              GetWishedTargetEntityProxy( void ) const;
        eCEntityProxy &                    GetWorkingPointProxy( void );
        GEBool                             HasRoutinePointRoamOrPatrol( void );
        GEBool                             IsFoorDetectionFailed( void );
        GEBool                             IsInProcessingRange( void );
        void                               Reset( GEBool, GEBool, GEBool );
        GEBool                             RunSimpleMovement( void );
        void                               SetCharacterMovement( gCCharacterMovement_PS * );
        void                               SetCurrentAniDirection( gEDirection );
        void                               SetCurrentTarget( bCVector const & );
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
        void                               SetNavigationPath( gCNavPath_PS * );
        void                               SetNewInterPose( GEBool );
        void                               SetNextAniDirection( gEDirection );
        void                               SetOnTheWay( GEBool );
        void                               SetPreferredPathPSObject( gCPrefPath_PSObj * );
        void                               SetReachedTargetEntityProxy( eCEntityProxy const & );
        void                               SetUnderWaterDepth( GEFloat );
        void                               SetWishedMovementMode( gECharMovementMode );
        void                               SetWishedTargetEntityProxy( eCEntityProxy const & );
        GEBool                             TestNextOnPreferredPath( void );
        GEFloat                            TestPreferredPathUse( gCPrefPath_PSObj * );
        void                               UpdateInteractObject( void );
        void                               UpdateSimpleMovementTime( GEFloat, GEBool );
        void                               UpdateZoneIDs( void );

    protected:
        void GameReset( void );
        void Invalidate( void );

};

GE_ASSERT_SIZEOF( gCNavigation_PS, 0x2AC )

#endif
