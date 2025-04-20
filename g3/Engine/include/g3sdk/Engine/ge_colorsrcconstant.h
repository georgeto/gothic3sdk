#pragma once

#include <Engine/ge_colorsrcbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCColorSrcConstant : public eCColorSrcBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCColorSrcConstant() override;
    protected: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: bCString const & GetEllementTypeName() const override;
    public: GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool) override;
    public: GEBool GetImplementation(bCString &, eEShaderColorSrcComponent, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCColorSrcConstant, eCColorSrcBase)
    GE_PROPERTY(bCFloatColor, Color, m_colColor)
    GE_PROPERTY(GEFloat, Alpha, m_fAlpha)

  protected:
    void DestroyLocal();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(48)
};

GE_ASSERT_SIZEOF(eCColorSrcConstant, 0x88)

GE_ASSERT_PROPERTY(eCColorSrcConstant, m_colColor, 0x44, 16)
GE_ASSERT_PROPERTY(eCColorSrcConstant, m_fAlpha, 0x54, 4)
