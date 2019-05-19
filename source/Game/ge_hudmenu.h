#ifndef GE_HUDMENU_H_INCLUDED
#define GE_HUDMENU_H_INCLUDED

enum gEHUDMenu
{
    gEHUDMenu_Main                     = 0,
    gEHUDMenu_Load                     = 1,
    gEHUDMenu_Save                     = 2,
    gEHUDMenu_Options                  = 3,
    gEHUDMenu_OptionsAudio             = 4,
    gEHUDMenu_OptionsVideo             = 5,
    gEHUDMenu_OptionsPerformance       = 6,
    gEHUDMenu_OptionsPerformanceCustom = 7,
    gEHUDMenu_OptionsControls          = 8,
    gEHUDMenu_OptionsControlsCustom    = 9,
    gEHUDMenu_Difficulty               = 10,
    gEHUDMenu_Credits                  = 11,
    gEHUDMenu_Intro                    = 12,
    gEHUDMenu_Loading                  = 13,
    gEHUDMenu_COUNT
};

enum gEHUDSound;

class GE_DLLIMPORT gCHUDMenu :
    public CFFGFCView
{
    public: virtual GEBool RequiresRestart( void ) const;
    public: virtual void   CancelRestart( void );
    public: virtual void   SaveOptions( eCConfigFile & );
    public: virtual void   ResetValues( void );
    public: virtual void   Open( void );
    public: virtual void   Close( void );
    public: virtual void   OnMenuChanged( gEHUDMenu, gEHUDMenu );
    public: virtual GEBool HandleCancel( void );
    public: virtual void   OnPaint( void );
    public: virtual void   OnEraseBkgnd( void );
    public: virtual       ~gCHUDMenu( void );

    public:
        gCHUDMenu( gCHUDMenu const & );
        gCHUDMenu( void );

    public:
        gCHUDMenu & operator = ( gCHUDMenu const & );

    public:
             gCHUDMenu( GEInt, CFFGFCWnd * );
        void PlaySoundA( gEHUDSound );

    protected:
        void Mute( GEBool );
        void MuteMusic( GEBool );
        void OpenMenu( gEHUDMenu );

};

#endif
