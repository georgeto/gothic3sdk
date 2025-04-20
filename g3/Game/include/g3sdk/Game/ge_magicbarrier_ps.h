#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCNPC_PS;

class GE_DLLIMPORT gCMagicBarrier_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCMagicBarrier_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    public: void OnTouch(eCEntity *, eCContactIterator &) override;
    public: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMagicBarrier_PS, eCEntityPropertySet)
    GE_PROPERTY(GEFloat, Thickness, m_fThickness)
    GE_ENUMPROP(gEMagicBarrierShape, Shape, m_eShape)
    GE_PROPERTY(bCString, OnEnterScript, m_strOnEnterScript)
    GE_PROPERTY(bCString, OnLeaveScript, m_strOnLeaveScript)
    GE_PROPERTY(bCString, OnInScript, m_strOnInScript)
    GE_PROPERTY(bCString, OnToucheBarrier, m_strOnToucheBarrier)

  protected:
    void Invalidate();
    void UpdateStatus(gCNPC_PS *, GEBool);
};

GE_ASSERT_SIZEOF(gCMagicBarrier_PS, 0x30)

GE_ASSERT_PROPERTY(gCMagicBarrier_PS, m_fThickness, 0x14, 4)
GE_ASSERT_PROPERTY(gCMagicBarrier_PS, m_eShape, 0x18, 8)
GE_ASSERT_PROPERTY(gCMagicBarrier_PS, m_strOnEnterScript, 0x20, 4)
GE_ASSERT_PROPERTY(gCMagicBarrier_PS, m_strOnLeaveScript, 0x24, 4)
GE_ASSERT_PROPERTY(gCMagicBarrier_PS, m_strOnInScript, 0x28, 4)
GE_ASSERT_PROPERTY(gCMagicBarrier_PS, m_strOnToucheBarrier, 0x2c, 4)
