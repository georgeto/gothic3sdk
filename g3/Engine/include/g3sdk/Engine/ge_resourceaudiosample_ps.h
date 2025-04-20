#pragma once

#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCAudioSound;

class GE_DLLIMPORT eCResourceAudioSample_PS : public eCResourceBase_PS
{
    // clang-format off
    public: virtual eCAudioSound * GetSample() const;
    public: virtual void ApplyDefaults();
    public: GEU16 GetVersion() const override;
    protected: bEResult Write(bCOStream &) override;
    protected: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceAudioSample_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    public: GEBool IsResourceFileAvailable(bCString const &) const override;
    public: void CalculateSize() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceAudioSample_PS, eCResourceBase_PS)

  public:
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  protected:
    void CreateSample();
    void DestroySample();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(eCResourceAudioSample_PS, 0x30)
