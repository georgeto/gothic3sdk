#pragma once

#include <Engine/ge_shaderellementbase.h>
#include <Engine/ge_shaderellementproxy_typed.h>
#include <Engine/ge_texcoordsrcbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTexCoordSrcProxy : public eTShaderEllementProxy<eCTexCoordSrcBase>
{
    // clang-format off
    protected: virtual void CopyFrom(eCTexCoordSrcProxy const &);
    public: GEBool IsVertexTexCoordUsed(GEInt, GEBool) const override;
    public: void Read(bCIStream &) override;
    public: void Write(bCOStream &) override;
    public: ~eCTexCoordSrcProxy() override;
    protected: void CopyFrom(eTShaderEllementProxy<eCTexCoordSrcBase> const &) override;
    // clang-format on

  public:
    eCTexCoordSrcProxy(eCTexCoordSrcProxy const &);
    explicit eCTexCoordSrcProxy(eCTexCoordSrcBase *);
    eCTexCoordSrcProxy();

  public:
    eCTexCoordSrcProxy const &operator=(eCTexCoordSrcProxy const &);
    GEBool operator==(eCTexCoordSrcProxy const &) const;
    GEBool operator!=(eCTexCoordSrcProxy const &) const;

  public:
    GEBool GetDeclarations(bTObjArray<eSShaderMaterialDeclaration> &, GEInt &, GEBool);
    GEBool GetPSImplementation(bCString &, GEInt, GEBool);
    GEBool GetVSImplementation(bCString &, GEInt, GEBool);
    GEInt GetVertexTexCoord() const;
    void SetVertexTexCoord(GEInt);

  protected:
    void Invalidate();
};
