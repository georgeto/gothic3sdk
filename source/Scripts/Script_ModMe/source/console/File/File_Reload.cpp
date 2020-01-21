#include "File_Reload.h"

#include "Script.h"

#include "util/Util.h"

static bTStringValMap<File_Reload::mFReloadCallback> s_Reloadables;

bCString CMD_File_Sub::Reload( bTObjArray< bCString > a_arrParams )
{
    if( s_Reloadables.IsValidKey( a_arrParams[0] ) )
    {
        s_Reloadables[a_arrParams[0]]();
        return bCString::GetFormattedString("Reloaded: %s", a_arrParams[0]);
    }

    eCResourceAdmin * pResourceAdmin = dynamic_cast< eCResourceAdmin * >( eCModuleAdmin::GetInstance().FindModule( "eCResourceAdmin" ) );
    eCResourceDataEntity * pResourceDataEntity = pResourceAdmin->QueryResourceDataEntity( a_arrParams[0], static_cast< eEResourceCacheBehavior >( 3 ) );

    bCString FilePath = pResourceDataEntity->GetFilePath();
    if( FilePath.Right( 5 ) == ".ximg" && eCVirtualFileSystem::GetInstance().ExistsFile( FilePath ) )
        eCVirtualFileSystem::GetInstance().DeleteFileA( FilePath );

    eEResourceCacheBehavior CacheBehaivor = static_cast< eCResourceBase_PS * >( *pResourceDataEntity )->GetCacheBehavior();
    pResourceDataEntity->Reload( CacheBehaivor );

    return "Reloaded: " + FilePath;
}

void File_Reload::RegisterReloadable( bCString a_strName, mFReloadCallback a_fCallback )
{
    s_Reloadables.SetAt( a_strName, a_fCallback );
}
