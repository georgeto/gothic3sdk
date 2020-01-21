#ifndef GE_ELODMESH_H_INCLUDED
#define GE_ELODMESH_H_INCLUDED

class eCProgVertex;
class eCFlexibleVtxBuffer;
struct PMesh;
enum eEQuadreeChild;
struct eSQuadTreePolygon;

class GE_DLLIMPORT eLoDMesh
{
    public:
        class eCProgTriangle;
        class eCSplitMeshUniformGrid;

        class eCProgMeshData {
            private:
                static GEFloat ms_fUVSplitThreshold;

            public:
                static GEFloat GE_STDCALL GetUVSplitThreshold( void );
                static void GE_STDCALL    SetUVSplitThreshold( GEFloat );

            private:
                GEByte __UNK_0000[0x30];

            public:
                eCProgMeshData & operator = ( eCProgMeshData const & );

            public:
                 eCProgMeshData( eCProgMeshData const & );
                 eCProgMeshData( void );
                ~eCProgMeshData( void );

            public:
                GEBool                 Add( eCProgMeshData const &, bCMatrix const * );
                GEBool                 Add( eCResourceDataEntity *, bCMatrix const * );
                void                   Clear( void );
                void                   CopyFrom( eCProgMeshData const & );
                GEBool                 Crunch( void );
                bCString const &       GetMeshFilePath( void ) const;
                eCProgTriangle &       GetTriangleAt( GEInt );
                eCProgTriangle const & GetTriangleAt( GEInt ) const;
                GEInt                  GetTriangleCount( void ) const;
                eCProgVertex &         GetVertexAt( GEInt );
                eCProgVertex const &   GetVertexAt( GEInt ) const;
                eCFlexibleVtxBuffer *  GetVertexBuffer( void ) const;
                GEInt                  GetVertexCount( void ) const;
                GEBool                 Mend( void );
                GEBool                 Optimize( void );
                void                   PreCalculateSplitParameters( GEU32, bCRect &, GEU32 & );
                eCResourceDataEntity * Save( bCString const & );
                eCResourceDataEntity * Save( void );
                void                   SetMeshFilePath( bCString const & );
                void                   SetVertexBuffer( eCFlexibleVtxBuffer * );
                bCRect                 Split( GEU32, bTObjArray<eCProgMeshData> &, bCRect const * );
                void                   WriteBackProgMesh( PMesh const & );

            protected:
                void                   Create( void );
                void                   Destroy( void );
                void                   Invalidate( void );
                GEBool                 Add( eCMeshElement *, bCMatrix const * );
                GEBool                 Add( eCResourceMeshComplex_PS *, bCMatrix const * );
                void                   CollectSplittedMeshes( bTObjArray<eCProgMeshData> &, eCSplitMeshUniformGrid & );
                eCResourceDataEntity * SaveComplex( bCString const & );
                eCMeshElement *        SaveSimple( GEInt, bTValArray<GEInt> & );

        };

        class eCProgTriangle {
            public:
                eCProgTriangle & operator =  ( eCProgTriangle const & );
                GEBool           operator == ( eCProgTriangle const & );

            public:
                 eCProgTriangle( eCProgTriangle const & );
                 eCProgTriangle( eCProgMeshData *, GEU16, GEU16, GEU16 );
                 eCProgTriangle( eCProgMeshData *, GEU32, GEU32, GEU32 );
                 eCProgTriangle( void );
                ~eCProgTriangle( void );

            public:
                void                 CalculateNormal( bCVector &, GEFloat & );
                void                 ChangeMesh( eCProgMeshData * );
                void                 CopyFrom( eCProgTriangle const & );
                bEResult             Create( eCProgMeshData *, GEU32, GEU32, GEU32 );
                void                 Destroy( void );
                GEU32                GetCrunchedVertIndex( GEInt ) const;
                eCProgVertex const & GetCrunchedVertex( GEInt ) const;
                GEInt                GetIndex( void ) const;
                GEInt                GetMaterialIndex( void ) const;
                GEU32                GetVertIndex( GEInt ) const;
                eCProgVertex const & GetVertex( GEInt ) const;
                GEInt                GetVertexCount( void ) const;
                void                 GetVerts( GEU32 &, GEU32 &, GEU32 & ) const;
                GEBool               HasVertex( GEU32 ) const;
                void                 Invalidate( void );
                GEBool               IsActive( void ) const;
                void                 SetActive( GEBool );
                void                 SetCrunchedVertIndex( GEInt, GEU32 );
                void                 SetIndex( GEInt );
                void                 SetMaterialIndex( GEInt );
                void                 SetVertIndex( GEInt, GEU32 );
        };

