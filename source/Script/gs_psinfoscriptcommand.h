#ifndef GS_PSINFOSCRIPTCOMMAND_H_INCLUDED
#define GS_PSINFOSCRIPTCOMMAND_H_INCLUDED

class gCInfoScriptLine_PS;

class GE_DLLIMPORT PSInfoScriptCommand
{
    public:
         PSInfoScriptCommand( gCInfoScriptLine_PS * );
         PSInfoScriptCommand( void );
        ~PSInfoScriptCommand( void );

    public:
        PSInfoScriptCommand & operator = ( PSInfoScriptCommand const & );

    public:
        bCString        GetCommand( void ) const;
        Entity          GetEntity1( void ) const;
        Entity          GetEntity2( void ) const;
        bCString        GetID1( void ) const;
        bCString        GetID2( void ) const;
        bCString        GetSampleFileBaseName( void ) const;
        bCUnicodeString GetStageDirection( void ) const;
        bCUnicodeString GetText( void ) const;
        bCString        GetTextID( void ) const;
        GEBool          IsValid( void ) const;

    protected:
        gCInfoScriptLine_PS *m_pGameInfoScriptCommand;
};

#endif
