#pragma once

#include <Engine/ge_enginecomponentbase.h>

#include <SharedBase.h>

class eCColorSrcSampler;
class eCGfxVertexDecl;
class eCGfxVisual;
class eCResourceShaderMaterial_PS;
class eCVegetation_GridNode;

enum eEVegetationQuality
{
    // TODO: Enumerator values
};

class eCGfxBufferAdmin
{
    GE_UNIMPL_STRUCT(eCGfxBufferAdmin)
};

struct eSVegetationWindData
{
    GE_UNIMPL_STRUCT(eSVegetationWindData)
};

class GE_DLLIMPORT eCVegetationAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCVegetationAdmin() override;
    public: bCGuid const & GetID() const override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCVegetationAdmin, eCEngineComponentBase)

  public:
    static bCString GE_STDCALL QualityToString(eEVegetationQuality);
    static eEVegetationQuality GE_STDCALL StringToQuality(bCString const &);

  public:
    void AddCachedGridNode(eCVegetation_GridNode *);
    eCGfxBufferAdmin *GetBufferAdmin();
    GEFloat GetDefaultViewRange() const;
    eCColorSrcSampler *GetDiffuseImageSampler();
    eCResourceShaderMaterial_PS *GetMaterial();
    eEVegetationQuality GetQuality() const;
    GEU32 GetTimeStamp() const;
    eCGfxVertexDecl *GetVertexDecl();
    eCGfxVisual *GetVisual();
    eSVegetationWindData const *GetWindData() const;
    void RemoveCachedGridNode(eCVegetation_GridNode *);
    void SetDefaultViewRange(GEFloat);
    void SetQuality(eEVegetationQuality);
    void SetWind(GEFloat, GEFloat, GEFloat, GEFloat, GEFloat, GEFloat);

  protected:
    void Invalidate();
    void GE_STDCALL OnToggleVegetation(bCObjectRefBase *, bCEvent *);

  private:
    GE_UNIMPL_MEMBERS(68)
};

GE_ASSERT_SIZEOF(eCVegetationAdmin, 0x58)
