#pragma once

#include <Engine/entity/ge_propertysetproxy.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCPropertyProxy : public eCPropertySetProxy
{
    // clang-format off
    public: virtual void Destroy();
    public: virtual bEResult Create();
    public: GEU16 GetVersion() const override;
    public: bCString GetAddress() const override;
    public: bEResult Read(bCIStream &) override;
    public: bEResult Write(bCOStream &) override;
    protected: bEResult CopyFrom(eCEntityProxy const &) override;
    protected: GEBool Compare(eCEntityProxy const &) const override;
    public: ~eCPropertyProxy() override;
    public: void SetAddress(bCString const &) override;
    // clang-format on

  public:
    static void GE_STDCALL SplitAddress(bCString const &, bCString &, bCString &, bCString &);
    static void GE_STDCALL SplitExpression(bCString const &, bCString &, bCString &, bCString &);

  public:
    eCPropertyProxy(eCPropertyProxy const &);
    eCPropertyProxy();

  public:
    eCPropertyProxy const &operator=(eCPropertyProxy const &);

  public:
    GEBool Execute();
    bCString const &GetExpression() const;
    bCString const &GetPropertyName() const;
    bCString GetValue() const;
    GEBool IsAddressValid() const;
    GEBool IsPropertyNameValid() const;
    void SetExpression(bCString const &);
    void SetProperty(bCString const &);
    GEBool SetValue(bCString const &, bCAccessorProperty::eEOperandValue);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(8)
};

GE_ASSERT_SIZEOF(eCPropertyProxy, 0x2c)
