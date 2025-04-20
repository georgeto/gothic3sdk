#pragma once

#include <SharedBase.h>

class eCEntity;
class eCEntityProxyInternal;

class GE_DLLIMPORT eCEntityProxy
{
    // clang-format off
    protected: virtual eCEntity const * ResolveEntity();
    public: virtual GEU16 GetVersion() const;
    public: virtual bCString GetAddress() const;
    public: virtual bEResult Read(bCIStream &);
    public: virtual bEResult Write(bCOStream &);
    protected: virtual bEResult CopyFrom(eCEntityProxy const &);
    protected: virtual GEBool Compare(eCEntityProxy const &) const;
    public: virtual ~eCEntityProxy();
    // clang-format on

  public:
    eCEntityProxy(eCEntityProxy const &);
    explicit eCEntityProxy(eCEntity *);
    eCEntityProxy();

  public:
    explicit operator eCEntity *();
    explicit operator eCEntity const *() const;
    eCEntityProxy const &operator=(eCEntityProxy const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(eCEntityProxy const &) const;
    GEBool operator!=(eCEntityProxy const &) const;
    eCEntity *operator->();
    eCEntity const *operator->() const;

  public:
    eCEntity *GetEntity();
    eCEntity const *GetEntity() const;
    bCPropertyID const &GetEntityID() const;
    GEBool IsEntityIDValid() const;
    void SetEntity(bCPropertyID const &);
    void SetEntity(bCString const &);
    void SetEntity(eCEntity const *);

  protected:
    bEResult Create();
    void Destroy();
    void Invalidate();

  private:
    // 0000 // eCEntityProxy::`vftable'
    /* 0004 */ eCEntityProxyInternal *mEntityProxyInternal;
    /* 0008 */ bCPropertyID mEntityID;
};

GE_ASSERT_SIZEOF(eCEntityProxy, 0x1c)

bCIStream &operator>>(bCIStream &, eCEntityProxy &);
bCOStream &operator<<(bCOStream &, eCEntityProxy &);

template <>
inline GEU32 g_GetHashValue<eCEntityProxy>(eCEntityProxy const &_e)
{
    return g_GetHashValue(_e.GetEntityID());
}
