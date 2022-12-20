#ifndef GE_COMMANDMANAGER_H_INCLUDED
#define GE_COMMANDMANAGER_H_INCLUDED

class eCScope;
class eCScopeInstance;
class eCScopeClass;

struct eSDispatchableClass;

enum eEScopeType;

class GE_DLLIMPORT eCCommandManager
{

    protected:
        static bCString m_strScopeDelimiter;

    public:
         eCCommandManager( eCCommandManager const & );
         eCCommandManager( void );
        ~eCCommandManager( void );

    public:
        eCCommandManager & operator =  ( eCCommandManager const & );
        bCOStream &        operator >> ( bCOStream & ) const;
        bCIStream &        operator << ( bCIStream & );

    public:
        eCConsoleCommands &       AccessCommands( void );
        GEBool                    AddScope( bCString const &, bCString const &, bCString const & );
        GEBool                    Complete( bCString &, GEInt );
        void                      CopyFrom( eCCommandManager const & );
        void                      CopyTo( eCCommandManager & ) const;
        GEBool                    Create( void );
        eCObjectInspectorDlg *    CreateObjectInspector( eCScopeInstance * );
        void                      Destroy( void );
        GEBool                    Execute( bCString const &, bCString &, eCConsoleDlg & );
        eCConsoleCommands const & GetCommands( void ) const;
        void                      GetCommands( eCConsoleCommands & ) const;
        eCScope *                 GetCurrentScope( void ) const;
        GEInt                     GetNumEqualCommands( bCString const & );
        eCScope *                 GetScope( bCString const & ) const;
        eCScope *                 GetScope( bCString const &, eEScopeType ) const;
        GEBool                    KillInstance( eCScopeInstance * );
        void                      PrintChoices( bCString const & );
        GEBool                    Read( bCIStream & );
        eCScopeClass *            RegisterClassA( eSDispatchableClass const & );
        GEBool                    SelectScope( bCString const & );
        GEBool                    SelectScope( eCScope * );
        void                      SetCommands( eCConsoleCommands const & );
        eCScopeInstance *         SpawnInstance( bCString const &, bCString const &, eCConsoleDlg * );
        void                      Write( bCOStream & ) const;

    protected:
        static bCString & GE_STDCALL GetScopeDelimiter( void );

    protected:
        GEBool ExecuteRecursive( bCString const &, bCString &, eCConsoleDlg &, bCVariant & );
        GEBool InternExecute( bCString const &, bCString &, eCConsoleDlg & );
        void   Invalidate( void );
        void   PrintClassList( eCScope const *, eCConsoleDlg &, int ) const;
        void   PrintFilteredScopeList( eCScope const *, eCConsoleDlg &, int, eEScopeType ) const;
        void   PrintInstanceList( eCScope const *, eCConsoleDlg &, int ) const;
        void   PrintScope( eCConsoleDlg & ) const;
        void   PrintScopeList( eCScope const *, eCConsoleDlg &, int ) const;
        GEBool ScopeExecute( bCString const &, bCString &, eCConsoleDlg & );

};

#endif
