#ifndef GFC_BITMAP_H_INCLUDED
#define GFC_BITMAP_H_INCLUDED

class IFFGUIBitmap;

class GE_DLLIMPORT CFFGFCBitmap
{
    private:
        IFFGUIBitmap * m_pHandle;

    public: virtual ~CFFGFCBitmap( void );

    public:
        static CFFGFCBitmap * GE_STDCALL FromHandle( IFFGUIBitmap * );

    public:
        CFFGFCBitmap( CFFGFCBitmap const & );
        CFFGFCBitmap( void );

    public:
        CFFGFCBitmap & operator = ( CFFGFCBitmap const & );

    public:
        GEBool         Create( bCString const & );
        void           Destroy( void );
        IFFGUIBitmap * GetHandle( void ) const;
        GEBool         IsAttached( void ) const;

    protected:
        void SetHandle( IFFGUIBitmap * );

};

GE_ASSERT_SIZEOF(CFFGFCBitmap, 0x08)

#endif
