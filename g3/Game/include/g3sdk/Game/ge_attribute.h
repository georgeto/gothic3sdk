#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCAttribute : public bCObjectRefBase
{
    // clang-format off
    public: virtual GEInt GetValue() const; // BaseValue + Modifier
    public: virtual GEInt GetMaximum() const; // Value
    public: virtual void SetValue(GEInt);
    public: virtual void SetMaximum(GEInt);
    public: virtual GEBool ApplyPerm(EAttribModOperation, GEInt);
    public: virtual GEBool ApplyTemp(EAttribModOperation, GEInt);
    public: virtual GEBool UnapplyTemp(EAttribModOperation, GEInt);
    protected: virtual void Cap();
    public: virtual gCAttribute * Clone() const;
    protected: virtual void ApplyDefaults();
    public: void Destroy() override;
    public: ~gCAttribute() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCAttribute, bCObjectRefBase)
    GE_PROPERTY(bCString, Tag, m_strTag)
    GE_PROPERTY(GEInt, Modifier, m_iModifier)
    // Wert ohne Boni
    GE_PROPERTY(GEInt, BaseValue, m_iBaseValue)

  public:
    eCLocString GetDescription() const;
    eCLocString GetLongName() const;
    eCLocString GetShortName() const;

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCAttribute, 0x18)

GE_ASSERT_PROPERTY(gCAttribute, m_strTag, 0xc, 4)
GE_ASSERT_PROPERTY(gCAttribute, m_iModifier, 0x10, 4)
GE_ASSERT_PROPERTY(gCAttribute, m_iBaseValue, 0x14, 4)
