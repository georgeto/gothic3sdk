#pragma once

#include <SharedBase.h>

class gCAmbientLibrary;
class gCAmbientSequencer;

class GE_DLLIMPORT gCAmbientSystem
{
    // clang-format off
    public: virtual ~gCAmbientSystem();
    // clang-format on

  public:
    gCAmbientSystem(gCAmbientSystem const &);
    gCAmbientSystem();

  public:
    gCAmbientSystem &operator=(gCAmbientSystem const &);

  public:
    gCAmbientLibrary &GetLibrary();
    gCAmbientLibrary const &GetLibrary() const;
    gCAmbientSequencer *GetSequencer() const;
    void Process(GEFloat);

  protected:
    void Create();
    void Destroy();
    void Invalidate();
};
