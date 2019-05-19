#ifndef GE_SPYADMIN_H_INCLUDED
#define GE_SPYADMIN_H_INCLUDED

class GE_DLLIMPORT bCSpyAdmin
{

    public:
        static bCSpyAdmin & GE_STDCALL GetInstance( void );

    public:
        ~bCSpyAdmin( void );

    public:
        bCSpyAdmin const & operator = ( bCSpyAdmin const & );

    public:
        void                     Create( void );
        bCCriticalSectionWin32 & GetCriticalSection( void );
        HWND__ *                 GetSpyHandle( void );
        GELPVoid                 GetSpyMutex( void );

    protected:
        bCSpyAdmin( bCSpyAdmin const & );
        bCSpyAdmin( void );

    protected:
        void Destroy( void );
        void Invalidate( void );

};

#endif
