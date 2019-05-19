#ifndef GS_PSTREASURESET_H_INCLUDED
#define GS_PSTREASURESET_H_INCLUDED

class gCTreasureSet_PS;

GS_DECLARE_PROPERTYSET( PSTreasureSet, gCTreasureSet_PS )
public:
    GS_DECLARE_PROPERTY( MaxTransferStacks,    GEU32 )
    GS_DECLARE_PROPERTY( MinTransferStacks,    GEU32 )
    GS_DECLARE_PROPERTY( TreasureDistribution, gETreasureDistribution )

public:
    GEBool IsValid( void ) const;

};

#endif