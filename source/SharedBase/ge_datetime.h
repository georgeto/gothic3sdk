#ifndef GE_DATETIME_H_INCLUDED
#define GE_DATETIME_H_INCLUDED

class GE_DLLIMPORT bCDateTime
{
    private:
        GEU64 m_u64DateTime;

    public:
         bCDateTime( _FILETIME const & );
         bCDateTime( bCDateTime const & );
         bCDateTime( void );
         bCDateTime( GEU64 );
        ~bCDateTime( void );

    public:
        bCDateTime const & operator =               ( _FILETIME const & );
        bCDateTime const & operator =               ( bCDateTime const & );
        GEBool             operator ==              ( bCDateTime const & ) const;
        GEBool             operator !=              ( bCDateTime const & ) const;
                           operator _FILETIME       ( void );
                           operator _FILETIME const ( void ) const;
        bCDateTime         operator -               ( bCDateTime const & ) const;
        bCDateTime         operator +               ( bCDateTime const & ) const;
        GEBool             operator <               ( bCDateTime const & ) const;
        GEBool             operator <=              ( bCDateTime const & ) const;
        GEBool             operator >               ( bCDateTime const & ) const;
        GEBool             operator >=              ( bCDateTime const & ) const;
        bCDateTime const & operator +=              ( bCDateTime const & );
        bCDateTime const & operator -=              ( bCDateTime const & );

    public:
        GEU64 & AccessDateTime( void );
        void    Add( bCDateTime const & );
        void    CopyFrom( bCDateTime const & );
        void    CopyTo( bCDateTime & ) const;
        void    GetDateString( bCString & ) const;
        void    GetDateTime( GEU64 & ) const;
        GEU64   GetDateTime( void ) const;
        void    GetShortDateString( bCString & ) const;
        void    GetTimeString( bCString & ) const;
        void    SetDateTime( _FILETIME const & );
        void    SetDateTime( GEU64 );
        void    Sub( bCDateTime const & );
        void    Update( void );

    protected:
        void Clear( void );
        void Init( void );

};

#endif
