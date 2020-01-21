#ifndef M_COMMANDHANDLER_H_INCLUDED
#define M_COMMANDHANDLER_H_INCLUDED

#include "SharedBase.h"

class mCCommandHandler
{
    public:
        typedef bCString( *mFSubCommand )( bTObjArray< bCString > a_arrParams );
        enum mEResult { Failed, Successful, NotResponsible };
        struct mSCommandDesc;
        struct mSSubCommandDesc;

    public:
        static mCCommandHandler & GetInstance();

    public:
        void     Initialize();
        GEBool   IsAutoCompleteBackward();
        GEBool   RegisterCommand( bCString const & a_strName, bCString const & a_strDescription );
        GEBool   RegisterSubCommand( bCString const & a_strParentName, mSSubCommandDesc a_SubCommandDesc );

    private:
        static mCCommandHandler s_CommandHandler;

    private:
        static GEBool OnExecuteHook( bCString const & a_rCommand, bCString & a_rStrResult );
        static GEBool OnCompleteHook( bCString & a_rCommand );
        static void   PrintChoicesHook( bCString const & a_rCommand );
        static void   PrintOutputHook( bCString const & a_strText, bCByteAlphaColor const & a_rColor );

    private:
        GEBool             AutoCompleteSubCommand( mSCommandDesc const & a_rCommandDesc, bCString & a_strCommand );
        mSCommandDesc *    GetCommand( bCString const & a_strName );
        mSSubCommandDesc * GetSubCommand( mSCommandDesc & a_CommandDesc, bCString const & a_strName );
        GEInt              GetSubCommandIndex( mSCommandDesc & a_CommandDesc, bCString const & a_strName );
        bCString           GetCommandHelpText( bCString const & a_strCommand );
        bCString           GetSubCommandHelpText( mSCommandDesc & a_rCommandDesc, bCString const & a_strSubCommand );
        mEResult           OnExecute( bCString const & a_rCommand, bCString & a_rStrResult );
        mEResult           OnComplete( bCString & a_rCommand );
        mEResult           PrintChoices( bCString const & a_rCommand );

    private:
        bTObjArray< mSCommandDesc > m_arrCommands;
};

struct mCCommandHandler::mSCommandDesc
{
    bCString                       m_strName;
    bCString                       m_strDescription;
    bTObjArray< mSSubCommandDesc > m_arrSubCommands;
};

struct mCCommandHandler::mSSubCommandDesc
{
    bCString                       m_strName;
    bCString                       m_strHelpText;
    GEInt                          m_iMinArgs;
    GEInt                          m_iMaxArgs;
    mFSubCommand                   m_pfuncExecute;
    mFSubCommand                   m_pfuncAutoComplete;
};


#endif