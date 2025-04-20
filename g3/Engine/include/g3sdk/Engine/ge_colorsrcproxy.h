#pragma once

#include <Engine/ge_colorsrcbase.h>
#include <Engine/ge_shaderellementproxy_typed.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCColorSrcProxy : public eTShaderEllementProxy<eCColorSrcBase>
{
    // clang-format off
    protected: virtual void CopyFrom(eCColorSrcProxy const &);
    public: void Read(bCIStream &) override;
    public: void Write(bCOStream &) override;
    public: ~eCColorSrcProxy() override;
    protected: void CopyFrom(eTShaderEllementProxy<eCColorSrcBase> const &) override;
    // clang-format on

  public:
    eCColorSrcProxy(eCColorSrcProxy const &);
    explicit eCColorSrcProxy(eCColorSrcBase *);
    eCColorSrcProxy();

  public:
    eCColorSrcProxy const &operator=(eCColorSrcProxy const &);
    GEBool operator==(eCColorSrcProxy const &) const;
    GEBool operator!=(eCColorSrcProxy const &) const;

  public:
    eEShaderColorSrcComponent GetColorComponent() const;
    GEBool GetImplementation(bCString &, GEBool);
    void SetColorComponent(eEShaderColorSrcComponent);

  protected:
    void Invalidate();
};
