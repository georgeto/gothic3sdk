#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCAnchor_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCAnchor_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: GEBool IsVisual() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnPropertySetAdded() override;
    protected: void OnPropertySetRemoved() override;
    protected: void OnChildrenAvailable(GEU32, GEU32, eCTemplateEntity *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCAnchor_PS, eCEntityPropertySet)
    GE_ENUMPROP(gEAnchorType, AnchorType, m_enuAnchorType)
    GE_PROPERTY(GEU32, UserCount, m_u32UserCount)
    GE_PROPERTY(GEU32, MaxUsers, m_u32MaxUsers)
    GE_PROPERTY(GEU32, PatrolIndex, m_u32PatrolIndex)

  public:
    bTObjArray<eCEntityProxy> &GetInteractPoints();
    bTObjArray<eCEntityProxy> const &GetInteractPoints() const;
    void RebuildInteractPoints();

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(gCAnchor_PS, 0x34)

GE_ASSERT_PROPERTY(gCAnchor_PS, m_enuAnchorType, 0x14, 8)
GE_ASSERT_PROPERTY(gCAnchor_PS, m_u32UserCount, 0x1c, 4)
GE_ASSERT_PROPERTY(gCAnchor_PS, m_u32MaxUsers, 0x20, 4)
GE_ASSERT_PROPERTY(gCAnchor_PS, m_u32PatrolIndex, 0x24, 4)
