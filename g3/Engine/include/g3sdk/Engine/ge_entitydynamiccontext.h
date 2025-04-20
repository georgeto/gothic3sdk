#pragma once

#include <Engine/ge_contextbase.h>
#include <Engine/ge_dynamicentity.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCEntityDynamicContext : public eCContextBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCEntityDynamicContext() override;
    public: eCDynamicEntity * CreateSpecificEntity() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCEntityDynamicContext, eCContextBase)

  public:
    void Invalidate();
    bEResult ReadSaveGame(bCIStream &);
    void SetCreationCallbackFunc(eCEntity *(GE_STDCALL *)());
    bEResult WriteSaveGame(bCOStream &);

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(eCEntityDynamicContext, 0x5c)
