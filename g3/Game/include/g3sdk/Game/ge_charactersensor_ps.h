#pragma once

#include <Engine.h>

class gCCharacterMovement_PS;

enum gESoftCollisionState
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT gCCharacterSensor_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCCharacterSensor_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCCharacterSensor_PS, eCEntityPropertySet)

  public:
    GEBool GetGoalChanged() const;
    bCQuaternion GetGoalRotation() const;
    bCVector GetPosition() const;
    bCVector GetUnsmoothedPosition() const;
    void SetGoalPose(bCMotion const &, GEBool);
    void SetGoalPosition(bCVector const &, GEBool);
    void SetGoalRotation(bCQuaternion const &);

  protected:
    void ClearVolatileFrameStates();
    void Invalidate();
    GEBool IsHeightDifferenceValid(GEFloat) const;
    void MessageDebug(GELPCChar) const;
    void PostProcessMovements();
    void ProcessPlayerMovements();
    void SaveFrameStates();
    void SetMovement_PS(gCCharacterMovement_PS &);
    void ShowDebug();
    void SmoothGoal(bCVector const &);
    gESoftCollisionState TestSoftCollisions(bCVector const &, bCVector const &, GEFloat, bCVector const &, bCVector &);

  private:
    GE_UNIMPL_MEMBERS(76)
};

GE_ASSERT_SIZEOF(gCCharacterSensor_PS, 0x60)
