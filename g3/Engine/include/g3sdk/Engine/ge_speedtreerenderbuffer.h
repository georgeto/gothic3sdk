#pragma once

#include <Engine/ge_ambientocclusionpreprocessor.h>
#include <Engine/ge_gfxvisual.h>

#include <SharedBase.h>

class CSpeedTreeRT;
class eCResourceShaderMaterial_PS;
class eCSpeedTree_PS;
class eCWraper_SpeedTreeRT;

enum eEShaderMaterialInstancing
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCSpeedTreeRenderBuffer : public bCObjectRefBase
{
  public:
    enum eEGeometryType
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: GEU32 AddReference() override;
    public: GEU32 ReleaseReference() override;
    public: ~eCSpeedTreeRenderBuffer() override;
    // clang-format on

  public:
    eCSpeedTreeRenderBuffer(eCSpeedTreeRenderBuffer const &);
    eCSpeedTreeRenderBuffer();

  public:
    eCSpeedTreeRenderBuffer &operator=(eCSpeedTreeRenderBuffer const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void AddToRenderQueue(eCSpeedTree_PS *);
    void ClearRenderQueue();
    void CopyTo(eCSpeedTreeRenderBuffer &) const;
    GEBool CreateGemoetry();
    GEBool DestroyGemoetry();
    eCResourceShaderMaterial_PS *GetMaterial(eEGeometryType);
    GEInt GetRenderQueueSize();
    eCWraper_SpeedTreeRT *GetSpeedTreeWraper() const;
    void Render(eEShaderMaterialInstancing);
    void RenderBranches(eEShaderMaterialInstancing);
    void RenderFronds(eEShaderMaterialInstancing);
    void RenderLeafs(eEShaderMaterialInstancing);
    void RenderTerrainShadows(eEShaderMaterialInstancing);
    void SetSpeedTreeWraper(eCWraper_SpeedTreeRT *);

  protected:
    static GEFloat ms_fLeafAOThickness;
    static GEU32 ms_u32SIMaxMemoryUse;

  protected:
    static GEInt GE_CCALL SortInstances(GELPCVoid, GELPCVoid);

  protected:
    GEBool CreateBranchGeometry(CSpeedTreeRT *, eCAmbientOcclusionPreprocessor::eCAOMeshBase *);
    GEBool CreateFrondGeometry(CSpeedTreeRT *, eCAmbientOcclusionPreprocessor::eCAOMeshBase *);
    GEBool CreateLeafGeometry(CSpeedTreeRT *, eCAmbientOcclusionPreprocessor::eCAOMeshBase *);
    void Invalidate();
    GEBool QueryOrCreateBranchMaterial();
    GEBool QueryOrCreateFrondMaterial();
    GEBool QueryOrCreateLeafMaterial();

  public:
    eCWraper_SpeedTreeRT *m_pSpeedTreeWraper;
    GEInt m_pSpeedTreeAdmin;
    eCGfxVisual *m_pBranchGeometry;
    eCGfxVisual *m_pFrondGeometry;
    eCGfxVisual *m_pLeafGeometry;
    GE_UNIMPL_MEMBERS(0x74)
};

GE_ASSERT_SIZEOF(eCSpeedTreeRenderBuffer, 0x94)
