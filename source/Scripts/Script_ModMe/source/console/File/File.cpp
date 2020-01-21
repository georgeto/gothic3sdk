#include "File.h"
#include "File_Dump.h"
#include "File_Reload.h"
#include "File_ColMesh.h"
#include "../m_commandhandler.h"

void RegisterFileCommands(void)
{
    mCCommandHandler & CommandHandler = mCCommandHandler::GetInstance();
    CommandHandler.RegisterCommand( "File", "Commands to deal with files." );

    mCCommandHandler::mSSubCommandDesc Desc;

    Desc.m_strName = "Dump";
    Desc.m_iMinArgs = 2;
    Desc.m_iMaxArgs = 2;
    Desc.m_strHelpText = "Dump the content of the specified file.\n" \
        "Usage:\n" \
        "  File Dump <Filepath>";
    Desc.m_pfuncExecute = &CMD_File_Sub::Dump;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "File", Desc );

    Desc.m_strName = "Reload";
    Desc.m_iMinArgs = 1;
    Desc.m_iMaxArgs = 1;
    Desc.m_strHelpText = "Reload the specified resource file.\n" \
        "Usage:\n" \
        "  File Reload <Resource name>";
    Desc.m_pfuncExecute = &CMD_File_Sub::Reload;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "File", Desc );

    Desc.m_strName = "ColMeshTriMesh";
    Desc.m_iMinArgs = 1;
    Desc.m_iMaxArgs = 4;
    Desc.m_strHelpText = "Create a TriMesh CollisionMesh of a mesh file.\n" \
        "Usage:\n" \
        "  File ColMeshTriMesh <Mesh name>\n";
        "  File ColMeshTriMesh <Mesh name> <scale>\n" \
        "  File ColMeshTriMesh <Mesh name> <scalex> <scaley> <scalez>";
    Desc.m_pfuncExecute = &CMD_File_Sub::ColMeshTriMesh;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "File", Desc );

    Desc.m_strName = "ColMeshConvexHull";
    Desc.m_iMinArgs = 1;
    Desc.m_iMaxArgs = 4;
    Desc.m_strHelpText = "Create a ConvexHull CollisionMesh of a mesh file.\n" \
        "Usage:\n" \
        "  File ColMeshConvexHull <Mesh name>\n" \
        "  File ColMeshConvexHull <Mesh name> <scale>\n" \
        "  File ColMeshConvexHull <Mesh name> <scalex> <scaley> <scalez>";
    Desc.m_pfuncExecute = &CMD_File_Sub::ColMeshConvexHull;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "File", Desc );
}
