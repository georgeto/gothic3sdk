#ifndef GE_GEOMETRYLAYER_H_INCLUDED
#define GE_GEOMETRYLAYER_H_INCLUDED

class GE_DLLIMPORT gCGeometryLayer :
    public gCLayerBase
{
    public: using eCProcessibleElement::Create;
    public:    virtual eCProcessibleElement::eEResult Create( gCSector &, gEGeometryType, bCString const & );
    public:    virtual bEResult                       Create( void );
    public:    virtual                               ~gCGeometryLayer( void );
    public:    virtual GEBool                         IsDataAvailable( void ) const;
    public:    virtual bCString                       GetFileExt( void ) const;
    public:    virtual bCString                       GetFileType( void ) const;
    public:    virtual bCString                       GetDataFileExt( void ) const;
    public:    virtual bCString                       GetDataFileType( void ) const;
    public:    virtual GEU16                          GetFileVersion( void ) const;
    protected: virtual eCProcessibleElement::eEResult DoLoadData( bCIStream & );
    protected: virtual eCProcessibleElement::eEResult DoSaveData( bCOStream &, bCString const & );
    protected: virtual void                           OnModify( void );
    public:    virtual void                           UpdateState( void );
    public:    virtual eCProcessibleElement::eEResult Activate( void );
    protected: virtual eCProcessibleElement::eEResult ReleaseData( void );
    public:    virtual bCString                       GetLayerCategory( void ) const;
    protected: virtual bCPropertyObjectBase *         OnCreateContext( void );

    public:
        static void GE_STDCALL                         GetFileExt( bCString & );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCGeometryLayer( gCGeometryLayer const & );
        gCGeometryLayer( void );

    public:
        gCGeometryLayer const & operator = ( gCGeometryLayer const & );

    public:
        bTPropertyContainer<gEGeometryType> &       AccessGeometryType( void );
        bCString &                                  AccessOriginImportName( void );
        eCSpatialEntity *                           CreateSpatialEntity( eCSpatialEntity * );
        bTPropertyContainer<gEGeometryType> const & GetGeometryType( void ) const;
        bCString const &                            GetOriginImportName( void ) const;
        void                                        SetGeometryType( bTPropertyContainer<gEGeometryType> const & );
        void                                        SetOriginImportName( bCString const & );
        void                                        UnloadCaches( void );

};

#endif
