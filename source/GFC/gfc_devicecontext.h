#ifndef GFC_DEVICECONTEXT_H_INCLUDED
#define GFC_DEVICECONTEXT_H_INCLUDED

class IFFGUIDeviceContext;
class GE_DLLIMPORT CFFGFCDeviceContext
{
    public: virtual ~CFFGFCDeviceContext( void );

    public:
        static CFFGFCDeviceContext * GE_STDCALL FromHandle( IFFGUIDeviceContext * );

    public:
        CFFGFCDeviceContext( CFFGFCDeviceContext const & );
        CFFGFCDeviceContext( CFFGFCWnd * );

    public:
        CFFGFCDeviceContext & operator = ( CFFGFCDeviceContext const & );

    public:
        GEInt                 CalcTextRect( GEU32, GELPCChar, GEInt, bCRect &, GEU32 );
        GEInt                 CalcTextRect( GEU32, GELPCUnicodeChar, GEInt, bCRect &, GEU32 );
        void                  Destroy( void );
        GEBool                DrawBitmap( CFFGFCBitmap *, bCRect const *, GEU32, GEFloat );
        GEBool                DrawBitmap( CFFGFCImageList *, GEInt, bCRect const *, GEU32, GEFloat );
        GEBool                DrawTextA( GEU32, GELPCChar, GEInt, bCRect *, GEU32, bCFloatAlphaColor, bCFloatAlphaColor * );
        GEBool                DrawTextA( GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32, bCFloatAlphaColor, bCFloatAlphaColor * );
        IFFGUIDeviceContext * GetHandle( void ) const;
        GEBool                IsAttached( void ) const;

    protected:
        void SetHandle( IFFGUIDeviceContext * );

    private:
        IFFGUIDeviceContext * m_pHandle;
};

GE_ASSERT_SIZEOF( CFFGFCDeviceContext, 0x08 );

#endif
