#pragma once

#include <SharedBase.h>

class eCTemplateEntity;

class GE_DLLIMPORT eCTemplateEntityProxy
{
    // clang-format off
    public: virtual GEU16 GetVersion() const;
    public: virtual bCString GetAddress() const;
    public: virtual bEResult Read(bCIStream &);
    public: virtual bEResult Write(bCOStream &);
    protected: virtual bEResult CopyFrom(eCTemplateEntityProxy const &);
    protected: virtual GEBool Compare(eCTemplateEntityProxy const &) const;
    public: virtual ~eCTemplateEntityProxy();
    // clang-format on

  public:
    eCTemplateEntityProxy(eCTemplateEntityProxy const &);
    explicit eCTemplateEntityProxy(eCTemplateEntity *);
    eCTemplateEntityProxy();

  public:
    explicit operator eCTemplateEntity *();
    explicit operator eCTemplateEntity const *() const;
    eCTemplateEntityProxy const &operator=(eCTemplateEntityProxy const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(eCTemplateEntityProxy const &) const;
    GEBool operator!=(eCTemplateEntityProxy const &) const;
    eCTemplateEntity *operator->();
    eCTemplateEntity const *operator->() const;

  public:
    eCTemplateEntity *GetEntity();
    eCTemplateEntity const *GetEntity() const;
    bCPropertyID const &GetEntityID() const;
    GEBool IsEntityIDValid() const;
    void SetEntity(bCPropertyID const &);
    void SetEntity(bCString const &);
    void SetEntity(eCTemplateEntity const *);

  protected:
    bEResult Create();
    void Destroy();
    void Invalidate();
    void SetEntityInternal(eCTemplateEntity const *);

  private:
    // 0000 // eCTemplateEntityProxy::`vftable'
    /* 0004 */ eCTemplateEntity *mEntityInternal;
    /* 0008 */ bCPropertyID *mEntityID;
};

GE_ASSERT_SIZEOF(eCTemplateEntityProxy, 0xc)

bCIStream &GE_STDCALL operator>>(bCIStream &, eCTemplateEntityProxy &);
bCOStream &GE_STDCALL operator<<(bCOStream &, eCTemplateEntityProxy &);
