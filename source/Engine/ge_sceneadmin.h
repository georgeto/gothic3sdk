#ifndef GE_SCENEADMIN_H_INCLUDED
#define GE_SCENEADMIN_H_INCLUDED

struct eSTriggerConfig;
enum eEGetEntityTypeHint
{
    eEGetEntityTypeHint_Entity             = 0,
    eEGetEntityTypeHint_ResourceDataEntity = 1,
    eEGetEntityTypeHint_TemplateEntity     = 2
};

class GE_DLLIMPORT eCSceneAdmin :
    public eCEngineComponentBase
{
    public: virtual GEU16          GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult       Write( bCOStream & );
    public: virtual bEResult       Read( bCIStream & );
    public: virtual void           Destroy( void );
    public: virtual bEResult       Create( void );
    public: virtual bEResult       CopyFrom( bCObjectBase const & );
    public: virtual               ~eCSceneAdmin( void );
    public: virtual bCGuid const & GetID( void ) const;
    public: virtual bEResult       Shutdown( void );
    public: virtual void           Process( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCSceneAdmin( void );

    public:
        eCSceneAdmin const & operator = ( eCSceneAdmin const & );

    public:
        GEBool                                                      CheckIfEntityNameExists( bCString const & ) const;
        void                                                        ClearRegisteredEntities( void );
        eCEntityAdmin &                                             GetAccessToEntityAdmin( void );
        eCEntityDynamicContext *                                    GetDynamicEntityContext( GEInt ) const;
        GEInt                                                       GetDynamicEntityContextCount( void ) const;
        GEBool                                                      GetEntitiesByName( bCString const &, bTPtrArray<eCEntity *> & );
        GEBool                                                      GetEntitiesByName( bCString const &, bTPtrArray<eCEntity *> & ) const;
        eCNode *                                                    GetEntity( bCPropertyID const &, eEGetEntityTypeHint );
        eCNode const *                                              GetEntity( bCPropertyID const &, eEGetEntityTypeHint ) const;
        eCEntity *                                                  GetEntityByName( bCString const & );
        eCEntity const *                                            GetEntityByName( bCString const & ) const;
        eCEntity *                                                  GetEntityByPartName( bCString const &, eEGetEntityTypeHint, GEInt a_iIndex = -1 );
        GEInt                                                       GetEntityCountByPartName( bCString const &, eEGetEntityTypeHint );
        GEInt                                                       GetNumEntitiesByName( bCString const & ) const;
        GEU32                                                       GetNumberOfDynamicEntities( void ) const;
        GEU32                                                       GetNumberOfStaticEntities( void ) const;
        eCGeometrySpatialContext *                                  GetSpatialContext( GEInt ) const;
        GEInt                                                       GetSpatialContextCount( void ) const;
        GEInt                                                       GetTemplateEntitiesByName( bCString const &, bTPtrArray<eCTemplateEntity *> & );
        eCTemplateEntity *                                          GetTemplateEntityByName( bCString const & );
        GEBool                                                      GetUniqueEntityByName( bCString const &, eCEntity * & ) const;
        bCBox const &                                               GetWorldBox( void ) const;
        GEBool                                                      IsEditorModeEnabled( void ) const;
        GEBool                                                      RegisterNameInfo( bCString const &, eCEntity const & );
        GEBool                                                      RegisterNameInfo( bCString const &, eCTemplateEntity const & );
        bTValMap<bCPropertyID, eCTemplateEntity *>::bCConstIterator TemplateEntitiesBegin( void ) const;
        bTValMap<bCPropertyID, eCTemplateEntity *>::bCConstIterator TemplateEntitiesEnd( void ) const;
        GEBool                                                      Trigger( bCString &, eSTriggerConfig & );
        GEBool                                                      UnregisterNameInfo( bCString const &, eCEntity const & );
        GEBool                                                      UnregisterNameInfo( bCString const &, eCTemplateEntity const & );

    protected:
        static GEInt GE_CCALL S_CompareEntityNames( GELPCVoid, GELPCVoid );

    protected:
        eCSceneAdmin( eCSceneAdmin const & );

    protected:
        GEBool CanBeTriggered( eCEntity &, eSTriggerConfig & ) const;
        void   EnableEditorMode( GEBool );
        void   Invalidate( void );
        GEBool RegisterDynamicEntityContext( eCEntityDynamicContext & );
        GEBool RegisterEntity( eCEntity * );
        GEBool RegisterResourceDataEntity( eCResourceDataEntity * );
        GEBool RegisterSpatialContext( eCGeometrySpatialContext & );
        GEBool RegisterTemplateEntity( eCTemplateEntity * );
        GEBool UnregisterDynamicEntityContext( eCEntityDynamicContext & );
        GEBool UnregisterEntity( eCEntity * );
        GEBool UnregisterResourceDataEntity( eCResourceDataEntity * );
        GEBool UnregisterSpatialContext( eCGeometrySpatialContext & );
        GEBool UnregisterTemplateEntity( eCTemplateEntity * );
    public:
        bTPtrMap<bCPropertyID, eCEntity *> m_mapEntities;
        bTPtrMap<bCPropertyID, eCResourceDataEntity *> m_mapResourceDataEntities;
        bTPtrMap<bCPropertyID, eCTemplateEntity *> m_mapTemplateEntities;
        bTPtrMap<bCString, bTPtrArray<eCEntity *>> m_mapNameInfoEntities;
        bTPtrMap<bCString, bTPtrArray<eCTemplateEntity *>> m_mapNameInfoTemplateEntities;
        GEBool m_bIsEditorModeEnabled;
        GE_PADDING( 3 )
        eCEntityAdmin m_EntityAdmin;
        GEU32 m_uNumberOfStaticEntities;
        GEU32 m_uNumberOfDynamicEntities;
        bTPtrArray<eCGeometrySpatialContext *> m_arrGeometrySpatialContexts;
        bCBox m_WorldBox;
};

GE_ASSERT_SIZEOF( eCSceneAdmin, 0x194 )

#endif
