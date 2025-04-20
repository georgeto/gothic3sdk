#pragma once

#include <SharedBase.h>

class eCGUIAdmin;
class eCGUIDatabase;
class eCGUIRenderer;
class eCGUIStreamer;

class GE_DLLIMPORT eCGUISubAdmin
{
    // clang-format off
    public: virtual ~eCGUISubAdmin();
    // clang-format on

  public:
    eCGUISubAdmin(eCGUISubAdmin const &);
    explicit eCGUISubAdmin(eCGUIAdmin *);

  public:
    eCGUISubAdmin &operator=(eCGUISubAdmin const &);

  public:
    eCGUIDatabase *GetDatabase() const;
    eCGUIRenderer *GetRenderer() const;
    eCGUIStreamer *GetStreamer() const;
};
