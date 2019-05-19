template<typename T>
gCHUDOptionBase<T>::gCHUDOptionBase(bCString const & a_strDescription, T * a_pValue)
    : m_strDescription(a_strDescription), m_pValue(a_pValue)
{
}

template<typename T>
void gCHUDOptionBase<T>::LoadLabelDescription(gCHUDLabel *a_pLabelDescription)
{
    a_pLabelDescription->SetWindowTextA( eCLocString( m_strDescription ) );
}

template<typename T>
GEBool gCHUDOptionBase<T>::RequiresRestart()
{
    return GEFalse;
}

template<typename T>
T gCHUDOptionBase<T>::GetValue()
{
    return *m_pValue;
}

template<typename T>
void gCHUDOptionBase<T>::SetValue(T const & a_Value)
{
    *m_pValue = a_Value;
}

template<typename T>
gCHUDOptionRange<T>::gCHUDOptionRange(bCString const & a_strDescription, T * a_pValue, GEInt a_iMin, GEInt a_iMax, GELPCUnicodeChar a_strValueFormat )
    : gCHUDOptionBase(a_strDescription, a_pValue), m_iMin(a_iMin), m_iMax(a_iMax), m_strValueFormat(a_strValueFormat)
{
}

template<typename T>
void gCHUDOptionRange<T>::InitSlider(CFFGFCSlider * a_pSlider)
{
    a_pSlider->SetRange(m_iMin, m_iMax);
}

template<typename T>
void gCHUDOptionRange<T>::LoadLabelValue(gCHUDLabel *a_pLabelValue)
{
    a_pLabelValue->SetWindowTextA(bCUnicodeString::GetFormattedString(m_strValueFormat, GetValueCapped()));
}

template<typename T>
void gCHUDOptionRange<T>::SaveSliderValue(CFFGFCSlider * a_pSlider)
{
    SetValueAsInt(a_pSlider->GetPos());
}

template<typename T>
void gCHUDOptionRange<T>::LoadSliderValue(CFFGFCSlider * a_pSlider)
{
    a_pSlider->SetPos(GetValueCapped());
}

template<typename T>
GEInt gCHUDOptionRange<T>::GetValueCapped()
{
    GEInt iValue = GetValueAsInt();
    if(iValue < m_iMin)
        iValue = m_iMin;
    else if(iValue > m_iMax)
        iValue = m_iMax;
    return iValue;
}