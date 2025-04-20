#pragma once

#include <SharedBase/container/array/ge_arraybase.h>
#include <SharedBase/container/array/ge_autoptrarray.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_string.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;
class bCPropertyObjectBase;

class GE_DLLIMPORT bCPropertyObjectFactory
{
    // clang-format off
    protected: virtual void Destroy();
    protected: virtual bCPropertyObjectFactory * DoClone() const;
    protected: virtual void CopyFrom(bCPropertyObjectFactory const &);
    public: virtual ~bCPropertyObjectFactory();
    // clang-format on

  public:
    static GEU16 GE_STDCALL ReadSkip(bCIStream &);

  public:
    explicit bCPropertyObjectFactory(bCString const &);

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    bTArrayBase<bCPropertyObjectBase *>::bCConstIterator BeginIterator() const;
    bTArrayBase<bCPropertyObjectBase *>::bCConstIterator EndIterator() const;
    GEInt GetObjectCount() const;
    GEInt GetPropertyObjectIndex(bCPropertyObjectBase const &) const;
    bCPropertyObjectBase const *GetRootObject() const;
    GEU16 Read(bCIStream &);
    GEBool RegisterPropertyObject(bCPropertyObjectBase const *);
    void SearchPropertyObjects(bTAutoPtrArray<bCPropertyObjectBase *> &, bCString const &);
    GEBool UnregisterPropertyObject(bCPropertyObjectBase const *);
    void Write(bCOStream &);

  protected:
    static GEU16 GE_STDCALL ReadSkipObject(bCIStream &);

  protected:
    bCPropertyObjectFactory(bCPropertyObjectFactory const &);
    bCPropertyObjectFactory();

  protected:
    bCPropertyObjectFactory const &operator=(bCPropertyObjectFactory const &);

  protected:
    bCPropertyObjectFactory *Clone() const;
    bCPropertyObjectBase *CloneObjectInstance() const;
    void CopyTo(bCPropertyObjectFactory &) const;
    void Invalidate();
    bCPropertyObjectBase *ReadNewObject(bCIStream &);
    GEBool ReadObject(bCIStream &, bCPropertyObjectBase &);
    void WriteObject(bCOStream &, bCPropertyObjectBase *) const;

  private:
    bTPtrArray<bCPropertyObjectBase *> m_arrPropertyObject;
    GEU16 m_u16Unknown;
    GE_PADDING(0x2)
    bCString m_strFactoryName;
};

GE_ASSERT_SIZEOF(bCPropertyObjectFactory, 0x18)
