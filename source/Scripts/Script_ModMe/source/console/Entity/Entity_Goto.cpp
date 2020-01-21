#include "Entity_Goto.h"

#include "Script.h"
#include "util/Util.h"

bCString CMD_Entity_Sub::Goto( bTObjArray< bCString > a_arrParams )
{
    // Zweimal nacheinander zur selben Position geht nicht
    eCEntity * pPlayer = gCSession::GetInstance().GetPlayer();

    gCCharacterMovement_PS * pCharMovement = dynamic_cast<gCCharacterMovement_PS *>(pPlayer->GetPropertySet(eEPropertySetType_CharacterMovement));
    gCScriptRoutine_PS * pScriptRoutine = dynamic_cast<gCScriptRoutine_PS *>(pPlayer->GetPropertySet(eEPropertySetType_ScriptRoutine));
    gCNavigation_PS * pNavigation = dynamic_cast<gCNavigation_PS *>(pPlayer->GetPropertySet(eEPropertySetType_Navigation));

    pCharMovement->SetMovementMode(static_cast<gECharMovementMode>(3));
    pScriptRoutine->AIFullStop();
    pScriptRoutine->SetCurrentTask("ZS_NavEval");
    pScriptRoutine->SetCurrentState("ZS_NavEval");
    pNavigation->Reset(GEFalse, GETrue, GETrue);

    bCMotion Destination;
    Destination.m_Position.SetX(a_arrParams[0].GetFloat(0));
    Destination.m_Position.SetY(a_arrParams[1].GetFloat(0));
    Destination.m_Position.SetZ(a_arrParams[2].GetFloat(0));
    Destination.m_Rotation = bCMatrix3::GetIdentity();
    pNavigation->AccessDestination().Add(Destination);

    return bCString::GetFormattedString("Player is going to %s/%s/%s.", a_arrParams[0], a_arrParams[1], a_arrParams[2]);
}
