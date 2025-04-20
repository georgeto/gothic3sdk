#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCSessionEditor : public eCInputReceiver
{
    // clang-format off
    public: virtual void CopyFrom(gCSessionEditor const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCSessionEditor() override;
    protected: eCInputReceiver::eEInputPriority GetInputPriority() const override;
    protected: GEInt OnAction(eCInpShared::eSGameKeyMessage const &) override;
    protected: GEInt OnKeyboard(eCInpShared::eSInputMessage const &) override;
    protected: GEInt OnMouse(eCInpShared::eSInputMessage const &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCSessionEditor, eCInputReceiver)
    GE_ENUMPROP(gESessionEditorState, State, m_enuState)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    NxActor *GetCurrentDragActor() const;
    eCEntity *GetCurrentEntity() const;
    void Invalidate();
    void OnPostRender();
    void PreShutdown();
    void Process();
    void SetCurrentDragActor(NxActor *);
    void SetCurrentEntity(eCEntity *);
    void Show(GEBool);

  protected:
    void LineDrag(bCVector const &, bCVector const &);
    void LinePick(bCVector const &, bCVector const &, bCVector const &);
    void GE_STDCALL OnConsoleCommand(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnDesktopClick(bCObjectRefBase *, eCClickEventArg *);
    void GE_STDCALL OnEditMenuClicked(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnFreeCamMode(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnNavigateMode(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnPhysicsMode(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnPropertyMode(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnSteeringMode(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleOption(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnViewMenuClicked(bCObjectRefBase *, bCEvent *);
    void RemoveAddedPSets();
    void UnPick();

  private:
    void DeregisterEvents();
    void RegisterEvents();

  private:
    GE_UNIMPL_MEMBERS(88)
};

GE_ASSERT_SIZEOF(gCSessionEditor, 0x70)

GE_ASSERT_PROPERTY(gCSessionEditor, m_enuState, 0x10, 8)
