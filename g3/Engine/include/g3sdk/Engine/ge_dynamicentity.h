#pragma once

#include <Engine/entity/ge_entity.h>

#include <SharedBase.h>

class eCContactIterator;

class GE_DLLIMPORT eCDynamicEntity : public eCEntity
{
  public:
    enum eECreatureClass
    {
        eECreatureClass_Object = 0,
        eECreatureClass_NPC = 1,
        eECreatureClass_Player = 2
    };

    // clang-format off
    public: virtual eECreatureClass GetCreatureClass() const;
    public: virtual void EnableMovementControlByPhysics(GEBool);
    public: virtual GEBool IsMovementControledByPhysics() const;
    public: virtual void DoDamage(eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator &);
    public: virtual void OnTrigger(eCEntity *, eCEntity *);
    public: virtual void OnUntrigger(eCEntity *, eCEntity *);
    public: virtual void OnTouch(eCEntity *, eCContactIterator &);
    public: virtual void OnIntersect(eCEntity *, eCContactIterator &);
    public: virtual void OnUntouch(eCEntity *, eCContactIterator &);
    public: virtual void OnDamage(eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator &);
    protected: virtual void DoSaveGameEntityPostRead();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCDynamicEntity() override;
    protected: eCDynamicEntity * DoClone() const override;
    public: bCVector GetLinearVelocity() const override;
    public: void SetLinearVelocity(bCVector const &) override;
    public: GEBool IsDummy() const override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void OnUpdatedWorldTreeBoundary() override;
    public: void Decay() override;
    public: GEBool IsAutoKillEnabled() const override;
    public: void SetCreator(eCTemplateEntity *) override;
    public: eCTemplateEntity const * GetCreator() const override;
    public: GEBool HasCreator() const override;
    public: void CopyEntityPrivateData(eCEntity const &, GEBool) override;
    protected: GEInt OnAction(eCInpShared::eSGameKeyMessage const &) override;
    protected: GEInt OnMouse(eCInpShared::eSInputMessage const &) override;
    protected: void OnProcess() override;
    protected: void OnPreProcess() override;
    protected: void OnPostProcess() override;
    protected: void OnDeinitialize() override;
    protected: void OnPostRead() override;
    public: void OnCacheIn() override;
    public: void OnCacheOut() override;
    public: void Render(GEI16) override;
    public: void RenderAlpha(GEI16) override;
    // clang-format on

  public:
    void EnableCollisionResponse(GEBool);
    bCPropertyID const &GetCreatorID() const;
    GEU16 GetVisualizedRotAxes() const;
    GEU16 GetVisualizedTransAxes() const;
    GEBool HasCollisionResponse() const;
    GEBool HasDrawName() const;
    GEBool IsNativeSaveGameEntity() const;
    bEResult ReadSaveGame(bCIStream &);
    void SetDrawName(GEU8);
    bEResult SetMeshVisual(bCString const &, GEBool);
    void SetVisualizedRotAxes(GEU16);
    void SetVisualizedTransAxes(GEU16);
    bEResult WriteSaveGame(bCOStream &);

  protected:
    eCDynamicEntity(eCDynamicEntity const &);
    eCDynamicEntity();

  protected:
    eCDynamicEntity const &operator=(eCDynamicEntity const &);

  protected:
    void Invalidate();
};
