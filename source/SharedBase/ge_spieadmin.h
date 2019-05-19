#ifndef GE_SPIEADMIN_H_INCLUDED
#define GE_SPIEADMIN_H_INCLUDED

class GE_DLLIMPORT bCSpieAdmin
{

    public:
        static bCSpieAdmin & GE_STDCALL GetInstance( void );

    public:
        ~bCSpieAdmin( void );

    public:
        bCSpieAdmin const & operator = ( bCSpieAdmin const & );

    public:
        void                     Create( void );
        bCCriticalSectionWin32 & GetCriticalSection( void );
        GEBool                   Send( GELPVoid const, GEU32 );

    protected:
        bCSpieAdmin( bCSpieAdmin const & );
        bCSpieAdmin( void );

    protected:
        void Destroy( void );
        void Invalidate( void );

};

#endif
