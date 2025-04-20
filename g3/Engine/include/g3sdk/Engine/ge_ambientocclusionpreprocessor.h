#pragma once

#include <Engine/EngineEnum.h>

#include <SharedBase.h>

class eCEntity;
class eCEntityPropertySet;
class eCResourceDataEntity;
class eCResourceMeshComplex_PS;

template <typename T>
class bTSphericalHarmonics3
{
    GE_UNIMPL_STRUCT(bTSphericalHarmonics3)
};

class GE_DLLIMPORT eCAmbientOcclusionPreprocessor : public bCObjectRefBase
{
  public:
    struct eSOrientedDisk
    {
        GE_UNIMPL_STRUCT(eSOrientedDisk)
    };

    class eCAOMeshGroup;

    class eCAOMeshBase
    {
        // clang-format off
            public: virtual ~eCAOMeshBase();
            public: virtual void Compute(eCAOMeshBase *);
            public: virtual void ComputePass(eCAOMeshBase *) = 0;
            public: virtual GEFloat ComputeOcclusion(eSOrientedDisk &);
            public: virtual void ComputeOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) = 0;
            public: virtual void ComputeSphereOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) = 0;
            public: virtual void ComputeSHOcclusion(bCVector const &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) = 0;
            public: virtual void GetResults(bTValArray<GEFloat> &) = 0;
            public: virtual GEInt GetMeshCount() const;
            public: virtual eCAOMeshBase * GetMeshAt(GEInt) const;
            public: virtual GEBool GetMeshSphere(bCSphere &) const = 0;
            public: virtual void FindMeshesOfInterest(eCAOMeshBase *, eCAOMeshGroup *, GEU16);
        // clang-format on

      public:
        eCAOMeshBase(eCAOMeshBase const &);
        eCAOMeshBase();

      public:
        eCAOMeshBase &operator=(eCAOMeshBase const &);
    };

    class eCAOMeshReciverBase : public eCAOMeshBase
    {
        // clang-format off
            public: virtual bTValArray<eSOrientedDisk> & GetDiskArray() = 0;
            public: ~eCAOMeshReciverBase() override;
        // clang-format on

      public:
        eCAOMeshReciverBase(eCAOMeshReciverBase const &);
        eCAOMeshReciverBase();

      public:
        eCAOMeshReciverBase &operator=(eCAOMeshReciverBase const &);
    };

    template <typename T>
    class eCAOPerTriangleMeshBase : public eCAOMeshReciverBase
    {
        // clang-format off
      public: ~eCAOPerTriangleMeshBase<T>() override;
      public: void ComputePass(eCAOMeshBase *) override;
      public: void ComputeOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
      public: void ComputeSphereOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
      public: void ComputeSHOcclusion(bCVector const &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
      public: void GetResults(bTValArray<GEFloat> &) override;
      public: GEBool GetMeshSphere(bCSphere &) const override;
      public: bTValArray<eSOrientedDisk> &GetDiskArray() override;
        // clang-format on

      public:
        eCAOPerTriangleMeshBase<T>(eCAOPerTriangleMeshBase<T> const &);
        eCAOPerTriangleMeshBase<T>();

      public:
        eCAOPerTriangleMeshBase<T> &operator=(eCAOPerTriangleMeshBase<T> const &);

      public:
        void Create(T const *, GEU32, bCVector const *, bCVector const *, GEU32, bCMatrix const *, GEBool);
        void GetResults(bTValArray<eSOrientedDisk> &, bTValArray<GEFloat> &);
        void RemapResults(bTValArray<GEFloat> &, bTValArray<GEFloat> &);
    };

    class eCAOCustomMesh : public eCAOMeshBase
    {
        // clang-format off
            public: virtual void Create(GEBool, bTValArray<eSOrientedDisk>);
            public: ~eCAOCustomMesh() override;
            public: void ComputePass(eCAOMeshBase *) override;
            public: void ComputeOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSphereOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSHOcclusion(bCVector const &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void GetResults(bTValArray<GEFloat> &) override;
            public: GEBool GetMeshSphere(bCSphere &) const override;
        // clang-format on

      public:
        eCAOCustomMesh(eCAOCustomMesh const &);
        eCAOCustomMesh();

      public:
        eCAOCustomMesh &operator=(eCAOCustomMesh const &);
    };

    class eCAOMeshEmitterInstance : public eCAOMeshBase
    {
        // clang-format off
            public: ~eCAOMeshEmitterInstance() override;
            public: void ComputePass(eCAOMeshBase *) override;
            public: void ComputeOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSphereOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSHOcclusion(bCVector const &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void GetResults(bTValArray<GEFloat> &) override;
            public: GEBool GetMeshSphere(bCSphere &) const override;
        // clang-format on

      public:
        eCAOMeshEmitterInstance(eCAOMeshEmitterInstance const &);
        eCAOMeshEmitterInstance(bCMatrix const &, eCAOMeshBase *);

      public:
        eCAOMeshEmitterInstance &operator=(eCAOMeshEmitterInstance const &);

      public:
        bTSphericalHarmonics3<GEFloat> const &GetResult() const;
    };

    class eCAOMeshGroup : public eCAOMeshBase
    {
        // clang-format off
            public: ~eCAOMeshGroup() override;
            public: void ComputePass(eCAOMeshBase *) override;
            public: void ComputeOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSphereOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSHOcclusion(bCVector const &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void GetResults(bTValArray<GEFloat> &) override;
            public: GEInt GetMeshCount() const override;
            public: eCAOMeshBase * GetMeshAt(GEInt) const override;
            public: GEBool GetMeshSphere(bCSphere &) const override;
        // clang-format on

      public:
        eCAOMeshGroup(eCAOMeshGroup const &);
        explicit eCAOMeshGroup(GEBool = GETrue);

      public:
        eCAOMeshGroup &operator=(eCAOMeshGroup const &);

      public:
        void AddMesh(eCAOMeshBase *);
        void RemoveMeshAt(GEInt);
    };

    class eCAOMeshInstance : public eCAOMeshBase
    {
        // clang-format off
            public: ~eCAOMeshInstance() override;
            public: void ComputePass(eCAOMeshBase *) override;
            public: void ComputeOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSphereOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSHOcclusion(bCVector const &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void GetResults(bTValArray<GEFloat> &) override;
            public: GEBool GetMeshSphere(bCSphere &) const override;
        // clang-format on

      public:
        eCAOMeshInstance(eCAOMeshInstance const &);
        eCAOMeshInstance(bCMatrix const &, eCAOMeshReciverBase *);

      public:
        eCAOMeshInstance &operator=(eCAOMeshInstance const &);
    };

    class eCAOMeshLoD : public eCAOMeshBase
    {
        // clang-format off
            public: ~eCAOMeshLoD() override;
            public: void Compute(eCAOMeshBase *) override;
            public: void ComputePass(eCAOMeshBase *) override;
            public: void ComputeOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSphereOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSHOcclusion(bCVector const &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void GetResults(bTValArray<GEFloat> &) override;
            public: GEBool GetMeshSphere(bCSphere &) const override;
            public: void FindMeshesOfInterest(eCAOMeshBase *, eCAOMeshGroup *, GEU16) override;
        // clang-format on

      public:
        eCAOMeshLoD(eCAOMeshLoD const &);
        explicit eCAOMeshLoD(GEBool = GETrue);

      public:
        eCAOMeshLoD &operator=(eCAOMeshLoD const &);

      public:
        void AddLoDMesh(eCAOMeshBase *);
        eCAOMeshBase *GetLoDMeshAt(GEInt) const;
        GEInt GetLoDMeshCount() const;
        void RemoveLoDMeshAt(GEInt);
    };

    class eCAOPerTriangleMesh16 : public eCAOPerTriangleMeshBase<unsigned short>
    {
        // clang-format off
            public: ~eCAOPerTriangleMesh16() override;
        // clang-format on

      public:
        eCAOPerTriangleMesh16(eCAOPerTriangleMesh16 const &);
        eCAOPerTriangleMesh16();

      public:
        eCAOPerTriangleMesh16 &operator=(eCAOPerTriangleMesh16 const &);
    };

    class eCAOPerTriangleMesh : public eCAOPerTriangleMeshBase<unsigned long>
    {
        // clang-format off
            public: ~eCAOPerTriangleMesh() override;
        // clang-format on

      public:
        eCAOPerTriangleMesh(eCAOPerTriangleMesh const &);
        eCAOPerTriangleMesh();

      public:
        eCAOPerTriangleMesh &operator=(eCAOPerTriangleMesh const &);
    };

    class eCAOPerVertexMesh : public eCAOMeshReciverBase
    {
        // clang-format off
            public: ~eCAOPerVertexMesh() override;
            public: void ComputePass(eCAOMeshBase *) override;
            public: void ComputeOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSphereOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void ComputeSHOcclusion(bCVector const &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &) override;
            public: void GetResults(bTValArray<GEFloat> &) override;
            public: GEBool GetMeshSphere(bCSphere &) const override;
            public: bTValArray<eSOrientedDisk> & GetDiskArray() override;
        // clang-format on

      public:
        eCAOPerVertexMesh(eCAOPerVertexMesh const &);
        eCAOPerVertexMesh();

      public:
        eCAOPerVertexMesh &operator=(eCAOPerVertexMesh const &);

      public:
        void Create(GEU32 const *, GEU32, bCVector const *, bCVector const *, GEU32, bCMatrix const *, GEBool);
    };

    class eCAOTreeNode
    {
      public:
        eCAOTreeNode(eCAOTreeNode const &);
        eCAOTreeNode();
        ~eCAOTreeNode();

      public:
        eCAOTreeNode &operator=(eCAOTreeNode const &);

      public:
        GEBool Build(bTValArray<eSOrientedDisk> &, bTValArray<GEInt> const &);
        void Compute(eCAOMeshBase *);
        void ComputeOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &);
        void ComputeSHOcclusion(bCVector const &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &);
        void ComputeSphereOcclusionFactor(eSOrientedDisk &, bTSphericalHarmonics3<GEFloat> &, bCMatrix const &);
        bCBox const &GetBoundingBox() const;
        bTValArray<GEInt> const &GetLeafIndices() const;
        GEBool IsEmpty() const;
        GEBool IsLeaf() const;
        GEBool IsValid() const;
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCAmbientOcclusionPreprocessor() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCAmbientOcclusionPreprocessor, bCObjectRefBase)

  public:
    static GEFloat ms_fShadowSoftness;
    static GEInt ms_iDiskCounter;
    static GEU32 ms_u32NumEntities;
    static GEU32 ms_u32NumVisualEntities;

  public:
    static GEInt GE_STDCALL GetMaxLeafsPerNode();
    static void GE_STDCALL SetMaxLeafsPerNode(GEInt);

  public:
    void AddEmitterMesh(eCAOMeshBase *);
    void AddMesh(eCAOMeshBase *);
    void Clear();
    GEBool CompileCurrentWorld(GEFloat);
    GEBool CompileCurrentWorldGrid();
    void Compute();
    eCAOMeshBase *GetEmitterMeshAt(GEInt) const;
    GEInt GetEmitterMeshIndex(eCAOMeshBase *) const;
    eCAOMeshBase *GetMeshAt(GEInt) const;
    GEInt GetMeshIndex(eCAOMeshBase *) const;

  protected:
    static GEInt ms_iMaxLeafsPerNode;

  protected:
    void CollectEntities(eCEntity *, bTValArray<eEPropertySetType> const &,
                         bTObjMap<eCResourceDataEntity *, bTValArray<eCEntity *>> &);
    void CollectPropertySet(eCEntityPropertySet const *, bTObjMap<eCResourceDataEntity *, bTValArray<eCEntity *>> &);
    void CollectVisuals(eCEntityPropertySet const *, eCResourceDataEntity *,
                        bTObjMap<eCResourceDataEntity *, bTValArray<eCEntity *>> &);
    eCAOMeshGroup *CreateComplexMeshGroup(eCResourceMeshComplex_PS *, eELightmapAmbientOcclusion);
    void Invalidate();
    GEBool ShouldCreateAOGrid(eCEntity *);

  private:
    GE_UNIMPL_MEMBERS(24)
};

GE_ASSERT_SIZEOF(eCAmbientOcclusionPreprocessor, 0x24)
