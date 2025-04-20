#pragma once

#include <Engine/ge_enginecomponentbase.h>

#include <SharedBase.h>

class eCGfxVertexDecl;
class eCSpeedTreeRenderBuffer;
class eCSpeedTreeWind_PS;

class GE_DLLIMPORT eCSpeedTreeAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCSpeedTreeAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: void Process() override;
    public: void OnBeginRenderSolid() override;
    public: void OnEndRenderSolid() override;
    public: void OnBeginRenderAlpha() override;
    public: void OnEndRenderAlpha() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCSpeedTreeAdmin, eCEngineComponentBase)

  public:
    void AddRenderBuffer(eCSpeedTreeRenderBuffer *);
    void BeginRenderTerrainShadows();
    void EndRenderTerrainShadows();
    eCGfxVertexDecl *GetBranchFrondVertexDecl();
    GEFloat const *GetLeafAngleMatrices() const;
    bCVector4 const *GetLeafBillboardTable(GEU16 &) const;
    eCGfxVertexDecl *GetLeafVertexDecl();
    GEFloat const *GetWindMatrices() const;
    void Invalidate();
    void RemoveRenderBuffer(eCSpeedTreeRenderBuffer *);
    void SetEnabled(GEBool);
    void SetLeafBillboardTable(bCVector4 const *, GEU16);

  protected:
    void AddSpeedWindPS(eCSpeedTreeWind_PS *);
    void GE_STDCALL OnToggleSpeedTree(bCObjectRefBase *, bCEvent *);
    void RemoveSpeedWindPS(eCSpeedTreeWind_PS *);
    void UpdateWindMatrices();

  private:
    GE_UNIMPL_MEMBERS(1428)
};

GE_ASSERT_SIZEOF(eCSpeedTreeAdmin, 0x5a8)
