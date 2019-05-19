#ifndef GE_CLOCK_H_INCLUDED
#define GE_CLOCK_H_INCLUDED

struct bSClockAdjustment
{
    GEFloat fFactor;
    GEUInt  uSecondsPerDay;
    GEUInt  uDayPerYear;
};

struct bSTimeAndDate
{
    GEUInt uYear;
    GEUInt uDayOfYear;
    GEUInt uSecondsOfDay;
};


class GE_DLLIMPORT bCClock
{

    public:
         bCClock( bCClock const & );
         bCClock( void );
        ~bCClock( void );

    public:
        bCClock & operator = ( bCClock const & );

    public:
        void   Adjust( bSClockAdjustment const & );
        void   GetTimeAndDate( bSTimeAndDate & );
        GEBool IsPaused( void ) const;
        void   Pause( void );
        void   Resume( void );
        void   Set( bSTimeAndDate const & );

    private:
        bSClockAdjustment m_ClockAdjustment;
        bSTimeAndDate     m_TimeAndDate;
        GEInt             m_iLastTimestamp;
        GEFloat           m_fCurrentTime;
        GEBool            m_bPaused;
        GE_PADDING( 3 )
};

#endif
