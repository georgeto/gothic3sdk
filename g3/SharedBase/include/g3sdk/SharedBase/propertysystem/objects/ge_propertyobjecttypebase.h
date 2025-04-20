#pragma once

#include <SharedBase/container/array/ge_arraybase.h>
#include <SharedBase/propertysystem/factories/ge_propertyobjectfactory.h>

class bCIStream;
class bCOStream;
class bCPropertyTypeBase;

class GE_DLLIMPORT bCPropertyObjectTypeBase
{
    // clang-format off
    public: virtual bCString const & GetClassName() const = 0;
    public: virtual bCString const & GetBaseClassName() const = 0;
    public: virtual bCPropertyObjectFactory const * GetObjectFactory() const = 0;
    public: virtual bCPropertyObjectFactory * AccessObjectFactory() = 0;
    public: virtual GEU16 Read(bCIStream &);
    public: virtual void Write(bCOStream &);
    protected: virtual void Destroy();
    protected: virtual bCPropertyObjectTypeBase * DoClone() const;
    protected: virtual void CopyFrom(bCPropertyObjectTypeBase const &);
    public: virtual ~bCPropertyObjectTypeBase();
    // clang-format on

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    bTArrayBase<bCPropertyTypeBase *>::bCConstIterator BeginIterator() const;
    bTArrayBase<bCPropertyTypeBase *>::bCConstIterator EndIterator() const;
    bCPropertyTypeBase const *FindPropertyTemplate(bCString const &) const;
    bCString const &GetDescription() const;
    bCPropertyTypeBase const &GetPropertyType(GEInt) const;
    GEInt GetPropertyTypeCount() const;
    GEBool IsPersistable() const;
    GEBool IsPropertyTypeValid(GEInt) const;
    GEBool RegisterPropertyTemplate(bCPropertyTypeBase const *);
    void SetDescription(bCString const &);
    GEBool UnregisterPropertyTemplate(bCPropertyTypeBase const *);

  protected:
    explicit bCPropertyObjectTypeBase(GEBool);

  protected:
    bCPropertyObjectTypeBase const &operator=(bCPropertyObjectTypeBase const &);

  protected:
    bCPropertyObjectTypeBase *Clone() const;
    void CopyTo(bCPropertyObjectTypeBase &) const;
    void Invalidate();

  private:
    bCPropertyObjectTypeBase(bCPropertyObjectTypeBase const &);
    bCPropertyObjectTypeBase();

  private:
    GEInt GetPropertyTemplateIndex(bCPropertyTypeBase const &) const;

  private:
    bCString m_strDescription;
    bTPtrArray<bCPropertyTypeBase *> m_arrPropertyType;
    GEByte m_u8BitfieldPersistable;
};

GE_ASSERT_SIZEOF(bCPropertyObjectTypeBase, 0x18)
