#ifndef GE_PVSCELLITEM_H_INCLUDED
#define GE_PVSCELLITEM_H_INCLUDED

struct eSCellMapKey;
struct eSStaticHierachyEntity;

class GE_DLLIMPORT eCPVSCellItem
{
    public:    virtual GEU16    GetVersion( void ) const;
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );
    protected: virtual bEResult CopyFrom( eCPVSCellItem const & );
    public:    virtual         ~eCPVSCellItem( void );

    protected:
        static GEInt ms_iKDTreeSortAxis;

    public:
        static void GE_STDCALL          GetCellIndex( bCPoint &, bCVector const &, GEU32 );
        static void GE_STDCALL          GetCellIndex( bCPoint &, eCEntity const &, GEU32 );
        static bCCriticalSectionWin32 & GE_STDCALLGetCriticalSection( void );
        static bCPoint GE_STDCALL       GetEntity2DCoord( bCVector const & );
        static GEI32 GE_STDCALL         GetWorldMapRadius( void );

    public:
        eCPVSCellItem( eCPVSCellItem const & );
        eCPVSCellItem( void );

    public:
        eCPVSCellItem const & operator = ( eCPVSCellItem const & );

    public:
        void                                      CacheInEntity( eCEntity *, GEU32 );
        void                                      CacheOut( GEU32 );
        void                                      CacheOutEntity( eCEntity *, GEU32 );
        void                                      DisableDatabaseSlot( GEU32 );
        void                                      EnableDatabaseSlot( GEU32 );
        GEBool                                    ExistsEntity( eCEntity * ) const;
        bCBox const &                             GetCellBox( void ) const;
        eSCellMapKey const &                      GetCellMapKey( void ) const;
        eCPVSPrefetcher3 *                        GetCurrentPVSPrefetcher( void ) const;
        bTSmallArray<eCDynamicEntity *> const &   GetDynamicEntities( void ) const;
        GEU32                                     GetDynamicSyncCount( void ) const;
        bCPoint                                   GetEntity2DCoord( eCEntity * );
        bTSmallArray<eCSpatialEntity *> const &   GetStaticEntities( void ) const;
      //bTSkipTree<bCBox, eSSkipTreeNode> const & GetStaticHierachy( void ) const;
        GEU32                                     GetStaticSyncCount( void ) const;
        GEBool                                    IsCorrectCell( bCPoint const & ) const;
        GEBool                                    IsCorrectCell( bCVector const & ) const;
        GEBool                                    IsCorrectCell( eCEntity const * ) const;
        GEBool                                    IsInCellIndex( bCRect const & ) const;
        GEBool                                    IsRemovedFromAllDatabases( void ) const;
        void                                      RenderOccludees( GEU16, GEU16 );
        void                                      SetCellCoords( GEInt, GEInt, GEU32 );
        void                                      SetCurrentPVSPrefetcher( eCPVSPrefetcher3 * );

    protected:
        static GEInt GE_CCALL SortKDTree( GELPCVoid, GELPCVoid );

    protected:
        void   BuildStaticHierachy( GEU32, eSStaticHierachyEntity *, GEU32, GEU32 );
        void   BuildStaticHierachy( void );
        GEBool DisableDatabaseSet( eCEntity *, GEU32 );
        GEBool EnableDatabaseSet( eCEntity *, GEU32 );
        void   Invalidate( void );

};

#endif
