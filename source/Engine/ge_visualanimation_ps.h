#ifndef GE_VISUALANIMATION_PS_H_INCLUDED
#define GE_VISUALANIMATION_PS_H_INCLUDED

typedef bCString bCAnimationResourceString;
class eCSpringAndDamperEffector;
class eCEffector;
class eCResourceAnimationMotion_PS;
struct eSSubSkeleton;
class eCVisualAnimationLipSync;
struct eSEntityLoDInfoDesc;
struct SStatus;

GE_IMPORT_PROPERTY_SET( eCVisualAnimation_PS, eCEntityPropertySet )
    public:    virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                                   Write( bCOStream & );
    public:    virtual bEResult                                   Read( bCIStream & );
    public:    virtual void                                       Destroy( void );
    public:    virtual bEResult                                   Create( void );
    public:    virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public:    virtual                                           ~eCVisualAnimation_PS( void );
    public:    virtual bEResult                                   PostInitializeProperties( void );
    protected: virtual GEBool                                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    protected: virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public:    virtual GEBool                                     HasRenderAlphaComponent( void ) const;
    public:    virtual GEBool                                     IsProcessable( void ) const;
    public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
    public:    virtual GEBool                                     IsVisual( void ) const;
    public:    virtual GEBool                                     SupportsRenderDebugOutput( void ) const;
    public:    virtual eCRenderContext *                          QueryRenderContext( void );
    protected: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public:    virtual void                                       OnPostRead( void );
    public:    virtual void                                       GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    public:    virtual eCVisualAnimation_PS *                     Clone( eCEntity * ) const;
    protected: virtual void                                       OnEnterProcessingRange( void );
    protected: virtual void                                       OnExitProcessingRange( void );
    public:    virtual void                                       GetOnScreenDebugLines( GEU32, bTObjArray<eSPropertySetDebugLine> & ) const;
    public:    virtual void                                       OnDeinitialize( void );
    protected: virtual void                                       OnUpdateInternals( void );
    protected: virtual void                                       OnPostUpdateInternals( void );
    public:    virtual void                                       OnPreProcess( void );
    public:    virtual void                                       OnCacheIn( void );
    public:    virtual void                                       OnCacheOut( void );
    public:    virtual void                                       GetBoundary( bCBox &, GEBool );
    public:    virtual void                                       OnProcess( void );
    public:    virtual void                                       OnChildrenAvailable( GEU32, GEU32, eCTemplateEntity * );
    public:    virtual GEBool                                     IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;

    private:
        static bTPropertyObject<eCVisualAnimation_PS, eCEntityPropertySet> ms_PropertyObjectInstance_eCVisualAnimation_PS;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        GE_IMPORT_DECLARE_PROPERTY( bCAnimationResourceString, ResourceFilePath,         m_strResourceFilePath )
        GE_IMPORT_DECLARE_PROPERTY( bCAnimationResourceString, FacialAnimFilePath,       m_strFacialAnimFilePath )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,                    PhysicsControled,         m_bIsPhysicsControled )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,                    ConstrainRootToWorld,     m_bConstrainRootToWorld )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,                    InterBoneCollision,       m_bInterBoneCollision )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,                    SkeletonCollisionEnabled, m_bSkeletonCollisionEnabled )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,                    BoneRaycastsEnabled,      m_bBoneRaycastsEnabled )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,                    BonesAreBreakable,        m_bBonesAreBreakable )
        GE_PADDING( 2 )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BonesBreakMaxForce,     m_fBonesBreakMaxForce )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BonesBreakMaxTorque,    m_fBonesBreakMaxTorque )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BoneLinearDamping,      m_fBoneLinearDamping )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BoneAngularDamping,     m_fBoneAngularDamping )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,  BoneTwistSpringEnabled, m_bBoneTwistSpringEnabled )
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BoneTwistSpring,        m_fBoneTwistSpring )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BoneTwistSpringDamping, m_fBoneTwistSpringDamping )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,  BoneSwingSpringEnabled, m_bBoneSwingSpringEnabled )
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BoneSwingSpring,        m_fBoneSwingSpring )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BoneSwingSpringDamping, m_fBoneSwingSpringDamping )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,  BoneJointSpringEnabled, m_bBoneJointSpringEnabled )
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BoneJointSpring,        m_fBoneJointSpring )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BoneJointSpringDamping, m_fBoneJointSpringDamping )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BoneProjectionDistance, m_fBoneProjectionDistance )
        GE_IMPORT_DECLARE_ENUMPROP( eEShapeGroup,     BoneShapeGroup,     m_enuBoneShapeGroup )
        GE_IMPORT_DECLARE_ENUMPROP( eEShapeMaterial,  BoneShapeMaterial,  m_enuBoneShapeMaterial )
        GE_IMPORT_DECLARE_ENUMPROP( eECollisionGroup, SkeletonShapeGroup, m_enuSkeletonShapeGroup )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, SpringParentNodesOnly, m_bSpringParentNodesOnly )
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, SpringParentNodesScale, m_fSpringParentNodeScale )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,  CreateSpringMassCloth,  m_bCreateSpringMassCloth )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,  DisablePhysicLodding,   m_bDisablePhysicLodding )
        GE_PADDING( 2 )
        GE_PADDING( 0x10 ) // GE_IMPORT_DECLARE_PROPERTY( (bTPropertyObject<eCSpringAndDamperEffector, eCEffector>), ClothEffector,  m_poClothEffector )
        GE_IMPORT_DECLARE_PROPERTY( GEInt, MaterialSwitch, m_iMaterialSwitch )

    public:
        class eCActorAttachment
        {
            public:                ~eCActorAttachment( void );
                                    eCActorAttachment( eCActorAttachment const & );
                                    eCActorAttachment( eCVisualAnimation_PS * );
                eCActorAttachment & operator = ( eCActorAttachment const & );
                void                Create( eCEntity *, bCString const &, bCMatrix const *, GEU32, GEBool );
                void                Destroy( void );
                void                ForceRelinkNode( void );
                eCEntity *          GetEntity( void );
                GEBool              IsEntityValid( void );
                GEBool              Process( GEU32 );
                GEBool              ProcessOnce( void );
                void                Read( bCIStream &, GEU16 );
                void                Write( bCOStream & );
        };

        class eCLookAtConstraint
        {
            public:                 ~eCLookAtConstraint( void );
                                     eCLookAtConstraint( eCLookAtConstraint const & );
                                     eCLookAtConstraint( eCVisualAnimation_PS * );
                eCLookAtConstraint & operator = ( eCLookAtConstraint const & );
                void                 Create( bCString const &, bCVector const &, bCVector const &, GEFloat );
                void                 Destroy( void );
                void                 Enable( GEBool );
                void                 ForceRelinkNode( void );
                void                 GetConstraints( bCVector &, bCVector &, GEFloat & ) const;
                bCString const &     GetNodeName( void ) const;
                void                 Read( bCIStream & );
                GEBool               SetTargetPos( bCVector const & );
                void                 Write( bCOStream & );
        };

        class eSMotionDesc
        {
            public:
                enum eEMotionOwner;

            public:                                 ~eSMotionDesc( void );
                                                     eSMotionDesc( eSMotionDesc const & );
                                                     eSMotionDesc( bCString const & );
                                                     eSMotionDesc( eCResourceAnimationMotion_PS * );
                                                     eSMotionDesc( eCResourceDataEntity * );
                                                     eSMotionDesc( void );
                eSMotionDesc const &                 operator =  ( eSMotionDesc const & );
                bCOStream &                          operator >> ( bCOStream & );
                bCIStream &                          operator << ( bCIStream & );
                eCResourceAnimationMotion_PS *       GetMotion( void );
                eCResourceAnimationMotion_PS const * GetMotion( void ) const;
                bCString const &                     GetMotionFilename( void ) const;
                eEMotionOwner                        GetMotionOwner( void ) const;
                GEBool                               IsValid( void ) const;
                void                                 SetMotion( bCString const & );
                void                                 SetMotion( eCResourceAnimationMotion_PS * );
                void                                 SetMotion( eCResourceDataEntity * );
                void                                 SetMotionOwner( eEMotionOwner );
        };


    public:
        eCVisualAnimation_PS( eCVisualAnimation_PS const & );
        eCVisualAnimation_PS( void );

    public:
        eCVisualAnimation_PS const & operator = ( eCVisualAnimation_PS const & );

    public:
        GEBool                                  AddAttachment( eCEntity *, bCString const &, bCMatrix const *, GEU32, GEBool );
        GEBool                                  AddBodyPart( eCEntity *, bCString const &, GEBool );
        void                                    AddForceAtPos( bCVector, bCVector );
        GEBool                                  AddOnceAttachment( eCEntity *, bCString const & );
        GEBool                                  ClearAttachments( void );
        GEBool                                  ClearLookAtConstraints( void );
        GEBool                                  ClearOnceAttachments( void );
        GEU32                                   CountSubSkeletons( bTPtrArray<EMotionFX::Node *> * );
        void                                    CreatePhysicsController( GEBool, eCVisualAnimation_PS * );
        void                                    DestroyPhysicsController( void );
        void                                    DisablePhysicsController( GEBool );
        void                                    EnableAutoAiming( GEBool, eCEntity *, bCString & );
        void                                    EnableSkeletonCollision( GEBool );
        void                                    EnableSkeletonCollisionWith( eCEntity *, GEBool );
        eCWrapper_emfx2Actor *                  GetActor( void );
        eCWrapper_emfx2Actor const *            GetActor( void ) const;
        eCVisualAnimationFactory &              GetAnimationFactory( void );
        eCVisualAnimationFactory const &        GetAnimationFactory( void ) const;
        GEBool                                  GetBoneMatrix( bCString const &, bCMatrix & );
        GEBool                                  GetBoneMatrix( GEInt, bCMatrix & );
        eCVisualAnimation_PS *                  GetChildByActor( NxActor * );
        GEU16                                   GetCurrentLoDLevel( void ) const;
        GEBool                                  GetDebugMode( void );
        GEFloat                                 GetLastAutoAimAngle( void );
        GEFloat                                 GetLocalTimeScale( void ) const;
        GEBool                                  GetLookAtConstraintAt( int, bCString &, bCVector &, bCVector &, GEFloat & ) const;
        GEInt                                   GetLookAtConstraintCount( void ) const;
        eCWrapper_emfx2Motion &                 GetMotion( eCWrapper_emfx2Actor::eEMotionType );
        eSMotionDesc const &                    GetMotionDesc( eCWrapper_emfx2Actor::eEMotionType );
        eSMotionDesc::eEMotionOwner             GetMotionOwner( eCWrapper_emfx2Actor::eEMotionType ) const;
        GEU32                                   GetNumAttachments( void );
        EMotionFX::eCNovodexPhysicsController * GetRagDollController( void );
        GEBool                                  GetRagDollEnabled( void ) const;
        GEBool                                  GetShowSkeleton( void );
        bCBox const &                           GetSkeletonBoundary( void ) const;
        bTObjArray<eSSubSkeleton> *             GetSubSkeletons( void );
        GEBool                                  HasActor( void ) const;
        GEBool                                  HasMotion( eCWrapper_emfx2Actor::eEMotionType ) const;
        GEInt                                   IntersectPhysicsRayNearestHit( bCUnitedRay const &, GEFloat &, bCString * ) const;
        GEBool                                  IsAutoAimingEnabled( void ) const;
        GEBool                                  IsBodyPartVisible( bCString const & );
        void                                    PausePhysicsController( GEBool, GEFloat );
        GEBool                                  PlayFacialMotion( eCResourceAnimationMotion_PS *, eCVisualAnimationLipSync * );
        void                                    PlayMotion( eCWrapper_emfx2Actor::eEMotionType, eCWrapper_emfx2Motion::eSMotionDesc * );
        void                                    ProcessPhysicsLOD( void );
        GEBool                                  RelinkAttachments( void );
        GEBool                                  RelinkLookAtConstraints( void );
        GEBool                                  RemoveAttachment( eCEntity * );
        GEBool                                  RemoveBodyPart( eCEntity *, bCString const & );
        GEBool                                  RemoveLookAtConstraint( bCString const & );
        GEBool                                  RemoveOnceAttachment( eCEntity * );
        GEBool                                  SetBodyPartVisible( bCString const &, GEBool );
        void                                    SetDebugMode( GEBool );
        void                                    SetForceAlwaysVisible( GEBool );
        void                                    SetLocalTimeScale( GEFloat );
        GEBool                                  SetLookAtConstraint( bCString const &, bCVector const &, bCVector const &, GEFloat );
        void                                    SetLookAtTarget( eCEntity * );
        void                                    SetLookAtTarget( eCEntity *, bCString const & );
        void                                    SetMotion( eCWrapper_emfx2Actor::eEMotionType, eCResourceAnimationMotion_PS * );
        void                                    SetMotion( eCWrapper_emfx2Actor::eEMotionType, eCResourceDataEntity * );
        void                                    SetMotionOwner( eCWrapper_emfx2Actor::eEMotionType, eSMotionDesc::eEMotionOwner );
        void                                    SetRagDollEnabled( GEBool, GEFloat, GEBool );
        void                                    SetShowSkeleton( GEBool );
        void                                    StopAtLoopEnd( eCWrapper_emfx2Actor::eEMotionType );
        GEBool                                  StopFacialMotion( void );
        void                                    StopMotion( eCWrapper_emfx2Actor::eEMotionType, GEFloat );
        void                                    StopRagDoll( void );
        void                                    UpdateAim( void );
        void                                    UpdateLoD( eSEntityLoDInfoDesc const * );

    protected:
        void DrawSkeleton( void );
        void GameReset( void );
        void GetStatus( SStatus & );
        void Invalidate( void );
        void PlayAni_Debug( bCString, bCString, GEFloat );
        void ShowDebug( void );
        void StopAni_Debug( void );
        void UpdateFrameEffects( void );
};

#endif
