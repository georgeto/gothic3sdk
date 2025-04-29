#pragma once

#include <Engine/entity/proxy/ge_entityproxy.h>

#include <SharedBase.h>

class eCEntityPropertySet;

class GE_DLLIMPORT eCPropertySetProxy : public eCEntityProxy
{
    // clang-format off
    public: virtual void SetAddress(bCString const &);
    protected: eCEntity const * ResolveEntity() override;
    public: GEU16 GetVersion() const override;
    public: bCString GetAddress() const override;
    public: bEResult Read(bCIStream &) override;
    public: bEResult Write(bCOStream &) override;
    protected: bEResult CopyFrom(eCEntityProxy const &) override;
    protected: GEBool Compare(eCEntityProxy const &) const override;
    public: ~eCPropertySetProxy() override;
    // clang-format on

  public:
    eCPropertySetProxy(eCPropertySetProxy const &);
    eCPropertySetProxy();

  public:
    eCPropertySetProxy const &operator=(eCPropertySetProxy const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    eCEntityPropertySet *GetAccessToPropertySet();
    eCEntityPropertySet const *GetPropertySet() const;
    bCString const &GetPropertySetType() const;
    GEBool IsPropertySetNameValid() const;
    GEBool IsPropertySetValid() const;
    void SetPropertySet(bCString const &);
    void SetPropertySet(eCEntityPropertySet const *);
    void SetPropertySetComfort(eCEntityPropertySet const *);

  protected:
    bEResult Create();
    void Destroy();
    void Invalidate();
    void SetPropertySetInternal(eCEntityPropertySet const *);

  private:
    // 0000 // eCPropertySetProxy::`vftable'
    // 0004 // eCEntityProxyInternal* mEntityProxyInternal;
    // 0008 // bCPropertyID mEntityID;
    /* 001C */ eCEntityPropertySet *m_EntityPropertySet;
    /* 0020 */ bCString *m_pEntityPropertySetName;
};

GE_ASSERT_SIZEOF(eCPropertySetProxy, 0x24)

template <>
inline GEU32 GE_STDCALL g_GetHashValue<eCPropertySetProxy>(eCPropertySetProxy const &_e)
{
    return g_GetHashValue(_e.GetEntityID());
}
