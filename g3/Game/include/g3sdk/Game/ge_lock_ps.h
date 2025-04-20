#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCLock_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCLock_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCLock_PS, eCEntityPropertySet)
    GE_ENUMPROP(gELockStatus, Status, m_enuStatus)
    GE_PROPERTY(eCTemplateEntityProxy, Key, m_proxyKey)
    GE_PROPERTY(GEInt, Difficulty, m_bDifficulty)
    GE_PROPERTY(GEInt, KeyAmount, m_bKeyAmount)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCLock_PS, 0x30)

GE_ASSERT_PROPERTY(gCLock_PS, m_enuStatus, 0x14, 8)
GE_ASSERT_PROPERTY(gCLock_PS, m_proxyKey, 0x1c, 12)
GE_ASSERT_PROPERTY(gCLock_PS, m_bDifficulty, 0x28, 4)
GE_ASSERT_PROPERTY(gCLock_PS, m_bKeyAmount, 0x2c, 4)
