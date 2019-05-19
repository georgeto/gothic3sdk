#ifndef GFC_TOOLTIPCTRL_H_INCLUDED
#define GFC_TOOLTIPCTRL_H_INCLUDED

class SFFGUIToolTipTool;
class CFFGFCToolInfo;

class GE_DLLIMPORT CFFGFCToolTipCtrl :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCToolTipCtrl( void );

    public:
        CFFGFCToolTipCtrl( CFFGFCToolTipCtrl const & );
        CFFGFCToolTipCtrl( void );

    public:
        CFFGFCToolTipCtrl & operator = ( CFFGFCToolTipCtrl const & );

    public:
        void             Activate( GEBool );
        GEBool           AddTool( CFFGFCWnd *, GELPCUnicodeChar, bCRect const *, GEU32 );
        GEBool           AdjustRect( bCRect &, GEBool );
        GEBool           Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        void             DelTool( CFFGFCWnd *, GEU32 );
        bCPoint          GetBubbleSize( SFFGUIToolTipTool & ) const;
        GEInt            GetDelayTime( GEU32 ) const;
        void             GetMargin( bCRect & ) const;
        GEInt            GetMaxTipWidth( void ) const;
        void             GetText( bCUnicodeString &, CFFGFCWnd *, GEU32 ) const;
        bCByteAlphaColor GetTipBkColor( void ) const;
        bCByteAlphaColor GetTipTextColor( void ) const;
        GEInt            GetToolCount( void ) const;
        GEBool           GetToolInfo( CFFGFCToolInfo &, CFFGFCWnd *, GEU32 ) const;
        void             Pop( void );
        void             SetDelayTime( GEInt );
        void             SetDelayTime( GEU32, GEInt );
        void             SetMargin( bCRect const & );
        void             SetMaxTipWidth( GEInt );
        void             SetTipBkColor( bCByteAlphaColor const & );
        void             SetTipTextColor( bCByteAlphaColor const & );
        GEBool           SetTitle( GEU32, bCUnicodeString const & );
        void             SetToolInfo( SFFGUIToolTipTool const & );
        void             SetToolRect( CFFGFCWnd *, GEU32, bCRect const & );
        void             SetWindowTheme( bCString const & );
        void             Update( void );
        void             UpdateTipText( bCUnicodeString const &, CFFGFCWnd *, GEU32 );

};

#endif
