#pragma once

#include <Engine/api/ge_apidevice.h>
#include <Engine/ge_gfxshared.h>

class GE_DLLIMPORT eCGfxVertexDecl : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxVertexDecl const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxVertexDecl() override;
    // clang-format on

  public:
    eCGfxVertexDecl(eCGfxVertexDecl const &);
    eCGfxVertexDecl();

  public:
    eCGfxVertexDecl &operator=(eCGfxVertexDecl const &);

  public:
    bEResult Create(eCGfxShared::eSGfxDclElement const *);
    bEResult GetDeclaration(eCGfxShared::eSGfxDclElement *, GEUInt &) const;
    void Invalidate();
    bEResult SetAtPrimitive(eCAPIPrimitive *) const;

  protected:
    bEResult CreateDeclaration(eCGfxShared::eSGfxDclElement const *);
    bEResult DestroyDeclaration();

  public:
    eCAPIDevice *m_pDevice;
    eCGfxShared::eSGfxDclElement *m_pDclElement;
};

GE_ASSERT_SIZEOF(eCGfxVertexDecl, 0x14)
