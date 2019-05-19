#ifndef GE_RESOURCEADMIN_H_INCLUDED
#define GE_RESOURCEADMIN_H_INCLUDED

class eCResourceStorageContext;
struct eSResourceStatistics;

class GE_DLLIMPORT eCResourceAdmin :
    public eCEngineComponentBase
{
    public: virtual GEU16          GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult       Write( bCOStream & );
    public: virtual bEResult       Read( bCIStream & );
    public: virtual void           Destroy( void );
    public: virtual bEResult       Create( void );
    public: virtual bEResult       CopyFrom( bCObjectBase const & );
    public: virtual               ~eCResourceAdmin( void );
    public: virtual bCGuid const & GetID( void ) const;
    public: virtual bEResult       PostInitialize( void );
    public: virtual bEResult       PreShutdown( void );
    public: virtual void           Process( void );

    public:
        static eCBaseCache::eELoDQualityStage GE_STDCALL GetEnumLoDQualityValue( bCString const & );
        static bCPropertyObjectBase const * GE_STDCALL   GetRootObject( void );

    public:
        eCResourceAdmin( void );

    public:
        eCResourceAdmin const & operator = ( eCResourceAdmin const & );

    public:
        eCMainCache &                    GetMainCache( void );
        eSResourceStatistics const &     GetResourceStatistics( void );
        eCResourceStorageContext &       GetStorageContext( void );
        eCResourceStorageContext const & GetStorageContext( void ) const;
        GEBool                           IsEditorModeEnabled( void ) const;
        eCResourceDataEntity *           QueryNewResourceDataEntity( void );
        eCResourceDataEntity *           QueryResourceDataEntity( bCString const &, eEResourceCacheBehavior );

    protected:
        eCResourceAdmin( eCResourceAdmin const & );

    protected:
        void EnableEditorMode( GEBool );
        void Invalidate( void );

};

#endif
