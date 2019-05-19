#ifndef GFC_MODULE_H_INCLUDED
#define GFC_MODULE_H_INCLUDED

class IFFGFCClient;

class GE_DLLIMPORT CFFGFCModule
{
    protected: virtual GEU32 OnCreate( void );
    protected: virtual void  OnDestroy( void );
    public:    virtual      ~CFFGFCModule( void );

    public:
        static CFFGFCModule & GE_STDCALL GetInstance( void );

    public:
        CFFGFCModule( CFFGFCModule const & );

    public:
        CFFGFCModule & operator = ( CFFGFCModule const & );

    public:
        GEBool                   DoModalFrame( void );
        CFFGFCBitmapMap *        GetBitmapMap( void ) const;
        IFFGFCClient *           GetClient( void ) const;
        CFFGFCDeviceContextMap * GetDeviceContextMap( void ) const;
        CFFGFCImageListMap *     GetImageListMap( void ) const;
        CFFGFCWndMap *           GetWndMap( void ) const;
        void                     SetClient( IFFGFCClient * );

    protected:
        CFFGFCModule( void );

    protected:
        GEBool Create( void );
        void   Destroy( void );

};

#endif
