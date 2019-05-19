#ifndef GS_PSAIZONE_H_INCLUDED
#define GS_PSAIZONE_H_INCLUDED

class gCAIZone_PS;

GS_DECLARE_PROPERTYSET( PSAIZone, gCAIZone_PS )
public:
    GS_DECLARE_PROPERTY( Owner,         eCEntityProxy )
    GS_DECLARE_PROPERTY( SecurityLevel, gESecurityLevel )
    GS_DECLARE_PROPERTY( Type,          gEZoneType )

public:
    GEBool IsValid( void ) const;

};

#endif
