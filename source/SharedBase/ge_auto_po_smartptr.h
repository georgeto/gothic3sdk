#ifndef GE_AUTO_PO_SMARTPTR_H_INCLUDED
#define GE_AUTO_PO_SMARTPTR_H_INCLUDED

template< typename CLASS >
class bTAutoPOSmartPtr
{
    public:
        void CopyFrom( bTAutoPOSmartPtr< CLASS > const & a_Source );
        void Create( void );
        void Destroy( void );
        void SetPropertyObject( bTPOPureSmartPtr<CLASS> * a_Source );

    public:
         bTAutoPOSmartPtr( void );
         bTAutoPOSmartPtr( CLASS & a_Object );
        ~bTAutoPOSmartPtr( void );

    public:
        bTAutoPOSmartPtr< CLASS > & operator =             ( bTAutoPOSmartPtr< CLASS > const & );
                                    operator CLASS *       ( void );
                                    operator CLASS const * ( void ) const;
        CLASS *                     operator ->            ( void );
        CLASS const *               operator ->            ( void ) const;
        bCOStream &                 operator >>            ( bCOStream & );
        bCIStream &                 operator <<            ( bCIStream & );

    private:
        bTPOPureSmartPtr<CLASS> * m_pPropertyObject;
};

#include "ge_auto_po_smartptr.inl"

GE_ASSERT_SIZEOF( bTAutoPOSmartPtr<bCObjectRefBase>, 0x04 );

#endif
