#pragma once

#include <SharedBase.h>

class eCDynamicEntity;
class eCEntity;
class eCEntityDynamicContext;

struct eSEntityStatistics
{
    GE_UNIMPL_STRUCT(eSEntityStatistics)
};

class GE_DLLIMPORT eCEntityAdmin : public bCObjectBase
{
  public:
    enum eEProcessingRangeCull
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: GEU32 const GetProfileLastTicksFirst() const override;
    public: ~eCEntityAdmin() override;
    // clang-format on

  public:
    eCEntityAdmin(eCEntityAdmin const &);
    eCEntityAdmin();

  public:
    void AddDirtyProcessingRangeEntity(eCEntity *, GEBool);
    void AddKilledEntity(eCEntity *);
    void ClearProcessingRangeList();
    eEProcessingRangeCull CullOldProcessingRangeRegion(bCBox const &);
    eEProcessingRangeCull CullProcessingRangeRegion(bCBox const &);
    void EnableProcessing(GEBool);
    void FourceFullROIUpdate();
    eCEntityDynamicContext *GetDynamicEntityContext(GEInt) const;
    GEInt GetDynamicEntityContextCount() const;
    bTSmallArray<eCEntity *> const &GetEntitiesInProcessingRange() const;
    bTSmallArray<eCEntity *> const &GetProcessableEntities() const;
    bCSphere const &GetROISphere();
    bCSphere const &GetROIStaticSphere();
    eSEntityStatistics const &GetStatistics();
    GEBool IntersectsOldProcessingRangeRegion(bCBox const &);
    GEBool IntersectsProcessingRangeRegion(bCBox const &);
    GEBool IntersectsStaticProcessingRangeRegion(bCBox const &);
    GEBool IsProcessingEnabled() const;
    void KillEntities();
    void OnEntityProcessingChanged(eCEntity *);
    void Process();
    void RemoveEarlyKilledEntity(eCEntity *);
    void SetKilledEntityCallback(GEBool(GE_STDCALL *)(eCEntity *), GEBool);
    void SetROISphere(bCSphere const &);
    void SetROIStaticSphere(bCSphere const &);
    void UpdateProcessingRangeEntity(eCEntity *, bTSmallArray<eCEntity *> &, bTSmallArray<eCEntity *> &);

  protected:
    eCEntityAdmin const &operator=(eCEntityAdmin const &);

  protected:
    void CollectDynamicProcessingRangeEntity(eCEntity *, bTSmallArray<eCEntity *> &, bTSmallArray<eCEntity *> &);
    void CollectStaticProcessingRangeEntity(eCEntity *, bTSmallArray<eCEntity *> &, bTSmallArray<eCEntity *> &,
                                            eEProcessingRangeCull);
    void Invalidate();
    void NotifyDeleteEntities(eCEntity *);
    GEBool ProcessDynamicEntity(eCDynamicEntity &);
    GEBool RegisterDynamicEntityContext(eCEntityDynamicContext &);
    GEBool RemoveFromProcessingList(eCEntity *);
    GEBool UnregisterDynamicEntityContext(eCEntityDynamicContext &);

  private:
    GE_UNIMPL_MEMBERS(0xfc)
};

GE_ASSERT_SIZEOF(eCEntityAdmin, 0x100)
