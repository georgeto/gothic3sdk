#pragma once

#include <SharedBase/propertysystem/objects/ge_propertyobjectbase.h>

template <typename CLASS>
class bTPOPureSmartPtr : public bCPropertyObjectBase
{
    // clang-format off
    public:    GEU16 Read( bCIStream & ) override;
    public:    void  Write( bCOStream & ) override;
    protected: void  Destroy( ) override;
    protected: void  Create( ) override;
    public:    bool  SetObject( bCObjectRefBase * ) override;
    public:    void  CopyFrom( bCPropertyObjectBase const & ) override;
    public:    ~bTPOPureSmartPtr( ) override;
    // clang-format on

  protected:
    CLASS *m_pObject;

  private:
    void SetObjectInternal(CLASS *);

  protected:
    bTPOPureSmartPtr();

  public:
    bTPOPureSmartPtr<CLASS> &operator=(bTPOPureSmartPtr<CLASS> const &) = delete;
};

#include "ge_po_puresmartptr.inl"

GE_ASSERT_SIZEOF(bTPOPureSmartPtr<bCObjectRefBase>, 0x0C)
