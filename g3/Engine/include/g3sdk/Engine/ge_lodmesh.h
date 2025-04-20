#pragma once

#include <SharedBase.h>

class PMesh;
class eCFlexibleVtxBuffer;
class eCMeshElement;
class eCResourceDataEntity;
class eCResourceMeshComplex_PS;

namespace eLoDMesh
{

class eCProgVertex
{
    GE_UNIMPL_STRUCT(eCProgVertex)
};

struct eSQuadTreePolygon
{
    GE_UNIMPL_STRUCT(eSQuadTreePolygon)
};

class eCProgMeshData;

class GE_DLLIMPORT eCProgTriangle
{
  public:
    eCProgTriangle(eCProgTriangle const &);
    eCProgTriangle(eCProgMeshData *, GEU16, GEU16, GEU16);
    eCProgTriangle(eCProgMeshData *, GEU32, GEU32, GEU32);
    eCProgTriangle();
    ~eCProgTriangle();

  public:
    eCProgTriangle &operator=(eCProgTriangle const &);
    GEBool operator==(eCProgTriangle const &);

  public:
    void CalculateNormal(bCVector &, GEFloat &);
    void ChangeMesh(eCProgMeshData *);
    void CopyFrom(eCProgTriangle const &);
    bEResult Create(eCProgMeshData *, GEU32, GEU32, GEU32);
    void Destroy();
    GEU32 GetCrunchedVertIndex(GEInt) const;
    eCProgVertex const &GetCrunchedVertex(GEInt) const;
    GEInt GetIndex() const;
    GEInt GetMaterialIndex() const;
    GEU32 GetVertIndex(GEInt) const;
    eCProgVertex const &GetVertex(GEInt) const;
    GEInt GetVertexCount() const;
    void GetVerts(GEU32 &, GEU32 &, GEU32 &) const;
    GEBool HasVertex(GEU32) const;
    void Invalidate();
    GEBool IsActive() const;
    void SetActive(GEBool);
    void SetCrunchedVertIndex(GEInt, GEU32);
    void SetIndex(GEInt);
    void SetMaterialIndex(GEInt);
    void SetVertIndex(GEInt, GEU32);
};

class GE_DLLIMPORT eCSplitMeshUniformGrid
{
  public:
    eCSplitMeshUniformGrid();
    ~eCSplitMeshUniformGrid();

  public:
    void Build(eCProgMeshData const &, bCRect const &, GEU32);
    void Build(eCProgMeshData const &, GEU32);
    GEU32 CalculateNumSplitSlots(eCProgMeshData const &, GEU32);
    bCRect CalculateWorldGridSize(eCProgMeshData const &, GEU32);
    void Destroy();
    bCRect GetCell(GEInt) const;
    GEInt GetCellCount() const;
    bCPoint GetPointFromVertex(eCProgVertex const &) const;
    bTPtrArray<eCProgTriangle *> const &GetPolyList(bCRect const &) const;
    bTPtrArray<eCProgTriangle *> const &GetPolyList(GEInt) const;
    bTPtrArray<eCProgTriangle *> const &GetPolyList(GEInt, GEInt) const;
    bCRect const &GetRectCellSize() const;
    bCRect const &GetRectMeshDimension() const;
    GEU16 GetVersion() const;

  protected:
    void CopyFrom(eCSplitMeshUniformGrid const &);
    bEResult Create();
    void Invalidate();

  private:
    eCSplitMeshUniformGrid(eCSplitMeshUniformGrid const &);

  private:
    eCSplitMeshUniformGrid const &operator=(eCSplitMeshUniformGrid const &);
};

class GE_DLLIMPORT eCProgMeshData
{
  public:
    static GEFloat GE_STDCALL GetUVSplitThreshold();
    static void GE_STDCALL SetUVSplitThreshold(GEFloat);

  public:
    eCProgMeshData(eCProgMeshData const &);
    eCProgMeshData();
    ~eCProgMeshData();

