#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCFocus_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCFocus_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    protected: GEBool IsProcessable() const override;
    protected: GEInt OnAction(eCInpShared::eSGameKeyMessage const &) override;
    protected: void OnRender(GEI16) override;
    protected: void OnProcess() override;
    protected: void OnPostProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCFocus_PS, eCEntityPropertySet)
    GE_ENUMPROP(gEFocusLookAt, FocusLookAtMode, m_enuFocusLookAtMode)
    GE_ENUMPROP(gEFocusLookAtKeysFOR, FocusLookAtKeysFOR, m_enuFocusLookAtKeysFOR)
    GE_PROPERTY(GEFloat, NormalModeItemScanRange, m_fNormalModeItemScanRange)
    GE_PROPERTY(GEFloat, NormalModeItemScanAzi, m_fNormalModeItemScanAzi)
    GE_PROPERTY(GEFloat, NormalModeItemScanElevUp, m_fNormalModeItemScanElevUp)
    GE_PROPERTY(GEFloat, NormalModeItemScanElevDown, m_fNormalModeItemScanElevDown)
    GE_PROPERTY(GEFloat, NormalModeItemPriority, m_fNormalModeItemPriority)
    GE_PROPERTY(GEFloat, NormalModeCharacterScanRange, m_fNormalModeCharacterScanRange)
    GE_PROPERTY(GEFloat, NormalModeCharacterScanAzi, m_fNormalModeCharacterScanAzi)
    GE_PROPERTY(GEFloat, NormalModeCharacterScanElevUp, m_fNormalModeCharacterScanElevUp)
    GE_PROPERTY(GEFloat, NormalModeCharacterScanElevDown, m_fNormalModeCharacterScanElevDown)
    GE_PROPERTY(GEFloat, NormalModeCharacterPriority, m_fNormalModeCharacterPriority)
    GE_PROPERTY(GEFloat, NormalModeInteractScanRange, m_fNormalModeInteractScanRange)
    GE_PROPERTY(GEFloat, NormalModeInteractScanAzi, m_fNormalModeInteractScanAzi)
    GE_PROPERTY(GEFloat, NormalModeInteractScanElevUp, m_fNormalModeInteractScanElevUp)
    GE_PROPERTY(GEFloat, NormalModeInteractScanElevDown, m_fNormalModeInteractScanElevDown)
    GE_PROPERTY(GEFloat, NormalModeInteractPriority, m_fNormalModeInteractPriority)
    GE_PROPERTY(GEFloat, MeleeModeItemScanRange, m_fMeleeModeItemScanRange)
    GE_PROPERTY(GEFloat, MeleeModeItemScanAzi, m_fMeleeModeItemScanAzi)
    GE_PROPERTY(GEFloat, MeleeModeItemScanElevUp, m_fMeleeModeItemScanElevUp)
    GE_PROPERTY(GEFloat, MeleeModeItemScanElevDown, m_fMeleeModeItemScanElevDown)
    GE_PROPERTY(GEFloat, MeleeModeItemPriority, m_fMeleeModeItemPriority)
    GE_PROPERTY(GEFloat, MeleeModeCharacterScanRange, m_fMeleeModeCharacterScanRange)
    GE_PROPERTY(GEFloat, MeleeModeCharacterScanAzi, m_fMeleeModeCharacterScanAzi)
    GE_PROPERTY(GEFloat, MeleeModeCharacterScanElevUp, m_fMeleeModeCharacterScanElevUp)
    GE_PROPERTY(GEFloat, MeleeModeCharacterScanElevDown, m_fMeleeModeCharacterScanElevDown)
    GE_PROPERTY(GEFloat, MeleeModeCharacterPriority, m_fMeleeModeCharacterPriority)
    GE_PROPERTY(GEFloat, MeleeModeInteractScanRange, m_fMeleeModeInteractScanRange)
    GE_PROPERTY(GEFloat, MeleeModeInteractScanAzi, m_fMeleeModeInteractScanAzi)
    GE_PROPERTY(GEFloat, MeleeModeInteractScanElevUp, m_fMeleeModeInteractScanElevUp)
    GE_PROPERTY(GEFloat, MeleeModeInteractScanElevDown, m_fMeleeModeInteractScanElevDown)
    GE_PROPERTY(GEFloat, MeleeModeInteractPriority, m_fMeleeModeInteractPriority)
    GE_PROPERTY(GEFloat, RangedModeItemScanRange, m_fRangedModeItemScanRange)
    GE_PROPERTY(GEFloat, RangedModeItemScanAzi, m_fRangedModeItemScanAzi)
    GE_PROPERTY(GEFloat, RangedModeItemScanElevUp, m_fRangedModeItemScanElevUp)
    GE_PROPERTY(GEFloat, RangedModeItemScanElevDown, m_fRangedModeItemScanElevDown)
    GE_PROPERTY(GEFloat, RangedModeItemPriority, m_fRangedModeItemPriority)
    GE_PROPERTY(GEFloat, RangedModeCharacterScanRange, m_fRangedModeCharacterScanRange)
    GE_PROPERTY(GEFloat, RangedModeCharacterScanAzi, m_fRangedModeCharacterScanAzi)
    GE_PROPERTY(GEFloat, RangedModeCharacterScanElevUp, m_fRangedModeCharacterScanElevUp)
    GE_PROPERTY(GEFloat, RangedModeCharacterScanElevDown, m_fRangedModeCharacterScanElevDown)
    GE_PROPERTY(GEFloat, RangedModeCharacterPriority, m_fRangedModeCharacterPriority)
    GE_PROPERTY(GEFloat, RangedModeInteractScanRange, m_fRangedModeInteractScanRange)
    GE_PROPERTY(GEFloat, RangedModeInteractScanAzi, m_fRangedModeInteractScanAzi)
    GE_PROPERTY(GEFloat, RangedModeInteractScanElevUp, m_fRangedModeInteractScanElevUp)
    GE_PROPERTY(GEFloat, RangedModeInteractScanElevDown, m_fRangedModeInteractScanElevDown)
    GE_PROPERTY(GEFloat, RangedModeInteractPriority, m_fRangedModeInteractPriority)
    GE_PROPERTY(GEFloat, MagicModeItemScanRange, m_fMagicModeItemScanRange)
    GE_PROPERTY(GEFloat, MagicModeItemScanAzi, m_fMagicModeItemScanAzi)
    GE_PROPERTY(GEFloat, MagicModeItemScanElevUp, m_fMagicModeItemScanElevUp)
    GE_PROPERTY(GEFloat, MagicModeItemScanElevDown, m_fMagicModeItemScanElevDown)
    GE_PROPERTY(GEFloat, MagicModeItemPriority, m_fMagicModeItemPriority)
    GE_PROPERTY(GEFloat, MagicModeCharacterScanRange, m_fMagicModeCharacterScanRange)
    GE_PROPERTY(GEFloat, MagicModeCharacterScanAzi, m_fMagicModeCharacterScanAzi)
    GE_PROPERTY(GEFloat, MagicModeCharacterScanElevUp, m_fMagicModeCharacterScanElevUp)
    GE_PROPERTY(GEFloat, MagicModeCharacterScanElevDown, m_fMagicModeCharacterScanElevDown)
    GE_PROPERTY(GEFloat, MagicModeCharacterPriority, m_fMagicModeCharacterPriority)
    GE_PROPERTY(GEFloat, MagicModeInteractScanRange, m_fMagicModeInteractScanRange)
    GE_PROPERTY(GEFloat, MagicModeInteractScanAzi, m_fMagicModeInteractScanAzi)
    GE_PROPERTY(GEFloat, MagicModeInteractScanElevUp, m_fMagicModeInteractScanElevUp)
    GE_PROPERTY(GEFloat, MagicModeInteractScanElevDown, m_fMagicModeInteractScanElevDown)
    GE_PROPERTY(GEFloat, MagicModeInteractPriority, m_fMagicModeInteractPriority)
    GE_PROPERTY(GEBool, AutoCollectFocus, m_bAutoCollectFocus)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, FocusLockMaxDistance, m_fFocusLockMaxDistance)
    GE_PROPERTY(GEFloat, NormalModePreferedRange, m_fNormalModePreferedRange)
    GE_PROPERTY(GEFloat, InteractHighPriorityBonus, m_fInteractHighPriorityBonus)
    GE_PROPERTY(GEBool, DrawFocusName, m_bDrawFocusName)
    GE_PADDING(1)
    GE_PROPERTY(GEBool, HighlightFocus, m_bHighlightFocus)
    GE_PROPERTY(GEBool, HighlightFocusInFight, m_bHighlightFocusInFight)
    GE_ENUMPROP(gEFocus, CurrentMode, m_enuCurrentMode)
    GE_PROPERTY(eCEntityProxy, CurrentEntity, m_CurrentEntity)
    GE_UNIMPL_MEMBERS(12)
    GE_PROPERTY(GEBool, FocusLocked, m_bFocusLocked) // Read only
    GE_PROPERTY(GEBool, EnableRangeRating, m_bEnableRangeRating)
    GE_PADDING(2)
    GE_PROPERTY(GEFloat, OverrideItemPriority, m_fOverrideItemPriority)
    GE_PROPERTY(GEFloat, OverrideCharacterPriority, m_fOverrideCharacterPriority)
    GE_PROPERTY(GEFloat, OverrideInteractPriority, m_fOverrideInteractPriority)
    GE_PROPERTY(GEFloat, OverrideRange, m_fOverrideRange)
    GE_PROPERTY(GEFloat, HardFocusMaxAzi, m_fHardFocusMaxAzi)
    GE_PROPERTY(GEFloat, HardFocusMaxElev, m_fHardFocusMaxElev)
    GE_PROPERTY(GEFloat, HardFocusMaxRange, m_fHardFocusMaxRange)

  public:
    bCVector &AccessCurrentPickPosition();
    GEBool &AccessDrawCrossHair();
    eCEntity *FindFocusEntity(GEBool);
    gECombatMode GetCombatMode() const;
    eCEntity *GetCrossHairEntity();
    bCVector const &GetCurrentPickPosition() const;
    GEBool const &GetDrawCrossHair() const;
    eCEntity *GetFocusEntity(gECombatMode, gEDirection);
    void SetCurrentPickPosition(bCVector const &);
    void SetDrawCrossHair(GEBool const &);
    void SetFocusEntity(eCEntity *);

  protected:
    static GEBool GE_STDCALL S_FilterEntity(eCEntity *, eCCollisionShape *);

  protected:
    void CollectInteractionEntities(GEFloat);
    GEBool FocusCheck(eCEntity *, eCEntity *, GEFloat, GEFloat &);
    GEBool FocusCheckBBox(eCEntity *, eCEntity *, GEFloat, GEFloat &);
    void GetAngles(bCVector const &, GEFloat &, GEFloat &) const;
    void GetAngles(eCEntity *, GEFloat &, GEFloat &) const;
    void GetCurrentMaxAngles(GEFloat &, GEFloat &, GEFloat &) const;
    GEFloat GetCurrentMaxRange() const;
    GEFloat GetCurrentPriority(eCEntity *) const;
    GEBool HasLowerPriority(eCEntity *, eCEntity *) const;
    void Invalidate();
    GEBool IsEntityInAngles(eCEntity *, GEFloat, GEFloat) const;
    GEBool IsEntityInRange(eCEntity *, GEFloat) const;
    GEBool IsEntityInRange2(eCEntity *, GEFloat) const;
    GEBool IsValidEntity(eCEntity *) const;

  private:
    GE_UNIMPL_MEMBERS(32)
};

