#ifndef GE_NAVZONE_PS_H_INCLUDED
#define GE_NAVZONE_PS_H_INCLUDED

class GE_DLLIMPORT gCNavZone_PS :
    public eCEntityPropertySet
{
    public:    virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult          Write( bCOStream & );
    public:    virtual bEResult          Read( bCIStream & );
    public:    virtual void              Destroy( void );
    public:    virtual bEResult          Create( void );
    public:    virtual bEResult          CopyFrom( bCObjectBase const & );
    public:    virtual                  ~gCNavZone_PS( void );
    public:    virtual bEResult          PostInitializeProperties( void );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    public:    virtual GEBool            IsReferencedByTemplate( void ) const;
    protected: virtual void              OnTouch( eCEntity *, eCContactIterator & );
    protected: virtual void              OnIntersect( eCEntity *, eCContactIterator & );
    protected: virtual void              OnUntouch( eCEntity *, eCContactIterator & );
    public:    virtual void              GetBoundary( bCBox &, GEBool );
    public:    virtual void              OnPostRead( void );
    public:    virtual void              OnPropertySetAdded( void );
    public:    virtual void              OnPropertySetRemoved( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCNavZone_PS( gCNavZone_PS const & );
        gCNavZone_PS( void );

    public:
        gCNavZone_PS const & operator = ( gCNavZone_PS const & );

    public:
        GEFloat &                    AccessBottomToleranz( void );
        GEBool &                     AccessLinkInnerArea( void );
        GEBool &                     AccessLinkInnerBottomArea( void );
        GEBool &                     AccessLinkInnerTopArea( void );
        bTValArray<bCVector> &       AccessPoint( void );
        GEFloat &                    AccessRadius( void );
        bCVector &                   AccessRadiusOffset( void );
        GEFloat &                    AccessTopToleranz( void );
        GEBool &                     AccessZoneIsCCW( void );
        void                         AddCollisionCircleOffset( bTValArray<bCMotion> &, bCVector const &, bCVector const &, GEBool );
        bEResult                     BuildClusterLists( void );
        GEFloat                      CalcAbsHeightDiffFlagAndPrioFlag( bCVector const &, GEBool &, GEBool & );
        bEResult                     CalcZoneHeights( void );
        bEResult                     DeregisterCollisionCirclePSObject( gCCollisionCircle_PSObj * );
        bEResult                     DeregisterDCCPS( gCDynamicCollisionCircle_PS * );
        bEResult                     DeregisterNegZonePSObject( gCNegZone_PSObj * );
        bEResult                     DeregisterPrefPathPSObject( gCPrefPath_PSObj * );
        GEBool                       DetectCollisionCircleExit( gCNavigation_PS *, bCVector & );
        void                         DynAttachCollisionCirclePSObj( gCCollisionCircle_PSObj * );
        void                         DynDeattachCollisionCirclePSObj( gCCollisionCircle_PSObj * );
        bCVector const &             Get3DEvade( GEBool );
        GEFloat const &              GetBottomToleranz( void ) const;
        GEFloat                      GetCosts( bCVector const &, bCVector const & ) const;
        bCVector2 const &            GetEvade( GEBool );
        GEBool const &               GetLinkInnerArea( void ) const;
        GEBool const &               GetLinkInnerBottomArea( void ) const;
        GEBool const &               GetLinkInnerTopArea( void ) const;
        GEU32                        GetNetIndex( void );
        bTValArray<bCVector> const & GetPoint( void ) const;
        GEFloat const &              GetRadius( void ) const;
        bCVector const &             GetRadiusOffset( void ) const;
        GEFloat const &              GetTopToleranz( void ) const;
        GEFloat                      GetZoneBottomHeight( void );
        GEBool const &               GetZoneIsCCW( void ) const;
        GEFloat                      GetZoneTopHeight( void );
        GEBool                       IntersectsStretch( bCStretch const &, GEFloat &, gCNavigation_PS *, GEBool );
        GEBool                       IsZoneIllegal( void );
        void                         OnStakesChanged( void );
        bEResult                     RegisterCollisionCirclePSObject( gCCollisionCircle_PSObj * );
        bEResult                     RegisterDCCPS( gCDynamicCollisionCircle_PS * );
        bEResult                     RegisterNegZonePSObject( gCNegZone_PSObj * );
        bEResult                     RegisterPrefPathPSObject( gCPrefPath_PSObj * );
        void                         SetBottomToleranz( GEFloat const & );
        GEBool                       SetFirstIntersection( GEFloat & );
        void                         SetLinkInnerArea( GEBool const & );
        void                         SetLinkInnerBottomArea( GEBool const & );
        void                         SetLinkInnerTopArea( GEBool const & );
        void                         SetNetIndex( GEU32 );
        void                         SetPoint( bTValArray<bCVector> const & );
        void                         SetRadius( GEFloat const & );
        void                         SetRadiusOffset( bCVector const & );
        void                         SetTopToleranz( GEFloat const & );
        void                         SetZoneIsCCW( GEBool const & );
        GEBool                       Test3DPointInInternalNegZone( bCVector const & );
        GEBool                       Test3DPointInZone( bCVector const &, GEBool );
        GEBool                       TestPointAgainstCollCircles( bCVector const &, GEBool, GEBool *, GEBool );
        GEBool                       TestPointAgainstDCCs( bCVector const &, eCEntity const & );
        GEBool                       TestPointAgainstNegZones( bCVector const &, GEBool );
        GEBool                       TestStretchAgainstCollCircles( bCStretch const &, GEBool, GEBool );
        GEBool                       TestStretchAgainstNegZones( bCStretch const & );
        GEBool                       TestStretchInZone( bCStretch const & );

    protected:
        bEResult AddLeftAndRightAngle( bCVector &, bCVector &, GEFloat &, GEFloat & );
        void     GameReset( void );
        bEResult GetAngleSums( GEFloat &, GEFloat & );
        void     Invalidate( void );

};

#endif