  public:
    eCProgMeshData &operator=(eCProgMeshData const &);

  public:
    GEBool Add(eCProgMeshData const &, bCMatrix const *);
    GEBool Add(eCResourceDataEntity *, bCMatrix const *);
    void Clear();
    void CopyFrom(eCProgMeshData const &);
    GEBool Crunch();
    bCString const &GetMeshFilePath() const;
    eCProgTriangle &GetTriangleAt(GEInt);
    eCProgTriangle const &GetTriangleAt(GEInt) const;
    GEInt GetTriangleCount() const;
    eCProgVertex &GetVertexAt(GEInt);
    eCProgVertex const &GetVertexAt(GEInt) const;
    eCFlexibleVtxBuffer *GetVertexBuffer() const;
    GEInt GetVertexCount() const;
    GEBool Mend();
    GEBool Optimize();
    void PreCalculateSplitParameters(GEU32, bCRect &, GEU32 &);
    eCResourceDataEntity *Save(bCString const &);
    eCResourceDataEntity *Save();
    void SetMeshFilePath(bCString const &);
    void SetVertexBuffer(eCFlexibleVtxBuffer *);
    bCRect Split(GEU32, bTObjArray<eCProgMeshData> &, bCRect const *);
    void WriteBackProgMesh(PMesh const &);

  protected:
    void Create();
    void Destroy();
    void Invalidate();

  private:
    static GEFloat ms_fUVSplitThreshold;

  private:
    GEBool Add(eCMeshElement *, bCMatrix const *);
    GEBool Add(eCResourceMeshComplex_PS *, bCMatrix const *);
    void CollectSplittedMeshes(bTObjArray<eCProgMeshData> &, eCSplitMeshUniformGrid &);
    eCResourceDataEntity *SaveComplex(bCString const &);
    eCMeshElement *SaveSimple(GEInt, bTValArray<GEInt> &);

  private:
    GEByte __UNK_0000[0x30];
};
GE_ASSERT_SIZEOF(eCProgMeshData, 0x30)

class GE_DLLIMPORT eCSplitMeshQuadTree
{
  public:
    enum eEQuadreeChild
    {
        // TODO: Enumerator values
    };

  public:
    eCSplitMeshQuadTree();
    ~eCSplitMeshQuadTree();

  public:
    void Build(eCProgMeshData const &);
    bEResult Create(GEBool);
    void Destroy();
    bCBox const &GetBox() const;
    eCSplitMeshQuadTree *GetChildAtIndex(eEQuadreeChild);
    eCSplitMeshQuadTree const *GetChildAtIndex(eEQuadreeChild) const;
    GEU32 GetChildrenCount() const;
    bTObjArray<eSQuadTreePolygon> const *GetPolyList() const;
    GEU32 GetPolygonsPerLeaf();
    GEU32 GetSize() const;
    GEU16 GetVersion() const;
    GEBool IsLeaf() const;
    GEBool IsRoot() const;
    void SetPolygonsPerLeaf(GEU32);

  protected:
    void Build(eCProgMeshData const &, bTObjArray<eSQuadTreePolygon> const &);
    void CopyFrom(eCSplitMeshQuadTree const &);
    void CopyLeafList(bCBitField const &, bTObjArray<eSQuadTreePolygon> const &, GEInt,
                      bTObjArray<eSQuadTreePolygon> &);
    void CopyPolyList(bCBitField const &, bTObjArray<eSQuadTreePolygon> const &, GEInt,
                      bTObjArray<eSQuadTreePolygon> &);
    bEResult Create();
    void EnlargeBox(bTObjArray<eSQuadTreePolygon> const &);
    void Invalidate();

  private:
    eCSplitMeshQuadTree(eCSplitMeshQuadTree const &);

  private:
    eCSplitMeshQuadTree const &operator=(eCSplitMeshQuadTree const &);
};

} // namespace eLoDMesh
