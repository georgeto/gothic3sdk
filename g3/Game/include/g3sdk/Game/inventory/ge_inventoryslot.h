#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCInventorySlot : public bCObjectRefBase
{
  public:
    enum ELink
    {
        // TODO: Enumerator values
    };

    // clang-format off
    protected: virtual void OnApplyStats(eCEntity *, eCEntity *);
    protected: virtual void OnUnApplyStats(eCEntity *, eCEntity *);
    public: virtual gCInventorySlot * Clone() const;
    public: void Destroy() override;
    public: ~gCInventorySlot() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCInventorySlot, bCObjectRefBase)
    GE_PROPERTY(eCTemplateEntityProxy, Template, m_entTemplate)
    GE_PROPERTY(eCEntityProxy, Item, m_entItem) // Read only
    GE_ENUMPROP(gESlot, Slot, m_enuSlot)        // Read only

  public:
    static GEBool GE_STDCALL GetBone(gESlot, gEUseType, bCString &, ELink &);
    static GEBool GE_STDCALL GetEquipSlots(gEUseType, gESlot &, gESlot &, eCEntity const *);

  public:
    GEBool EnableRendering(GEBool, eCEntity *);
    gESlot GetAlternativeEquipSlot(eCEntity const *) const;
    gEItemCategory GetCategory() const;
    GEBool GetEquipSlots(gESlot &, gESlot &, eCEntity const *) const;
    gESlot GetPrimaryEquipSlot(eCEntity const *) const;
    gEUseType GetUseType() const;
    GEBool IsConsumable() const;
    GEBool IsEquipment() const;
    GEBool IsLinked() const;
    GEBool IsPermanent() const;
    GEBool LinkToSlot(eCEntity *, gESlot);
    GEBool ReBuildSlot(eCEntity *);
    GEBool UnLinkFromSlot(eCEntity *);
    GEBool UpdateVisibility(eCEntity *);

  protected:
    static GEBool GE_STDCALL AttachItemToSekelton(eCEntity *, eCEntity *, gESlot);
    static GEBool GE_STDCALL DetachItemFromSkeleton(eCEntity *, eCEntity *, gESlot);
    static GEBool GE_STDCALL EnableItemRendering(eCEntity *, eCEntity *, gESlot, GEBool);
    static eCEntity *GE_STDCALL SpawnItem(eCEntity *, eCTemplateEntity const *, GEBool);
    static GEBool GE_STDCALL UpdateItemVisibility(eCEntity *, eCEntity *, gESlot);

  protected:
    void ApplyDefaults();
    void Invalidate();
    eCEntity *SpawnItem(eCEntity *) const;
    eCEntity *SpawnPickUp(eCEntity *) const;
};

GE_ASSERT_SIZEOF(gCInventorySlot, 0x3c)

GE_ASSERT_PROPERTY(gCInventorySlot, m_entTemplate, 0xc, 12)
GE_ASSERT_PROPERTY(gCInventorySlot, m_entItem, 0x18, 28)
GE_ASSERT_PROPERTY(gCInventorySlot, m_enuSlot, 0x34, 8)
