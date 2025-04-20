#pragma once

#include <SharedBase.h>

class NxActor;
class eCEntity;
class eCPhysicObjectStateBuffer;

class GE_DLLIMPORT eCPhysicObject
{
    // clang-format off
    public: virtual void CacheIn();
    public: virtual void CacheOut();
    public: virtual bEResult Read(bCIStream &);
    public: virtual bEResult Write(bCOStream &);
    public: virtual void Destroy();
    public: virtual bEResult Create();
    public: virtual bEResult Create(bTPtrArray<NxActor *> &);
    public: virtual ~eCPhysicObject();
    // clang-format on

  public:
    explicit eCPhysicObject(eCEntity &);
    eCPhysicObject(eCEntity &, bTPtrArray<NxActor *> &);
    eCPhysicObject(eCPhysicObject const &);

  public:
    NxActor &GetActor();
    NxActor const &GetActor() const;
    bCQuaternion GetBoneOrientation(GEU32, GEFloat);
    bCVector GetBonePosition(GEU32, GEFloat);
    eCPhysicObjectStateBuffer &GetBuffer();
    eCPhysicObjectStateBuffer const &GetBuffer() const;
    GEBool GetCollisionEnabled() const;
    eCEntity &GetEntity();
    eCEntity const &GetEntity() const;
    GEBool GetIgnoredByTraceRay() const;
    GEU32 GetNumBones() const;
    GEBool GetResponseEnabled() const;
    GEBool IsSleeping() const;
    GEBool IsValid() const;
    void Process();
    void PutToSleep();
    void SetCollisionEnabled(GEBool);
    void SetIgnoredByTraceRay(GEBool);
    void SetResponseEnabled(GEBool);
    void SetWorldMatrix(bCMatrix const &);
    void WakeUp();

  protected:
    static bTPtrArray<eCPhysicObjectStateBuffer *> ms_arrBuffers;

  protected:
    static void GE_STDCALL ExecuteBuffers();

  protected:
    void Invalidate();
    void OnActorChanged();
    void SaveStep();

  private:
    eCPhysicObject const &operator=(eCPhysicObject const &);
};
