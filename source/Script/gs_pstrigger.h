#ifndef GS_PSTRIGGER_H_INCLUDED
#define GS_PSTRIGGER_H_INCLUDED

class eCTrigger_PS;

GS_DECLARE_PROPERTYSET( PSTrigger, eCTrigger_PS )
public:
    GEBool IsValid( void ) const;
    void   Trigger( Entity & );
    void   Untrigger( Entity & );

};

#endif
