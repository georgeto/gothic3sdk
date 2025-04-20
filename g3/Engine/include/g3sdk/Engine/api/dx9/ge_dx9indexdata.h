#pragma once

#include <Engine/api/ge_apiindexdata.h>

struct ID3DXMesh;
struct IDirect3DDevice9;

class GE_DLLIMPORT eCDX9IndexData : public eCAPIIndexData
{
    // clang-format off
    public: bEResult LockBuffer(GEUInt, GEUInt, GEU32, GELPByte*) override;
    public: bEResult UnlockBuffer() override;
    public: bEResult GetDesc(eCGfxShared::eSGfxIndexBufDesc *) override;
    public: ~eCDX9IndexData() override;
    // clang-format on

  public:
    eCDX9IndexData(eCDX9IndexData const &);

  public:
    eCDX9IndexData &operator=(eCDX9IndexData const &);

  protected:
    static void(GE_STDCALL *ms_pRegIndexBufferLock)();

  protected:
    static void GE_STDCALL sSetIndexBufferLockCallback(void(GE_STDCALL *)());

  protected:
    eCDX9IndexData(eCGfxShared::eSGfxIndexBufDesc const &, IDirect3DDevice9 *, GEBool &);
    eCDX9IndexData(ID3DXMesh *const, IDirect3DDevice9 *);
};
