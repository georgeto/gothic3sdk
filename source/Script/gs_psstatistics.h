#ifndef GS_PSSTATISTICS_H_INCLUDED
#define GS_PSSTATISTICS_H_INCLUDED

class gCStatistics_PS;
enum EAttrib;
enum ETrait;

GS_DECLARE_PROPERTYSET( PSStatistics, gCStatistics_PS )
public:
    GEInt  GetBaseMaximum( EAttrib ) const;
    GEInt  GetBaseValue( EAttrib ) const;
    GEInt  GetMaximum( EAttrib ) const;
    GEInt  GetTraitValue( ETrait ) const;
    GEInt  GetValue( EAttrib ) const;
    GEBool HasTrait( ETrait ) const;
    GEBool IsValid( void ) const;
    void   SetBaseMaximum( EAttrib, GEInt );
    void   SetBaseValue( EAttrib, GEInt );

};

#endif
