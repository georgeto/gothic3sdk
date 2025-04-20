#pragma once

#include <Engine.h>

class gCCameraModeParams : public bCObjectRefBase
{
    // GE_UNIMPL_STRUCT(gCCameraModeParams)
    GE_UNIMPL_MEMBERS(132)
};
GE_ASSERT_SIZEOF(gCCameraModeParams, 144)

enum gECameraMode
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT gCCameraAI_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual void SetTarget(eCEntity *);
    public: virtual eCEntity const * GetTarget() const;
    public: virtual eCEntity * GetTarget();
    public: virtual void SetMode(gECameraMode, GEBool, GEBool);
    public: virtual gECameraMode GetMode();
    public: virtual gECameraMode GetLastMode();
    public: virtual GEBool IsLookingBack() const;
    public: virtual GEBool IsInFirstPerson() const;
    public: virtual GEBool IsInTempFirstPerson() const;
    public: virtual void EnableTempFirstPerson(GEBool);
    public: virtual GEBool IsInSpecialBowMode() const;
    public: virtual void EnableSpecialBowMode(GEBool);
    protected: virtual void DrawRay(bCUnitedRay const &, GEFloat);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCCameraAI_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool CanBePaused() const override;
    protected: GEBool IsProcessable() const override;
    public: GEInt OnAction(eCInpShared::eSGameKeyMessage const &) override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    protected: void OnUpdatedWorldMatrix() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCCameraAI_PS, eCEntityPropertySet)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeNormal, m_poCamModeNormal)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeMelee, m_poCamModeMelee)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeRanged, m_poCamModeRanged)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeMagic, m_poCamModeMagic)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialog, m_poCamModeDialog)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeInventory, m_poCamModeInventory)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeSwim, m_poCamModeSwim)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDive, m_poCamModeDive)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeInteraction, m_poCamModeInteraction)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeFall, m_poCamModeFall)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDeath, m_poCamModeDeath)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeFirstPerson, m_poCamModeFirstPerson)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeFirstPersonFight, m_poCamMode1stPersonFight)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeFirstPersonRnged, m_poCamMode1stPersonRnged)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeShoulder, m_poCamModeShoulder)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogFaceL, m_poCamModeDialogFaceL)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogFaceR, m_poCamModeDialogFaceR)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogFace2L, m_poCamModeDialogFace2L)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogFace2R, m_poCamModeDialogFace2R)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogShoulder1L, m_poCamModeDialogShoulder1L)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogShoulder2L, m_poCamModeDialogShoulder2L)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogShoulder1R, m_poCamModeDialogShoulder1R)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogShoulder2R, m_poCamModeDialogShoulder2R)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogSideL, m_poCamModeDialogSideL)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogSideR, m_poCamModeDialogSideR)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogLerp1, m_poCamModeDialogLerp1)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogLerp2, m_poCamModeDialogLerp2)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogLerp3, m_poCamModeDialogLerp3)
    GE_OBJECTPROP(gCCameraModeParams, bCObjectRefBase, CamModeDialogLerp4, m_poCamModeDialogLerp4)

  public:
    static GEBool GE_STDCALL S_FilterShape(eCEntity *, eCCollisionShape *);
    static eCEntity *GE_STDCALL S_GetRayTargetEntity();

  public:
    bTPropertyObject<gCCameraModeParams, bCObjectRefBase> &AccessCamMode1stPersonRnged();
    void AddTremor(bCVector const &, GEFloat, GEFloat, GEFloat, bCVector const &);
    void Disable(GEBool const &);
    void EntityMovedBigDistance();
    bTPropertyObject<gCCameraModeParams, bCObjectRefBase> const &GetCamMode1stPersonRnged() const;
    GEBool GetDebugMode() const;
    GEBool GetInvertXAxis() const;
    GEBool GetInvertYAxis() const;
    bCVector GetListenerPosition() const;
    GEFloat GetMouseSensitivityX() const;
    GEFloat GetMouseSensitivityY() const;
    GEFloat GetMouseSmoothingX() const;
    GEFloat GetMouseSmoothingY() const;
    bCVector GetSpeakerPosition() const;
    GEBool IsDialogCameraActive() const;
    GEBool IsDisabled() const;
    void GE_STDCALL OnConsoleCommand(bCObjectRefBase *, bCEvent *);
    void SetCamMode1stPersonRnged(bTPropertyObject<gCCameraModeParams, bCObjectRefBase> const &);
    void SetDebugMode(GEBool);
    void SetDialogRoles(eCEntity *, eCEntity *);
    void SetInvertXAxis(GEBool);
    void SetInvertYAxis(GEBool);
    void SetLookAtTarget(bCVector &);
    void SetMouseSensitivityX(GEFloat);
    void SetMouseSensitivityY(GEFloat);
    void SetMouseSmoothingX(GEFloat);
    void SetMouseSmoothingY(GEFloat);
    void SetMoveSpeed(GEFloat);
    void SetMoveSpeedAccelerator(GEFloat);
    void SetMoveSpeedDeccelerator(GEFloat);
    void StartDialogCamera(GEBool);
    void StopDialogCamera();
    void StopTremor();

  protected:
    static eCEntity *ms_pRayTargetEntity;

  protected:
    void ApplyTremor(bCMatrix &);
    GEBool CorrectCameraPosition(bCVector &, GEFloat, GEFloat, GEFloat, GEBool, bCVector *);
    GEBool DialogPresetIsValid(gCCameraModeParams &, GEBool);
    void EnableItemRendering(GEBool);
    gCCameraModeParams *FindPreset(GEBool, GEBool);
    GEFloat GetAzimuth(bCVector const &) const;
    GEFloat GetCurrentDistance() const;
    GEFloat GetCurrentWishedDistance();
    bCMatrix GetCurrentWishedRotation();
    bCVector GetCurrentWishedTranslation();
    GEFloat GetElevation(bCVector const &) const;
    bCMatrix GetFirstPersonMat() const;
    bCMatrix GetHeadMat(eCEntityProxy const &) const;
    void Invalidate();
    void MaintainWallDistance(bCVector &);
    void ProcessCurrentMode();
    void RegisterConsoleCommands();
    void SetChildrenRenderAlphaValue(eCEntity *, GEFloat);
    void ShowDebug();
    void UpdateCameraPosition(bCVector const &);
    void UpdateDeltaRotX(GEFloat);
    void UpdateDeltaRotY(GEFloat);
    void UpdateDistance(GEFloat, GEFloat);
    void UpdateFOV(GEFloat);
    void UpdateListenerPosition(GEBool);
    void UpdatePlayerPosition();
    void UpdateSpeakerPosition(GEBool);

  private:
    GE_UNIMPL_MEMBERS(884)
};

GE_ASSERT_SIZEOF(gCCameraAI_PS, 0x558)

GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeNormal, 0x14, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeMelee, 0x24, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeRanged, 0x34, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeMagic, 0x44, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialog, 0x54, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeInventory, 0x64, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeSwim, 0x74, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDive, 0x84, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeInteraction, 0x94, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeFall, 0xa4, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDeath, 0xb4, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeFirstPerson, 0xc4, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamMode1stPersonFight, 0xd4, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamMode1stPersonRnged, 0xe4, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeShoulder, 0xf4, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogFaceL, 0x104, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogFaceR, 0x114, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogFace2L, 0x124, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogFace2R, 0x134, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogShoulder1L, 0x144, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogShoulder2L, 0x154, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogShoulder1R, 0x164, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogShoulder2R, 0x174, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogSideL, 0x184, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogSideR, 0x194, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogLerp1, 0x1a4, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogLerp2, 0x1b4, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogLerp3, 0x1c4, 16)
GE_ASSERT_PROPERTY(gCCameraAI_PS, m_poCamModeDialogLerp4, 0x1d4, 16)
