#pragma once

#include <Game.h>

class GE_DLLIMPORT Effect
{
  public:
    Effect &operator=(Effect const &);

  private:
    Effect(Effect const &);
    explicit Effect(gCEffect * = nullptr);

  private:
    explicit operator gCEffect *() const;

  private:
    gCEffect *m_pHandle;
};

GE_ASSERT_SIZEOF(Effect, 0x4)
