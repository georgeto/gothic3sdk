#include "ge_hudstaticnpc.h"

#include "util/Memory.h"
#include "util/Util.h"

void gCHUDStaticNPC::_UnkFunc(void)
{
    // Do nothing, like the original function
}

void gCHUDStaticNPC::OnPaint(void)
{
    if(m_FieldType == gEFieldType_Value)
        Load();
    CFFGFCStatic::OnPaint();
}

gCHUDStaticNPC::~gCHUDStaticNPC(void)
{
}

gCHUDStaticNPC::gCHUDStaticNPC(void)
: m_EntityProxy(), m_FieldType(gEFieldType_Value), m_ValueType(gEValueType_HP)
{
}

void gCHUDStaticNPC::Init(gEFieldType a_FieldType, gEValueType a_ValueType)
{
    m_FieldType = a_FieldType;
    m_ValueType = a_ValueType;
    Load();
}

typedef void (*gCHUDStaticNPC_LoadLabel)(/*gCHUDStaticNPC * a_pTextField@<ebx>*/);
typedef void (*gCHUDStaticNPC_LoadValue)(gCHUDStaticNPC * a_pTextField);

void gCHUDStaticNPC::Load()
{
    if(m_FieldType == gEFieldType_Label)
        LoadLabel();
    else
        LoadValue();
}

void gCHUDStaticNPC::LoadLabel()
{
    static gCHUDStaticNPC_LoadLabel fLoadLabel = force_cast<gCHUDStaticNPC_LoadLabel>(RVA_Game(0xA5E00));
    __asm {
        mov ebx, this
        call fLoadLabel
    }
}

void gCHUDStaticNPC::LoadValue()
{
    static gCHUDStaticNPC_LoadValue fLoadValue = force_cast<gCHUDStaticNPC_LoadValue>(RVA_Game(0xA62F0));
    fLoadValue(this);
}

void gCHUDStaticNPC::SetEntity(eCEntity * a_pEntity)
{
    if(m_EntityProxy.GetEntity() != a_pEntity)
        m_EntityProxy.SetEntity(a_pEntity);

    Load();
}
