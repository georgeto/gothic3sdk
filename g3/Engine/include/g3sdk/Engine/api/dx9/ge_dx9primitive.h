#pragma once

#include <Engine/api/ge_apiprimitive.h>

class eCDX9Device;
struct IDirect3DDevice9;

class GE_DLLIMPORT eCDX9Primitive : public eCAPIPrimitive
{
    // clang-format off
    public: GEBool SetStream(GEU32, eCAPIVertexData *) override;
    public: GEBool SetIndexData(eCAPIIndexData *) override;
    public: GEBool SetVertexDecl(GELPVoid) override;
    public: GEBool SetFVF(GEU32) override;
    public: GEBool SetStreamSrcFrequency(GEU32, GEU32) override;
    public: GEU32 GetStreamSrcFrequency(GEU32) const override;
    public: GEBool SetStreamOffset(GEU32, GEU32) override;
    public: GEU32 GetStreamOffset(GEU32) const override;
    public: GEBool SetStreamStride(GEU32, GEU32) override;
    public: GEU32 GetStreamStride(GEU32) const override;
    public: GEBool SetDrawCallDescription(eCGfxShared::eSGfxDrawCallDesc const &) override;
    public: eCGfxShared::eSGfxDrawCallDesc & GetDrawCallDescription() override;
    public: eCGfxShared::eSGfxDrawCallDesc const & GetDrawCallDescription() const override;
    public: void EnableStream(GEU32, GEBool) override;
    public: GEBool IsStreamEnabled(GEU32) const override;
    public: GEBool Execute() override;
    public: ~eCDX9Primitive() override;
    // clang-format on

  public:
    eCDX9Primitive(eCDX9Primitive const &);
    eCDX9Primitive(IDirect3DDevice9 *, eCDX9Device *);

  public:
    eCDX9Primitive &operator=(eCDX9Primitive const &);
};
