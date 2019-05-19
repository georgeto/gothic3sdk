#ifndef GE_PO_PURESMARTPTR_H_INCLUDED
#define GE_PO_PURESMARTPTR_H_INCLUDED

template< typename CLASS >
class bTPOPureSmartPtr :
    public bCPropertyObjectBase
{
    public:    virtual GEU16 Read( bCIStream & );
    public:    virtual void  Write( bCOStream & );
    protected: virtual void  Destroy( void );
    protected: virtual void  Create( void );
    public:    virtual bool  SetObject( bCObjectRefBase * );
    public:    virtual void  CopyFrom( bCPropertyObjectBase const & );
    public:    virtual       ~bTPOPureSmartPtr( void );

    protected:
        CLASS * m_pObject;
    private:
        void SetObjectInternal( CLASS * );
    protected:
        bTPOPureSmartPtr( void );  // not defined
    private:
        bTPOPureSmartPtr< CLASS > & operator = ( bTPOPureSmartPtr< CLASS > const & );  // not defined
};

#include "ge_po_puresmartptr.inl"

GE_ASSERT_SIZEOF( bTPOPureSmartPtr<bCObjectRefBase>, 0x0C );

#endif
