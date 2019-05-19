#ifndef GE_NAVPATH_PS_H_INCLUDED
#define GE_NAVPATH_PS_H_INCLUDED

class GE_DLLIMPORT gCNavPath_PS :
    public eCEntityPropertySet
{
    public:
        bTValArray<bCVector> m_arrPoint;
        bTValArray<GEFloat>  m_arrRadius;
        GEBool               m_bUnlimitedHeight;
        GE_PADDING( 3 )
        bCPropertyID m_ZoneAEntityID;
        bCPropertyID m_ZoneBEntityID;
        bCVector     m_ZoneAIntersectionMargin1;
        bCVector     m_ZoneAIntersectionMargin2;
        bCVector     m_ZoneAIntersectionCenter;
        bCVector     m_ZoneBIntersectionMargin1;
        bCVector     m_ZoneBIntersectionMargin2;
        bCVector     m_ZoneBIntersectionCenter;
        GEFloat      m_fTopToleranz;
        GEFloat      m_fBottomToleranz;
        GEBool       m_bLinkInnerArea;
        GEBool       m_bLinkInnerTopArea;
        GEBool       m_bLinkInnerBottomArea;
        GE_PADDING( 1 )
        bTPtrArray<gCDynamicCollisionCircle_PS *> m_arrDCCPS;
        GEBool m_bOpenStatus;
        GE_PADDING( 3 )
        GEU32 __UNK_00BC;
        GEU32           __UNK_00C0;
        GEU32           __UNK_00C4;
        GEUInt          m_uNetIndex;
        bCMatrix        field_CC;
        gEZoneType      m_enuZoneType;
        gESecurityLevel m_enuSecurityLevel;
        eCEntityProxy   m_Owner;
        GEU16           m_u16Version;
        GE_PADDING( 2 )

    public:    virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult          Write( bCOStream & );
    public:    virtual bEResult          Read( bCIStream & );
    public:    virtual void              Destroy( void );
    public:    virtual bEResult          Create( void );
    public:    virtual bEResult          CopyFrom( bCObjectBase const & );
    public:    virtual                  ~gCNavPath_PS( void );
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
        gCNavPath_PS( gCNavPath_PS const & );
        gCNavPath_PS( void );

    public:
        gCNavPath_PS const & operator = ( gCNavPath_PS const & );

    public:
        GEFloat &                    AccessBottomToleranz( void );
        GEBool &                     AccessLinkInnerArea( void );
        GEBool &                     AccessLinkInnerBottomArea( void );
        GEBool &                     AccessLinkInnerTopArea( void );
        bTValArray<bCVector> &       AccessPoint( void );
        bTValArray<GEFloat> &        AccessRadius( void );
        GEFloat &                    AccessTopToleranz( void );
        GEBool &                     AccessUnlimitedHeight( void );
        bCPropertyID &               AccessZoneAEntityID( void );
        bCVector &                   AccessZoneAIntersectionCenter( void );
        bCVector &                   AccessZoneAIntersectionMargin1( void );
        bCVector &                   AccessZoneAIntersectionMargin2( void );
        bCPropertyID &               AccessZoneBEntityID( void );
        bCVector &                   AccessZoneBIntersectionCenter( void );
        bCVector &                   AccessZoneBIntersectionMargin1( void );
        bCVector &                   AccessZoneBIntersectionMargin2( void );
        GEFloat                      CalcAbsHeightDiffFlagAndPrioFlag( bCVector const &, GEBool &, GEBool & );
        bCVector                     CalcNearestPathPoint( bCVector const & );
        bEResult                     CalcPathHeights( void );
        bEResult                     DeregisterDCCPS( gCDynamicCollisionCircle_PS * );
        GEFloat const &              GetBottomToleranz( void ) const;
        GEFloat                      GetCosts( bCVector const &, bCVector const & ) const;
        GEFloat                      GetCosts( void ) const;
        GEBool const &               GetLinkInnerArea( void ) const;
        GEBool const &               GetLinkInnerBottomArea( void ) const;
        GEBool const &               GetLinkInnerTopArea( void ) const;
        GEU32                        GetNetIndex( void );
        GEBool                       GetOpenStatus( void ) const;
        eCEntityProxy const &        GetOwner( void ) const;
        GEFloat                      GetPathBottomHeight( void );
        GEFloat                      GetPathTopHeight( void );
        bTValArray<bCVector> const & GetPoint( void ) const;
        bTValArray<GEFloat> const &  GetRadius( void ) const;
        gESecurityLevel              GetSecurityLevel( void ) const;
        GEFloat const &              GetTopToleranz( void ) const;
        GEBool const &               GetUnlimitedHeight( void ) const;
        bCPropertyID const &         GetZoneAEntityID( void ) const;
        bCVector const &             GetZoneAIntersectionCenter( void ) const;
        bCVector const &             GetZoneAIntersectionMargin1( void ) const;
        bCVector const &             GetZoneAIntersectionMargin2( void ) const;
        bCPropertyID const &         GetZoneBEntityID( void ) const;
        bCVector const &             GetZoneBIntersectionCenter( void ) const;
        bCVector const &             GetZoneBIntersectionMargin1( void ) const;
        bCVector const &             GetZoneBIntersectionMargin2( void ) const;
        gEZoneType                   GetZoneType( void ) const;
        bEResult                     RegisterDCCPS( gCDynamicCollisionCircle_PS * );
        void                         SetBottomToleranz( GEFloat const & );
        void                         SetLinkInnerArea( GEBool const & );
        void                         SetLinkInnerBottomArea( GEBool const & );
        void                         SetLinkInnerTopArea( GEBool const & );
        void                         SetNetIndex( GEU32 );
        void                         SetOpenStatus( GEBool );
        void                         SetOwner( eCEntityProxy const & );
        void                         SetPoint( bTValArray<bCVector> const & );
        void                         SetRadius( bTValArray<GEFloat> const & );
        void                         SetSecurityLevel( gESecurityLevel );
        void                         SetTopToleranz( GEFloat const & );
        void                         SetUnlimitedHeight( GEBool const & );
        void                         SetZoneAEntityID( bCPropertyID const & );
        void                         SetZoneAIntersectionCenter( bCVector const & );
        void                         SetZoneAIntersectionMargin1( bCVector const & );
        void                         SetZoneAIntersectionMargin2( bCVector const & );
        void                         SetZoneBEntityID( bCPropertyID const & );
        void                         SetZoneBIntersectionCenter( bCVector const & );
        void                         SetZoneBIntersectionMargin1( bCVector const & );
        void                         SetZoneBIntersectionMargin2( bCVector const & );
        void                         SetZoneType( gEZoneType );
        GEBool                       Test3DPointOnPath( bCVector const & );
        GEBool                       TestPointAgainstDCCs( bCVector const &, eCEntity const & );
        GEBool                       TestStretchOnPath( bCStretch const & );
        GEBool                       UseNavigationPath( bCVector const &, bCVector const &, bCMatrix &, GEInt &, GEInt & );

    protected:
        void GameReset( void );
        void Invalidate( void );

};

GE_ASSERT_SIZEOF( gCNavPath_PS, 0x134 );

#endif
