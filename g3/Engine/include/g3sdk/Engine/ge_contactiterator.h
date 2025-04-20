#pragma once

#include <Engine/EngineEnum.h>

#include <SharedBase.h>

class NxContactPair;
class NxShape;
class eCCollisionShape;

enum eECollisionPairFlags
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCContactIterator
{
  public:
    eCContactIterator(NxContactPair &, GEBool);
    eCContactIterator(eCContactIterator const &);
    explicit eCContactIterator(eEPropertySetType);
    eCContactIterator(eEPropertySetType, bCVector const &);
    eCContactIterator(eEPropertySetType, bCVector const &, bCString &, GEInt);
    eCContactIterator(eEPropertySetType, bCVector const &, eCCollisionShape *);
    eCContactIterator();
    ~eCContactIterator();

  public:
    eCContactIterator &operator=(eCContactIterator const &);

  public:
    bCVector &GetAvgCollisionPosition();
    bCString const &GetBone(GEInt);
    GEInt const GetBoneIndex(GEInt);
    eEPropertySetType GetCollisionType();
    GEU32 GetExtData();
    GEU32 GetNumPatches();
    GEU32 GetNumPatchesRemaining();
    GEU32 GetNumPoints();
    GEU32 GetNumPointsRemaining();
    GEU32 GetNumShapes();
    eECollisionPairFlags GetPairFlags();
    bCVector GetPatchNormal();
    bCVector GetPoint();
    NxShape *GetProprietaryShape(GEInt);
    GEFloat GetSeparation();
    eCCollisionShape *GetShape(GEInt);
    bCVector GetShapeCenter(GEInt);
    GEFloat GetShapeDepth(GEInt);
    eEShapeGroup GetShapeGroup(GEInt);
    GEFloat GetShapeHeight(GEInt);
    eEShapeMaterial GetShapeMaterial(GEInt);
    bCMatrix3 GetShapeOrientation(GEInt);
    eECollisionShapeType GetShapeType(GEInt);
    GEFloat GetShapeWidth(GEInt);
    bCVector const &GetSumFrictionForce() const;
    bCVector const &GetSumNormalForce() const;
    GEBool GoNextPatch();
    GEBool GoNextPoint();
    GEBool GoNextShape();
    GEBool IsPointShape() const;
    GEBool IsValid() const;
    void ResetIterator();

  protected:
    void CreateIterator();
};
