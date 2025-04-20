#pragma once

#include <SharedBase.h>

class eCGfxCameraStates;

class GE_DLLIMPORT eCGfxCamera : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxCamera const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxCamera() override;
    // clang-format on

  public:
    eCGfxCamera(eCGfxCamera const &);
    eCGfxCamera();

  public:
    eCGfxCamera &operator=(eCGfxCamera const &);

  public:
    bEResult AttachCameraStates(eCGfxCameraStates *);
    bEResult Execute();
    bEResult GetAttachedCameraStates(eCGfxCameraStates *&) const;
    bCMatrix const &GetDepthBiasProjectionMatrix() const;
    bCMatrix const &GetInverseViewMatrix() const;
    bEResult GetProjectionMatrix(bCMatrix &) const;
    bCMatrix const &GetProjectionMatrix() const;
    bEResult GetViewMatrix(bCMatrix &) const;
    bCMatrix const &GetViewMatrix() const;
    bCMatrix const &GetViewProjectionMatrix() const;
    void Invalidate();
    bEResult SetDepthBiasProjectionMatrix(bCMatrix const &);
    bEResult SetProjectionMatrix(bCMatrix const &);
    bEResult SetViewMatrix(bCMatrix const &);

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxCamera *ms_pActiveCamera;
    static eCGfxCamera *ms_pMasterCamera;
    static void(GE_STDCALL *ms_pRegisterCameraExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxCamera *GE_STDCALL sGetActiveCamera();
    static eCGfxCamera *GE_STDCALL sGetMasterCamera();
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetCameraExecuteCallback(void(GE_STDCALL *)());
    static void GE_STDCALL sSetMasterCamera(eCGfxCamera *);
};
