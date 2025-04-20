#pragma once

#include <SharedBase/container/map/ge_ptrmap.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;
class bCPropertyObjectBase;
class bCPropertyObjectTypeBase;
class bCString;

class GE_DLLIMPORT bCPropertyObjectSingleton
{
  public:
    class bCPOTypeListItem
    {
      public:
        explicit bCPOTypeListItem(bCPropertyObjectTypeBase *);

      public:
        bCPOTypeListItem &operator=(bCPOTypeListItem const &);
        bCOStream &operator>>(bCOStream &) const;
        bCIStream &operator<<(bCIStream &);

      public:
        bCPropertyObjectTypeBase *AccessObjectType();
        bCString const &GetBaseClassName() const;
        bCPropertyObjectTypeBase const *GetObjectType() const;
    };

    // clang-format off
    protected: virtual void CopyFrom(bCPropertyObjectSingleton const &);
    protected: virtual ~bCPropertyObjectSingleton();
    // clang-format on

  public:
    static bCPropertyObjectSingleton &GE_STDCALL GetInstance();

  public:
    bTPtrMap<bCString, bCPOTypeListItem *>::bCConstIterator BeginIterator() const;
    void EnableRegistration(GELPVoid, GEBool);
    bTPtrMap<bCString, bCPOTypeListItem *>::bCConstIterator EndIterator() const;
    bCPropertyObjectTypeBase *FindTemplate(bCString const &) const;
    bCPropertyObjectBase const *GetRootObject(bCString const &) const;
    GEBool IsRegistrationEnabled();
    GEBool Matches(bCString const &, bCString const &) const;
    bCPropertyObjectBase *QueryNewObject(bCString const &);
    bCPropertyObjectBase *ReadNewObject(bCIStream &);
    GEBool ReadObject(bCIStream &, bCPropertyObjectBase &);
    GEBool RegisterTemplate(bCPropertyObjectTypeBase const *);
    void WriteObject(bCOStream &, bCPropertyObjectBase *);

  protected:
    bCPropertyObjectSingleton();

  protected:
    bCPropertyObjectSingleton const &operator=(bCPropertyObjectSingleton const &);

  protected:
    void CopyTo(bCPropertyObjectSingleton &) const;
    void Create();
    void Destroy();
    void Invalidate();

  private:
    bCPropertyObjectSingleton(bCPropertyObjectSingleton const &);
};
