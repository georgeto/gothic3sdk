#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCItem_PS;

class GE_DLLIMPORT gCEntity : public eCDynamicEntity
{
    // clang-format off
    public: virtual void DoDamage(eCEntity *, eCEntity *, GEInt, GEInt, GEInt, eCContactIterator &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~gCEntity() override;
    public: gCEntity * DoClone() const override;
    protected: void OnUpdatedWorldMatrix() override;
    public: GEBool CreateFromTemplate(bCString const &) override;
    public: void CopyEntityPrivateData(eCEntity const &, GEBool) override;
    public: eCDynamicEntity::eECreatureClass GetCreatureClass() const override;
    public: void OnDamage(eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator &) override;
    // clang-format on

  public:
    static gECombatMode GE_STDCALL GetCombatMode(eCEntity *);
    static gEUseType GE_STDCALL GetUseType(eCEntity *);
    static eCEntity *GE_STDCALL GetWeapon(eCEntity *, GEBool);
    static GEBool GE_STDCALL IsCharacter(eCEntity *);
    static GEBool GE_STDCALL IsDead(eCEntity *);
    static GEBool GE_STDCALL IsDown(eCEntity *);
    static GEBool GE_STDCALL IsInteractable(eCEntity *);
    static GEBool GE_STDCALL IsItem(eCEntity *);
    static GEBool GE_STDCALL IsNPC(eCEntity *);
    static GEBool GE_STDCALL IsPlayer(eCEntity *);
    static GEBool GE_STDCALL IsReady(eCEntity *);

  public:
    gECombatMode GetCombatMode() const;
    gEUseType GetUseType() const;
    eCEntity *GetWeapon(GEBool) const;
    gCItem_PS *GetWeaponItem(GEBool) const;

  protected:
    gCEntity(gCEntity const &);
    gCEntity();

  protected:
    gCEntity const &operator=(gCEntity const &);

  protected:
    GEBool DoExplode();
    void Invalidate();

  private:
    GEBool AddPropertySetToProcessingEntityThisIsAnE3HackDoNotUseLetsTalkAboutItLater(eCEntityPropertySet *, GEBool);
    GEBool RemovePropertySetToProcessingEntityThisIsAnE3HackDoNotUseLetsTalkAboutItLater(GEInt);
};
