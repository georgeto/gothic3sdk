#pragma once

#include <Game/ge_infoscriptline_ps.h>

#include <Engine.h>

class gCInfo_PS;

class GE_DLLIMPORT gCInfoScript_PS : public bCObjectRefBase
{
    // clang-format off
    public: virtual GEBool IsEditorRelevant() const;
    public: virtual eEPropertySetType GetPropertySetType() const;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCInfoScript_PS() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCInfoScript_PS, bCObjectRefBase)
    GE_PROPERTY(bTObjArray<bTAutoPOSmartPtr<gCInfoScriptLine_PS>>, InfoScriptLines, m_arrInfoScriptLines)
    GE_PROPERTY(GEInt, CurrentScriptLine, m_currentScriptLine) // Read only
    GE_PROPERTY(GEBool, ScriptIsRunnig, m_bScriptIsRunning)    // Read only
    GE_PADDING(1)

  public:
    void AddCommand(bCString const &, bCString const &, bCString const &, bCString const &, bCString const &,
                    eCLocString const &);
    GEBool Execute(gCInfo_PS *);
    gCInfoScriptLine_PS *GetCommand(GEInt);
    gCInfoScriptLine_PS const *GetCommand(GEInt) const;
    GEInt GetCommandCount() const;
    gCInfoScriptLine_PS *GetCurrentCommand();
    gCInfoScriptLine_PS const *GetCurrentCommand() const;
    gCInfo_PS *GetInfo();
    GEBool IsRunning() const;
    void OnCommandCompleted(GEBool);
    void SetInfo(gCInfo_PS *);

  protected:
    void Invalidate();

  protected:
    gCInfo_PS *m_pInfo;
};

GE_ASSERT_SIZEOF(gCInfoScript_PS, 0x24)

GE_ASSERT_PROPERTY(gCInfoScript_PS, m_arrInfoScriptLines, 0xc, 12)
GE_ASSERT_PROPERTY(gCInfoScript_PS, m_currentScriptLine, 0x18, 4)
GE_ASSERT_PROPERTY(gCInfoScript_PS, m_bScriptIsRunning, 0x1c, 1)
