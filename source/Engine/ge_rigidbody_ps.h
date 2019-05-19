#ifndef GE_RIGIDBODY_PS_H_INCLUDED
#define GE_RIGIDBODY_PS_H_INCLUDED

class GE_DLLIMPORT eCRigidBody_PS :
    public eCRigidBodyBase_PS
{
    public: virtual bCVector GetPivotVelocity( void ) const;
    public: virtual bCVector GetPointVelocity( bCVector const & ) const;
    public: virtual bCVector GetLocalPointVelocity( bCVector const & ) const;
    public: virtual void     AddBodyFlag( eERigidbody_Flag );
    public: virtual void     RemoveBodyFlag( eERigidbody_Flag );
    public: virtual GEBool   ContainsBodyFlag( eERigidbody_Flag ) const;
    public: virtual void     EnableMovementControlByAI( GEBool, GEBool, GEBool );
    public: virtual GEBool   IsMovementControledByAI( void ) const;
    public: virtual GEBool   UpdateEntityIfControlledByAI( void ) const;
    public: virtual GEU16    GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );

        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x001EF030 - ?CopyFrom@eCIteratorAdmin@@UAE?AW4bEResult@@ABVbCObjectBase@@@Z
    public: virtual bEResult CopyFrom( bCObjectBase const & );

    public:    virtual         ~eCRigidBody_PS( void );
    public:    virtual bEResult PostInitializeProperties( void );
    protected: virtual GEBool   OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );

        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x0020F6A0 - ?LoadConfigFiles@eCApplication@@UAE_NXZ
    public: virtual GEBool LoadConfigFiles( void );

    public:    virtual GEBool       IsEditorRelevant( void ) const;
    protected: virtual void         OnEnterProcessingRange( void );
    protected: virtual void         OnExitProcessingRange( void );
    protected: virtual void         OnUpdatedWorldMatrix( void );
    public:    virtual void         GetBoundary( bCBox &, GEBool );
    protected: virtual void         OnPropertySetAdded( void );
    public:    virtual void         StopMotion( void );
    public:    virtual void         StopRotation( void );
    public:    virtual void         StopMovement( void );
    public:    virtual void         SetPosition( bCVector const & );
    public:    virtual void         SetPose( bCMatrix const & );
    public:    virtual void         SetRotation( bCQuaternion const & );
    public:    virtual void         SetRotation( bCMatrix3 const & );
    public:    virtual void         SetLinearVelocity( bCVector const & );
    public:    virtual void         SetAngularVelocity( bCVector const & );
    public:    virtual void         SetLinearMomentum( bCVector const & );
    public:    virtual void         SetAngularMomentum( bCVector const & );
    public:    virtual bCVector     GetPosition( void ) const;
    public:    virtual bCMatrix     GetPose( void ) const;
    public:    virtual bCMatrix3    GetRotation( void ) const;
    public:    virtual bCQuaternion GetRotationQuat( void ) const;
    public:    virtual bCVector     GetLinearVelocity( void ) const;
    public:    virtual bCVector     GetAngularVelocity( void ) const;
    public:    virtual bCVector     GetLinearMomentum( void ) const;
    public:    virtual bCVector     GetAngularMomentum( void ) const;
    public:    virtual void         SetMass( GEFloat const & );
    public:    virtual GEFloat      GetMass( void ) const;
    public:    virtual void         SetCenterOfGravity( bCVector const & );
    public:    virtual bCVector     GetCenterOfGravity( void ) const;
    public:    virtual void         SetMassSpaceInertiaTensor( bCVector const & );
    public:    virtual bCVector     GetMassSpaceInertiaTensor( void ) const;
    public:    virtual void         AddForce( bCVector const &, eEForceMode );
    public:    virtual void         AddTorque( bCVector const &, eEForceMode );
    public:    virtual void         AddRelForce( bCVector const &, eEForceMode );
    public:    virtual void         AddRelTorque( bCVector const &, eEForceMode );
    public:    virtual void         AddForceAtPos( bCVector const &, bCVector const &, eEForceMode );
    public:    virtual void         AddForceAtRelPos( bCVector const &, bCVector const &, eEForceMode );
    public:    virtual void         AddRelForceAtPos( bCVector const &, bCVector const &, eEForceMode );
    public:    virtual void         AddRelForceAtRelPos( bCVector const &, bCVector const &, eEForceMode );
    public:    virtual void         SetGravityEnabled( GEBool );
    public:    virtual GEBool       GetGravityEnabled( void ) const;
    public:    virtual void         SetIsSleeping( GEBool );
    public:    virtual GEBool       GetIsSleeping( void ) const;

        //FIXME: In Exports aber nicht in VTable enthalten: 0x0020F6A0 - ?IsPhysicRelevant@eCRigidBody_PS@@UBE_NXZ - public: virtual GEBool IsPhysicRelevant(void)const

        //FIXME: In Exports aber nicht in VTable enthalten: 0x00033720 - ?OnPostRead@eCRigidBody_PS@@MAEXXZ - protected: virtual void OnPostRead(void)

        //FIXME: In Exports aber nicht in VTable enthalten: 0x001F4840 - ?SetEntity@eCRigidBody_PS@@UAEXPAVeCEntity@@@Z - public: virtual void SetEntity(eCEntity *)

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCRigidBody_PS( eCRigidBody_PS const & );
        eCRigidBody_PS( void );

    public:
        eCRigidBody_PS const & operator = ( eCRigidBody_PS const & );

    public:
        GEFloat &                                     AccessAngularDamping( void );
        bTPropertyContainer<eERigidbody_Flag> &       AccessBodyFlag( void );
        GEFloat &                                     AccessCCDMotionTreshold( void );
        bCVector &                                    AccessCenterOfMass( void );
        GEFloat &                                     AccessLinearDamping( void );
        bCVector &                                    AccessMassSpaceInertia( void );
        GEFloat &                                     AccessMaxAngularVelocity( void );
        bCVector &                                    AccessStartAngularVelocity( void );
        bCVector &                                    AccessStartForce( void );
        bCVector &                                    AccessStartTorque( void );
        bCVector &                                    AccessStartVelocity( void );
        GEFloat &                                     AccessTotalMass( void );
        GEFloat &                                     AccessWakeUpCounter( void );
        GEFloat const &                               GetAngularDamping( void ) const;
        bTPropertyContainer<eERigidbody_Flag> const & GetBodyFlag( void ) const;
        GEFloat const &                               GetCCDMotionTreshold( void ) const;
        bCVector const &                              GetCenterOfMass( void ) const;
        GEFloat const &                               GetLinearDamping( void ) const;
        GEFloat                                       GetLocalTimeScale( void ) const;
        bCVector const &                              GetMassSpaceInertia( void ) const;
        GEFloat const &                               GetMaxAngularVelocity( void ) const;
        bCVector const &                              GetStartAngularVelocity( void ) const;
        bCVector const &                              GetStartForce( void ) const;
        bCVector const &                              GetStartTorque( void ) const;
        bCVector const &                              GetStartVelocity( void ) const;
        GEFloat const &                               GetTotalMass( void ) const;
        GEFloat const &                               GetWakeUpCounter( void ) const;
        void                                          SetAngularDamping( GEFloat const & );
        void                                          SetBodyFlag( bTPropertyContainer<eERigidbody_Flag> const & );
        void                                          SetCCDMotionTreshold( GEFloat const & );
        void                                          SetCenterOfMass( bCVector const & );
        void                                          SetFixedStepTranslation( bCVector const & );
        void                                          SetFixedYStep( GEFloat );
        void                                          SetLinearDamping( GEFloat const & );
        void                                          SetLocalTimeScale( GEFloat );
        void                                          SetMassSpaceInertia( bCVector const & );
        void                                          SetMaxAngularVelocity( GEFloat const & );
        void                                          SetMoverGoal( bCVector const &, GEFloat );
        void                                          SetStartAngularVelocity( bCVector const & );
        void                                          SetStartForce( bCVector const & );
        void                                          SetStartTorque( bCVector const & );
        void                                          SetStartVelocity( bCVector const & );
        void                                          SetTotalMass( GEFloat const & );
        void                                          SetWakeUpCounter( GEFloat const & );

    protected:
        GEBool       GetIsSleepingToggled( void ) const;
        GEBool       GetMoverGoalReached( void ) const;
        bCQuaternion GetStepRotation( GEFloat );
        bCVector     GetStepTranslation( GEFloat );
        void         Invalidate( void );
        void         ProcessMovement( void );
        void         SaveStep( void );
        void         SetActor( NxActor * );
        void         SetIsSleepingToggled( GEBool );

};

#endif
