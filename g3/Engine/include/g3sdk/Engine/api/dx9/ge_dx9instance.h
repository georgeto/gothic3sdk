#pragma once

#include <Engine/api/ge_apiinstance.h>

// No GE_DLLIMPORT on eCDX9Instance, because otherwise eCDX9Instantiator::CreateInstance uses a 'local vftable'.
class eCDX9Instance : public eCAPIInstance
{
    // clang-format off
    public: bEResult Init(eCGfxShared::eEAPIType) override;
    public: bEResult Finit() override;
    public: bEResult GetAdapterCount(GEU32 *) override;
    public: bEResult GetModeCount(GEU32, GEU32 *) override;
    public: bEResult GetAdapterDisplayMode(GEU32, eCGfxShared::eSGfxModeDesc *) override;
    public: bEResult GetAdapterDesc(GEU32, eCGfxShared::eSGfxAdapterDesc *) override;
    public: bEResult GetModeDesc(GEU32, GEU32, eCGfxShared::eSGfxModeDesc *) override;
    public: bEResult CreateDevice(GEU32, eCAPIDevice::eSAPIStartParameters const &, eCAPIDevice **) override;
    public: ~eCDX9Instance() override;
    // clang-format on

  public:
    eCDX9Instance(eCDX9Instance const &);

  public:
    eCDX9Instance &operator=(eCDX9Instance const &);

  protected:
    friend class eCDX9Instantiator;
    explicit eCDX9Instance(eCAPIInstance **);

  private:
    eCGfxShared::eEAPIType m_apiType;
};

GE_ASSERT_SIZEOF(eCDX9Instance, 0xc)

class eCDX9Instantiator
{
  public:
    static eCDX9Instance *CreateInstance(eCAPIInstance **a_ppInstance);
};
