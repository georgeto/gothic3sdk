#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_triggerbase_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCEventFilter_PS : public eCTriggerBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCEventFilter_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: void OnTrigger(eCEntity *, eCEntity *) override;
    protected: void OnUntrigger(eCEntity *, eCEntity *) override;
    protected: void OnTouch(eCEntity *, eCContactIterator &) override;
    protected: void OnIntersect(eCEntity *, eCContactIterator &) override;
    protected: void OnUntouch(eCEntity *, eCContactIterator &) override;
    protected: void OnDamage(eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator &) override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    public: bCString const & GetTriggerTarget(GEInt) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCEventFilter_PS, eCTriggerBase_PS)
    GE_ENUMPROP(eEEventType, FireEventWhenTriggered, m_enuFireEventWhenTriggered)
    GE_ENUMPROP(eEEventType, FireEventWhenUntriggered, m_enuFireEventWhenUntriggered)
    GE_ENUMPROP(eEEventType, FireEventWhenTouched, m_enuFireEventWhenTouched)
    GE_ENUMPROP(eEEventType, FireEventWhenUntouched, m_enuFireEventWhenUntouched)
    GE_ENUMPROP(eEEventType, FireEventWhenIntersects, m_enuFireEventWhenIntersects)
    GE_ENUMPROP(eEEventType, FireEventWhenDamaged, m_enuFireEventWhenDamaged)
    GE_PROPERTY(GEU16, DefaultDamage, m_u16DefaultDamage)
    GE_PROPERTY(GEU16, DefaultDamageType, m_u16DefaultDamageType)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCEventFilter_PS, 0x50)

GE_ASSERT_PROPERTY(eCEventFilter_PS, m_enuFireEventWhenTriggered, 0x1c, 8)
GE_ASSERT_PROPERTY(eCEventFilter_PS, m_enuFireEventWhenUntriggered, 0x24, 8)
GE_ASSERT_PROPERTY(eCEventFilter_PS, m_enuFireEventWhenTouched, 0x2c, 8)
GE_ASSERT_PROPERTY(eCEventFilter_PS, m_enuFireEventWhenUntouched, 0x34, 8)
GE_ASSERT_PROPERTY(eCEventFilter_PS, m_enuFireEventWhenIntersects, 0x3c, 8)
GE_ASSERT_PROPERTY(eCEventFilter_PS, m_enuFireEventWhenDamaged, 0x44, 8)
GE_ASSERT_PROPERTY(eCEventFilter_PS, m_u16DefaultDamage, 0x4c, 2)
GE_ASSERT_PROPERTY(eCEventFilter_PS, m_u16DefaultDamageType, 0x4e, 2)
