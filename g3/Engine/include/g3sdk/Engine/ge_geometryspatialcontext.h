#pragma once

#include <Engine/entity/ge_spatialentity.h>
#include <Engine/ge_contextbase.h>

#include <SharedBase.h>

class eCArchiveFile;

class GE_DLLIMPORT eCGeometrySpatialContext : public eCContextBase
{
    // clang-format off
    public: virtual void CopyFrom(eCGeometrySpatialContext const &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCGeometrySpatialContext() override;
    public: void SetGraph(eCNode *) override;
    public: GEBool IsProcessing() const override;
    public: eCSpatialEntity * CreateSpecificEntity() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCGeometrySpatialContext, eCContextBase)

  public:
    void Activate();
    void CacheIn();
    void CacheOut();
    void Deactivate();
    void EnableHybridContext(GEBool);
    bCString GetFileBaseName() const;
    void GetFileBaseName(bCString &) const;
    GEU32 GetNodeFileSize() const;
    GEBool IsCachedIn() const;
    GEBool IsHybridContext() const;
    GEBool IsInvalid() const;
    GEBool IsLocked() const;
    GEBool IsSignaledCacheOut() const;
    void Lock();
    void PurgeRenderHooks();
    bEResult ReadNodes();
    void SignalCacheOut();
    void Unlock();
    bEResult WriteNodes();

  protected:
    void Invalidate();
    bEResult ReadNodesOld(eCArchiveFile &, GEU16);
    bEResult ReadNodesV56(eCArchiveFile &);
    bEResult ReadNodesV83(eCArchiveFile &);

  private:
    void TraversePurgeRenderHookEntities(eCSpatialEntity *);
    void TraversePurgeRenderHookEntity(eCSpatialEntity &);

  private:
    GE_UNIMPL_MEMBERS(48)
};

GE_ASSERT_SIZEOF(eCGeometrySpatialContext, 0x88)
