#ifndef GE_HUDDIALOG_H_INCLUDED
#define GE_HUDDIALOG_H_INCLUDED

class GE_DLLIMPORT gCHUDDialog :
    public CFFGFCDialog
{
    public: virtual ~gCHUDDialog( void );

    public:
        gCHUDDialog( gCHUDDialog const & );
        gCHUDDialog( void );

    public:
        gCHUDDialog & operator = ( gCHUDDialog const & );

    public:
             gCHUDDialog( GEInt, CFFGFCWnd * );
        void PlaySoundA( gEHUDSound );

};

#endif
