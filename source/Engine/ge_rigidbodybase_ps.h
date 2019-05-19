#ifndef GE_RIGIDBODYBASE_PS_H_INCLUDED
#define GE_RIGIDBODYBASE_PS_H_INCLUDED

enum eEForceMode;

class GE_DLLIMPORT eCRigidBodyBase_PS :
    public eCEntityPropertySet
{

    //FIXME: In VTable1 aber nicht in Exports enthalten: 0x00033720 - ?OnSaveGameEntityPostRead@eCEntityPropertySet@@UAEXXZ
    //FIXME: Doppelt in VTable1 enthalten: 0x00033720 - ?OnSaveGameEntityPostRead@eCEntityPropertySet@@UAEXXZ
    //FIXME: Doppelt in VTable1 enthalten: 0x00033720 - ?OnSaveGameEntityPostRead@eCEntityPropertySet@@UAEXXZ
    //public: virtual void OnSaveGameEntityPostRead( void );


    //FIXME: In VTable1 aber nicht in Exports enthalten: 0x00033720 - ?OnSaveGameEntityPostRead@eCEntityPropertySet@@UAEXXZ
    //FIXME: Doppelt in VTable1 enthalten: 0x00033720 - ?OnSaveGameEntityPostRead@eCEntityPropertySet@@UAEXXZ
    //public: virtual void OnSaveGameEntityPostRead( void );


    //FIXME: In VTable1 aber nicht in Exports enthalten: 0x00033720 - ?OnSaveGameEntityPostRead@eCEntityPropertySet@@UAEXXZ
    //FIXME: Doppelt in VTable1 enthalten: 0x00033720 - ?OnSaveGameEntityPostRead@eCEntityPropertySet@@UAEXXZ
    //public: virtual void OnSaveGameEntityPostRead( void );

    public: virtual void         SetLinearMomentum( bCVector const & );
    public: virtual void         SetLinearVelocity( bCVector const & );
    public: virtual void         SetMass( GEFloat const & );
    public: virtual void         SetMassSpaceInertiaTensor( bCVector const & );
    public: virtual void         SetPose( bCMatrix const & );
    public: virtual void         SetPosition( bCVector const & );
    public: virtual void         SetRotation( bCMatrix3 const & );
    public: virtual void         SetRotation( bCQuaternion const & );
    public: virtual bCVector     GetAngularMomentum( void ) const;
    public: virtual bCVector     GetMassSpaceInertiaTensor( void ) const;
    public: virtual bCMatrix3    GetRotation( void ) const;
    public: virtual bCQuaternion GetRotationQuat( void ) const;
    public: virtual bCVector     GetAngularVelocity( void ) const;
    public: virtual bCVector     GetCenterOfGravity( void ) const;
    public: virtual bCVector     GetLinearMomentum( void ) const;
    public: virtual bCVector     GetPosition( void ) const;

        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //protected: void AddControls( struct eIDispatch * );

    public: virtual GEFloat GetMass( void ) const;

        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //protected: void AddControls( struct eIDispatch * );

    public: virtual bCVector GetLinearVelocity( void ) const;

        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //protected: void AddControls( struct eIDispatch * );

    public: virtual bCMatrix GetPose( void ) const;

        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x0020E240 - ?OnIntersect@eCEntityPropertySet@@MAEXPAVeCEntity@@AAVeCContactIterator@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x0020E240 - ?OnIntersect@eCEntityPropertySet@@MAEXPAVeCEntity@@AAVeCContactIterator@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x0020E240 - ?OnIntersect@eCEntityPropertySet@@MAEXPAVeCEntity@@AAVeCContactIterator@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x0020E240 - ?OnIntersect@eCEntityPropertySet@@MAEXPAVeCEntity@@AAVeCContactIterator@@@Z
        //protected: virtual void OnIntersect( eCEntity *, eCContactIterator & );


        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x0020E240 - ?OnIntersect@eCEntityPropertySet@@MAEXPAVeCEntity@@AAVeCContactIterator@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x0020E240 - ?OnIntersect@eCEntityPropertySet@@MAEXPAVeCEntity@@AAVeCContactIterator@@@Z
        //protected: virtual void OnIntersect( eCEntity *, eCContactIterator & );


        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x0020E240 - ?OnIntersect@eCEntityPropertySet@@MAEXPAVeCEntity@@AAVeCContactIterator@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x0020E240 - ?OnIntersect@eCEntityPropertySet@@MAEXPAVeCEntity@@AAVeCContactIterator@@@Z
        //protected: virtual void OnIntersect( eCEntity *, eCContactIterator & );


        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x0020E240 - ?OnIntersect@eCEntityPropertySet@@MAEXPAVeCEntity@@AAVeCContactIterator@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x0020E240 - ?OnIntersect@eCEntityPropertySet@@MAEXPAVeCEntity@@AAVeCContactIterator@@@Z
        //protected: virtual void OnIntersect( eCEntity *, eCContactIterator & );

    public: virtual void AddRelForceAtPos( bCVector const &, bCVector const &, eEForceMode );
    public: virtual void AddRelForceAtRelPos( bCVector const &, bCVector const &, eEForceMode );

        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x001B1A90 - ?OnMenuProfileSound@eCPerformanceAdmin@@IAGXPAVbCObjectRefBase@@PAVbCEvent@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x001B1A90 - ?OnMenuProfileSound@eCPerformanceAdmin@@IAGXPAVbCObjectRefBase@@PAVbCEvent@@@Z
        //protected: void __stdcall eCPerformanceAdmin::OnMenuProfileSound( bCObjectRefBase *, bCEvent * );


        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x001B1A90 - ?OnMenuProfileSound@eCPerformanceAdmin@@IAGXPAVbCObjectRefBase@@PAVbCEvent@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x001B1A90 - ?OnMenuProfileSound@eCPerformanceAdmin@@IAGXPAVbCObjectRefBase@@PAVbCEvent@@@Z
        //protected: void __stdcall eCPerformanceAdmin::OnMenuProfileSound( bCObjectRefBase *, bCEvent * );


        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //protected: void AddControls( struct eIDispatch * );


        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x00214E50 - ?IsProcessing@eCContextBase@@UBE_NXZ
    public: virtual GEBool IsProcessing( void ) const;


        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //FIXME: Doppelt in VTable1 enthalten: 0x00276700 - ?AddControls@eCObjectInspectorDlg@@IAEXPAUeIDispatch@@@Z
        //protected: void AddControls( struct eIDispatch * );


        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x0020F6A0 - ?LoadConfigFiles@eCApplication@@UAE_NXZ
    public: virtual GEBool LoadConfigFiles( void );

    public:    virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult          Write( bCOStream & );
    public:    virtual bEResult          Read( bCIStream & );
    public:    virtual void              Destroy( void );
    public:    virtual bEResult          Create( void );
    public:    virtual bEResult          CopyFrom( bCObjectBase const & );
    public:    virtual                  ~eCRigidBodyBase_PS( void );
    public:    virtual GEBool            GetGravityEnabled( void ) const;
    public:    virtual bEResult          PostInitializeProperties( void );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    public:    virtual GEBool            GetIsSleeping( void ) const;
    public:    virtual GEBool            IsEditorRelevant( void ) const;
    protected: virtual void              OnProcess( void );
    public:    virtual void              AddForceAtPos( bCVector const &, bCVector const &, eEForceMode );
    public:    virtual void              AddForce( bCVector const &, eEForceMode );
    public:    virtual void              AddRelForce( bCVector const &, eEForceMode );
    public:    virtual void              AddRelTorque( bCVector const &, eEForceMode );
    public:    virtual void              AddTorque( bCVector const &, eEForceMode );
    public:    virtual void              SetAngularMomentum( bCVector const & );
    public:    virtual void              SetAngularVelocity( bCVector const & );
    public:    virtual void              SetCenterOfGravity( bCVector const & );
    public:    virtual void              StopRotation( void );
    public:    virtual void              SetGravityEnabled( GEBool );
    public:    virtual void              AddForceAtRelPos( bCVector const &, bCVector const &, eEForceMode );
    public:    virtual void              SetIsSleeping( GEBool );

        //FIXME: In Exports aber nicht in VTable enthalten: 0x00273440 - ?IsEditorRelevant@eCRigidBodyBase_PS@@UBE_NXZ - public: virtual GEBool IsEditorRelevant(void)const

        //FIXME: In Exports aber nicht in VTable enthalten: 0x00033720 - ?StopMotion@eCRigidBodyBase_PS@@UAEXXZ - public: virtual void StopMotion(void)

        //FIXME: In Exports aber nicht in VTable enthalten: 0x00033720 - ?StopMovement@eCRigidBodyBase_PS@@UAEXXZ - public: virtual void StopMovement(void)

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCRigidBodyBase_PS( eCRigidBodyBase_PS const & );
        eCRigidBodyBase_PS( void );

    public:
        eCRigidBodyBase_PS const & operator = ( eCRigidBodyBase_PS const & );

    public:
        GEBool &       AccessPhysicsEnabled( void );
        GEBool const & GetPhysicsEnabled( void ) const;
        void           SetPhysicsEnabled( GEBool const & );

    protected:
        void Invalidate( void );

};

#endif
