#ifndef GE_NEGZONE_PS_H_INCLUDED
#define GE_NEGZONE_PS_H_INCLUDED

GE_IMPORT_PROPERTY_SET( gCNegZone_PS, eCEntityPropertySet )
    public: virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult          Write( bCOStream & );
    public: virtual bEResult          Read( bCIStream & );
    public: virtual void              Destroy( void );
    public: virtual bEResult          Create( void );
    public: virtual bEResult          CopyFrom( bCObjectBase const & );
    public: virtual                  ~gCNegZone_PS( void );
    public: virtual eEPropertySetType GetPropertySetType( void ) const;
    public: virtual GEBool            IsReferencedByTemplate( void ) const;
    public: virtual void              GetBoundary( bCBox &, GEBool );
    public: virtual void              OnPropertySetAdded( void );
    public: virtual void              OnPropertySetRemoved( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        GE_IMPORT_DECLARE_PROPERTY( bTValArray<class bCVector>, Point,        m_arrPoint )
        GE_IMPORT_DECLARE_PROPERTY( GEFloat,                    Radius,       m_fRadius )
        GE_IMPORT_DECLARE_PROPERTY( bCVector,                   RadiusOffset, m_vecRadiusOffset )
        GE_IMPORT_DECLARE_PROPERTY( GEBool,                     ZoneIsCCW,    m_bZoneIsCCW )
        GE_PADDING( 3 )
        GE_IMPORT_DECLARE_PROPERTY( bCPropertyID, ZoneEntityID, m_ZoneEntityID )

    public:
        gCNegZone_PS( gCNegZone_PS const & );
        gCNegZone_PS( void );

    public:
        gCNegZone_PS const & operator = ( gCNegZone_PS const & );

    public:
        bEResult          AddLeftAndRightAngle( bCVector &, bCVector &, GEFloat &, GEFloat & );
        void              CreatePSObject( void );
        bEResult          GetAngleSums( GEFloat &, GEFloat & );
        gCNegZone_PSObj * GetPSObject( void ) const;
        GEBool            IsZoneIllegal( void );
        void              OnStakesChanged( void );
        GEBool            Test3DPointInZone( bCVector const &, GEBool );

    protected:
        void Invalidate( void );

};

#endif
