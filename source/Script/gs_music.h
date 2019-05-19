#ifndef GS_MUSIC_H_INCLUDED
#define GS_MUSIC_H_INCLUDED

class GE_DLLIMPORT Music
{
    public:
         Music( void );
        ~Music( void );

    public:
        Music & operator = ( Music const & );

    public:
        GEBool TriggerExplore( void );
        GEBool TriggerFight( void );
        GEBool TriggerRevolution( void );
        GEBool TriggerShowdown( void );
        GEBool TriggerSituation( bCString const & );
        GEBool TriggerVictory( void );

    protected:
        GEBool Trigger( bCString const &, bCString const &, bCString const &, gEMusicFragmentPosition, gEMusicTriggerTime, gEMusicTransition, GEInt, GEInt, GEBool );

};

GE_DLLIMPORT_EXTC Music music;

#endif
