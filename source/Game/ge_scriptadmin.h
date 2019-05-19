#ifndef GE_SCRIPTADMIN_H_INCLUDED
#define GE_SCRIPTADMIN_H_INCLUDED

struct gScriptRunTimeSingleState;

struct gSScriptDLL
{
    GELPVoid                         m_hModule;
    bCString                         m_strFileName;
    bTObjArray< gSScriptAIState >    m_arrScriptAIStates;
    bTObjArray< gSScriptAIFunction > m_arrScriptAIFunctions;
    bTObjArray< gSScriptAICallback > m_arrScriptAICallbacks;
    bTObjArray< gSScriptAIRoutine >  m_arrScriptAIRoutines;
    bTObjArray< gSScript >           m_arrScripts;
};
GE_ASSERT_SIZEOF( gSScriptDLL, 0x0044 )

#pragma warning( push )
#pragma warning( disable : 4625 )// copy constructor could not be generated because a base class copy constructor is inaccessible

class GE_DLLIMPORT gCScriptAdmin :
    public eCScriptAdminBase
{
    public: virtual GEBool      IsValid( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult    Write( bCOStream & );
    public: virtual bEResult    Read( bCIStream & );
    public: virtual void        Destroy( void );
    public: virtual bEResult    Create( void );
    public: virtual GEU32 const GetProfileLastTicksFirst( void ) const;
    public: virtual            ~gCScriptAdmin( void );
    public: virtual bEResult    Initialize( void );
    public: virtual bEResult    PostInitialize( void );
    public: virtual bEResult    PreShutdown( void );
    public: virtual bEResult    Shutdown( void );
    public: virtual void        Process( void );
    public: virtual void        PostProcess( void );
    public: virtual GEInt       CallScript( bCString const &, eCEntity *, eCEntity *, GEInt );
    public: virtual GEBool      LoadAllScriptDLLs( void );
    public: virtual GEBool      UnloadAllScriptDLLs( void );
    public: virtual GEBool      LoadScriptDLL( bCString const & );
    public: virtual GEBool      UnloadScriptDLL( bCString const & );
    public: virtual GEBool      IsScriptDLLLoaded( bCString const & ) const;
    public: virtual GEBool      GetScriptDLLWithState( bCString const &, bCString & ) const;
    public: virtual GEBool      GetScriptDLLWithFunction( bCString const &, bCString & ) const;
    public: virtual GEBool      GetScriptDLLWithCallback( bCString const &, bCString & ) const;
    public: virtual GEBool      GetScriptDLLWithRoutine( bCString const &, bCString & ) const;
    public: virtual GEBool      GetScriptDLLWithScript( bCString const &, bCString & ) const;
    public: virtual GEBool      GetScriptSourceFileWithState( bCString const &, bCString & ) const;
    public: virtual GEBool      GetScriptSourceFileWithFunction( bCString const &, bCString & ) const;
    public: virtual GEBool      GetScriptSourceFileWithCallback( bCString const &, bCString & ) const;
    public: virtual GEBool      GetScriptSourceFileWithRoutine( bCString const &, bCString & ) const;
    public: virtual GEBool      GetScriptSourceFileWithScript( bCString const &, bCString & ) const;
    public: virtual GEBool      GetScriptDLL( bCString const &, bCString & ) const;
    public: virtual GEBool      GetScriptSourceFile( bCString const &, bCString & ) const;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCScriptAdmin( void );

    public:
        gCScriptAdmin const & operator = ( gCScriptAdmin const & );

    public:
        void   AddProfileTicks( GEU32 );
        GEInt  CallScriptFromScript( bCString const &, GELPVoid, GELPVoid, GEInt );
        void   ClearDLLList( void );
        GEInt  RunScript( bCString const &, gCScriptProcessingUnit * );
        GEBool RunScriptCallback( bCString const &, gCScriptProcessingUnit * );
        GEInt  RunScriptFromScript( bCString const &, gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt );
        GEBool RunScriptFunction( bCString const &, bTObjStack<gScriptRunTimeSingleState> &, gCScriptProcessingUnit * );
        GEBool RunScriptRoutine( bCString const &, gCScriptProcessingUnit * );
        GEBool RunScriptState( bCString const &, bTObjStack<gScriptRunTimeSingleState> &, gCScriptProcessingUnit * );

    protected:
        gCScriptProcessingUnit                    m_SPU;
        GEBool                                    m_bAllScriptDllsLoaded;
        bTPtrArray<gSScriptDLL *>                 m_arrDLLs;
        bTValMap< bCString, gSScriptAIState* >    m_ScriptAIStates;
        bTValMap< bCString, gSScriptAIFunction* > m_ScriptAIFunctions;
        bTValMap< bCString, gSScriptAICallback* > m_ScriptAICallbacks;
        bTValMap< bCString, gSScriptAIRoutine* >  m_ScriptAIRoutines;
        bTValMap< bCString, gSScript* >           m_Scripts;
        GEU32                                     m_uProfileLastTicks;
        GEU32                                     m_uProfileTicks;
};

#pragma warning( pop )

GE_ASSERT_SIZEOF( gCScriptAdmin, 0x208 )

gCScriptAdmin & GetScriptAdmin();

#endif
