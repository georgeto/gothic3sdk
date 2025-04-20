#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCGfxVertexDecl;
class eCGfxVisual;
class eCShaderBase;

class GE_DLLIMPORT eCSkyObject
{
  public:
    struct eSSkyObjectBillboard
    {
        GE_UNIMPL_STRUCT(eSSkyObjectBillboard)
    };

    // clang-format off
    public: virtual void Destroy();
    public: virtual void Create(GEBool, eCGfxShared::eECmpFunc, eCGfxShared::eEWrite, GEU32);
    public: virtual void Render();
    public: virtual ~eCSkyObject();
    // clang-format on

  public:
    eCSkyObject(eCSkyObject const &);
    eCSkyObject();

  public:
    eCSkyObject &operator=(eCSkyObject const &);

  public:
    eSSkyObjectBillboard *AccessBillboards();
    void ClearBillboards();
    void DestroyBuffers();
    GEInt GetBillboardCount() const;
    GEU32 GetBillboardRenderCount() const;
    bTValArray<eSSkyObjectBillboard> const &GetBillboards() const;
    eCShaderBase *GetShader() const;
    eCGfxVisual *GetVisual();
    void SetBillboardCount(GEInt);
    GEBool SetBillboardRenderCount(GEU32);
    void SetBillboards(bTValArray<eSSkyObjectBillboard> const &);
    void SetDirty();
    void SetShader(eCShaderBase *);

  protected:
    static eCGfxVertexDecl *ms_pGfxVertexDecl;

  protected:
    GEBool CreateBuffers();
    void DestroyLocal();
    GEBool FillIndexBuffers();
    GEBool FillVertexBuffer();
    void Invalidate();
};
