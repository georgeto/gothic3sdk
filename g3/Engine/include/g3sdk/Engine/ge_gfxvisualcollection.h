#pragma once

#include <SharedBase.h>

class eCGfxVisual;

class GE_DLLIMPORT eCGfxVisualCollection : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxVisualCollection const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxVisualCollection() override;
    // clang-format on

  public:
    eCGfxVisualCollection(eCGfxVisualCollection const &);
    eCGfxVisualCollection();

  public:
    eCGfxVisualCollection &operator=(eCGfxVisualCollection const &);

  public:
    GELPVoid AddVisual(eCGfxVisual *, GEInt);
    bEResult BatchInstance(GELPVoid, GELPVoid, enum eEGfxBatchInstanceCall(GE_STDCALL *)(GELPVoid, eCGfxVisual *));
    bEResult BeginBatch();
    bEResult EndBatch();
    void Invalidate();
    bEResult RemoveVisual(GELPVoid);
    void SortingNeedsUpdate();

  protected:
    static GEInt GE_CCALL SortVisuals(GELPCVoid, GELPCVoid);
};
