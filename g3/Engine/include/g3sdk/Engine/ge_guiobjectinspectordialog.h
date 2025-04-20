#pragma once

#include <GFC.h>

class eCScopeInstance;
struct eIDispatch;

class GE_DLLIMPORT eCGUIObjectInspectorDialog : public CFFGFCDialog
{
    // clang-format off
    public: ~eCGUIObjectInspectorDialog() override;
    // clang-format on

  public:
    eCGUIObjectInspectorDialog(eCGUIObjectInspectorDialog const &);
    eCGUIObjectInspectorDialog();

  public:
    eCGUIObjectInspectorDialog &operator=(eCGUIObjectInspectorDialog const &);

  public:
    void AddControls(eIDispatch *);
    void AddControls(eCScopeInstance *);
    GEBool Create(eCScopeInstance *);
    void RemoveControls();
};
