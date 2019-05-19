#ifndef GFC_BITMAPMAP_H_INCLUDED
#define GFC_BITMAPMAP_H_INCLUDED

class GE_DLLIMPORT CFFGFCBitmapMap
{

    public:
         CFFGFCBitmapMap( CFFGFCBitmapMap const & );
         CFFGFCBitmapMap( void );
        ~CFFGFCBitmapMap( void );

    public:
        CFFGFCBitmapMap & operator = ( CFFGFCBitmapMap const & );

    public:
        CFFGFCBitmap * FromHandle( IFFGUIBitmap * );
        void           RemovePermanent( IFFGUIBitmap * );
        void           SetPermanent( IFFGUIBitmap *, CFFGFCBitmap * );

    protected:
        void           DeleteTemporary( void );
        CFFGFCBitmap * LookupPermanent( IFFGUIBitmap * ) const;
        CFFGFCBitmap * LookupTemporary( IFFGUIBitmap * ) const;

};

#endif
