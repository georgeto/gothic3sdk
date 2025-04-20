#pragma once

#include <SharedBase.h>

class eCAnimation_HardRenderActor;
class eCResourceDataEntity;
class eCVisualAnimationLoD;
class eCVisualAnimation_PS;

class GE_DLLIMPORT eCAnimation_HardwareSkinner : public bCObjectRefBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCAnimation_HardwareSkinner() override;
    // clang-format on

  public:
    eCAnimation_HardwareSkinner(eCAnimation_HardwareSkinner const &);
    eCAnimation_HardwareSkinner();

  public:
    void PrefetchActor(eCVisualAnimation_PS &);
    GEBool RemoveActorResource(eCResourceDataEntity *);
    void ResetResources();

  protected:
    eCAnimation_HardwareSkinner const &operator=(eCAnimation_HardwareSkinner const &);

  protected:
    eCAnimation_HardRenderActor *InsertOrGetActor(eCVisualAnimationLoD &, eCVisualAnimation_PS &);
    void Invalidate();
    GEBool RemoveActor(eCVisualAnimationLoD &);
    void Render(eCVisualAnimation_PS &, GEBool, GEBool);

  public:
    bTPtrMap<eCResourceDataEntity *, eCAnimation_HardRenderActor *> m_mapResourceToActor;
    bTPtrArray<eCVisualAnimationLoD *> m_arrVisAnimLoD;
};

GE_ASSERT_SIZEOF(eCAnimation_HardwareSkinner, 0x28)
