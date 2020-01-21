#include "ge_hudoption.h"

#include "Gui.h"

gCHUDOptionBool::gCHUDOptionBool(bCString const & a_strDescription, GEBool * a_pValue)
    : gCHUDOptionBase(a_strDescription, a_pValue), m_strLabelOn("HUD_Slider_Value_On"), m_strLabelOff("HUD_Slider_Value_Off")
{
}

gCHUDOptionBool::gCHUDOptionBool(bCString const & a_strDescription, GEBool * a_pValue, bCString const & a_strLabelOn, bCString const & a_strLabelOff)
    : gCHUDOptionBase(a_strDescription, a_pValue), m_strLabelOn(a_strLabelOn), m_strLabelOff(a_strLabelOff)
{
}

void gCHUDOptionBool::InitSlider(CFFGFCSlider * a_pSlider)
{
    a_pSlider->SetRange(0, 1);
}

void gCHUDOptionBool::LoadLabelValue(gCHUDLabel *a_pLabelValue)
{
    a_pLabelValue->SetWindowTextA(eCLocString(GetValue() ? m_strLabelOn :  m_strLabelOff));
}

void gCHUDOptionBool::SaveSliderValue(CFFGFCSlider * a_pSlider)
{
    SetValue(a_pSlider->GetPos() == 1);
}

void gCHUDOptionBool::LoadSliderValue(CFFGFCSlider * a_pSlider)
{
    a_pSlider->SetPos(GetValue() ? 1 : 0);
}

gCHUDOptionRangeInt::gCHUDOptionRangeInt(bCString const & a_strDescription, GEInt * a_pValue, GEInt a_iMin, GEInt a_iMax, GELPCUnicodeChar a_strValueFormat)
    : gCHUDOptionRange<GEInt>(a_strDescription, a_pValue, a_iMin, a_iMax, a_strValueFormat)
{
}

GEInt gCHUDOptionRangeInt::GetValueAsInt()
{
    return GetValue();
}

void gCHUDOptionRangeInt::SetValueAsInt(GEInt const & a_Value)
{
    return SetValue(a_Value);
}

gCHUDOptionRangeU32::gCHUDOptionRangeU32(bCString const & a_strDescription, GEU32 * a_pValue, GEU32 a_iMin, GEU32 a_iMax, GELPCUnicodeChar a_strValueFormat)
    : gCHUDOptionRange<GEU32>(a_strDescription, a_pValue, a_iMin, a_iMax, a_strValueFormat)
{
}

GEInt gCHUDOptionRangeU32::GetValueAsInt()
{
    return GetValue();
}

void gCHUDOptionRangeU32::SetValueAsInt(GEInt const & a_Value)
{
    return SetValue(a_Value);
}

gCHUDOptionPercent::gCHUDOptionPercent(bCString const & a_strDescription, GEFloat * a_pValue, GEInt a_iMin, GEInt a_iMax, GELPCUnicodeChar a_strValueFormat)
    : gCHUDOptionRange<GEFloat>(a_strDescription, a_pValue, a_iMin, a_iMax, a_strValueFormat)
{
}

GEInt gCHUDOptionPercent::GetValueAsInt()
{
    return static_cast<GEInt>(GetValue() * 100.0f);
}

void gCHUDOptionPercent::SetValueAsInt(GEInt const & a_Value)
{
    SetValue(a_Value / 100.0f);
}

void gCSliderOption::DoDataExchange( CFFGFCDataExchange * a_pDataExchange, GEInt a_IdDescription, GEInt a_IdSlider, GEInt a_IdValue )
{
    FF_DDX_Control( a_pDataExchange, a_IdDescription, m_LabelDescription );
    FF_DDX_Control( a_pDataExchange, a_IdSlider, m_Slider );
    FF_DDX_Control( a_pDataExchange, a_IdValue, m_LabelValue );
}

void gCSliderOption::Init( gCHUDOption * a_pHUDOption )
{
    m_pHUDOption = a_pHUDOption;
    m_pHUDOption->InitSlider( &m_Slider );
    LoadValue();
}

void gCSliderOption::LoadLabels()
{
    m_pHUDOption->LoadLabelValue( &m_LabelValue );
    m_pHUDOption->LoadLabelDescription( &m_LabelDescription );
}

void gCSliderOption::LoadValue()
{
    m_pHUDOption->LoadSliderValue( &m_Slider );
}
