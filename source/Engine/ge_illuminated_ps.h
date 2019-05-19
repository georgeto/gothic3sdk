#ifndef GE_ILLUMINATED_PS_H_INCLUDED
#define GE_ILLUMINATED_PS_H_INCLUDED

class eCShadowMapDirectionalLight;
class eCLightSet;
struct eSShaderMaterialIllumination;
class eCTerrainShadowMap;

GE_IMPORT_PROPERTY_SET( eCIlluminated_PS, eCEntityPropertySet )
    public:    virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    protected: virtual bEResult          Write( bCOStream & );
    protected: virtual bEResult          Read( bCIStream & );
    public:    virtual void              Destroy( void );
    public:    virtual bEResult          Create( void );
    public:    virtual bEResult          CopyFrom( bCObjectBase const & );
    public:    virtual                  ~eCIlluminated_PS( void );
    public:    virtual GEBool            IsReferencedByTemplate( void ) const;
    public:    virtual bEResult          PostInitializeProperties( void );
    public:    virtual GEBool            OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    protected: virtual void              OnUpdatedWorldMatrix( void );
    protected: virtual void              OnCacheIn( void );
    protected: virtual void              OnCacheOut( void );
    protected: virtual void              OnPropertySetAdded( void );
    protected: virtual void              OnPropertySetRemoved( void );

    public:

    private:
        static bTPropertyObject<eCIlluminated_PS, eCEntityPropertySet> ms_PropertyObjectInstance_eCIlluminated_PS;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        GE_IMPORT_DECLARE_PROPERTY( GEBool, EnableDynamicLighting, m_bEnableDynamicLighting )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, EnableAmbient,         m_bEnableAmbient )
        GE_PADDING( 2 )
        GE_IMPORT_DECLARE_ENUMPROP( eEStaticIlluminated, StaticIlluminated, m_eStaticIlluminated )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, CastShadows,   m_bCastShadows )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, ReciveShadows, m_bReciveShadows )
        GE_PADDING( 2 )
        GE_IMPORT_DECLARE_ENUMPROP( eEDirectionalShadowType, DirectionalShadowType, m_eDirectionalShadowType )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, ReciveTreeShadows,   m_bReciveTreeShadows )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, CastStaticShadows,   m_bCastStaticShadows )
        GE_IMPORT_DECLARE_PROPERTY( GEBool, ReciveStaticShadows, m_bReciveStaticShadows )
        GE_PADDING( 1 )

    public:
        eCIlluminated_PS( eCIlluminated_PS const & );
        eCIlluminated_PS( void );

    public:
        eCIlluminated_PS const & operator = ( eCIlluminated_PS const & );

    public:
        void                                 ClearStaticLightData( void );
        eCShadowMapDirectionalLight *        GetDirectionalShadowMap( void ) const;
        eCLightSet const *                   GetLightSet( void ) const;
        eSShaderMaterialIllumination &       GetShaderMaterialIllumination( void );
        eSShaderMaterialIllumination const & GetShaderMaterialIllumination( void ) const;
        eCTerrainShadowMap *                 GetTerrainShadowMap( void ) const;
        void                                 SetDSMOcclusionQuery( GELPVoid );
        void                                 SetDirectionalShadowMap( eCShadowMapDirectionalLight * );
        void                                 SetLightSet( eCLightSet * );
        void                                 UpdateIllumination( void );

    protected:
        void Invalidate( void );

    public:
        GE_PADDING( 9 )
        GEU8 m_uStaticLightCount;
        GE_PADDING( 2 )
        GEU8 m_StaticLightData[0x70]; // 7 x bCVector4
};

GE_ASSERT_SIZEOF( eCIlluminated_PS, 0xAC )

#endif
