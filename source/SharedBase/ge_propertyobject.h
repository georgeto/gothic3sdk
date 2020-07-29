#ifndef GE_PROPERTYOBJECT_H_INCLUDED
#define GE_PROPERTYOBJECT_H_INCLUDED

template< typename CLASS, typename BASECLASS >
class bTPropertyObject :
    public bTPOPureSmartPtr<CLASS>
{
    public:    virtual CLASS *                          GetObject() const;
    public:    virtual bCString const &                 GetClassName() const;
    public:    virtual bCString const &                 GetBaseClassName() const;
    public:    virtual bCString const &                 GetDescription() const;
    public:    virtual bCPropertyObjectTypeBase const * GetType() const;
    public:    virtual GEU16                            Read( bCIStream & );
    public:    virtual void                             Write( bCOStream & );
    protected: virtual GEU16                            ReadData( bCIStream &, GEU16 );
    protected: virtual void                             WriteData( bCOStream & );
    protected: virtual void                             Destroy( void );
    protected: virtual void                             Create( void );
    public:    virtual bCPropertyObjectBase *           DoClone( void ) const;
    public:    virtual void                             CopyFrom( bCPropertyObjectBase const & );
    public:    virtual                                 ~bTPropertyObject( void );

    public:
        // Use only for self defined property objects
        static inline bTPropertyObjectType<CLASS, BASECLASS> & GetTypeInstance()
        {
            return bTPropertyObjectType<CLASS, BASECLASS>::GetInstance();
        }
    public:
        void CreateInternal( GEBool a_bRoot );
    protected:
        bCPropertyObjectTypeBase * m_pPropertyObjectType;
    public:
        bTPropertyObject( GEBool a_bRoot = GEFalse );
    public:
        bTPropertyObject< CLASS, BASECLASS > & operator = ( bTPropertyObject< CLASS, BASECLASS > const & );
};

#include "ge_propertyobject.inl"

namespace {
    typedef bTPropertyObject<bCObjectRefBase, bCObjectBase> bTPropertyObject_DUMMY;
    GE_ASSERT_SIZEOF(bTPropertyObject_DUMMY, 0x10);
}

#endif
