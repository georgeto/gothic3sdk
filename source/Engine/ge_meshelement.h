#ifndef GE_MESHELEMENT_H_INCLUDED
#define GE_MESHELEMENT_H_INCLUDED

class eCMeshCollisionDesc;
class eCVertexStructArrayBase;
struct eSLightmapGroup;
struct eSLightmapUVGroup;
struct eCSpatialHierarchy;
class eCVertexbufferPoolItem;
enum eEProjectionPlane;

class GE_DLLIMPORT eCMeshElement :
    public bCObjectRefBase
{
    public: virtual void     CalcBoundary( void );
    public: virtual GEBool   IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCMeshCollisionDesc * *, GEInt ) const;
    public: virtual GEBool   IntersectsVolume( bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool ) const;
    public: virtual GEU16    GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual bEResult CopyFrom( bCObjectBase const & );
    public: virtual         ~eCMeshElement( void );

    public:
        eCMeshElement( eCMeshElement const & );
        eCMeshElement( void );

    public:
        eCMeshElement & operator = ( eCMeshElement const & );

    public:
        GEBool                                BuildSpatialHierarchy( GEBool );
        void                                  CalculateSize( void );
        GEBool                                CreateLightmapUVGroups( GEBool );
        eCVertexStructArrayBase *             CreateStreamArray( eEVertexStreamArrayType );
        GEBool                                DeleteStreamArray( eEVertexStreamArrayType );
        GEBool                                DestroyLightmapUVGroups( void );
        bCBox const &                         GetBoundingBox( void ) const;
        void                                  GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
        GEU32                                 GetFVF( void ) const;
        eSLightmapGroup const &               GetLightmapPerVertexGroup( void ) const;
        bTObjArray<eSLightmapUVGroup> &       GetLightmapUVGroups( void );
        bTObjArray<eSLightmapUVGroup> const & GetLightmapUVGroups( void ) const;
        bCString const &                      GetMaterialFileName( void ) const;
        bCString const &                      GetMaterialName( void ) const;
        eCResourceDataEntity *                GetResourceDataEntity( void );
        GEU32                                 GetSize( void ) const;
        GEBool                                GetSmoothNormal( bCVector &, GEU32, bCVector const & );
        eCSpatialHierarchy const &            GetSpatialHierarchy( void ) const;
        eCVertexStructArrayBase *             GetStreamArray( GEU32 );
        eCVertexStructArrayBase *             GetStreamArray( eEVertexStreamArrayType );
        eCVertexStructArrayBase const *       GetStreamArray( GEU32 ) const;
        eCVertexStructArrayBase const *       GetStreamArray( eEVertexStreamArrayType ) const;
        GEU32                                 GetTriangleCount( void ) const;
        GEBool                                GetTriangleIndices( GEU32, GEU32 * const ) const;
        GEBool                                GetTriangles( bTValArray<bCTriangle> & ) const;
        eCVertexbufferPoolItem *              GetVertexbufferPoolItem( void ) const;
        GEBool                                HasStreamArray( eEVertexStreamArrayType ) const;
        GEBool                                SetMaterialFile( bCString const & );
        void                                  SetResourceDataEntity( eCResourceDataEntity * );
        GEBool                                SetStreamArray( eCVertexStructArrayBase const & );
        void                                  SetVertexbufferPoolItem( eCVertexbufferPoolItem * );
        void                                  UnloadResources( void );

    protected:
        static GEInt GE_CCALL SortLightmapUVGroups( GELPCVoid, GELPCVoid );

    protected:
        GEInt             DublicateVertexAddLast( GEInt );
        eEProjectionPlane FindProjectionPlane( bCTriangle const & ) const;
        GEBool            GetVertexTriangleMap( bTObjArray<bTValArray<GEU32> > & );
        void              GroupTriangleNeighbors( GEU32, bTValArray<GEU32> &, bTValArray<GEU32> const &, bTObjArray<bTValArray<GEU32> > const &, bTValArray<eEProjectionPlane> const & );
        void              Invalidate( void );

};

#endif
