#pragma once

#include <Engine/ge_colorsrcbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCColorSrcMask : public eCColorSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCColorSrcMask() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEInt GetProxyCount() const override;
    public: eCShaderEllementProxy const * GetProxyAt(GEInt) const override;
    public: bCString GetProxyNameAt(GEInt) const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool GetImplementation(bCString &, eEShaderColorSrcComponent, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCColorSrcMask, eCColorSrcBase)
    GE_PROPERTY(GEFloat, MaskThreshold, m_fMaskThreshold)

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(68)
};

GE_ASSERT_SIZEOF(eCColorSrcMask, 0x8c)

GE_ASSERT_PROPERTY(eCColorSrcMask, m_fMaskThreshold, 0x44, 4)
