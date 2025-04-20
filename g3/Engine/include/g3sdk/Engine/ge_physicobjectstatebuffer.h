#pragma once

#include <Engine/EngineEnum.h>

#include <SharedBase.h>

class NxShape;
class eCCollisionShape;
class eCEntity;

enum eEPhysicObjectFlag
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCPhysicObjectStateBuffer
{
  public:
    static eCPhysicObjectStateBuffer ms_BufferDefault;

  public:
    static void GE_STDCALL ClearDefaultBuffer();

  public:
    eCPhysicObjectStateBuffer(eCPhysicObjectStateBuffer const &);
    eCPhysicObjectStateBuffer();
    ~eCPhysicObjectStateBuffer();

  public:
    eCPhysicObjectStateBuffer &operator=(eCPhysicObjectStateBuffer const &);

  public:
    void AddActorFlag(eEPhysicObjectFlag);
    void AddBodyFlag(eERigidbody_Flag);
    void AddForce(bCVector const &, eEForceMode);
    void AddForceAtPos(bCVector const &, bCVector const &, eEForceMode);
    void AddForceAtRelPos(bCVector const &, bCVector const &, eEForceMode);
    void AddRelForce(bCVector const &, eEForceMode);
    void AddRelForceAtPos(bCVector const &, bCVector const &, eEForceMode);
    void AddRelForceAtRelPos(bCVector const &, bCVector const &, eEForceMode);
    void AddRelTorque(bCVector const &, eEForceMode);
    void AddShape(eCCollisionShape *);
    void AddTorque(bCVector const &, eEForceMode);
    void EnableCollisionDetection(GEBool);
    void EnableCollisionResponse(GEBool);
    void EnableShapeCollision(eEShapeGroup, GEBool, GEInt);
    void Execute();
    void Init();
    void RemoveActorFlag(eEPhysicObjectFlag);
    void RemoveBodyFlag(eERigidbody_Flag);
    void RemoveShape(NxShape *);
    void RemoveShapes(eECollisionShapeType);
    void RemoveShapes(eEShapeGroup);
    void RemoveShapes();
    void Reset();
    void SetAngularMomentum(bCVector const &);
    void SetAngularVelocity(bCVector const &);
    void SetCenterOfGravity(bCVector const &);
    void SetCollisionGroup(eECollisionGroup);
    void SetEntity(eCEntity &);
    void SetIsSleeping(GEBool);
    void SetLinearMomentum(bCVector const &);
    void SetLinearVelocity(bCVector const &);
    void SetMass(GEFloat const &);
    void SetMassSpaceInertiaTensor(bCVector const &);
    void SetPose(bCMatrix const &);
    void SetPosition(bCVector const &);
    void SetRotation(bCMatrix3 const &);
    void SetRotation(bCQuaternion const &);
    void SetShapeByLocalAABB(eCCollisionShape *, bCBox const &);
    void SetShapeGroup(eEShapeGroup, eEShapeGroup);

  protected:
    static bCCriticalSectionWin32 ms_csExecuteBuffer;

  protected:
    static eCPhysicObjectStateBuffer &GE_STDCALL GetBuffer(eCEntity &);

  protected:
    void ClearAll();
};
