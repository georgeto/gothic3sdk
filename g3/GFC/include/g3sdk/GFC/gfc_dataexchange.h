#pragma once

#include <SharedBase.h>

class CFFGFCWnd;

class GE_DLLIMPORT CFFGFCDataExchange
{
  public:
    CFFGFCDataExchange(CFFGFCWnd *, GEBool);

  public:
    CFFGFCDataExchange &operator=(CFFGFCDataExchange const &);
};

void GE_STDCALL FF_DDX_Control(CFFGFCDataExchange *, GEInt, CFFGFCWnd &);
