#pragma once

#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCResourceImageAVI_PS : public eCResourceBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceImageAVI_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    public: GEBool IsDataAvailable() const override;
    protected: void CalculateSize() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceImageAVI_PS, eCResourceBase_PS)

  public:
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  protected:
    void DeleteResources();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(28)
};

GE_ASSERT_SIZEOF(eCResourceImageAVI_PS, 0x48)
