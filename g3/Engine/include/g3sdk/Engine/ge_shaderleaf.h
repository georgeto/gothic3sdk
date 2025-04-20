#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_shaderbase.h>

#include <SharedBase.h>

class eCColorSrcProxy;

class GE_DLLIMPORT eCShaderLeaf : public eCShaderBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCShaderLeaf() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: GEBool IsVertexTexCoordUsed(GEInt, GEBool) const override;
    public: GEBool IsVertexDiffuseUsed(GEBool) const override;
    public: GEBool IsVertexTangentUsed() const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool SupportsInstancing() const override;
    public: GEBool Prefetch(GEInt) override;
    protected: GEBool CreateShaderVersion(eEShaderMaterialVersion) override;
    public: GEBool HasOpacity() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCShaderLeaf, eCShaderBase)
    GE_ENUMPROP(eEShaderMaterialTransformation, TransformationType, m_eTransformationType)
    GE_PROPERTY(GEBool, EnableSpecular, m_bEnableSpecular)
    GE_PROPERTY(GEBool, DisableLighting, m_bDisableLighting)
    GE_PROPERTY(GEBool, EnableSubSurface, m_bEnableSubSurface)
    GE_PADDING(1)

  public:
    eCColorSrcProxy &GetColorSrcDiffuse();
    eCColorSrcProxy &GetColorSrcNormal();
    eCColorSrcProxy &GetColorSrcSpecular();
    eCColorSrcProxy &GetColorSrcSpecularPower();

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(128)
};

GE_ASSERT_SIZEOF(eCShaderLeaf, 0x14c)

GE_ASSERT_PROPERTY(eCShaderLeaf, m_eTransformationType, 0xc0, 8)
GE_ASSERT_PROPERTY(eCShaderLeaf, m_bEnableSpecular, 0xc8, 1)
GE_ASSERT_PROPERTY(eCShaderLeaf, m_bDisableLighting, 0xc9, 1)
GE_ASSERT_PROPERTY(eCShaderLeaf, m_bEnableSubSurface, 0xca, 1)
