#ifndef GFC_DEVICECONTEXTMAP_H_INCLUDED
#define GFC_DEVICECONTEXTMAP_H_INCLUDED

class GE_DLLIMPORT CFFGFCDeviceContextMap
{

    public:
         CFFGFCDeviceContextMap( CFFGFCDeviceContextMap const & );
         CFFGFCDeviceContextMap( void );
        ~CFFGFCDeviceContextMap( void );

    public:
        CFFGFCDeviceContextMap & operator = ( CFFGFCDeviceContextMap const & );

    public:
        CFFGFCDeviceContext * FromHandle( IFFGUIDeviceContext * );
        void                  RemovePermanent( IFFGUIDeviceContext * );
        void                  SetPermanent( IFFGUIDeviceContext *, CFFGFCDeviceContext * );

    protected:
        void                  DeleteTemporary( void );
        CFFGFCDeviceContext * LookupPermanent( IFFGUIDeviceContext * ) const;
        CFFGFCDeviceContext * LookupTemporary( IFFGUIDeviceContext * ) const;

};

#endif
