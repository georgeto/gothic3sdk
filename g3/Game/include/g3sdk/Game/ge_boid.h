#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCFlock_PS;

enum eEBoidState
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT gCBoid
{
  public:
    gCBoid(gCBoid const &);
    gCBoid();
    ~gCBoid();

  public:
    gCBoid &operator=(gCBoid const &);

  public:
    void AddFlock(eCEntity *);
    void Destroy();
    gESpecies GetSpecies() const;
    void Invalidate();
    void Process();
    GEBool RemoveFlock(eCEntity *, GEBool);

  protected:
    void CalcBoundingSphere();
    void CheckInterventions();
    void CheckStateChanges();
    void FindLeader();
    void FindTravelPoint();
    bCVector GetEvadeVec(gCFlock_PS *);
    bCVector GetNeighbourVelocity(gCFlock_PS *);
    bCVector GetPathVelocity(gCFlock_PS *);
    bCVector GetPerceivedCenterVec(gCFlock_PS *);
    void SetState(eEBoidState);
    void Travel();
};
