#ifndef GE_PVSPREFETCHERJOB_H_INCLUDED
#define GE_PVSPREFETCHERJOB_H_INCLUDED

enum eECurrentStagePrefetcher;

class GE_DLLIMPORT eCPVSPrefetcherJob
{

    protected:
        static GEU32 ms_u32TimeSliceMSecOperate;

    public:
         eCPVSPrefetcherJob( eCFrustumDatabase * );
        ~eCPVSPrefetcherJob( void );

    public:
        eCPVSPrefetcherJob const & operator = ( eCPVSPrefetcherJob const & );

    public:
        void                     ClearJob( void );
        bEResult                 Create( eCPVSPrefetcher3 *, bTSmallArray<eCEntity *> *, bTSmallArray<eCEntity *> *, bTSmallArray<eCGeometrySpatialContext *> * );
        void                     Destroy( void );
        void                     DisableTimeSlice( void );
        eCPVSCellItem *          GetCell( eSCellMapKey const & ) const;
        eECurrentStagePrefetcher GetCurrentStage( void ) const;
        GEBool                   IsEmpty( void ) const;
        GEBool                   IsFinished( void ) const;
        void                     Process( void );
        GEBool                   RemoveDynamicEntityFromList( eCEntity * );
        void                     ScanEntities( eCEntity &, bTSmallArray<eCEntity *> & );

    protected:
        eCPVSPrefetcherJob( eCPVSPrefetcherJob const & );

    protected:
        void CacheInDynamicEntities( void );
        void CacheInHybridEntities( void );
        void CacheInStaticContexts( void );
        void CacheInStaticEntities( void );
        void Invalidate( void );
        void ProcessForce( void );

};

#endif
