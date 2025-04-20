#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/proxy/ge_templateentityproxy.h>
#include <Engine/io/ge_inpshared.h>

#include <SharedBase.h>

class eCCollisionDesc;
class eCContactIterator;
class eCEntity;
class eCRenderContext;
class eCTemplateEntity;
struct eSRayIntersectionDesc;

struct eSPropertySetDebugLine
{
    GE_UNIMPL_STRUCT(eSPropertySetDebugLine)
};

enum eEDecayState
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCEntityPropertySet : public bCObjectRefBase
{
  public:
    enum eEPSSaveGameRelevance
    {
        // Do not include in save game
        eEPSSaveGameRelevance_None = 0,
        // Use ReadSaveGame and WriteSaveGame
        eEPSSaveGameRelevance_ReadWriteSaveGame = 1,
        // Use Read and Write
        eEPSSaveGameRelevance_ReadWrite = 2
    };

    // clang-format off
    public: virtual eEPropertySetType GetPropertySetType() const;
    public: virtual bCString const & GetPropertySetClassName() const;
    public: virtual eCEntity const * GetEntity() const;
    public: virtual eCEntity * GetEntity();
    public: virtual GEBool CanBePaused() const;
    public: virtual GEBool IsReferencedByTemplate() const;
    public: virtual GEBool IsPersistable() const;
    public: virtual GEBool IsCopyable() const;
    public: virtual GEBool IsVisual() const;
    public: virtual GEBool IsProcessable() const;
    public: virtual GEBool IsPhysicRelevant() const;
    public: virtual GEBool IsEditorRelevant() const;
    public: virtual eCRenderContext * QueryRenderContext();
    public: virtual GEBool SupportsRenderDebugOutput() const;
    public: virtual GEBool IsRefracted() const;
    public: virtual GEBool HasRenderAlphaComponent() const;
    public: virtual bEResult ReadSaveGame(bCIStream &);
    public: virtual bEResult WriteSaveGame(bCOStream &);
    public: virtual eEPSSaveGameRelevance GetSaveGameRelevance() const;
    public: virtual void OnSaveGameEntityPostRead();
    public: virtual void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &);
    public: virtual eCEntityPropertySet * Clone(eCEntity *) const;
    public: virtual void SetEntity(eCEntity *);
    protected: virtual GEInt OnAction(eCInpShared::eSGameKeyMessage const &);
    protected: virtual GEInt OnMouse(eCInpShared::eSInputMessage const &);
    protected: virtual GEInt OnKeyboard(eCInpShared::eSInputMessage const &);
    protected: virtual void OnTrigger(eCEntity *, eCEntity *);
    protected: virtual void OnUntrigger(eCEntity *, eCEntity *);
    protected: virtual void OnTouch(eCEntity *, eCContactIterator &);
    protected: virtual void OnIntersect(eCEntity *, eCContactIterator &);
    protected: virtual void OnUntouch(eCEntity *, eCContactIterator &);
    protected: virtual void OnDamage(eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator &);
    protected: virtual void OnEnterProcessingRange();
    protected: virtual void OnExitProcessingRange();
    protected: virtual void Trigger(bCString const &);
    public: virtual GEBool IsAutoKillEnabled() const;
    public: virtual eEDecayState GetDecayState() const;
    public: virtual void Decay();
    public: virtual void GetOnScreenDebugLines(GEU32, bTObjArray<eSPropertySetDebugLine> &) const;
    protected: virtual void OnRender(GEI16);
    protected: virtual void OnRenderAlpha(GEI16);
    public: virtual void OnRenderDebug();
    protected: virtual void OnUpdateInternals();
    protected: virtual void OnPostUpdateInternals();
    protected: virtual void OnUpdatedWorldMatrix();
    protected: virtual void OnUpdatedWorldTreeBoundary();
    protected: virtual void OnCacheIn();
    protected: virtual void OnCacheOut();
    public: virtual void GetBoundary(bCBox &, GEBool);
    public: virtual void OnProcess();
    public: virtual void OnPreProcess();
    public: virtual void OnPostProcess();
    public: virtual void OnPostRead();
    public: virtual void OnPostCopy(eCEntityPropertySet const &);
    public: virtual void OnDeinitialize();
    public: virtual void OnPropertySetAdded();
    public: virtual void OnPropertySetRemoved();
    public: virtual void OnChildrenAvailable(GEU32, GEU32, eCTemplateEntity *);
    public: virtual void OnCustomPatch(eCEntityPropertySet const *);
    public: virtual GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const;
    public: virtual GEBool IntersectsVolume(bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool) const;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCEntityPropertySet() override;
    public: GEBool IsVirtualReferencingEnabled() const override;
    protected: GEBool OnNotifyPropertyValueChangedEnterEx(GELPCChar, GEBool) override;
    protected: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    protected: GEBool NotifyPropertyValueChangedEnterEx(GELPCChar, GEBool) override;
    protected: GEBool NotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCEntityPropertySet, bCObjectRefBase)

  public:
    void EnableRendering(GEBool);
    GEBool IsRenderingEnabled() const;
    void Modified();

  protected:
    void Invalidate();

  private:
    // 0000 // eCEntityPropertySet::`vftable'
    // 0004 // bCPropertyObjectBase * mPropertyObject;
    // 0008 // GEU32 mReferenceCount;
    /* 000C */ eCEntity *mEntity;
    /* 0010 */ GEU32 mState;
};

GE_ASSERT_SIZEOF(eCEntityPropertySet, 0x14)

GE_DLLIMPORT_EXTC GELPCChar const g_ppszPropertySetTypes[115];
