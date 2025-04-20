#pragma once

#include <Engine/ge_shaderellementproxy.h>

template <typename T>
class GE_DLLIMPORT eTShaderEllementProxy : public eCShaderEllementProxy
{
    // clang-format off
    public: eCShaderEllementBase * GetShaderEllement() const override;
    public: GEBool SetShaderEllement(eCShaderEllementBase *) override;
    public: GEBool IsVertexTexCoordUsed(GEInt, GEBool) const override;
    public: GEBool IsVertexDiffuseUsed(GEBool) const override;
    public: void Read(bCIStream &) override;
    public: void Write(bCOStream &) override;
    public: ~eTShaderEllementProxy<T>() override;
    protected: virtual void CopyFrom(eTShaderEllementProxy<T> const &);
    // clang-format on

  public:
    eTShaderEllementProxy<T>(eTShaderEllementProxy<T> const &);
    explicit eTShaderEllementProxy<T>(T *);
    eTShaderEllementProxy<T>();

  public:
    eTShaderEllementProxy<T> const &operator=(eTShaderEllementProxy<T> const &);
    GEBool operator==(eTShaderEllementProxy<T> const &) const;
    GEBool operator!=(eTShaderEllementProxy<T> const &) const;
    T *operator->();
    T const *operator->() const;

  public:
    explicit operator T *();
    explicit operator T const *() const;
    T *GetInstance() const;
    bCGuid const &GetToken() const;
    GEBool IsValid() const;
    void SetInstance(T *);
    void SetToken(bCGuid const &);

  protected:
    void Invalidate();
};
