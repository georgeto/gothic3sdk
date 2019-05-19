#ifndef GFC_DIALOG_H_INCLUDED
#define GFC_DIALOG_H_INCLUDED

class GE_DLLIMPORT CFFGFCDialog :
    public CFFGFCWnd
{
    public:    virtual GEInt  DoModal( void );
    public:    virtual GEBool OnInitDialog( void );
    public:    virtual void   OnOK( void );
    public:    virtual void   OnCancel( void );
    protected: virtual GEInt  WindowProc( GEUInt, GEUInt, GEUInt );
    public:    virtual       ~CFFGFCDialog( void );

    public:
        CFFGFCDialog( CFFGFCDialog const & );
        CFFGFCDialog( void );

    public:
        CFFGFCDialog & operator = ( CFFGFCDialog const & );

    public:
               CFFGFCDialog( GEInt, CFFGFCWnd * );
               CFFGFCDialog( GELPCChar, CFFGFCWnd * );
        GEBool Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        void   EndDialog( GEInt );

    private:
        void PostModal( void );
        void PreModal( void );

};

#endif
