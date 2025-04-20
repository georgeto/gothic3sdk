#pragma once

#include <Game.h>

class Entity;

class GE_DLLIMPORT PSInfoScriptCommand
{
  public:
    explicit PSInfoScriptCommand(gCInfoScriptLine_PS *);
    PSInfoScriptCommand();
    ~PSInfoScriptCommand();

  public:
    PSInfoScriptCommand &operator=(PSInfoScriptCommand const &);

  public:
    bCString GetCommand() const;
    Entity GetEntity1() const;
    Entity GetEntity2() const;
    bCString GetID1() const;
    bCString GetID2() const;
    bCString GetSampleFileBaseName() const;
    bCUnicodeString GetStageDirection() const;
    bCUnicodeString GetText() const;
    bCString GetTextID() const;
    GEBool IsValid() const;

  private:
    gCInfoScriptLine_PS *m_pGameInfoScriptCommand;
};
