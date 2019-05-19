#ifndef GE_PROPERTYOBJECTTYPE_H_INCLUDED
#define GE_PROPERTYOBJECTTYPE_H_INCLUDED

#pragma warning ( push )
#pragma warning ( disable : 4625 ) // copy constructor could not be generated because a base class copy constructor is inaccessible
template< typename CLASS, typename BASECLASS >
class bTPropertyObjectType :
    public bCPropertyObjectTypeBase
{
    public:    virtual bCString const &                GetClassName() const;
    public:    virtual bCString const &                GetBaseClassName() const;
    public:    virtual bCPropertyObjectFactory const * GetObjectFactory() const;
    public:    virtual bCPropertyObjectFactory *       AccessObjectFactory();
    public:    virtual GEU16                           Read( bCIStream & );
    public:    virtual void                            Write( bCOStream & );
    protected: virtual bCPropertyObjectTypeBase *      DoClone( void ) const;
    protected: virtual void                            CopyFrom( bCPropertyObjectTypeBase const & );
    public:    virtual                                ~bTPropertyObjectType( void );

    public:
        static bTPropertyObjectType< CLASS, BASECLASS > & GetInstance(); // Use only for self defined property objects
    private:
        bTPropertyObjectType( void );  // not defined
    private:
        bTPropertyObjectType< CLASS, BASECLASS > & operator = ( bTPropertyObjectType< CLASS, BASECLASS > const & );  // not defined
    private:
        bCPropertyObjectFactory m_PropertyObjectFactory;
};

#include "ge_propertyobjecttype.inl"
#pragma warning ( pop )

namespace {
    typedef bTPropertyObjectType<bCObjectRefBase, bCObjectBase> bTPropertyObjectType_DUMMY;
    GE_ASSERT_SIZEOF( bTPropertyObjectType_DUMMY, 0x30 );
}

#endif
