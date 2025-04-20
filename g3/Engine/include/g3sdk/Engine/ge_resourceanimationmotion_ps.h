#pragma once

#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCWrapper_emfx2Motion;

class GE_DLLIMPORT eCResourceAnimationMotion_PS : public eCResourceBase_PS
{
  public:
    struct eSFrameEffect
    {
        GE_UNIMPL_STRUCT(eSFrameEffect)
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceAnimationMotion_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    protected: void CalculateSize() override;
    protected: GEBool IsLocked() override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void OnUpdateInternals() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceAnimationMotion_PS, eCResourceBase_PS)

  public:
    static void GE_STDCALL GetNativeFileExt(bCString &);
    static void GE_STDCALL GetProprietaryFileExt(bCString &);
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    bTObjArray<eSFrameEffect> const &GetFrameEffectList() const;
    eCWrapper_emfx2Motion &GetMotionObject();

  protected:
    void DeleteResources();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(44)
};

GE_ASSERT_SIZEOF(eCResourceAnimationMotion_PS, 0x58)
