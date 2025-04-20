#pragma once

#include <SharedBase.h>

class CFFGFCBitmapMap;
class CFFGFCDeviceContextMap;
class CFFGFCImageListMap;
class CFFGFCWndMap;
class IFFGFCClient;

class GE_DLLIMPORT CFFGFCModule
{
    // clang-format off
    protected: virtual GEU32 OnCreate();
    protected: virtual void OnDestroy();
    public: virtual ~CFFGFCModule();
    // clang-format on

  public:
    static CFFGFCModule &GE_STDCALL GetInstance();

  public:
    CFFGFCModule(CFFGFCModule const &);

  public:
    CFFGFCModule &operator=(CFFGFCModule const &);

  public:
    GEBool DoModalFrame();
    CFFGFCBitmapMap *GetBitmapMap() const;
    IFFGFCClient *GetClient() const;
    CFFGFCDeviceContextMap *GetDeviceContextMap() const;
    CFFGFCImageListMap *GetImageListMap() const;
    CFFGFCWndMap *GetWndMap() const;
    void SetClient(IFFGFCClient *);

  protected:
    CFFGFCModule();

  protected:
    GEBool Create();
    void Destroy();
};
