#ifndef GS_PSINFOMANAGER_H_INCLUDED
#define GS_PSINFOMANAGER_H_INCLUDED

class gCInfoManager_PS;
enum gEFaceAni;

GS_DECLARE_PROPERTYSET( PSInfoManager, gCInfoManager_PS )
public:
    GS_DECLARE_PROPERTY( ChildMode, GEBool )

public:
    GEBool              End( void );
    gEAction            GetAction( bCString const & );
    PSInfoScriptCommand GetCurrentCommand( void ) const;
    Info                GetCurrentInfo( void ) const;
    gEFaceAni           GetFaceAni( bCString const & );
    Entity              GetNPC( void );
    gESecurityLevel     GetSecurityLevel( bCString const & );
    GEBool              Give( Entity const &, Entity const &, Template const &, GEU32 );
    GEBool              Give( Entity const &, Entity const &, GEInt, GEU32 );
    GEBool              HasCommentInfo( Entity const &, Entity const & ) const;
    GEBool              HasImportantInfo( Entity const &, Entity const & ) const;
    GEBool              HasInfo( Entity const &, Entity const & ) const;
    GEBool              IsRunning( void ) const;
    GEBool              IsValid( void ) const;
    GEBool              IsWaitingforScript( void ) const;
    GEBool              OnCommandCompleted( GEBool a_bAbortExecution );
    GEBool              Start( Entity const &, Entity const & );
    GEBool              StartComment( Entity const &, Entity const & );

};

#endif
