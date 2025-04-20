#pragma once

#include <Engine/ge_resourcematerialtechnique_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCResourceMaterialObjectExtended_PS : public eCResourceMaterialTechnique_PS
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceMaterialObjectExtended_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    protected: void CalculateSize() override;
    public: GEInt Execute(GEInt, eCGfxVisual *, eCGfxImageData *, eCIlluminationAdmin::eSIllumination *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceMaterialObjectExtended_PS, eCResourceBase_PS)
    GE_PROPERTY(GEBool, IsBlended, m_bIsBlended)
    GE_PADDING(1)

  public:
    static void GE_STDCALL GetProprietaryFileExt(bCString &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  protected:
    void DeleteResources();
    void Invalidate();
    bEResult RecreateCompleteMaterial();
};

GE_ASSERT_SIZEOF(eCResourceMaterialObjectExtended_PS, 0x34)

GE_ASSERT_PROPERTY(eCResourceMaterialObjectExtended_PS, m_bIsBlended, 0x30, 1)
