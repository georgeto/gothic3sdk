#ifndef GE_CHARACTERSENSOR_PS_H_INCLUDED
#define GE_CHARACTERSENSOR_PS_H_INCLUDED

enum gESoftCollisionState;

class GE_DLLIMPORT gCCharacterSensor_PS :
    public eCEntityPropertySet
{
    public:    virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult          Write( bCOStream & );
    public:    virtual bEResult          Read( bCIStream & );
    public:    virtual void              Destroy( void );
    public:    virtual bEResult          Create( void );
    public:    virtual bEResult          CopyFrom( bCObjectBase const & );
    public:    virtual                  ~gCCharacterSensor_PS( void );
    public:    virtual bEResult          PostInitializeProperties( void );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    protected: virtual void              GetBoundary( bCBox &, GEBool );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCCharacterSensor_PS( gCCharacterSensor_PS const & );
        gCCharacterSensor_PS( void );

    public:
        gCCharacterSensor_PS const & operator = ( gCCharacterSensor_PS const & );

    public:
        GEBool       GetGoalChanged( void ) const;
        bCQuaternion GetGoalRotation( void ) const;
        bCVector     GetPosition( void ) const;
        bCVector     GetUnsmoothedPosition( void ) const;
        void         SetGoalPose( bCMotion const &, GEBool );
        void         SetGoalPosition( bCVector const &, GEBool );
        void         SetGoalRotation( bCQuaternion const & );

    protected:
        void                 ClearVolatileFrameStates( void );
        void                 Invalidate( void );
        GEBool               IsHeightDifferenceValid( GEFloat ) const;
        void                 MessageDebug( GELPCChar ) const;
        void                 PostProcessMovements( void );
        void                 ProcessPlayerMovements( void );
        void                 SaveFrameStates( void );
        void                 SetMovement_PS( gCCharacterMovement_PS & );
        void                 ShowDebug( void );
        void                 SmoothGoal( bCVector const & );
        gESoftCollisionState TestSoftCollisions( bCVector const &, bCVector const &, GEFloat, bCVector const &, bCVector & );

};

#endif
