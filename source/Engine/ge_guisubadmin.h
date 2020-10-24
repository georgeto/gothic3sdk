#ifndef GE_GUISUBADMIN_H_INCLUDED
#define GE_GUISUBADMIN_H_INCLUDED

class GE_DLLIMPORT eCGUISubAdmin
{
    public: virtual ~eCGUISubAdmin( void );

    public:
        eCGUISubAdmin( eCGUISubAdmin const & );
        eCGUISubAdmin( eCGUIAdmin * );

    public:
        eCGUISubAdmin & operator = ( eCGUISubAdmin const & );

    public:
        eCGUIDatabase * GetDatabase( void ) const;
        eCGUIRenderer * GetRenderer( void ) const;
        eCGUIStreamer * GetStreamer( void ) const;
};

#endif