        class eCSplitMeshQuadTree {
            public:
                 eCSplitMeshQuadTree( void );
                ~eCSplitMeshQuadTree( void );

            public:
                void                                  Build( eCProgMeshData const & );
                bEResult                              Create( GEBool );
                void                                  Destroy( void );
                bCBox const &                         GetBox( void ) const;
                eCSplitMeshQuadTree *                 GetChildAtIndex( eEQuadreeChild );
                eCSplitMeshQuadTree const *           GetChildAtIndex( eEQuadreeChild ) const;
                GEU32                                 GetChildrenCount( void ) const;
                bTObjArray<eSQuadTreePolygon> const * GetPolyList( void ) const;
                GEU32                                 GetPolygonsPerLeaf( void );
                GEU32                                 GetSize( void ) const;
                GEU16                                 GetVersion( void ) const;
                GEBool                                IsLeaf( void ) const;
                GEBool                                IsRoot( void ) const;
                void                                  SetPolygonsPerLeaf( GEU32 );

            protected:
                void     Build( eCProgMeshData const &, bTObjArray<eSQuadTreePolygon> const & );
                void     CopyFrom( eCSplitMeshQuadTree const & );
                void     CopyLeafList( bCBitField const &, bTObjArray<eSQuadTreePolygon> const &, GEInt, bTObjArray<eSQuadTreePolygon> & );
                void     CopyPolyList( bCBitField const &, bTObjArray<eSQuadTreePolygon> const &, GEInt, bTObjArray<eSQuadTreePolygon> & );
                bEResult Create( void );
                void     EnlargeBox( bTObjArray<eSQuadTreePolygon> const & );
                void     Invalidate( void );

            private:
                eCSplitMeshQuadTree const & operator = ( eCSplitMeshQuadTree const & );

            private:
                eCSplitMeshQuadTree( eCSplitMeshQuadTree const & );

        };

        class eCSplitMeshUniformGrid {
            public:
                eCSplitMeshUniformGrid( void );
                ~eCSplitMeshUniformGrid( void );

            public:
                void                                 Build( eCProgMeshData const &, bCRect const &, GEU32 );
                void                                 Build( eCProgMeshData const &, GEU32 );
                GEU32                                CalculateNumSplitSlots( eCProgMeshData const &, GEU32 );
                bCRect                               CalculateWorldGridSize( eCProgMeshData const &, GEU32 );
                void                                 Destroy( void );
                bCRect                               GetCell( GEInt ) const;
                GEInt                                GetCellCount( void ) const;
                bCPoint                              GetPointFromVertex( eCProgVertex const & ) const;
                bTPtrArray<eCProgTriangle *> const & GetPolyList( bCRect const & ) const;
                bTPtrArray<eCProgTriangle *> const & GetPolyList( GEInt ) const;
                bTPtrArray<eCProgTriangle *> const & GetPolyList( GEInt, GEInt ) const;
                bCRect const &                       GetRectCellSize( void ) const;
                bCRect const &                       GetRectMeshDimension( void ) const;
                GEU16                                GetVersion( void ) const;

            protected:
                void     CopyFrom( eCSplitMeshUniformGrid const & );
                bEResult Create( void );
                void     Invalidate( void );

            private:
                eCSplitMeshUniformGrid const & operator = ( eCSplitMeshUniformGrid const & );

            private:
                eCSplitMeshUniformGrid( eCSplitMeshUniformGrid const & );
        };

        GE_ASSERT_SIZEOF(eLoDMesh::eCProgMeshData, 0x30);
};

#endif
