#pragma once

#include <SharedBase.h>

class eCResourceAnimationActor_PS;
class eCVisualAnimationLoD;
class eCWrapper_emfx2Actor;

class GE_DLLIMPORT eCAnimation_BaseRenderActor
{
    // clang-format off
    public: virtual bEResult Create(eCResourceAnimationActor_PS *) = 0;
    protected: virtual bEResult Create();
    public: virtual void Destroy();
    public: virtual GEBool RemoveFromList(eCVisualAnimationLoD &) = 0;
    public: virtual void Prefetch(GEInt) = 0;
    public: virtual ~eCAnimation_BaseRenderActor();
    // clang-format on

  public:
    eCAnimation_BaseRenderActor(eCAnimation_BaseRenderActor const &);
    eCAnimation_BaseRenderActor();

  public:
    eCAnimation_BaseRenderActor &operator=(eCAnimation_BaseRenderActor const &);

  public:
    eCWrapper_emfx2Actor *GetActorWrapper();

  protected:
    void Invalidate();
    void SetActorWrapper(eCWrapper_emfx2Actor *);

  private:
    eCWrapper_emfx2Actor *m_pActorWrapper;
};

GE_ASSERT_SIZEOF(eCAnimation_BaseRenderActor, 0x8)
