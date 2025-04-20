#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCClipboardClient
{
    // clang-format off
    public: virtual void Clear() = 0;
    public: virtual void Copy() = 0;
    public: virtual void Cut() = 0;
    public: virtual void Paste() = 0;
    public: virtual void Undo() = 0;
    public: virtual ~eCClipboardClient();
    // clang-format on

  public:
    eCClipboardClient(eCClipboardClient const &);

  public:
    eCClipboardClient &operator=(eCClipboardClient const &);

  protected:
    eCClipboardClient();
};
