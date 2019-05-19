#ifndef GE_ENTITYPROPERTYSET_H_INCLUDED
#define GE_ENTITYPROPERTYSET_H_INCLUDED

class eCTemplateEntity;

class eCRenderContext;

struct eSPropertySetDebugLine;
class eCContactIterator;
enum eEDecayState;
struct eSRayIntersectionDesc;
class eCCollisionDesc;

class GE_DLLIMPORT eCEntityPropertySet :
    public bCObjectRefBase
{
    public:
        enum eEPSSaveGameRelevance
        {
            // Do not include in save game
            eEPSSaveGameRelevance_None              = 0,
            // Use ReadSaveGame and WriteSaveGame
            eEPSSaveGameRelevance_ReadWriteSaveGame = 1,
            // Use Read and Write
            eEPSSaveGameRelevance_ReadWrite         = 2
        };

    private:
        // 0000 // eCEntityPropertySet::`vftable'
        // 0004 // bCPropertyObjectBase * mPropertyObject;
        // 0008 // GEU32 mReferenceCount;
        /* 000C */ eCEntity * mEntity;
        /* 0010 */ GEU32      mState;

    public:    virtual eEPropertySetType     GetPropertySetType( void ) const;
    public:    virtual bCString const &      GetPropertySetClassName( void ) const;
    public:    virtual eCEntity const *      GetEntity( void ) const;
    public:    virtual eCEntity *            GetEntity( void );
    public:    virtual GEBool                CanBePaused( void ) const;
    public:    virtual GEBool                IsReferencedByTemplate( void ) const;
    public:    virtual GEBool                IsPersistable( void ) const;
    public:    virtual GEBool                IsCopyable( void ) const;
    public:    virtual GEBool                IsVisual( void ) const;
    public:    virtual GEBool                IsProcessable( void ) const;
    public:    virtual GEBool                IsPhysicRelevant( void ) const;
    public:    virtual GEBool                IsEditorRelevant( void ) const;
    public:    virtual eCRenderContext *     QueryRenderContext( void );
    public:    virtual GEBool                SupportsRenderDebugOutput( void ) const;
    public:    virtual GEBool                IsRefracted( void ) const;
    public:    virtual GEBool                HasRenderAlphaComponent( void ) const;
    public:    virtual bEResult              ReadSaveGame( bCIStream & );
    public:    virtual bEResult              WriteSaveGame( bCOStream & );
    public:    virtual eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public:    virtual void                  OnSaveGameEntityPostRead( void );
    public:    virtual void                  GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    public:    virtual eCEntityPropertySet * Clone( eCEntity * ) const;
    public:    virtual void                  SetEntity( eCEntity * );
    protected: virtual GEInt                 OnAction( eCInpShared::eSGameKeyMessage const & );
    protected: virtual GEInt                 OnMouse( eCInpShared::eSInputMessage const & );
    protected: virtual GEInt                 OnKeyboard( eCInpShared::eSInputMessage const & );
    protected: virtual void                  OnTrigger( eCEntity *, eCEntity * );
    protected: virtual void                  OnUntrigger( eCEntity *, eCEntity * );
    protected: virtual void                  OnTouch( eCEntity *, eCContactIterator & );
    protected: virtual void                  OnIntersect( eCEntity *, eCContactIterator & );
    protected: virtual void                  OnUntouch( eCEntity *, eCContactIterator & );
    protected: virtual void                  OnDamage( eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator & );
    protected: virtual void                  OnEnterProcessingRange( void );
    protected: virtual void                  OnExitProcessingRange( void );
    protected: virtual void                  Trigger( bCString const & );
    public:    virtual GEBool                IsAutoKillEnabled( void ) const;
    public:    virtual eEDecayState          GetDecayState( void ) const;
    public:    virtual void                  Decay( void );
    public:    virtual void                  GetOnScreenDebugLines( GEU32, bTObjArray<eSPropertySetDebugLine> & ) const;
    protected: virtual void                  OnRender( GEI16 );
    protected: virtual void                  OnRenderAlpha( GEI16 );
    public:    virtual void                  OnRenderDebug( void );
    protected: virtual void                  OnUpdateInternals( void );
    protected: virtual void                  OnPostUpdateInternals( void );
    protected: virtual void                  OnUpdatedWorldMatrix( void );
    protected: virtual void                  OnUpdatedWorldTreeBoundary( void );
    protected: virtual void                  OnCacheIn( void );
    protected: virtual void                  OnCacheOut( void );
    public:    virtual void                  GetBoundary( bCBox &, GEBool );
    public:    virtual void                  OnProcess( void );
    public:    virtual void                  OnPreProcess( void );
    public:    virtual void                  OnPostProcess( void );
    public:    virtual void                  OnPostRead( void );
    public:    virtual void                  OnPostCopy( eCEntityPropertySet const & );
    public:    virtual void                  OnDeinitialize( void );
    public:    virtual void                  OnPropertySetAdded( void );
    public:    virtual void                  OnPropertySetRemoved( void );
    public:    virtual void                  OnChildrenAvailable( GEU32, GEU32, eCTemplateEntity * );
    public:    virtual void                  OnCustomPatch( eCEntityPropertySet const * );
    public:    virtual GEBool                IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;
    public:    virtual GEBool                IntersectsVolume( bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool ) const;
    public:    virtual GEU16                 GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult              Write( bCOStream & );
    public:    virtual bEResult              Read( bCIStream & );
    public:    virtual void                  Destroy( void );
    public:    virtual bEResult              Create( void );
    public:    virtual bEResult              CopyFrom( bCObjectBase const & );
    public:    virtual                      ~eCEntityPropertySet( void );
    public:    virtual GEBool                IsVirtualReferencingEnabled( void ) const;
    protected: virtual GEBool                OnNotifyPropertyValueChangedEnterEx( GELPCChar, GEBool );
    protected: virtual GEBool                OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    protected: virtual GEBool                NotifyPropertyValueChangedEnterEx( GELPCChar, GEBool );
    protected: virtual GEBool                NotifyPropertyValueChangedExitEx( GELPCChar, GEBool );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCEntityPropertySet( eCEntityPropertySet const & );
        eCEntityPropertySet( void );

    public:
        eCEntityPropertySet const & operator = ( eCEntityPropertySet const & );

    public:
        void   EnableRendering( GEBool );
        GEBool IsRenderingEnabled( void ) const;
        void   Modified( void );

    protected:
        void Invalidate( void );

};

#endif
