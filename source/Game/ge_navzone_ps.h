#ifndef GE_NAVZONE_PS_H_INCLUDED
#define GE_NAVZONE_PS_H_INCLUDED

class gCCollisionCircle_PSObj;

GE_IMPORT_PROPERTY_SET( gCNavZone_PS, eCEntityPropertySet )
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
        GE_IMPORT_DECLARE_PROPERTY( bTValArray<class bCVector>, Point, m_arrPoint )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, Radius, m_fRadius )
        GE_IMPORT_DECLARE_PROPERTY( bCVector, RadiusOffset, m_vecRadiusOffset )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, ZoneIsCCW, m_bZoneIsCCW )
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, TopToleranz, m_fTopToleranz )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat, BottomToleranz, m_fBottomToleranz )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, LinkInnerArea, m_bLinkInnerArea )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, LinkInnerTopArea, m_bLinkInnerTopArea )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, LinkInnerBottomArea, m_bLinkInnerBottomArea )
        GE_PADDING( 1 )

    public:
        bTValArray<GEFloat> m_TestStretch_PerPointFloat;
        int __UNK_004C;
        int __UNK_0050;
        int __UNK_0054;
        int __UNK_0058;
        int __UNK_005C;
        bCStretch m_TestStretch;
        bCVector2 m_TestStretchStart2D;
        bCVector2 m_TestStretchEnd2D;
        bCVector2 m_TestStretchVector2D;
        bCVector2 m_TestStretchOrthogonalOrSomething;
        float m_fInitWith_1_0;
        bCVector2 Intersect1_Vector;
        int Intersect1_StartPoint;
        int Intersect1_EndPoint;
        float m_fInitWith_MINUS0_0000099999997;
        bCVector2 Intersect2_Vector;
        int Intersect2_StartPoint;
        int Intersect2_EndPoint;
        void *m_pIntersectsStretch_Navigation;
        bTPtrArray<gCNegZone_PSObj *> m_arrNegZones;
        bTPtrArray<gCCollisionCircle_PSObj *> m_arrNegCircles;
        bTPtrArray<gCPrefPath_PSObj *> m_arrPrefPaths;
        int __UNK_00E8;
        int __UNK_00EC;
        int __UNK_00F0;
        float fMeanY;
        float fMaxYOffset;
        float fMinYOffset;
        unsigned __int32 m_uNetIndex;
        bCMatrix m_InverseWorldMatrix;
        int __UNK_0144;

    public:
        gCNavZone_PS( gCNavZone_PS const & );
        gCNavZone_PS( void );

    public:
        gCNavZone_PS const & operator = ( gCNavZone_PS const & );

    public:
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
        GEFloat                      GetCosts( bCVector const &, bCVector const & ) const;
        bCVector2 const &            GetEvade( GEBool );
        GEU32                        GetNetIndex( void );
        GEFloat                      GetZoneBottomHeight( void );
        GEFloat                      GetZoneTopHeight( void );
        GEBool                       IntersectsStretch( bCStretch const &, GEFloat &, gCNavigation_PS *, GEBool );
        GEBool                       IsZoneIllegal( void );
        void                         OnStakesChanged( void );
        bEResult                     RegisterCollisionCirclePSObject( gCCollisionCircle_PSObj * );
        bEResult                     RegisterDCCPS( gCDynamicCollisionCircle_PS * );
        bEResult                     RegisterNegZonePSObject( gCNegZone_PSObj * );
        bEResult                     RegisterPrefPathPSObject( gCPrefPath_PSObj * );
        GEBool                       SetFirstIntersection( GEFloat & );
        void                         SetNetIndex( GEU32 );
        GEBool                       Test3DPointInInternalNegZone( bCVector const & );
        // When the point lies on the segment between the last and the first point of the NavZone,
        // then a_bIncludeLastSegment is returned. Used for DCCs, but why?!
        GEBool                       Test3DPointInZone( bCVector const & a_Point, GEBool a_bIncludeLastSegment );
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

GE_ASSERT_SIZEOF( gCNavZone_PS, 0x148 )

#endif
