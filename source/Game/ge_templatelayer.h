#ifndef GE_TEMPLATELAYER_H_INCLUDED
#define GE_TEMPLATELAYER_H_INCLUDED

class gCDatabase;

class GE_DLLIMPORT gCTemplateLayer :
    public gCLayerBase
{
    public: using eCProcessibleElement::Create;
    public:    virtual eCProcessibleElement::eEResult Create( gCDatabase &, bCString const & );
    public:    virtual GEBool                         IsValid( void ) const;
    public:    virtual bEResult                       Create( void );
    public:    virtual                               ~gCTemplateLayer( void );
    public:    virtual bCString                       GetFileExt( void ) const;
    public:    virtual bCString                       GetFileType( void ) const;
    public:    virtual bCString                       GetDataFileExt( void ) const;
    public:    virtual bCString                       GetDataFileType( void ) const;
    public:    virtual GEU16                          GetFileVersion( void ) const;
    protected: virtual eCProcessibleElement::eEResult DoLoadData( bCIStream & );
    protected: virtual eCProcessibleElement::eEResult DoSaveData( bCOStream &, bCString const & );
    protected: virtual void                           OnModify( void );
    protected: virtual void                           OnActivate( void );
    protected: virtual eCProcessibleElement::eEResult ReleaseData( void );
    protected: virtual bCPropertyObjectBase *         OnCreateContext( void );

    public:
        static void GE_STDCALL                         GetFileExt( bCString & );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCTemplateLayer( gCTemplateLayer const & );
        gCTemplateLayer( void );

    public:
        gCTemplateLayer const & operator = ( gCTemplateLayer const & );

    public:
        GEBool             ExistsFile( eCTemplateEntity const & ) const;
        gCDatabase &       GetDatabase( void );
        gCDatabase const & GetDatabase( void ) const;
        void               GetFileNames( bTObjArray<bCString> & ) const;
        eCTemplateEntity * GetTemplateEntity( bCString const & );
        bCString           GetTemplateEntityFileName( eCTemplateEntity const & ) const;
        GEBool             HasDatabase( void ) const;
        eCTemplateEntity * InsertNewTemplateEntity( eCTemplateEntity const &, GEBool );
        eCTemplateEntity * InsertNewTemplateEntity( eCDynamicEntity const &, GEBool, GEBool );
        eCTemplateEntity * InsertNewTemplateEntity( eCEntity const &, GEBool, GEBool );
        eCTemplateEntity * InsertNewTemplateEntity( eCSpatialEntity const &, GEBool, GEBool );
        eCTemplateEntity * InsertNewTemplateEntity( void );
        GEBool             IsReadOnly( eCTemplateEntity const & ) const;
        GEBool             IsReadOnly( void ) const;
        GEBool             ReadAll( void );
        GEBool             ReadHeaders( bCIStream & );
        GEBool             SaveHeaders( bCOStream & );
        void               SetDatabase( gCDatabase const * );

    private:
        gCSector &         GetSector( void );
        gCSector const &   GetSector( void ) const;
        eCTemplateEntity * GetTemplateEntity( eCTemplateEntity &, bCString const & );
        GEBool             HasSector( void ) const;
        void               SetSector( bCPropertyObjectBase const * );
        void               SetSector( gCSector const * );

};

#endif
