#pragma once

#include <Game/dummycollector/ge_dummycollectorbase.h>

#include <Engine.h>

class GE_DLLIMPORT gCDummyCollectorPSet_Base : public gCDummyCollectorBase
{
  public:
    struct gSCollectionMember
    {
        eCEntity *m_pEntity;
        eCEntityPropertySet *m_pPropertySet;
        eCEntity *m_pDummyEntity;
        bTObjArray<eCEntity *> field_12;
        bTObjArray<eCEntity *> field_24;
    };

    // clang-format off
    protected: virtual void RemoveFromCollectionInternal(eCEntity &, bTSmallArray<eCEntity *> &);
    public: virtual eEPropertySetType GetPropertySetType() const = 0;
    public: virtual GEU32 GetPropertySetMemberCount(eCEntity &) const;
    public: virtual bEResult AddPropertySetMember(eCEntity &, eCEntity *&, GEInt, GEInt, GEInt) = 0;
    protected: virtual bEResult DeleteIndexInPropertySet(GEInt, GEInt) = 0;
    protected: virtual bEResult AddIndexInPropertySet(GEInt, GEInt, GEInt, GEInt) = 0;
    protected: virtual bEResult VisualizeCollectionMember(GEInt, GEBool) = 0;
    public: bEResult Apply() override;
    public: bEResult UpdateCollection() override;
    public: bEResult UpdateCollection(eCEntity &) override;
    public: bEResult ClearCollection() override;
    public: bEResult RemoveFromCollection(eCEntity &) override;
    public: GEU32 GetReferencedEntitiesCount() const override;
    public: eCEntity * GetReferencedEntityAt(GEU32) const override;
    public: GEBool IsInUpdateCollection() const override;
    public: ~gCDummyCollectorPSet_Base() override;
    // clang-format on

  public:
    gCDummyCollectorPSet_Base(gCDummyCollectorPSet_Base const &);

  public:
    gCDummyCollectorPSet_Base &operator=(gCDummyCollectorPSet_Base const &);

  public:
    bEResult DeletePropertySetMember(eCEntity &, GEInt);
    bEResult DeletePropertySetMember(eCEntity &, eCEntity *);
    void EnableRenderingForIndex(eCEntity &, GEInt, GEBool);
    eCEntity *GetDummyEntity(eCEntity const &) const;
    eCEntity *GetDummyEntityAtIndex(eCEntity &, GEInt) const;
    GEInt GetEntityAndMemberIndex(eCEntity const *, eCEntity *&);

  protected:
    explicit gCDummyCollectorPSet_Base(eCEntity &);

  protected:
    bEResult AddNewPropertySetMember(eCEntity &, eCEntity *&, GEInt, GEInt, GEInt);
    bEResult ApplyPropertySet(bCBox const &, eEPropertySetType const &);
    bEResult BlockAllDummyVisuals(GEInt);
    bEResult CollectPropertySets(eCEntity &, eEPropertySetType const &);
    bEResult CollectPropertySets(bCBox const &, eEPropertySetType const &);
    bEResult UnblockAllDummyVisuals(GEInt);

  private:
    eCEntity *m_pBaseRootyEntity;
    bTObjArray<gSCollectionMember> m_arrCollectionMembers;
    GEBool m_bInUpdateCollection;
    GE_PADDING(0x3)
};

GE_ASSERT_SIZEOF(gCDummyCollectorPSet_Base, 0x1c)
