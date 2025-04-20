#pragma once

#include <GUI.h>

class CFFGFCImageList;

class GE_DLLIMPORT CFFGFCImageListMap
{
  public:
    CFFGFCImageListMap(CFFGFCImageListMap const &);
    CFFGFCImageListMap();
    ~CFFGFCImageListMap();

  public:
    CFFGFCImageListMap &operator=(CFFGFCImageListMap const &);

  public:
    CFFGFCImageList *FromHandle(IFFGUIImageList *);
    void RemovePermanent(IFFGUIImageList *);
    void SetPermanent(IFFGUIImageList *, CFFGFCImageList *);

  protected:
    void DeleteTemporary();
    CFFGFCImageList *LookupPermanent(IFFGUIImageList *) const;
    CFFGFCImageList *LookupTemporary(IFFGUIImageList *) const;
};
