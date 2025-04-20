#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/collision/ge_physicsscene.h>
#include <Engine/entity/ge_entitypropertyset.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCPhysicsScene_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCPhysicsScene_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    protected: void OnProcess() override;
    protected: void OnPostRead() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCPhysicsScene_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, IsPhysicsEnabled, m_bPhysicsEnabled)
    GE_PADDING(3)
    GE_PROPERTY(bCVector, GravityVector, m_vecGravity)
    GE_PROPERTY(GEFloat, DefaultSkinWidth, m_fDefaultSkinWidth)
    GE_PROPERTY(GEFloat, DefaultSleepLinVeloSquared, m_fDefaultSleepLinVelo2)
    GE_PROPERTY(GEFloat, DefaultSleepAngVeloSquared, m_fDefaultSleepAngVelo2)
    GE_PROPERTY(GEFloat, BounceTreshold, m_fBounceTreshold)
    GE_PROPERTY(GEFloat, DynFrictionScaling, m_fDynFrictionScaling)
    GE_PROPERTY(GEFloat, StatFrictionScaling, m_fStatFrictionScaling)
    GE_PROPERTY(GEFloat, MaximumAngularVelocity, m_fMaxAngVelocity)
    GE_PROPERTY(GEFloat, SimulationFPS, m_fSimulationFPS)

  public:
    eECollisionGroup GetCollisionGroupEnumByString(bCString) const;
    eCCollisionPairNotification GetCollisionGroupNotifications(eECollisionGroup, eECollisionGroup) const;
    bCString GetCollisionGroupStringByEnum(eECollisionGroup) const;
    GEBool GetGroupsCanCollide(eEShapeGroup, eEShapeGroup) const;
    eEShapeGroup GetShapeGroupEnumByString(bCString) const;
    bCString GetShapeGroupStringByEnum(eEShapeGroup) const;
    void SetCollisionGroupNotifications(eECollisionGroup, eECollisionGroup, eCCollisionPairNotification const &);
    void SetGroupsCanCollide(eEShapeGroup, eEShapeGroup, GEBool);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(48)
};

GE_ASSERT_SIZEOF(eCPhysicsScene_PS, 0x74)

GE_ASSERT_PROPERTY(eCPhysicsScene_PS, m_bPhysicsEnabled, 0x14, 1)
GE_ASSERT_PROPERTY(eCPhysicsScene_PS, m_vecGravity, 0x18, 12)
GE_ASSERT_PROPERTY(eCPhysicsScene_PS, m_fDefaultSkinWidth, 0x24, 4)
GE_ASSERT_PROPERTY(eCPhysicsScene_PS, m_fDefaultSleepLinVelo2, 0x28, 4)
GE_ASSERT_PROPERTY(eCPhysicsScene_PS, m_fDefaultSleepAngVelo2, 0x2c, 4)
GE_ASSERT_PROPERTY(eCPhysicsScene_PS, m_fBounceTreshold, 0x30, 4)
GE_ASSERT_PROPERTY(eCPhysicsScene_PS, m_fDynFrictionScaling, 0x34, 4)
GE_ASSERT_PROPERTY(eCPhysicsScene_PS, m_fStatFrictionScaling, 0x38, 4)
GE_ASSERT_PROPERTY(eCPhysicsScene_PS, m_fMaxAngVelocity, 0x3c, 4)
GE_ASSERT_PROPERTY(eCPhysicsScene_PS, m_fSimulationFPS, 0x40, 4)
