#pragma once

#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCGfxImageData;

class GE_DLLIMPORT eCResourceImage_PS : public eCResourceBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceImage_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: void SetResourceFilePath(bCString const &) override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    public: GEBool IsDataAvailable() const override;
    protected: void CalculateSize() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceImage_PS, eCResourceBase_PS)

  public:
    static void GE_STDCALL GetProprietaryFileExt(bCString &);
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    bEResult Execute(GEU32, eEResourceCacheBehavior);
    eCGfxImageData *GetAccessToImageData() const;
    GEBool IsMipmapStageAllowed(GEU32, GEU32, GEBool &);
    bEResult LoadAndGetImageData(eCGfxImageData *&);

  protected:
    static GEBool GE_STDCALL IsMipmapStageAllowed(GEU32, GEU32, GEU32, GEBool &);

  protected:
    void DeleteResources();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(28)
};

GE_ASSERT_SIZEOF(eCResourceImage_PS, 0x48)
