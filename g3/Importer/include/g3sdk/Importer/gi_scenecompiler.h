#pragma once

#include <Game.h>

class GE_DLLIMPORT iCSceneCompiler : public bCObjectRefBase
{
  public:
    enum iECompileOptions
    {
        iECompileOptions_NotUsed = 0x01,
        iECompileOptions_CompileStatic = 0x02,
        iECompileOptions_CompressWorld = 0x04,
        iECompileOptions_NoLongerUsed = 0x08,
        iECompileOptions_CompileNavigation = 0x10,
        iECompileOptions_CompileLightmaps = 0x20,
        iECompileOptions_CompilePhysicMeshes = 0x40,
        iECompileOptions_Preparecompilation = 0x80,
        iECompileOptions_CompileLightmapMeshes = 0x100,
        iECompileOptions_CompileLightdata = 0x200,
        iECompileOptions_CleanWorld = 0x400
    };

  public:
    struct iSStaticBoundaryItem
    {
        GE_UNIMPL_STRUCT(iSStaticBoundaryItem)
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~iCSceneCompiler() override;
    // clang-format on

  public:
    iCSceneCompiler();

  public:
    iCSceneCompiler &operator=(iCSceneCompiler const &);

  public:
    bEResult CompileWorld(bCString const &a_strWorldName, iECompileOptions a_Options, GEBool a_bDeleteCompilation);
    GEBool ParseCommandLine(bCCommandLine const &);

  protected:
    static GEBool GE_STDCALL OnCacheOutContext(eCGeometrySpatialContext *);

  protected:
    iCSceneCompiler(iCSceneCompiler const &);

  protected:
    void CleanWorld(gCWorld *);
    void CollectEntitiesForNewStaticGeometry(gCWorld *, bTObjArray<iSStaticBoundaryItem> &,
                                             bTPtrArray<gCGeometryLayer *> &);
    void CompileForStatic(gCWorld *);
    void CompileLightmapMeshes(eCEntity *);
    void CompileLightmapMeshes(gCWorld *);
    GEBool CompileLightmaps(gCWorld *, eCCameraBase &);
    GEBool CompilePhysicEntityRecursive(eCEntity *);
    GEBool CompilePhysicMeshes(gCWorld *);
    void CompressWorld(gCWorld *);
    GEBool ConvertChildrenToStaticEntities(eCEntity *, gCGeometryLayer *, GEBool);
    eCEntity *ConvertDynamicToStaticEntity(eCEntity *, gCGeometryLayer *);
    GEBool ConvertDynamicToStaticLayer(gCDynamicLayer *, gCGeometryLayer *);
    void CopyPhysicalDir(bCString const &, bCString const &);
    void DeleteEmptySectors(gCWorld *);
    void DeleteOldDynamicLayers(gCWorld *);
    void DeleteOldStaticLayers(gCWorld *, bTPtrArray<gCGeometryLayer *> &);
    void DeletePhysicalDir(bCString const &);
    bCBox GetStaticWorldBoundary(gCWorld *);
    void Invalidate();
    void OptimizeDynamicGeometry(gCWorld *);
    void OptimizeStaticGeometry(gCWorld *);
    void OptimizeVegetation(eCEntity *, iSStaticBoundaryItem &);
    GEBool PrefetchWorld(gCWorld *, eCCameraBase &);
    void PrepareCompilation(gCWorld *);
    void SaveWorld(gCWorld *);

  private:
    GEU32 m_u32Unknown;
    GEBool m_bCompileLightdata;
    GE_PADDING(0x3)
};

GE_ASSERT_SIZEOF(iCSceneCompiler, 0x14)

inline iCSceneCompiler::iECompileOptions operator|(iCSceneCompiler::iECompileOptions lhs,
                                                   iCSceneCompiler::iECompileOptions rhs)
{
    return static_cast<iCSceneCompiler::iECompileOptions>(static_cast<GEInt>(lhs) | static_cast<GEInt>(rhs));
};
