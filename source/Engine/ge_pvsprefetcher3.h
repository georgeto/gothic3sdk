#ifndef GE_PVSPREFETCHER3_H_INCLUDED
#define GE_PVSPREFETCHER3_H_INCLUDED

class GE_DLLIMPORT eCPVSPrefetcher3 :
    public bCObjectRefBase
{
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual bEResult CopyFrom( bCObjectBase const & );
    public: virtual         ~eCPVSPrefetcher3( void );

    public:
        typedef GEBool (GE_STDCALL * eCPVSPrefetcher3::gFContextCacheOutCallback)( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCPVSPrefetcher3( eCPVSPrefetcher3 const & );
        eCPVSPrefetcher3( void );

    public:
        eCPVSPrefetcher3 const & operator = ( eCPVSPrefetcher3 const & );

    public:
        GEBool                          AddNewEntity( eCEntity * );
        GEBool                          CacheIn( eCEntity * );
        void                            CacheOut( void );
        GEBool                          CacheOut( eCEntity * );
        void                            ClearCells( eCFrustumDatabase & );
        void                            EnablePrefetcher( GEBool );
        void                            ForcePrefetch( void );
        bCPoint                         GetAllCellIndices( eCFrustumDatabase & ) const;
        void                            GetAllValidCells( bTSmallArray<eCPVSCellItem *> & );
        GEU32                           GetCachedInStaticContexts( void );
        GEU32                           GetCachedInStaticContextsFileMem( void );
        gFContextCacheOutCallback const GetContextCacheOutCallback( eCGeometrySpatialContext * );
        GEU32                           GetDeltaFrameTime( void ) const;
        eCPVSCellItem *                 GetNonDeactivationCell( void );
        void                            GetValidCells( eCFrustumDatabase &, bTSmallArray<eCPVSCellItem *> & );
        GEI32                           GetWorldMaximumRadius( void ) const;
        GEBool                          IsJobRunning( void ) const;
        GEBool                          Process( eCFrustumDatabase & );
        GEBool                          Recalibrate( bCVector const &, eCEntity * );
        GEBool                          RemoveNewAddedEntity( eCEntity * );
        void                            SetContextCacheOutCallback( GEBool ( GE_STDCALL* )( eCGeometrySpatialContext * ));
        void                            WaitForEmptyThreadQueue( void );

    protected:
        void   CalculateRectIndices( eCFrustumDatabase &, bCSphere const &, bCRect & );
        void   Execute( eCFrustumDatabase &, bCSphere const & );
        void   Invalidate( void );
        GEBool RecalculateGrid( eCFrustumDatabase &, bCSphere const &, bTSmallArray<eCPVSCellItem *> & );

};

#endif
