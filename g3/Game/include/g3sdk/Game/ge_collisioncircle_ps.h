#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCCollisionCircle_PSObj;

class GE_DLLIMPORT gCCollisionCircle_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCCollisionCircle_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnPostRead() override;
    public: void OnPropertySetAdded() override;
    public: void OnPropertySetRemoved() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCCollisionCircle_PS, eCEntityPropertySet)
    GE_PROPERTY(GEU32, CircleCount, m_u32CircleCount)
    GE_PROPERTY(GEFloat, DefaultRadius, m_fDefaultRadius)
    GE_PROPERTY(bTValArray<bCVector>, Offset, m_arrOffset)
    GE_PROPERTY(bTValArray<GEFloat>, Radius, m_arrRadius)
    GE_ENUMPROP(gENavObstacleType, Type, m_Type)
    GE_PROPERTY(bTValArray<bCPropertyID>, ZoneEntityIDs, m_arrZoneEntityIDs)

  public:
    void CreatePSObject();
    gCCollisionCircle_PSObj *GetPSObject() const;

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(gCCollisionCircle_PS, 0x4c)

GE_ASSERT_PROPERTY(gCCollisionCircle_PS, m_u32CircleCount, 0x14, 4)
GE_ASSERT_PROPERTY(gCCollisionCircle_PS, m_fDefaultRadius, 0x18, 4)
GE_ASSERT_PROPERTY(gCCollisionCircle_PS, m_arrOffset, 0x1c, 12)
GE_ASSERT_PROPERTY(gCCollisionCircle_PS, m_arrRadius, 0x28, 12)
GE_ASSERT_PROPERTY(gCCollisionCircle_PS, m_Type, 0x34, 8)
GE_ASSERT_PROPERTY(gCCollisionCircle_PS, m_arrZoneEntityIDs, 0x3c, 12)
