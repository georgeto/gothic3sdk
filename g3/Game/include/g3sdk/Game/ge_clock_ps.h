#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCClock_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCClock_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsProcessable() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void OnProcess() override;
    public: void OnPreProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCClock_PS, eCEntityPropertySet)
    GE_PROPERTY(GEU32, Year, m_u32Year)
    GE_PROPERTY(GEU32, Day, m_u32Day)
    GE_PROPERTY(GEU32, Hour, m_u32Hour)
    GE_PROPERTY(GEU32, Minute, m_u32Minute)
    GE_PROPERTY(GEU32, Second, m_u32Second)
    GE_PROPERTY(GEFloat, Factor, m_fFactor)

  public:
    GEU32 GetTimeStampInSeconds() const;
    GEBool IsPaused() const;
    void PauseClock();
    void ResumeClock();

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(48)
};

GE_ASSERT_SIZEOF(gCClock_PS, 0x5c)

GE_ASSERT_PROPERTY(gCClock_PS, m_u32Year, 0x14, 4)
GE_ASSERT_PROPERTY(gCClock_PS, m_u32Day, 0x18, 4)
GE_ASSERT_PROPERTY(gCClock_PS, m_u32Hour, 0x1c, 4)
GE_ASSERT_PROPERTY(gCClock_PS, m_u32Minute, 0x20, 4)
GE_ASSERT_PROPERTY(gCClock_PS, m_u32Second, 0x24, 4)
GE_ASSERT_PROPERTY(gCClock_PS, m_fFactor, 0x28, 4)
