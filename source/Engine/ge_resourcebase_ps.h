#ifndef GE_RESOURCEBASE_PS_H_INCLUDED
#define GE_RESOURCEBASE_PS_H_INCLUDED

enum eEResourceCacheBehavior
{
    eEResourceCacheBehavior_Immediate = 1,
    eEResourceCacheBehavior_Lazy      = 2,
    eEResourceCacheBehavior_3      = 3
};
enum eEResourceState;
class eCResourceDataEntity;

class GE_DLLIMPORT eCResourceBase_PS :
    public bCObjectRefBase
{
    public:
        enum eECacheType;

    public:    virtual bCString const &             GetNativeFileExt( void ) const;
    public:    virtual bCString const &             GetProprietaryFileExt( void ) const;
    public:    virtual GEU32                        GetSize( void ) const;
    public:    virtual eECacheType                  GetCacheType( void ) const;
    public:    virtual eCResourceDataEntity *       GetEntity( void );
    public:    virtual eCResourceDataEntity const * GetEntity( void ) const;
    protected: virtual void                         SetResourceFilePath( bCString const & );
    public:    virtual bEResult                     DoLoad( void );
    public:    virtual bEResult                     DoUnload( void );
    public:    virtual bEResult                     DoReload( void );
    public:    virtual bEResult                     DoConvert( void );
    public:    virtual bEResult                     DoSave( void );
    public:    virtual GEBool                       IsDataAvailable( void ) const;
    public:    virtual GEBool                       IsResourceFileAvailable( bCString const & ) const;
    protected: virtual void                         CalculateSize( void );
    public:    virtual GEBool                       IsVirtualReferencingEnabled( void ) const;
    public:    virtual void                         GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    protected: virtual eCArchiveFile                CreateProprietaryFile( bCString const & );
    public:    virtual void                         GetBoundary( bCBox &, GEBool );
    public:    virtual void                         OnUpdateInternals( void );
    public:    virtual GEBool                       IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;
    public:    virtual GEBool                       IntersectsVolume( bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool ) const;
    public:    virtual GEU16                        GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                     Write( bCOStream & );
    public:    virtual bEResult                     Read( bCIStream & );
    public:    virtual void                         Destroy( void );
    public:    virtual bEResult                     Create( void );
    public:    virtual bEResult                     CopyFrom( bCObjectBase const & );
    public:    virtual GEU32                        AddReference( void );
    public:    virtual GEU32                        ReleaseReference( void );
    public:    virtual                             ~eCResourceBase_PS( void );
    protected: virtual GEBool                       IsLocked( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCResourceBase_PS( eCResourceBase_PS const & );
        eCResourceBase_PS( void );

    public:
        GEFloat &               AccessResourcePriority( void );
        eEResourceCacheBehavior GetCacheBehavior( void ) const;
        eEResourceState         GetCurrentResourceState( void ) const;
        bCString                GetFileBaseName( void ) const;
        bCDateTime              GetFileTime( void ) const;
        bCString const &        GetNFOFileExt( void ) const;
        bCString                GetNFOFileName( void ) const;
        bCString                GetNativeFileName( void ) const;
        bCString                GetProprietaryFileName( void ) const;
        GEFloat const &         GetResourcePriority( void ) const;
        GEBool                  IsInvalid( void ) const;
        GEBool                  IsProcessing( void ) const;
        void                    SetResourcePriority( GEFloat const & );
        void                    WaitUntilNonProcessing( GEInt );

    protected:
        void Invalidate( void );

    private:
        bEResult Convert( eEResourceCacheBehavior );
        bEResult Load( eEResourceCacheBehavior );
        bEResult Reload( eEResourceCacheBehavior );
        bEResult Save( eEResourceCacheBehavior );
        void     SetFileBaseName( bCString const & );
        bEResult Unload( eEResourceCacheBehavior );

};

#endif
