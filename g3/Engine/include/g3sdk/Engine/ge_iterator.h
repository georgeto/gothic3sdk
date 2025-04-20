#pragma once

#include <Engine/EngineEnum.h>

#include <SharedBase.h>

class eCCameraBase;
class eCCollisionDesc;
class eCContextBase;
class eCEntity;
class eCEntityPropertySet;
class eCFrustumElementItem;
class eCIteratorReport;
class eCResourceDataEntity;
struct eSRayIntersectionDesc;

class eIterator
{
  public:
    enum eAlphaMaterialCollision;
    enum eEHitSubType;
};

class GE_DLLIMPORT eCIterator : public bCObjectRefBase
{
  public:
    enum eEIteratorResult
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCIterator() override;
    // clang-format on

  public:
    eCIterator(eCIterator const &);
    eCIterator();

  public:
    eCIterator const &operator=(eCIterator const &);
    eCIteratorReport const &operator[](GEInt) const;

  public:
    eCIteratorReport &AccessIteratorReportAtIndex(GEInt);
    GEBool AddEntityReport(eCEntity const &, bCObjectRefBase const *, eCCollisionDesc *);
    void ClearIteratorReports();
    GEBool Collect(eSRayIntersectionDesc &, eIterator::eEHitSubType, bTSmallArray<eEPropertySetType> &,
                   bCString const *, eCIterator const *);
    GEBool Collect(bCVolume &, eIterator::eEHitSubType, bTSmallArray<eEPropertySetType> &, bCString const *,
                   eCIterator const *, GEBool, GEFloat);
    GEBool Collect(eIterator::eEHitSubType, bTSmallArray<eEPropertySetType> &, bCString const *, eCIterator const *);
    GEBool CollectScreenRect(bCRect &, eIterator::eEHitSubType, bTSmallArray<eEPropertySetType> &, bCString const *,
                             eCIterator const *, GEBool, GEFloat);
    void EnableContextFilter(GEBool, GEBool(GE_STDCALL *)(eCContextBase *, eCIterator &));
    void EnableEntityFilter(GEBool, GEBool(GE_STDCALL *)(eCEntity *, eCIterator &));
    void EnableMaterialFilter(GEBool, GEBool(GE_STDCALL *)(bCObjectRefBase *, eCResourceDataEntity *, eCIterator &));
    void EnablePropertysetFilter(GEBool, GEBool(GE_STDCALL *)(eCEntityPropertySet *, eCIterator &));
    void EnableRenderstateFilter(GEBool, GEBool(GE_STDCALL *)(eCFrustumElementItem *, eCIterator &));
    eIterator::eAlphaMaterialCollision GetAlphaMaterialCollision() const;
    eCCameraBase *GetCamera() const;
    eIterator::eEHitSubType GetHitSubType() const;
    eCIteratorReport const &GetIteratorReportAtIndex(GEInt) const;
    GEInt GetIteratorReportCount() const;
    bCTriangle::bESides GetPolygonBackfaceCulling() const;
    GEBool IsIteratorReportValid(GEInt) const;
    GEBool PickScene(bCPoint const &, eIterator::eEHitSubType, bTSmallArray<eEPropertySetType> &, bCString const *,
                     GEFloat, eCIterator const *);
    void SetAlphaMaterialCollision(eIterator::eAlphaMaterialCollision);
    void SetCamera(eCCameraBase *);
    void SetPolygonBackfaceCulling(bCTriangle::bESides);
    GEBool TraceRay(bCUnitedRay const &, eIterator::eEHitSubType, bTSmallArray<eEPropertySetType> &, bCString const *,
                    GEFloat, eCIterator const *);
    GEBool TraceRayFirstHit(bCUnitedRay const &, eIterator::eEHitSubType, bTSmallArray<eEPropertySetType> &,
                            bCString const *, GEFloat, eCIterator const *);
    GEBool TraceRayNearestHit(bCUnitedRay const &, eIterator::eEHitSubType, bTSmallArray<eEPropertySetType> &,
                              bCString const *, GEFloat, eCIterator const *);

  protected:
    eEIteratorResult CollectEntities(eSRayIntersectionDesc &, eCEntity const *);
    eEIteratorResult CollectEntities(bCVolume &, eCEntity const *);
    eEIteratorResult CollectEntity(eSRayIntersectionDesc &, eCEntity const &);
    eEIteratorResult CollectEntity(bCVolume &, eCEntity const &);
    eEIteratorResult CollectGameContexts(eSRayIntersectionDesc &);
    eEIteratorResult CollectGameContexts(bCVolume &);
    eEIteratorResult CollectIteratorEntries(eSRayIntersectionDesc &, eCIterator const &);
    eEIteratorResult CollectIteratorEntries(bCVolume &, eCIterator const &);
    eEIteratorResult CollectPropertySet(eSRayIntersectionDesc &, eCEntity const &, eCEntityPropertySet &);
    eEIteratorResult CollectPropertySet(bCVolume &, eCEntity const &, eCEntityPropertySet &);
    eEIteratorResult CollectStaticContexts(eSRayIntersectionDesc &);
    eEIteratorResult CollectStaticContexts(bCVolume &);
    void Invalidate();
};
