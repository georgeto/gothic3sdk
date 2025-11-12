#pragma once

#include <Game/ge_effectmap.h>

#include <Engine.h>

class gCEffect;

class GE_DLLIMPORT gCEffectSystem : public eCEffectSystemBase
{
    // clang-format off
    public: GELPVoid StartEffect(bCString const &, eCEntity *, eCEntity *, bCMatrix const *, GEBool) override;
    public: GEBool StopEffect(GELPVoid, GEBool) override;
    public: GEBool ProcessEffect(GELPVoid, GEFloat) override;
    public: GEBool EnableEffectProcessing(GELPVoid, GEBool) override;
    public: void GetEffectDependencies(bCString const &, bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: ~gCEffectSystem() override;
    // clang-format on

  public:
    gCEffectSystem(gCEffectSystem const &);
    gCEffectSystem();

  public:
    gCEffectSystem &operator=(gCEffectSystem const &);

  public:
    gCEffectMap &GetItems();
    gCEffectMap const &GetItems() const;
    bTValArray<gCEffect *> const &GetRunningEffects() const;
    void Process(GEFloat);

  protected:
    void DeleteAllEffects();
    void Destroy();
    void Invalidate();

  private:
    gCEffectMap m_EffectMap;
    bTPtrArray<gCEffect *> m_RunningEffects;
};

GE_ASSERT_SIZEOF(gCEffectSystem, 0x24)
