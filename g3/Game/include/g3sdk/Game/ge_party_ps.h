#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCParty_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCParty_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: GEBool IsReferencedByTemplate() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void GetOnScreenDebugLines(GEU32, bTObjArray<eSPropertySetDebugLine> &) const override;
    protected: void OnChildrenAvailable(GEU32, GEU32, eCTemplateEntity *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCParty_PS, eCEntityPropertySet)
    GE_PROPERTY(eCEntityProxy, PartyLeaderEntity, m_PartyLeader)
    GE_ENUMPROP(gEPartyMemberType, PartyMemberType, m_enuPartyMemberType)
    GE_PROPERTY(GEBool, Waiting, m_bWaiting)
    GE_PADDING(1)

  public:
    bTObjArray<eCEntityProxy> &GetMembers();
    bTObjArray<eCEntityProxy> const &GetMembers() const;

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(gCParty_PS, 0x48)

GE_ASSERT_PROPERTY(gCParty_PS, m_PartyLeader, 0x14, 28)
GE_ASSERT_PROPERTY(gCParty_PS, m_enuPartyMemberType, 0x30, 8)
GE_ASSERT_PROPERTY(gCParty_PS, m_bWaiting, 0x38, 1)
