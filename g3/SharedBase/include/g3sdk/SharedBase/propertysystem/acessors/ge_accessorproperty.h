#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_string.h>
#include <SharedBase/types/ge_types.h>

class bCAccessorCreator;
class bCAccessorPropertyObject;
class bCObjectRefBase;
class bCPropertyID;
class bCPropertyObjectBase;
class bCPropertyTypeBase;

enum bEPropertyTypeDetail
{
    bEPropertyTypeDetail_None = 0,
    bEPropertyTypeDetail_bCString = 1,
    bEPropertyTypeDetail_bCUnicodeString = 2,
    bEPropertyTypeDetail_bCGuid = 3,
    bEPropertyTypeDetail_bCVector = 4,
    bEPropertyTypeDetail_bCVector4 = 5,
    bEPropertyTypeDetail_bCMatrix = 6,
    bEPropertyTypeDetail_bCMatrix3 = 7,
    bEPropertyTypeDetail_bCBox = 8,
    bEPropertyTypeDetail_bCSphere = 9,
    bEPropertyTypeDetail_bCQuaternion = 10,
    bEPropertyTypeDetail_bCObjectBase = 11,
    bEPropertyTypeDetail_bTPropertyObject = 12,
    bEPropertyTypeDetail_float = 13,
    bEPropertyTypeDetail_double = 14,
    bEPropertyTypeDetail_bool = 15,
    bEPropertyTypeDetail_char = 16,
    bEPropertyTypeDetail___int64 = 17,
    bEPropertyTypeDetail_long = 18,
    bEPropertyTypeDetail_short = 19,
    bEPropertyTypeDetail_int = 20,
    bEPropertyTypeDetail_bTPropertyContainer = 21
};

class GE_DLLIMPORT bCAccessorProperty
{
  public:
    enum eEOperandValue
    {
        eEOperandValue_Assign = 0,
        eEOperandValue_Add = 1,
        eEOperandValue_Subtract = 2,
        eEOperandValue_Multiply = 3,
        eEOperandValue_Divide = 4
    };

  public:
    bCAccessorProperty(bCAccessorProperty const &);
    explicit bCAccessorProperty(bCAccessorCreator const &);
    bCAccessorProperty(bCAccessorCreator const &, bCPropertyID const &);
    bCAccessorProperty(bCAccessorCreator const &, bCString const &);
    explicit bCAccessorProperty(bCAccessorPropertyObject const &);
    explicit bCAccessorProperty(bCObjectRefBase const *);
    bCAccessorProperty(bCObjectRefBase const *, bCString const &);
    explicit bCAccessorProperty(bCPropertyObjectBase const *);
    bCAccessorProperty();
    ~bCAccessorProperty();

  public:
    bCAccessorProperty const &operator=(bCAccessorProperty const &);
    GEBool operator==(bCAccessorProperty const &) const;
    GEBool operator!=(bCAccessorProperty const &) const;
    bCAccessorProperty operator[](bCString const &);
    bCAccessorProperty operator[](bCString const &) const;
    bCAccessorProperty operator++(GEInt);
    bCAccessorProperty &operator++();

  public:
    GEBool Compare(bCAccessorProperty const &) const;
    void ConvertStringToValue(bCString const &, eEOperandValue);
    bCString ConvertValueToString();
    void CopyFrom(bCAccessorProperty const &);
    void CopyTo(bCAccessorProperty &) const;
    void DumpOutputDebugString();
    bCAccessorPropertyObject &GetAccessorPropertyObject();
    bCAccessorPropertyObject const &GetAccessorPropertyObject() const;
    bCString const &GetClassNameA() const;
    bCString const &GetPropertyCategory() const;
    bCString const &GetPropertyDescription() const;
    bCString GetPropertyHeader() const;
    bCPropertyID const &GetPropertyID() const;
    bCString const &GetPropertyName() const;
    bCPropertyObjectBase *GetPropertyObject();
    bCPropertyObjectBase const *GetPropertyObject() const;
    bCString const &GetPropertyType() const;
    bCPropertyTypeBase *GetPropertyTypeObject();
    bCPropertyTypeBase const *GetPropertyTypeObject() const;
    bEPropertyTypeDetail GetPropertyValueDetailType() const;
    void Invalidate();
    GEBool IsEnum() const;
    GEBool IsPropertyReadOnly() const;
    GEBool IsValid() const;

  protected:
    static bCString ms_strEmptyName;

  protected:
    GEBool Iterate();
    GEBool ResolveProperty(bCPropertyID const &);
    GEBool ResolveProperty(bCString const &);

  private:
    GE_UNIMPL_MEMBERS(0xc)
};

GE_ASSERT_SIZEOF(bCAccessorProperty, 0xc)
