#ifndef GE_EVENTWIN32_H_INCLUDED
#define GE_EVENTWIN32_H_INCLUDED

class GE_DLLIMPORT bCEventWin32
{

    public:
         bCEventWin32( void );
        ~bCEventWin32( void );

    public:
        bCEventWin32 & operator = ( bCEventWin32 const & );

    public:
        GELPVoid GetHandle( void ) const;
        GEBool   IsValid( void ) const;
        void     Pulse( void );
        void     Signal( void );
        void     Unsignal( void );
        void     WaitForSignal( GEI32 );

    protected:
        GEBool Create( void );
        void   Destroy( void );

};

#endif
