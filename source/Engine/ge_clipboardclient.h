#ifndef GE_CLIPBOARDCLIENT_H_INCLUDED
#define GE_CLIPBOARDCLIENT_H_INCLUDED

class GE_DLLIMPORT eCClipboardClient
{
    public: virtual void Clear( void ) = 0;
    public: virtual void Copy( void )  = 0;
    public: virtual void Cut( void )   = 0;
    public: virtual void Paste( void ) = 0;
    public: virtual void Undo( void )  = 0;
    public: virtual     ~eCClipboardClient( void );

    public:
        eCClipboardClient( eCClipboardClient const & );

    public:
        eCClipboardClient & operator = ( eCClipboardClient const & );

    protected:
        eCClipboardClient( void );

};

#endif
