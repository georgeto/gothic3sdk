#pragma once

#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCAPIInstance;
class eCGfxAssistantAdmin;
class eCGfxContextAdmin;
class eCGfxGaugeAdmin;
class eCGfxMixerAdmin;

class GE_DLLIMPORT eCGfxAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCGfxAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult Shutdown() override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCGfxAdmin, eCEngineComponentBase)

  public:
    static bEResult GE_STDCALL sEnumAdapterDesc(GEU32, eCGfxShared::eSGfxAdapterDesc &);
    static bEResult GE_STDCALL sGetAdapterCount(GEU32 &);
    static bEResult GE_STDCALL sGetAdapterDisplayMode(GEU32, eCGfxShared::eSGfxModeDesc &);

  public:
    bEResult Create(eCGfxShared::eEAPIType);
    bEResult EnumContext(GEU32, eCGfxShared::eSGfxContextDesc &) const;
    eCGfxShared::eEAPIType GetAPIType() const;
    eCGfxAssistantAdmin &GetAccessToAssistant();
    eCGfxContextAdmin &GetAccessToContext();
    eCGfxGaugeAdmin &GetAccessToGauge();
    eCGfxMixerAdmin &GetAccessToMixer();
    bEResult GetContextCount(GEU32 &) const;
    void Invalidate();

  protected:
    static eCAPIInstance *ms_pAPIInstance;

  protected:
    static eCAPIInstance *GE_STDCALL sGetAPIInstance();

  protected:
    void InitializeAdmin(eCGfxShared::eEAPIType);

  private:
    GE_UNIMPL_MEMBERS(1540)
};

GE_ASSERT_SIZEOF(eCGfxAdmin, 0x618)
