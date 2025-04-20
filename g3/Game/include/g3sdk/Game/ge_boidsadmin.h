#pragma once

#include <Engine.h>

class gCBoid;

class GE_DLLIMPORT gCBoidsAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: GEU32 const GetProfileLastTicksFirst() const override;
    public: GEU32 const GetProfileLastTicksSecond() const override;
    public: ~gCBoidsAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCBoidsAdmin, eCEngineComponentBase)

  public:
    void DeregisterFlock(eCEntity *, GEBool);
    void Invalidate();
    void RegisterFlock(eCEntity *);
    GEBool TryMergeWithOtherBoid(gCBoid *);

  protected:
    gCBoid *FindAssembly(eCEntity *);

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(gCBoidsAdmin, 0x20)
