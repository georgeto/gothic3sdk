#pragma once

#include <Game/ge_attribute.h>

#include <SharedBase.h>

// Für dynamische Attribute (HP, MP, SP).
// Aktueller Wert steht in BaseValue, Modifier ist 0.
class GE_DLLIMPORT gCStat : public gCAttribute
{
    // clang-format off
    public: void Destroy() override;
    public: ~gCStat() override;
    public: GEInt GetMaximum() const override;
    public: void SetMaximum(GEInt) override;
    public: GEBool ApplyPerm(EAttribModOperation, GEInt) override;
    public: GEBool ApplyTemp(EAttribModOperation, GEInt) override;
    public: GEBool UnapplyTemp(EAttribModOperation, GEInt) override;
    protected: void Cap() override;
    public: gCAttribute * Clone() const override;
    protected: void ApplyDefaults() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCStat, gCAttribute)
    GE_PROPERTY(GEInt, BaseMaximum, m_iBaseMaximum)
    GE_PROPERTY(GEInt, MaximumModifier, m_iMaximumModifier)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCStat, 0x20)

GE_ASSERT_PROPERTY(gCStat, m_iBaseMaximum, 0x18, 4)
GE_ASSERT_PROPERTY(gCStat, m_iMaximumModifier, 0x1c, 4)
