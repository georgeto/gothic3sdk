#ifndef GE_SCRIPTADMINBASE_H_INCLUDED
#define GE_SCRIPTADMINBASE_H_INCLUDED

class GE_DLLIMPORT eCScriptAdminBase :
    public eCEngineComponentBase
{
    public: virtual GEInt  CallScript( bCString const &, eCEntity *, eCEntity *, GEInt )         = 0;
    public: virtual GEBool LoadAllScriptDLLs( void )                                             = 0;
    public: virtual GEBool UnloadAllScriptDLLs( void )                                           = 0;
    public: virtual GEBool LoadScriptDLL( bCString const & )                                     = 0;
    public: virtual GEBool UnloadScriptDLL( bCString const & )                                   = 0;
    public: virtual GEBool IsScriptDLLLoaded( bCString const & ) const                           = 0;
    public: virtual GEBool GetScriptDLLWithState( bCString const &, bCString & ) const           = 0;
    public: virtual GEBool GetScriptDLLWithFunction( bCString const &, bCString & ) const        = 0;
    public: virtual GEBool GetScriptDLLWithCallback( bCString const &, bCString & ) const        = 0;
    public: virtual GEBool GetScriptDLLWithRoutine( bCString const &, bCString & ) const         = 0;
    public: virtual GEBool GetScriptDLLWithScript( bCString const &, bCString & ) const          = 0;
    public: virtual GEBool GetScriptSourceFileWithState( bCString const &, bCString & ) const    = 0;
    public: virtual GEBool GetScriptSourceFileWithFunction( bCString const &, bCString & ) const = 0;
    public: virtual GEBool GetScriptSourceFileWithCallback( bCString const &, bCString & ) const = 0;
    public: virtual GEBool GetScriptSourceFileWithRoutine( bCString const &, bCString & ) const  = 0;
    public: virtual GEBool GetScriptSourceFileWithScript( bCString const &, bCString & ) const   = 0;
    public: virtual GEBool GetScriptDLL( bCString const &, bCString & ) const                    = 0;
    public: virtual GEBool GetScriptSourceFile( bCString const &, bCString & ) const             = 0;

    public: virtual ~eCScriptAdminBase( void );

    public:
        eCScriptAdminBase( eCScriptAdminBase const & );
        eCScriptAdminBase( void );

    public:
        eCScriptAdminBase & operator = ( eCScriptAdminBase const & );

};

#endif