GE_ASSERT_SIZEOF(gCFocus_PS, 0x198)

GE_ASSERT_PROPERTY(gCFocus_PS, m_enuFocusLookAtMode, 0x14, 8)
GE_ASSERT_PROPERTY(gCFocus_PS, m_enuFocusLookAtKeysFOR, 0x1c, 8)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeItemScanRange, 0x24, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeItemScanAzi, 0x28, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeItemScanElevUp, 0x2c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeItemScanElevDown, 0x30, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeItemPriority, 0x34, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeCharacterScanRange, 0x38, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeCharacterScanAzi, 0x3c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeCharacterScanElevUp, 0x40, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeCharacterScanElevDown, 0x44, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeCharacterPriority, 0x48, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeInteractScanRange, 0x4c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeInteractScanAzi, 0x50, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeInteractScanElevUp, 0x54, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeInteractScanElevDown, 0x58, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModeInteractPriority, 0x5c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeItemScanRange, 0x60, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeItemScanAzi, 0x64, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeItemScanElevUp, 0x68, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeItemScanElevDown, 0x6c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeItemPriority, 0x70, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeCharacterScanRange, 0x74, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeCharacterScanAzi, 0x78, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeCharacterScanElevUp, 0x7c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeCharacterScanElevDown, 0x80, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeCharacterPriority, 0x84, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeInteractScanRange, 0x88, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeInteractScanAzi, 0x8c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeInteractScanElevUp, 0x90, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeInteractScanElevDown, 0x94, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMeleeModeInteractPriority, 0x98, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeItemScanRange, 0x9c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeItemScanAzi, 0xa0, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeItemScanElevUp, 0xa4, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeItemScanElevDown, 0xa8, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeItemPriority, 0xac, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeCharacterScanRange, 0xb0, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeCharacterScanAzi, 0xb4, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeCharacterScanElevUp, 0xb8, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeCharacterScanElevDown, 0xbc, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeCharacterPriority, 0xc0, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeInteractScanRange, 0xc4, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeInteractScanAzi, 0xc8, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeInteractScanElevUp, 0xcc, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeInteractScanElevDown, 0xd0, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fRangedModeInteractPriority, 0xd4, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeItemScanRange, 0xd8, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeItemScanAzi, 0xdc, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeItemScanElevUp, 0xe0, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeItemScanElevDown, 0xe4, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeItemPriority, 0xe8, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeCharacterScanRange, 0xec, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeCharacterScanAzi, 0xf0, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeCharacterScanElevUp, 0xf4, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeCharacterScanElevDown, 0xf8, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeCharacterPriority, 0xfc, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeInteractScanRange, 0x100, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeInteractScanAzi, 0x104, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeInteractScanElevUp, 0x108, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeInteractScanElevDown, 0x10c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fMagicModeInteractPriority, 0x110, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_bAutoCollectFocus, 0x114, 1)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fFocusLockMaxDistance, 0x118, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fNormalModePreferedRange, 0x11c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fInteractHighPriorityBonus, 0x120, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_bDrawFocusName, 0x124, 1)
GE_ASSERT_PROPERTY(gCFocus_PS, m_bHighlightFocus, 0x126, 1)
GE_ASSERT_PROPERTY(gCFocus_PS, m_bHighlightFocusInFight, 0x127, 1)
GE_ASSERT_PROPERTY(gCFocus_PS, m_enuCurrentMode, 0x128, 8)
GE_ASSERT_PROPERTY(gCFocus_PS, m_CurrentEntity, 0x130, 28)
GE_ASSERT_PROPERTY(gCFocus_PS, m_bFocusLocked, 0x158, 1)
GE_ASSERT_PROPERTY(gCFocus_PS, m_bEnableRangeRating, 0x159, 1)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fOverrideItemPriority, 0x15c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fOverrideCharacterPriority, 0x160, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fOverrideInteractPriority, 0x164, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fOverrideRange, 0x168, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fHardFocusMaxAzi, 0x16c, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fHardFocusMaxElev, 0x170, 4)
GE_ASSERT_PROPERTY(gCFocus_PS, m_fHardFocusMaxRange, 0x174, 4)
