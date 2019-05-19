#ifndef GS_PSQUESTMANAGER_H_INCLUDED
#define GS_PSQUESTMANAGER_H_INCLUDED

class gCQuestManager_PS;

GS_DECLARE_PROPERTYSET( PSQuestManager, gCQuestManager_PS )
public:
    GEBool CancelQuest( bCString const & );
    GEBool CloseQuest( bCString const & );
    GEBool FailQuest( bCString const & );
    GEBool IsCancelled( bCString const & );
    GEBool IsFailed( bCString const & );
    GEBool IsFinished( bCString const & );
    GEBool IsObsolete( bCString const & );
    GEBool IsOpen( bCString const & );
    GEBool IsRunning( bCString const & );
    GEBool IsSucceeded( bCString const & );
    GEBool IsValid( void ) const;
    GEBool OnEnclaveStateChanged( Entity const & );
    GEBool OnEnter( Entity const &, bCString const & );
    GEBool OnLeave( Entity const &, bCString const & );
    GEBool OnNPCDefeated( Entity const & );
    GEBool OnNPCKilled( Entity const & );
    GEBool OnReceiveItem( Entity const &, Entity const &, Template const &, GEU32 );
    GEBool OnSpellCast( Entity const &, Entity const &, bCString );
    GEBool RunQuest( bCString const & );
    GEBool SucceedQuest( bCString const & );

};

#endif
