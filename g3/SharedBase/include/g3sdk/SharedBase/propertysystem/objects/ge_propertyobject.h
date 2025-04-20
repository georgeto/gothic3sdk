#pragma once

#include <SharedBase/propertysystem/base/ge_po_puresmartptr.h>
#include <SharedBase/propertysystem/objects/ge_propertyobjecttype.h>

template <typename CLASS, typename BASECLASS>
class bTPropertyObject : public bTPOPureSmartPtr<CLASS>
{
    // clang-format off
    public:    CLASS *                          GetObject() const override;
    public:    bCString const &                 GetClassName() const override;
    public:    bCString const &                 GetBaseClassName() const override;
    public:    bCString const &                 GetDescription() const override;
    public:    bCPropertyObjectTypeBase const * GetType() const override;
    public:    GEU16                            Read( bCIStream & ) override;
    public:    void                             Write( bCOStream & ) override;
    protected: GEU16                            ReadData( bCIStream &, GEU16 ) override;
    protected: void                             WriteData( bCOStream & ) override;
    protected: void                             Destroy( ) override;
    protected: void                             Create( ) override;
    public:    bCPropertyObjectBase *           DoClone( ) const override;
    public:    void                             CopyFrom( bCPropertyObjectBase const & ) override;
    public:    ~bTPropertyObject( ) override;
    // clang-format on

  public:
    // Use only for self defined property objects
    static inline bTPropertyObjectType<CLASS, BASECLASS> &GetTypeInstance()
    {
        return bTPropertyObjectType<CLASS, BASECLASS>::GetInstance();
    }

  public:
    void CreateInternal(GEBool a_bRoot);

  protected:
    bCPropertyObjectTypeBase *m_pPropertyObjectType;

  public:
    explicit bTPropertyObject(GEBool a_bRoot = GEFalse);

  public:
    bTPropertyObject<CLASS, BASECLASS> &operator=(bTPropertyObject<CLASS, BASECLASS> const &);
};

#include "ge_propertyobject.inl"

using bTPropertyObject_DUMMY = bTPropertyObject<bCObjectRefBase, bCObjectBase>;
GE_ASSERT_SIZEOF(bTPropertyObject_DUMMY, 0x10)
