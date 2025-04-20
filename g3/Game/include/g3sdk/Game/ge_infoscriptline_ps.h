#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCInfoScriptLine_PS : public bCObjectRefBase
{
    // clang-format off
    public: virtual GEBool IsEditorRelevant() const;
    public: virtual void OnPreProcess();
    public: virtual void OnProcess();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCInfoScriptLine_PS() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCInfoScriptLine_PS, bCObjectRefBase)
    GE_PROPERTY(bCString, Command, m_command)
    GE_PROPERTY(bCString, Entity1, m_strEntity1)
    GE_PROPERTY(bCString, Entity2, m_strEntity2)
    GE_PROPERTY(bCString, ID1, m_id1)
    GE_PROPERTY(bCString, ID2, m_id2)
    GE_PROPERTY(eCLocString, Text, m_text)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCInfoScriptLine_PS, 0x24)

GE_ASSERT_PROPERTY(gCInfoScriptLine_PS, m_command, 0xc, 4)
GE_ASSERT_PROPERTY(gCInfoScriptLine_PS, m_strEntity1, 0x10, 4)
GE_ASSERT_PROPERTY(gCInfoScriptLine_PS, m_strEntity2, 0x14, 4)
GE_ASSERT_PROPERTY(gCInfoScriptLine_PS, m_id1, 0x18, 4)
GE_ASSERT_PROPERTY(gCInfoScriptLine_PS, m_id2, 0x1c, 4)
GE_ASSERT_PROPERTY(gCInfoScriptLine_PS, m_text, 0x20, 4)
