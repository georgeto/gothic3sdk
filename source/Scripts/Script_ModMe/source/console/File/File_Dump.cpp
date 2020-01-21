#include "File_Dump.h"

#include "Script.h"
#include "util/Util.h"

bCString CMD_File_Sub::Dump( bTObjArray< bCString > a_arrParams )
{
    eCArchiveManager & ArchiveManager = eCArchiveManager::GetInstance();
    eCArchiveFile File = ArchiveManager.GetFile( a_arrParams[0] );
    bCString FilePath = File.GetFilePath();
    if( !File.IsValid() )
        return bCString::GetFormattedString( "$File '%s' does not exist.", FilePath );
    if( !File.Open( eCArchiveFile::bEArchiveFileAccessMode_Read, GEFalse ) )
        return bCString::GetFormattedString( "$Could not open the file '%s'.", FilePath );

    bCString FileName;
    File.GetFileName( FileName );

    bCString DumpFilePath = a_arrParams[1];//"/Dumps/" + FileName;
    ArchiveManager.CreateFileA( DumpFilePath );
    eCArchiveFile DumpFile = ArchiveManager.GetFile( DumpFilePath );
    DumpFile.Open( eCArchiveFile::bEArchiveFileAccessMode_ReadWrite, GETrue );

    for ( GEI64 i = 0, ie = File.GetFileSize(); i < ie; i++ )
    {
        GEU8 u8Data;
        File.Read( u8Data );
        DumpFile << u8Data;
    }

    File.Close();
    DumpFile.Close();

    return bCString::GetFormattedString( "Dumped '%s' to '%s'", FilePath, DumpFile.GetFilePath().GetText() );
}
