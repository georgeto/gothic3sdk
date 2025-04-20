#pragma once

#include <Engine/ge_illuminationadmin.h>
#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCGfxImageData;
class eCGfxVisual;

class GE_DLLIMPORT eCResourceMaterialTechnique_PS : public eCResourceBase_PS
{
    // clang-format off
    public: virtual GEBool IsMapChannelUsed(GEU32, GEBool);
    public: virtual GEBool IsDiffuseColorUsed(GEBool);
    public: virtual GEInt Execute(GEInt, eCGfxVisual *, eCGfxImageData *, eCIlluminationAdmin::eSIllumination *) = 0;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override = 0;
    public: bEResult Read(bCIStream &) override = 0;
    public: void Destroy() override = 0;
    public: bEResult Create() override = 0;
    public: bEResult CopyFrom(bCObjectBase const &) override = 0;
    public: ~eCResourceMaterialTechnique_PS() override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: bEResult DoLoad() override = 0;
    public: bEResult DoUnload() override = 0;
    public: bEResult DoReload() override = 0;
    public: bEResult DoConvert() override = 0;
    public: bEResult DoSave() override = 0;
    // clang-format on

  public:
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    eCResourceMaterialTechnique_PS(eCResourceMaterialTechnique_PS const &);
    eCResourceMaterialTechnique_PS();

  public:
    GEBool &AccessIsAlphaTested();
    GEBool &AccessIsUnLit();
    GEBool const &GetIsAlphaTested();
    GEBool const &GetIsBlended();
    GEBool const &GetIsUnLit();
    void SetIsAlphaTested(GEBool const &);
    void SetIsUnLit(GEBool const &);

  protected:
    eCResourceMaterialTechnique_PS const &operator=(eCResourceMaterialTechnique_PS const &);

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(eCResourceMaterialTechnique_PS, 0x30)
