#pragma once

#include <Game.h>

class GE_DLLIMPORT iCSectorCompiler
{
    // clang-format off
    public: virtual ~iCSectorCompiler();
    // clang-format on

  public:
    explicit iCSectorCompiler(gCSector *);

  public:
    iCSectorCompiler &operator=(iCSectorCompiler const &);

  public:
    GEU32 GetCompiledToHybridEntities() const;
    GEU32 GetCompiledToStaticEntities() const;
    GEU32 GetRemovedEntities() const;
    GEU32 GetScannedEntities() const;
    GEBool IsValid() const;
    GEBool Process();
    void SetLowPolyLayer(gCGeometryLayer *);
    void SetLowPolyMasterEntity(eCDynamicEntity *);

  protected:
    iCSectorCompiler(iCSectorCompiler const &);
    iCSectorCompiler();

  protected:
    void CheckEntitiesForLowPoly(eCEntity *);
    void CheckEntityForLowPoly(eCEntity *);
    void CheckEntityForSpeedTree(eCEntity *);
    bEResult Create(gCSector *);
    GEBool CreateHybridLayer();
    void Destroy();
    eCGeometrySpatialContext &GetDefaultContext();
    eCGeometrySpatialContext *GetHybridContext();
    void Invalidate();
};
