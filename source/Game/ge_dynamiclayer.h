#ifndef GE_DYNAMICLAYER_H_INCLUDED
#define GE_DYNAMICLAYER_H_INCLUDED

class GE_DLLIMPORT gCDynamicLayer :
    public gCLayerBase
{
    public: using eCProcessibleElement::Create;
    public:    virtual eCProcessibleElement::eEResult Create( gCSector &, bCString const &, gEEntityType );
    protected: virtual GEU16                          GetVersion( void ) const;
    public:    virtual bEResult                       Create( void );
    public:    virtual                               ~gCDynamicLayer( void );
    public:    virtual bCString                       GetFileExt( void ) const;
    public:    virtual bCString                       GetFileType( void ) const;
    public:    virtual bCString                       GetDataFileExt( void ) const;
    public:    virtual bCString                       GetDataFileType( void ) const;
    public:    virtual GEU16                          GetFileVersion( void ) const;
    protected: virtual eCProcessibleElement::eEResult DoLoadData( bCIStream & );
    protected: virtual eCProcessibleElement::eEResult DoSaveData( bCOStream &, bCString const & );
    protected: virtual void                           OnModify( void );
    protected: virtual void                           OnActivate( void );
    protected: virtual void                           UpdateState( void );
    protected: virtual eCProcessibleElement::eEResult ReleaseData( void );
    protected: virtual bCPropertyObjectBase *         OnCreateContext( void );

    protected:
        static bCString const ms_strDynamicEntityLayer;
        static bCString const ms_strDynamicEntityTempLayer;

    public:
        static void GE_STDCALL                         GetDataFileExt( bCString & );
        static void GE_STDCALL                         GetFileExt( bCString & );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCDynamicLayer( gCDynamicLayer const & );
        gCDynamicLayer( void );

    public:
        gCDynamicLayer const & operator = ( gCDynamicLayer const & );

    public:
        bTPropertyContainer<gEEntityType> &       AccessEntityType( void );
        eCDynamicEntity *                         CreateDynamicEntity( bTObjArray<bCString> const & );
        eCDynamicEntity *                         CreateDynamicEntity( bCString const & );
        eCDynamicEntity *                         CreateDynamicEntity( void );
        eCEntityDynamicContext const &            GetEntityContext( void ) const;
        bTPropertyContainer<gEEntityType> const & GetEntityType( void ) const;
        GEBool                                    IsSysLayer( void ) const;
        GEBool                                    IsSysTempLayer( void ) const;
        void                                      SetEntityType( bTPropertyContainer<gEEntityType> const & );

    protected:
        static GEU32 GE_STDCALL      GetMagicCode1( void );
        static GEU32 GE_STDCALL      GetMagicCode2( void );
        static eCEntity * GE_STDCALL g_funcCreateCustomEntity( void );

    protected:
        eCEntityDynamicContext & GetEntityContext( void );

};

#endif
