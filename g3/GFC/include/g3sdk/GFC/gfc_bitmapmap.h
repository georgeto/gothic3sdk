#pragma once

#include <GUI.h>

class CFFGFCBitmap;

class GE_DLLIMPORT CFFGFCBitmapMap
{
  public:
    CFFGFCBitmapMap(CFFGFCBitmapMap const &);
    CFFGFCBitmapMap();
    ~CFFGFCBitmapMap();

  public:
    CFFGFCBitmapMap &operator=(CFFGFCBitmapMap const &);

  public:
    CFFGFCBitmap *FromHandle(IFFGUIBitmap *);
    void RemovePermanent(IFFGUIBitmap *);
    void SetPermanent(IFFGUIBitmap *, CFFGFCBitmap *);

  protected:
    void DeleteTemporary();
    CFFGFCBitmap *LookupPermanent(IFFGUIBitmap *) const;
    CFFGFCBitmap *LookupTemporary(IFFGUIBitmap *) const;
};
