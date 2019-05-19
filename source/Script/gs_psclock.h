#ifndef GS_PSCLOCK_H_INCLUDED
#define GS_PSCLOCK_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSClock, gCClock_PS )
public:
    GEInt   GetDay( void ) const;
    GEInt   GetHour( void ) const;
    GEInt   GetMinute( void ) const;
    GEU32   GetTimeStampInSeconds( void ) const;
    GEFloat GetWorldTime( void ) const;
    GEInt   GetYear( void ) const;
    GEBool  IsValid( void ) const;
    void    SetDay( GEInt ) const;
    void    SetFactor( GEFloat ) const;
    void    SetHour( GEInt ) const;
    void    SetMinute( GEInt ) const;
    void    SetWorldTime( GEFloat ) const;
    void    SetYear( GEInt ) const;

};

#endif
