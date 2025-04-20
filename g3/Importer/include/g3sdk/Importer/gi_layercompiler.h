#pragma once

#include <Game.h>

class iCSectorCompiler;

class GE_DLLIMPORT iCLayerCompiler
{
  public:
    struct iSCompileDesc
    {
        GE_UNIMPL_STRUCT(iSCompileDesc)
    };

    // clang-format off
    public: virtual ~iCLayerCompiler();
    // clang-format on

  public:
    explicit iCLayerCompiler(iCSectorCompiler &);

  public:
    GEU32 GetCompiledToHybridEntities() const;
    GEU32 GetCompiledToStaticEntities() const;
    GEU32 GetRemovedEntities() const;
    GEU32 GetScannedEntities() const;
    GEBool IsValid() const;
    GEBool Process(bTSmallArray<gCDynamicLayer *> &);

  protected:
    iCLayerCompiler(iCLayerCompiler const &);

  protected:
    GEBool AddEntityToContext(eCEntity *, eCGeometrySpatialContext &);
    bEResult Create();
    void Destroy();
    GEBool HasHybridPropertysets(eCDynamicEntity *) const;
    void Invalidate();
    GEBool IsEntityRemovable(eCDynamicEntity *) const;
    GEBool IsolateEntity(eCEntity *);
    GEBool MoveEntitiesTo(bTSmallArray<eCEntity *> &, eCGeometrySpatialContext *);
    GEBool ProcessEntities(eCDynamicEntity *, iSCompileDesc &);
    GEBool ProcessEntity(eCDynamicEntity *, iSCompileDesc &);
    GEBool RemoveIllegalPropertySets(eCEntity *);
};
