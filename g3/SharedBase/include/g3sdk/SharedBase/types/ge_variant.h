#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCVariant
{
  public:
    enum bEType
    {
        // TODO: Enumerator values
    };

    union bUType;

  public:
    explicit bCVariant(GEI8 const &);
    explicit bCVariant(GEU8 const &);
    explicit bCVariant(GEI16 const &);
    explicit bCVariant(GEU16 const &);
    explicit bCVariant(GEInt const &);
    explicit bCVariant(GEI32 const &);
    explicit bCVariant(GEU32 const &);
    explicit bCVariant(GEFloat const &);
    explicit bCVariant(GEDouble const &);
    explicit bCVariant(GELPChar const &);
    explicit bCVariant(GELPVoid const &);
    bCVariant(bCVariant const &);
    explicit bCVariant(GEI64 const &);
    explicit bCVariant(GEU64 const &);
    explicit bCVariant(GEBool const &);
    bCVariant();
    ~bCVariant();

  public:
    bCVariant const &operator=(GEI8 const &);
    bCVariant const &operator=(GEU8 const &);
    bCVariant const &operator=(GEI16 const &);
    bCVariant const &operator=(GEU16 const &);
    bCVariant const &operator=(GEInt const &);
    bCVariant const &operator=(GEI32 const &);
    bCVariant const &operator=(GEU32 const &);
    bCVariant const &operator=(GEFloat const &);
    bCVariant const &operator=(GEDouble const &);
    bCVariant const &operator=(GELPChar const &);
    bCVariant const &operator=(GELPVoid const &);
    bCVariant const &operator=(bCVariant const &);
    bCVariant const &operator=(GEI64 const &);
    bCVariant const &operator=(GEU64 const &);
    bCVariant const &operator=(GEBool const &);

  public:
    void Clear();
    void CopyFrom(bCVariant const &);
    void CopyTo(bCVariant &) const;
    GEBool const &GetBool() const;
    bUType const &GetData() const;
    void GetData(GEI8 &) const;
    void GetData(GEU8 &) const;
    void GetData(GEI16 &) const;
    void GetData(GEU16 &) const;
    void GetData(GEInt &) const;
    void GetData(GEI32 &) const;
    void GetData(GEU32 &) const;
    void GetData(GEFloat &) const;
    void GetData(GEDouble &) const;
    void GetData(GELPChar &) const;
    void GetData(GELPVoid &) const;
    void GetData(bUType &) const;
    void GetData(GEI64 &) const;
    void GetData(GEU64 &) const;
    void GetData(GEBool &) const;
    GEDouble const &GetDouble() const;
    GEFloat const &GetFloat() const;
    GEI16 const &GetI16() const;
    GEI32 const &GetI32() const;
    GEI64 const &GetI64() const;
    GEI8 const &GetI8() const;
    GEInt const &GetInt() const;
    GELPChar const &GetString() const;
    bEType const &GetType() const;
    void GetType(bEType &) const;
    GEU16 const &GetU16() const;
    GEU32 const &GetU32() const;
    GEU64 const &GetU64() const;
    GEU8 const &GetU8() const;
    GELPVoid const &GetVoidPointer() const;
    void SetData(GEI8);
    void SetData(GEU8);
    void SetData(GEI16);
    void SetData(GEU16);
    void SetData(GEInt);
    void SetData(GEI32);
    void SetData(GEU32);
    void SetData(GEFloat);
    void SetData(GEDouble);
    void SetData(GELPCChar);
    void SetData(GELPCVoid);
    void SetData(GEI64);
    void SetData(GEU64);
    void SetData(GEBool);

  protected:
    bUType &AccessData();
    bEType &AccessType();
    void Init();
    void SetData(bUType const &);
    void SetType(bEType const &);
};
