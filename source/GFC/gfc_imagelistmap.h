#ifndef GFC_IMAGELISTMAP_H_INCLUDED
#define GFC_IMAGELISTMAP_H_INCLUDED

class GE_DLLIMPORT CFFGFCImageListMap
{

    public:
         CFFGFCImageListMap( CFFGFCImageListMap const & );
         CFFGFCImageListMap( void );
        ~CFFGFCImageListMap( void );

    public:
        CFFGFCImageListMap & operator = ( CFFGFCImageListMap const & );

    public:
        CFFGFCImageList * FromHandle( IFFGUIImageList * );
        void              RemovePermanent( IFFGUIImageList * );
        void              SetPermanent( IFFGUIImageList *, CFFGFCImageList * );

    protected:
        void              DeleteTemporary( void );
        CFFGFCImageList * LookupPermanent( IFFGUIImageList * ) const;
        CFFGFCImageList * LookupTemporary( IFFGUIImageList * ) const;

};

#endif
