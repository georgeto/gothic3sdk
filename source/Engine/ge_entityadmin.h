#ifndef GE_ENTITYADMIN_H_INCLUDED
#define GE_ENTITYADMIN_H_INCLUDED

class eEProcessingRangeCull;
struct eSEntityStatistics;

class GE_DLLIMPORT eCEntityAdmin :
    public bCObjectBase
{
    public: virtual GEU16       GetVersion( void ) const;
    public: virtual void        Destroy( void );
    public: virtual bEResult    Create( void );
    public: virtual bEResult    CopyFrom( bCObjectBase const & );
    public: virtual GEU32 const GetProfileLastTicksFirst( void ) const;
    public: virtual            ~eCEntityAdmin( void );

    public:
        eCEntityAdmin( eCEntityAdmin const & );
        eCEntityAdmin( void );

    public:
        void                             AddDirtyProcessingRangeEntity( eCEntity *, GEBool );
        void                             AddKilledEntity( eCEntity * );
        void                             ClearProcessingRangeList( void );
        eEProcessingRangeCull            CullOldProcessingRangeRegion( bCBox const & );
        eEProcessingRangeCull            CullProcessingRangeRegion( bCBox const & );
        void                             EnableProcessing( GEBool );
        void                             FourceFullROIUpdate( void );
        eCEntityDynamicContext *         GetDynamicEntityContext( GEInt ) const;
        GEInt                            GetDynamicEntityContextCount( void ) const;
        bTSmallArray<eCEntity *> const & GetEntitiesInProcessingRange( void ) const;
        bTSmallArray<eCEntity *> const & GetProcessableEntities( void ) const;
        bCSphere const &                 GetROISphere( void );
        bCSphere const &                 GetROIStaticSphere( void );
        eSEntityStatistics const &       GetStatistics( void );
        GEBool                           IntersectsOldProcessingRangeRegion( bCBox const & );
        GEBool                           IntersectsProcessingRangeRegion( bCBox const & );
        GEBool                           IntersectsStaticProcessingRangeRegion( bCBox const & );
        GEBool                           IsProcessingEnabled( void ) const;
        void                             KillEntities( void );
        void                             OnEntityProcessingChanged( eCEntity * );
        void                             Process( void );
        void                             RemoveEarlyKilledEntity( eCEntity * );
        void                             SetKilledEntityCallback( GEBool ( GE_STDCALL* )( eCEntity * ), GEBool );
        void                             SetROISphere( bCSphere const & );
        void                             SetROIStaticSphere( bCSphere const & );
        void                             UpdateProcessingRangeEntity( eCEntity *, bTSmallArray<eCEntity *> &, bTSmallArray<eCEntity *> & );

    protected:
        eCEntityAdmin const & operator = ( eCEntityAdmin const & );

    protected:
        void   CollectDynamicProcessingRangeEntity( eCEntity *, bTSmallArray<eCEntity *> &, bTSmallArray<eCEntity *> & );
        void   CollectStaticProcessingRangeEntity( eCEntity *, bTSmallArray<eCEntity *> &, bTSmallArray<eCEntity *> &, eEProcessingRangeCull );
        void   Invalidate( void );
        void   NotifyDeleteEntities( eCEntity * );
        GEBool ProcessDynamicEntity( eCDynamicEntity & );
        GEBool RegisterDynamicEntityContext( eCEntityDynamicContext & );
        GEBool RemoveFromProcessingList( eCEntity * );
        GEBool UnregisterDynamicEntityContext( eCEntityDynamicContext & );

    private:
        GE_PADDING( 0xFC )
};

GE_ASSERT_SIZEOF( eCEntityAdmin, 0x100 )

#endif
