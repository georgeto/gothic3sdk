#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_colorsrcbase.h>

#include <SharedBase.h>

class eCColorSrcProxy;

class GE_DLLIMPORT eCColorSrcCombiner : public eCColorSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCColorSrcCombiner() override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool GetImplementation(bCString &, eEShaderColorSrcComponent, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCColorSrcCombiner, eCColorSrcBase)
    GE_ENUMPROP(eEColorSrcCombinerType, CombinerType, m_eCombinerType)

  public:
    eCColorSrcProxy &GetColorSrc1();
    eCColorSrcProxy &GetColorSrc2();

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(64)
};

GE_ASSERT_SIZEOF(eCColorSrcCombiner, 0x8c)

GE_ASSERT_PROPERTY(eCColorSrcCombiner, m_eCombinerType, 0x44, 8)
