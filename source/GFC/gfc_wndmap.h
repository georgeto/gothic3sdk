#ifndef GFC_WNDMAP_H_INCLUDED
#define GFC_WNDMAP_H_INCLUDED

class GE_DLLIMPORT CFFGFCWndMap
{

    public:
         CFFGFCWndMap( CFFGFCWndMap const & );
         CFFGFCWndMap( void );
        ~CFFGFCWndMap( void );

    public:
        CFFGFCWndMap & operator = ( CFFGFCWndMap const & );

    public:
        CFFGFCWnd * FromHandle( IFFGUIWindow * );
        void        RemovePermanent( IFFGUIWindow * );
        void        SetPermanent( IFFGUIWindow *, CFFGFCWnd * );

    protected:
        void        DeleteTemporary( void );
        CFFGFCWnd * LookupPermanent( IFFGUIWindow * ) const;
        CFFGFCWnd * LookupTemporary( IFFGUIWindow * ) const;

};

#endif
