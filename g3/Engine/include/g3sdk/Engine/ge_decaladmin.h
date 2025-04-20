#pragma once

#include <Engine/ge_enginecomponentbase.h>

#include <SharedBase.h>

class eCDecal;
class eCEntity;
class eCFrustumDatabase;
class eCResourceDataEntity;

class GE_DLLIMPORT eCDecalAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCDecalAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: bEResult RestoreResources(GEBool) override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCDecalAdmin, eCEngineComponentBase)

  public:
    GEBool ClearDecals();
    GEBool CreateDecals(bTValArray<eCDecal *> &, bCRay const &, bCVector const &, eCResourceDataEntity *, GEBool);
    GEBool CreateDecals(bTValArray<eCDecal *> &, bCVector const &, bCVector const &, bCVector const &, bCVector const &,
                        eCResourceDataEntity *, eCEntity *, GEBool);
    GEBool RenderDecals(eCFrustumDatabase *);

  protected:
    static GEInt GE_CCALL SortRenderQueue(GELPCVoid, GELPCVoid);

  protected:
    GEBool AddDecal(eCDecal *);
    GEBool CreateBuffers();
    GEBool CreateDefaultShader();
    GEBool DestroyBuffers();
    GEBool DestroyDefaultShader();
    void Invalidate();
    GEBool RemoveDecal(eCDecal *);

  private:
    GE_UNIMPL_MEMBERS(44)
};

GE_ASSERT_SIZEOF(eCDecalAdmin, 0x40)
