#pragma once

#include <Engine/ge_guisubadmin.h>

#include <GUI.h>

class GE_DLLIMPORT eCGUIStreamer : public eCGUISubAdmin
{
    // clang-format off
    public: ~eCGUIStreamer() override;
    // clang-format on

  public:
    eCGUIStreamer(eCGUIStreamer const &);
    explicit eCGUIStreamer(eCGUIAdmin *);

  public:
    eCGUIStreamer &operator=(eCGUIStreamer const &);

  public:
    GEBool Create();
    void Destroy();
    GEBool LoadTheme(IFFGUITheme *);
    GEBool SaveTheme(IFFGUITheme *);

  protected:
    void Invalidate();
    GEBool UpdateTheme(IFFGUITheme *, GEInt, GEBool);
};
