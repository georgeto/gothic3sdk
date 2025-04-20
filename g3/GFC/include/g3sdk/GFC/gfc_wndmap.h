#pragma once

#include <GUI.h>

class CFFGFCWnd;

class GE_DLLIMPORT CFFGFCWndMap
{
  public:
    CFFGFCWndMap(CFFGFCWndMap const &);
    CFFGFCWndMap();
    ~CFFGFCWndMap();

  public:
    CFFGFCWndMap &operator=(CFFGFCWndMap const &);

  public:
    CFFGFCWnd *FromHandle(IFFGUIWindow *);
    void RemovePermanent(IFFGUIWindow *);
    void SetPermanent(IFFGUIWindow *, CFFGFCWnd *);

  protected:
    void DeleteTemporary();
    CFFGFCWnd *LookupPermanent(IFFGUIWindow *) const;
    CFFGFCWnd *LookupTemporary(IFFGUIWindow *) const;
};
