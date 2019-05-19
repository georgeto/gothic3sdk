#ifndef GFC_IMAGELIST_H_INCLUDED
#define GFC_IMAGELIST_H_INCLUDED

class IFFGUIImageList;
class SFFGUIBitmap;

class GE_DLLIMPORT CFFGFCImageList
{
    public: virtual ~CFFGFCImageList( void );

    public:
        static CFFGFCImageList * GE_STDCALL FromHandle( IFFGUIImageList * );

    public:
        CFFGFCImageList( CFFGFCImageList const & );
        CFFGFCImageList( void );

    public:
        CFFGFCImageList & operator = ( CFFGFCImageList const & );

    public:
        GEInt             AddImage( CFFGFCBitmap * );
        void              Create( void );
        void              Destroy( void );
        IFFGUIImageList * GetHandle( void ) const;
        GEInt             GetImageCount( void ) const;
        GEBool            GetImageInfo( GEInt, SFFGUIBitmap & ) const;
        GEBool            IsAttached( void ) const;
        GEBool            LoadBitmapA( CFFGFCBitmap *, GEInt, GEInt, GEInt, GEU32 );
        GEBool            RemoveImage( GEInt );
        GEBool            ReplaceImage( GEInt, CFFGFCBitmap * );
        GEBool            SetImageCount( GEInt );

    protected:
        void SetHandle( IFFGUIImageList * );

    private:
        unsigned __int32 __UNK_0004;

};

GE_ASSERT_SIZEOF(CFFGFCImageList, 0x08)

#endif
