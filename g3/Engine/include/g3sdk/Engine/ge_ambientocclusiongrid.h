#pragma once

#include <SharedBase.h>

class eCEntity;
class eCEntityPropertySet;
class eCIterator;

class GE_DLLIMPORT eCAmbientOcclusionGrid : public bCObjectRefBase
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCAmbientOcclusionGrid() override;
    // clang-format on

  public:
    eCAmbientOcclusionGrid(eCAmbientOcclusionGrid const &);
    eCAmbientOcclusionGrid();

  public:
    eCAmbientOcclusionGrid &operator=(eCAmbientOcclusionGrid const &);

  public:
    GEBool CalcValueAtLocalPos(bCVector const &, GEFloat &) const;
    GEBool CalcValueAtWorldPos(bCVector const &, GEFloat &) const;
    void Clear();
    GEBool ComputeAOGrid(GEBool);
    GEBool ComputePVS();
    bEResult Create(eCEntity *);
    void Invalidate();

  protected:
    static GEInt (*ms_arrNeighborOffsets)[3];

  protected:
    static GEBool GE_STDCALL PVSPropertySetCallback(eCEntityPropertySet *, eCIterator &);

  protected:
    GEU32 GetCellCount() const;
    GEInt GetGridCellIndex(GEInt, GEInt, GEInt) const;
};
