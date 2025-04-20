#pragma once

#include <Engine/ge_enginecomponentbase.h>

#include <SharedBase.h>

class eCParticleMaterial;
class eCParticle_PS;
class eCStrip_PS;

class GE_DLLIMPORT eCParticleModule : public eCEngineComponentBase
{
  public:
    struct SCreateParticleMaterial
    {
        GE_UNIMPL_STRUCT(SCreateParticleMaterial)
    };

    // clang-format off
    public: GEU32 const GetProfileLastTicksFirst() const override;
    public: GEU32 const GetProfileLastTicksSecond() const override;
    public: ~eCParticleModule() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: bEResult RestoreResources(GEBool) override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCParticleModule, eCEngineComponentBase)

  public:
    static eCParticleModule &GE_STDCALL GetInstance();

  public:
    void AddProfileTicksProcess(GEU32);
    void AddProfileTicksRender(GEU32);
    eCParticleMaterial *CreateParticleMaterial(SCreateParticleMaterial const &);
    eCParticle_PS *GetMasterInstance(eCParticle_PS const *);
    void OnDestroy(eCParticle_PS const *);
    void Register(eCParticle_PS *);
    void Register(eCStrip_PS *);
    GEBool RegisterInstance(eCParticle_PS *);
    void Unregister(eCParticle_PS *);
    void Unregister(eCStrip_PS *);
    GEBool UnregisterInstance(eCParticle_PS *);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(64)
};

GE_ASSERT_SIZEOF(eCParticleModule, 0x54)
