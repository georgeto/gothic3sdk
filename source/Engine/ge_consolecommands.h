#ifndef GE_CONSOLECOMMANDS_H_INCLUDED
#define GE_CONSOLECOMMANDS_H_INCLUDED

enum eEConsoleDataType;

class GE_DLLIMPORT eCConsoleCommands
{
    public: virtual ~eCConsoleCommands( void );

    public:
        eCConsoleCommands( eCConsoleCommands const & );
        eCConsoleCommands( void );

    public:
        eCConsoleCommands & operator = ( eCConsoleCommands const & );

    public:
        void            AddArgument( bCString const &, bCString const &, eEConsoleDataType, GEU64, bCString const & );
        void            AddCommand( bCString const &, bCString const &, bCDelegateBase *, GEU64, bCString const & );
        void            AddFunction( bCString const &, bCString const &, bCDelegateBase *, GEU64, bCString const & );
        void            AddProperty( bCString const &, bCString const &, eEConsoleDataType, bCDelegateBase *, GEU64, bCString const & );
        GEBool          AutoComplete( bCString &, GEInt );
        void            BeginAddClass( bCString const &, bCString const &, bCDelegateBase * );
        GEBool          CheckCommandIsValid( bCString const &, eEConsoleDataType const & );
        void            EndAddClass( bCString const & );
        GEBool          Execute( bCString const &, bCString & );
        //bTPtrTreeAVL<bCString,eCConsoleData *> * GetChildTreeNode(eCConsoleData *,bCDelegateBase const *,bCString &);
        eCConsoleData * GetClassData( bCString const & );
        GEInt           GetNumEqualCommands( bCString const & );
        GEInt           GetNumEqualCommands( bCString const &, bCString & );
        eCConsoleData * GetRoot( void );
        //bTPtrTreeAVL<bCString,eCConsoleData *> * GetTreeNode(bCString const &,bCString &);
        //bTPtrTreeAVL<bCString,eCConsoleData *> * GetTreeNode(bCDelegateBase const *,bCString &);
        void            Help( void );
        void            PrintChoices( bCString const & );
        void            Remove( bCString const & );
        void            Remove( bCDelegateBase *, GEBool );

    private:
        GEBool                  ExecuteClass( bCString const &, bCString &, eCConsoleData *, bCString & );
        GEBool                  ExecuteCommand( bCString const &, bCString &, eCConsoleData * );
        GEBool                  ExecuteFunction( bCString const &, bCString &, eCConsoleData *, bCString & );
        GEBool                  ExecuteProperty( bCString const &, bCString &, eCConsoleData *, bCString & );
        GEBool                  ExecuteRecursive( bCString const &, bCString &, eCConsoleData *, bCString & );
        eEConsoleDataType const GetConDataTypeOfString( bCString const & ) const;
        bCString const &        GetStringOfConDataType( eEConsoleDataType const & ) const;

};

#endif
