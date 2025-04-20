#pragma once

#include <Game/GameEnum.h>
#include <Game/ge_mover_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT gCDoor_PS : public gCMover_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCDoor_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void OnPropertySetAdded() override;
    public: void OnPropertySetRemoved() override;
    public: void SetIsOpen(GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCDoor_PS, gCMover_PS)
    GE_ENUMPROP(gEDoorStatus, Status, m_enuStatus)

  public:
    eCEntityProxy &GetNavPathEntityProxy();
    void SetNavPathEntityProxy(eCEntityProxy &);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(32)
};

GE_ASSERT_SIZEOF(gCDoor_PS, 0x13c)

GE_ASSERT_PROPERTY(gCDoor_PS, m_enuStatus, 0x114, 8)
