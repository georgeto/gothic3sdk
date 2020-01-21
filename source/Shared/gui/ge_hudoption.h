#ifndef GE_HUDOPTION_H_INCLUDED
#define GE_HUDOPTION_H_INCLUDED

#include "Game.h"
#include "ge_hudlabel.h"

class gCHUDOption
{
    public: virtual void   InitSlider( CFFGFCSlider * a_pSlider )                  = 0;
    // Read runtime value (e.g. eSSetupEngine)
    public: virtual void   LoadLabelValue( gCHUDLabel *a_pLabelValue )             = 0;
    // Write runtime value (e.g. eSSetupEngine)
    public: virtual void   SaveSliderValue( CFFGFCSlider * a_pSlider )             = 0;
    // Read runtime value (e.g. eSSetupEngine)
    public: virtual void   LoadSliderValue( CFFGFCSlider * a_pSlider )             = 0;
    public: virtual void   LoadLabelDescription( gCHUDLabel *a_pLabelDescription ) = 0;
    public: virtual void   SliderGainendFocus()                                    { } // = 0;
    public: virtual void   SliderLostFocus()                                       { } // = 0;
    public: virtual GEBool RequiresRestart()                                       = 0;
    public: virtual void   ResetValue()                                            { };
    public: virtual void   __UNK_0005()                                            { } // = 0;
    public: virtual void   __UNK_0006()                                            { } // = 0;
    public: virtual       ~gCHUDOption()                                           { };
};

GE_ASSERT_SIZEOF( gCHUDOption, 0x04 )

template<typename T>
class gCHUDOptionBase
    : public gCHUDOption
{
    public:
        virtual void LoadLabelDescription( gCHUDLabel *a_pLabelDescription );
        virtual GEBool RequiresRestart();

        virtual T GetValue();
        virtual void SetValue( T const & a_Value );

    public:
        gCHUDOptionBase( bCString const & a_strDescription, T * a_pValue );

    private:
        bCString m_strDescription;
        T * m_pValue;
};

class gCHUDOptionBool
    : public gCHUDOptionBase<GEBool>
{
    public:
        virtual void InitSlider( CFFGFCSlider * a_pSlider );
        virtual void LoadLabelValue( gCHUDLabel *a_pLabelValue );
        virtual void SaveSliderValue( CFFGFCSlider * a_pSlider );
        virtual void LoadSliderValue( CFFGFCSlider * a_pSlider );

    public:
        gCHUDOptionBool( bCString const & a_strDescription, GEBool * a_pValue );
        gCHUDOptionBool( bCString const & a_strDescription, GEBool * a_pValue, bCString const & a_strLabelOn, bCString const & a_strLabelOff );

    private:
        bCString m_strLabelOn;
        bCString m_strLabelOff;
};

template<typename T>
class gCHUDOptionRange
    : public gCHUDOptionBase<T>
{
    public:
        virtual void InitSlider( CFFGFCSlider * a_pSlider );
        virtual void LoadLabelValue( gCHUDLabel *a_pLabelValue );
        virtual void SaveSliderValue( CFFGFCSlider * a_pSlider );
        virtual void LoadSliderValue( CFFGFCSlider * a_pSlider );

        virtual GEInt GetValueAsInt() = 0;
        virtual void SetValueAsInt( GEInt const & a_Value ) = 0;

    public:
        gCHUDOptionRange( bCString const & a_strDescription, T * a_pValue, GEInt a_iMin, GEInt a_iMax, GELPCUnicodeChar a_strValueFormat );

    protected:
        GEInt GetValueCapped();

    private:
        GEInt m_iMin;
        GEInt m_iMax;
        GELPCUnicodeChar m_strValueFormat;
};


class gCHUDOptionRangeInt
    : public gCHUDOptionRange<GEInt>
{
    public:
        virtual GEInt GetValueAsInt();
        virtual void SetValueAsInt( GEInt const & a_Value );

    public:
        gCHUDOptionRangeInt( bCString const & a_strDescription, GEInt * a_pValue, GEInt a_iMin, GEInt a_iMax, GELPCUnicodeChar a_strValueFormat = L"%d" );
};


class gCHUDOptionRangeU32
    : public gCHUDOptionRange<GEU32>
{
    public:
        virtual GEInt GetValueAsInt();
        virtual void SetValueAsInt( GEInt const & a_Value );

    public:
        gCHUDOptionRangeU32( bCString const & a_strDescription, GEU32 * a_pValue, GEU32 a_iMin, GEU32 a_iMax, GELPCUnicodeChar a_strValueFormat = L"%u" );
};


class gCHUDOptionPercent
    : public gCHUDOptionRange<GEFloat>
{
    public:
        virtual GEInt GetValueAsInt();
        virtual void SetValueAsInt( GEInt const & a_Value );

    public:
        gCHUDOptionPercent( bCString const & a_strDescription, GEFloat * a_pValue, GEInt a_iMin, GEInt a_iMax, GELPCUnicodeChar a_strValueFormat = L"%+d%%" );
};

class gCSliderOption
{
    public:
        gCHUDLabel    m_LabelDescription;
        gCHUDLabel    m_LabelValue;
        CFFGFCSlider  m_Slider;
        gCHUDOption * m_pHUDOption;

    public:
        void DoDataExchange( CFFGFCDataExchange * a_pDataExchange, GEInt a_IdDescription, GEInt a_IdSlider, GEInt a_IdValue );
        void Init( gCHUDOption * a_pHUDOption );
        void LoadLabels();
        void LoadValue();
};

#include "ge_hudoption.inl"

#endif
