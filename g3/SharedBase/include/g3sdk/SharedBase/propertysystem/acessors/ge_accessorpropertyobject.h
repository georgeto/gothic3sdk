#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_string.h>
#include <SharedBase/types/ge_types.h>

class bCAccessorCreator;
class bCIStream;
class bCOStream;
class bCObjectRefBase;
class bCPropertyObjectBase;
class bCPropertyObjectTypeBase;

class GE_DLLIMPORT bCAccessorPropertyObject
{
  public:
    bCAccessorPropertyObject(bCAccessorPropertyObject const &);
    explicit bCAccessorPropertyObject(bCAccessorCreator const &);
    explicit bCAccessorPropertyObject(bCString const &);
    explicit bCAccessorPropertyObject(bCObjectRefBase *);
    explicit bCAccessorPropertyObject(bCPropertyObjectBase *);
    explicit bCAccessorPropertyObject(bCObjectRefBase const *);
    explicit bCAccessorPropertyObject(bCPropertyObjectBase const *);
    bCAccessorPropertyObject();
    ~bCAccessorPropertyObject();

  public:
    bCAccessorPropertyObject const &operator=(bCAccessorPropertyObject const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCAccessorPropertyObject const &) const;
    GEBool operator!=(bCAccessorPropertyObject const &) const;
    bCAccessorPropertyObject operator++(GEInt);
    bCAccessorPropertyObject &operator++();

  public:
    bCAccessorPropertyObject Clone() const;
    GEBool Compare(bCAccessorPropertyObject const &) const;
    void CopyFrom(bCAccessorPropertyObject const &);
    void CopyTo(bCAccessorPropertyObject &) const;
    void DumpOutputDebugString(GEBool);
    bCAccessorPropertyObject GetBaseClass() const;
    bCString const &GetClassNameA() const;
    bCObjectRefBase *GetNativeObject();
    bCObjectRefBase const *GetNativeObject() const;
    bCPropertyObjectBase *GetPropertyObject();
    bCPropertyObjectBase const *GetPropertyObject() const;
    bCString GetPropertyObjectHeader() const;
    bCPropertyObjectTypeBase const *GetPropertyObjectType() const;
    bCPropertyObjectBase const *GetRootObject() const;
    GEBool HasBaseClass() const;
    GEBool HasPropertyObject() const;
    GEBool IsDerivedFrom(bCAccessorPropertyObject const &) const;
    GEBool IsDerivedFrom(bCPropertyObjectBase const *) const;
    GEBool IsKindOf(bCAccessorPropertyObject const &) const;
    GEBool IsValid() const;
    GEU16 Read(bCIStream &);
    void Write(bCOStream &);

  protected:
    void Invalidate();
    void SetInstance(bCObjectRefBase *);
    void SetInstance(bCPropertyObjectBase *);

  private:
    GE_UNIMPL_MEMBERS(0x8)
};

GE_ASSERT_SIZEOF(bCAccessorPropertyObject, 0x8)

bCOStream &GE_STDCALL operator<<(bCOStream &, bCAccessorPropertyObject &);
bCIStream &GE_STDCALL operator>>(bCIStream &, bCAccessorPropertyObject &);
