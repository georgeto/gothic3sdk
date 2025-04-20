#pragma once

#include <GUI.h>

class CFFGFCDeviceContext;

class GE_DLLIMPORT CFFGFCDeviceContextMap
{
  public:
    CFFGFCDeviceContextMap(CFFGFCDeviceContextMap const &);
    CFFGFCDeviceContextMap();
    ~CFFGFCDeviceContextMap();

  public:
    CFFGFCDeviceContextMap &operator=(CFFGFCDeviceContextMap const &);

  public:
    CFFGFCDeviceContext *FromHandle(IFFGUIDeviceContext *);
    void RemovePermanent(IFFGUIDeviceContext *);
    void SetPermanent(IFFGUIDeviceContext *, CFFGFCDeviceContext *);

  protected:
    void DeleteTemporary();
    CFFGFCDeviceContext *LookupPermanent(IFFGUIDeviceContext *) const;
    CFFGFCDeviceContext *LookupTemporary(IFFGUIDeviceContext *) const;
};
