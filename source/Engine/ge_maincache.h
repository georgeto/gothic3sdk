#ifndef GE_MAINCACHE_H_INCLUDED
#define GE_MAINCACHE_H_INCLUDED

class eCAnimationCache;
class eCCollisionMeshCache;
class eCImageCache;
class eCMaterialCache;
class eCMeshCache;
class eCSoundCache;
class eCSpeedTreeCache;

class eCBaseCache
{
    public:
        enum eELoDQualityStage;
        enum eEUpdateCacheInfoOperation;
};

class GE_DLLIMPORT eCMainCache :
    public bCObjectRefBase
{
    public: virtual void     UpdateResourceInfo( eCResourceDataEntity const &, eCBaseCache::eEUpdateCacheInfoOperation );
    public: virtual GEU16    GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual bEResult CopyFrom( bCObjectBase const & );
    public: virtual         ~eCMainCache( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCMainCache( void );

    public:
        eCMainCache const & operator = ( eCMainCache const & );

    public:
        eCAnimationCache &     AccessAnimationCache( void );
        eCCollisionMeshCache & AccessCollisionMeshCache( void );
        GEBool &               AccessDisableThreading( void );
        eCImageCache &         AccessImageCache( void );
        eCMaterialCache &      AccessMaterialCache( void );
        eCMeshCache &          AccessMeshCache( void );
        eCSoundCache &         AccessSoundCache( void );
        eCSpeedTreeCache &     AccessSpeedTreeCache( void );
        GEBool                 CacheInResource( eCResourceDataEntity & );
        GEBool                 CacheOutResource( eCResourceDataEntity &, eEResourceCacheBehavior );
        GEBool                 ConvertResource( eCResourceDataEntity & );
        void                   GetCacheSizes( GEU32 &, GEU32 &, GEU32 &, GEU32 &, GEU32 &, GEU32 &, GEU32 & );
        GEBool const &         GetDisableThreading( void ) const;
        void                   Process( void );
        void                   PurgeCaches( GEBool );
        void                   PurgeImageCache( GEBool );
        GEBool                 ReleaseMemory( GEU32, eCResourceBase_PS::eECacheType );
        GEU32                  RequestMemory( GEU32, eCResourceBase_PS::eECacheType );
        GEBool                 SaveResource( eCResourceDataEntity & );
        void                   SetCacheSizes( GEU32, GEU32, GEU32, GEU32, GEU32, GEU32, GEU32 );
        void                   SetDisableThreading( GEBool const & );
        void                   WaitForEmptyThreadQues( void );

    protected:
        eCMainCache( eCMainCache const & );

    protected:
        void Invalidate( void );

};

#endif
