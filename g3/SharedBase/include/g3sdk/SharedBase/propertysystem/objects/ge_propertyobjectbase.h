#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;
class bCObjectRefBase;
class bCPropertyObjectTypeBase;
class bCString;

class GE_DLLIMPORT bCPropertyObjectBase
{
    // clang-format off
    public: virtual bCObjectRefBase * GetObject() const = 0;
    public: virtual bCString const & GetClassName() const = 0;
    public: virtual bCString const & GetBaseClassName() const = 0;
    public: virtual bCString const & GetDescription() const = 0;
    public: virtual bCPropertyObjectTypeBase const * GetType() const = 0;
    public: virtual GEU16 Read(bCIStream &);
    public: virtual void Write(bCOStream &);
    protected: virtual GEU16 ReadData(bCIStream &, GEU16);
    protected: virtual void WriteData(bCOStream &);
    protected: virtual void Destroy() = 0;
    protected: virtual void Create() = 0;
    public: virtual GEBool SetObject(bCObjectRefBase *) = 0;
    public: virtual GEU32 AddReference();
    public: virtual GEU32 ReleaseReference();
    protected: virtual bCPropertyObjectBase * DoClone() const = 0;
    public: virtual void CopyFrom(bCPropertyObjectBase const &);
    public: virtual ~bCPropertyObjectBase();
    // clang-format on

  public:
    explicit bCPropertyObjectBase(bCString const &);

  public:
    bCPropertyObjectBase const &operator=(bCPropertyObjectBase const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    bCPropertyObjectBase *Clone() const;
    void CopyTo(bCPropertyObjectBase &) const;
    GEU32 GetReferenceCount();
    bCPropertyObjectTypeBase const *GetTemplate() const;
    GEU16 GetVersion() const;
    GEBool IsEmbedded() const;
    GEBool IsPersistable() const;
    // The "static XXX::ms_PropertyObjectInstance_XXX" objects are the root objects
    GEBool IsRoot() const;

  protected:
    bCPropertyObjectBase(bCPropertyObjectBase const &);
    bCPropertyObjectBase();

  protected:
    void Invalidate();
    void ObjectPersistable(GEBool);

  protected:
    GEU32 m_u32Bitfield; // Bit0: IsRoot; Bit1: IsPersistable; Bit2: IsEmbedded
};

GE_ASSERT_SIZEOF(bCPropertyObjectBase, 0x8)

GE_DLLIMPORT_EXTC bCString g_strRootPropertyObject_Postfix;
