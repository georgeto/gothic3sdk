#pragma once

#include <Engine/entity/ge_entitypropertyset.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTriggerBase_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual bCString const & GetTriggerTarget(GEInt) const;
    protected: virtual void OnTimer();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCTriggerBase_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    protected: void OnTrigger(eCEntity *, eCEntity *) override;
    protected: void OnUntrigger(eCEntity *, eCEntity *) override;
    protected: void OnTouch(eCEntity *, eCContactIterator &) override;
    protected: void OnIntersect(eCEntity *, eCContactIterator &) override;
    protected: void OnUntouch(eCEntity *, eCContactIterator &) override;
    protected: void OnDamage(eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator &) override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCTriggerBase_PS, eCEntityPropertySet)
    GE_PROPERTY(bCString, TargetEntity, m_strTargetEntity)

  protected:
    void Invalidate();
    GEBool IsOnTimer() const;
    void ResetOnTimer();
    void SetOnTimer(GEFloat);

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(eCTriggerBase_PS, 0x1c)

GE_ASSERT_PROPERTY(eCTriggerBase_PS, m_strTargetEntity, 0x14, 4)

GE_DLLIMPORT_EXTC eCContactIterator g_InvalidContact;
