#pragma once

#include <Engine/ge_resourcesound_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCResourceSoundList_PS : public eCResourceSound_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    protected: bEResult Write(bCOStream &) override;
    protected: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceSoundList_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    public: void CalculateSize() override;
    public: GEInt GetSampleCount() const override;
    public: GEBool GetSampleDescriptor(GEInt, eSResourceSoundSample &) const override;
    public: GEBool SetSampleDescriptor(GEInt, eSResourceSoundSample const &) override;
    public: GEInt InsertSample(GEInt, eSResourceSoundSample const &) override;
    public: GEBool RemoveSample(GEInt) override;
    public: eCAudioSound * GetSound() const override;
    public: eCAudioSound * GetSound(GEInt) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceSoundList_PS, eCResourceSound_PS)
    GE_PROPERTY(GEU32, Reserved, m_u32Reserved)

  public:
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  protected:
    void CreateSound();
    void DestroySound();
    void Invalidate();
    eCAudioSound *LoadSample(GEInt) const;
    GEInt SelectSample() const;

  private:
    GE_UNIMPL_MEMBERS(16)
};

GE_ASSERT_SIZEOF(eCResourceSoundList_PS, 0x84)

GE_ASSERT_PROPERTY(eCResourceSoundList_PS, m_u32Reserved, 0x70, 4)
