#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCSkill_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCSkill_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void GetOnScreenDebugLines(GEU32, bTObjArray<eSPropertySetDebugLine> &) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCSkill_PS, eCEntityPropertySet)
    GE_PROPERTY(bCString, Tag, m_strTag)
    GE_PROPERTY(GEInt, LearnPoints, m_iLearnPoints)
    GE_PROPERTY(bCString, ReqAttrib1Tag, m_strReqAttrib1)
    GE_PROPERTY(GEInt, ReqAttrib1Value, m_iReqAttrib1)
    GE_PROPERTY(bCString, ReqAttrib2Tag, m_strReqAttrib2)
    GE_PROPERTY(GEInt, ReqAttrib2Value, m_iReqAttrib2)
    GE_PROPERTY(bCString, ReqAttrib3Tag, m_strReqAttrib3)
    GE_PROPERTY(GEInt, ReqAttrib3Value, m_iReqAttrib3)
    GE_PROPERTY(bCString, ReqAttrib4Tag, m_strReqAttrib4)
    GE_PROPERTY(GEInt, ReqAttrib4Value, m_iReqAttrib4)
    GE_PROPERTY(eCTemplateEntityProxy, ReqSkill1, m_entReqSkill1)
    GE_ENUMPROP(gESkillCategory, Category, m_enuCategory)
    GE_PROPERTY(GEInt, SortOrder, m_iSortOrder)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCSkill_PS, 0x54)

GE_ASSERT_PROPERTY(gCSkill_PS, m_strTag, 0x14, 4)
GE_ASSERT_PROPERTY(gCSkill_PS, m_iLearnPoints, 0x18, 4)
GE_ASSERT_PROPERTY(gCSkill_PS, m_strReqAttrib1, 0x1c, 4)
GE_ASSERT_PROPERTY(gCSkill_PS, m_iReqAttrib1, 0x20, 4)
GE_ASSERT_PROPERTY(gCSkill_PS, m_strReqAttrib2, 0x24, 4)
GE_ASSERT_PROPERTY(gCSkill_PS, m_iReqAttrib2, 0x28, 4)
GE_ASSERT_PROPERTY(gCSkill_PS, m_strReqAttrib3, 0x2c, 4)
GE_ASSERT_PROPERTY(gCSkill_PS, m_iReqAttrib3, 0x30, 4)
GE_ASSERT_PROPERTY(gCSkill_PS, m_strReqAttrib4, 0x34, 4)
GE_ASSERT_PROPERTY(gCSkill_PS, m_iReqAttrib4, 0x38, 4)
GE_ASSERT_PROPERTY(gCSkill_PS, m_entReqSkill1, 0x3c, 12)
GE_ASSERT_PROPERTY(gCSkill_PS, m_enuCategory, 0x48, 8)
GE_ASSERT_PROPERTY(gCSkill_PS, m_iSortOrder, 0x50, 4)
