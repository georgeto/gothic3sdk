#pragma once

#include <Game.h>

class GE_DLLIMPORT Info
{
  public:
    explicit Info(gCInfo_PS *);
    Info();
    ~Info();

  public:
    Info &operator=(Info const &);

  public:
    gEInfoCondType GetConditionType() const;
    gEInfoType GetInfoType() const;
    GEBool IsComment() const;
    GEBool IsImportant() const;
    GEBool IsValid() const;

  private:
    gCInfo_PS *m_pGameInfo;
};
