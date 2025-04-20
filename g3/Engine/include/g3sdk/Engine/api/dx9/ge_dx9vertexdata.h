#pragma once

#include <Engine/api/ge_apivertexdata.h>

struct ID3DXMesh;
struct IDirect3DDevice9;

class GE_DLLIMPORT eCDX9VertexData : public eCAPIVertexData
{
    // clang-format off
    public: bEResult LockBuffer(GEUInt, GEUInt, GEU32, GELPByte*) override;
    public: bEResult UnlockBuffer() override;
    public: bEResult GetDesc(eCGfxShared::eSGfxVertexBufDesc *) override;
    public: bEResult SetStride(GEU32) override;
    public: ~eCDX9VertexData() override;
    // clang-format on

  public:
    static GEU32 s_u32CountManaged;
    static GEU32 s_u32CountMemManaged;
    static GEU32 s_u32CountMemNonManaged;
    static GEU32 s_u32CountNonManaged;
    static GEU32 s_u32ErrorCorrected;
    static GEU32 s_u32ErrorNotCorrected;
    static GEU32 s_u32PeekManaged;
    static GEU32 s_u32PeekMemManaged;
    static GEU32 s_u32PeekMemNonManaged;
    static GEU32 s_u32PeekNonManaged;

  public:
    eCDX9VertexData(eCDX9VertexData const &);

  public:
    eCDX9VertexData &operator=(eCDX9VertexData const &);

  protected:
    static void(GE_STDCALL *ms_pRegVertexBufferLock)();

  protected:
    static void GE_STDCALL sSetVertexBufferLockCallback(void(GE_STDCALL *)());

  protected:
    eCDX9VertexData(eCGfxShared::eSGfxVertexBufDesc const &, IDirect3DDevice9 *, GEBool &);
    eCDX9VertexData(ID3DXMesh *const, IDirect3DDevice9 *);
};
