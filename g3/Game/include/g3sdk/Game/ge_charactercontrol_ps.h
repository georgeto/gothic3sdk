#pragma once

#include <Game/GameEnum.h>
#include <Game/ge_charactermovement_ps.h>

#include <Engine.h>

class GE_DLLIMPORT gCCharacterControl_PS : public eCEntityPropertySet
{
    // clang-format off
    protected: virtual void ProcessMovements();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCCharacterControl_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: void SetEntity(eCEntity *) override;
    public: GEInt OnAction(eCInpShared::eSGameKeyMessage const &) override;
    protected: void OnPreProcess() override;
    protected: void OnPostProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCCharacterControl_PS, eCEntityPropertySet)
    GE_ENUMPROP(gECharacterControlFOR, ControlFrameOfReference, m_enuControlFOR)
    GE_ENUMPROP(gESessionKey, PressedKey, m_enuPressedKey) // Read only
    GE_PROPERTY(GEBool, IsPressed, m_bPressed)             // Read only
    GE_PROPERTY(GEBool, IsPressedBefore, m_bPressedBefore) // Read only
    GE_PADDING(2)
    GE_PROPERTY(GEU32, DurationPressedMSecs, m_u32DurationPressedMSecs) // Read only

  public:
    GEBool GetAnyControlPressed() const;
    bCVector const &GetWishedDirection();
    void SetMovementConstraints(GEFloat);
    void SetWishedMovementMode(gECharMovementMode);

  protected:
    void ClearVolatileFrameStates();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(132)
};

GE_ASSERT_SIZEOF(gCCharacterControl_PS, 0xb0)

GE_ASSERT_PROPERTY(gCCharacterControl_PS, m_enuControlFOR, 0x14, 8)
GE_ASSERT_PROPERTY(gCCharacterControl_PS, m_enuPressedKey, 0x1c, 8)
GE_ASSERT_PROPERTY(gCCharacterControl_PS, m_bPressed, 0x24, 1)
GE_ASSERT_PROPERTY(gCCharacterControl_PS, m_bPressedBefore, 0x25, 1)
GE_ASSERT_PROPERTY(gCCharacterControl_PS, m_u32DurationPressedMSecs, 0x28, 4)
