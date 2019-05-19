#include "../Game.h"

gCScriptAdmin& GetScriptAdmin() {
    return *dynamic_cast< gCScriptAdmin * >( eCModuleAdmin::GetInstance().FindModule( "gCScriptAdmin" ));
}
