#ifndef GE_TIMER_H_INCLUDED
#define GE_TIMER_H_INCLUDED

class GE_DLLIMPORT bCTimer
{

    public:
        static void GE_STDCALL  EnableSafeTimer( GEBool );
        // Retrieves the number of milliseconds that have elapsed since the system was started, internally uses GetTickCount().
        static GEU32 GE_STDCALL GetTimeStamp( void );
        static GEU64 GE_STDCALL QueryPerformanceCounter( void );
        static GEU64 GE_STDCALL QueryPerformanceFrequency( void );

    public:
         bCTimer( bCTimer const & );
         bCTimer( void );
        ~bCTimer( void );

    public:
        bCTimer & operator = ( bCTimer const & );

    public:
        void Adjust( GEFloat );
        void GetLastTime( GEFloat & ) const;
        void GetTime( GEFloat & );
        void GetTimeDifference( GEFloat & ) const;
        void Pause( void );
        void Reset( void );
        void Resume( void );
        void Set( GEFloat );

};

#endif
