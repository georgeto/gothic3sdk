#pragma once

#include <SharedBase/kernel/object/ge_objectrefbase.h>
#include <SharedBase/propertysystem/objects/ge_propertyobjecttypebase.h>

template <typename CLASS, typename BASECLASS>
class bTPropertyObjectType : public bCPropertyObjectTypeBase
{
    // clang-format off
    public:    bCString const &                GetClassName() const override;
    public:    bCString const &                GetBaseClassName() const override;
    public:    bCPropertyObjectFactory const * GetObjectFactory() const override;
    public:    bCPropertyObjectFactory *       AccessObjectFactory() override;
    public:    GEU16                           Read( bCIStream & ) override;
    public:    void                            Write( bCOStream & ) override;
    protected: bCPropertyObjectTypeBase *      DoClone( ) const override;
    protected: void                            CopyFrom( bCPropertyObjectTypeBase const & ) override;
    public:    ~bTPropertyObjectType( ) override;
    // clang-format on

  public:
    static bTPropertyObjectType<CLASS, BASECLASS> &GetInstance(); // Use only for self defined property objects

  private:
    bTPropertyObjectType();

  public:
    bTPropertyObjectType<CLASS, BASECLASS> &operator=(bTPropertyObjectType<CLASS, BASECLASS> const &) = delete;

  private:
    bCPropertyObjectFactory m_PropertyObjectFactory;
};

#include "ge_propertyobjecttype.inl"

using bTPropertyObjectType_DUMMY = bTPropertyObjectType<bCObjectRefBase, bCObjectBase>;
GE_ASSERT_SIZEOF(bTPropertyObjectType_DUMMY, 0x30)
