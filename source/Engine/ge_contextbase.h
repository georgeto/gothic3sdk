#ifndef GE_CONTEXTBASE_H_INCLUDED
#define GE_CONTEXTBASE_H_INCLUDED

class eCNode;

class GE_DLLIMPORT eCContextBase :
    public bCObjectRefBase
{
    public:    virtual GEBool   IsDataAvailable( void ) const;
    public:    virtual void     SetGraph( eCNode * );
    public:    virtual GEBool   IsProcessing( void ) const;
    public:    virtual GEFloat  QueryProgress( void ) const;
    public:    virtual eCNode * CreateSpecificEntity( void );
    protected: virtual void     UpdateBoundingBox( void );
    public:    virtual void     OnUpdateInternals( void );
    public:    virtual GEU16    GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );
    public:    virtual bEResult CopyFrom( bCObjectBase const & );
    public:    virtual         ~eCContextBase( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCContextBase( eCContextBase const & );
        eCContextBase( void );

    public:
        eCContextBase const & operator = ( eCContextBase const & );

    public:
        bCBox &          AccessContextBox( void );
        bCGuid &         AccessID( void );
        void             DisableUpdateInternalsOnWrite( void );
        void             Enable( GEBool );
        bCBox const &    GetContextBox( void ) const;
        bCString const & GetFilePath( void ) const;
        eCNode *         GetGraph( void );
        eCNode const *   GetGraph( void ) const;
        bCGuid const &   GetID( void ) const;
        GEU32            GetNodeCount( void ) const;
        GEFloat          GetObjectCullFactor( void ) const;
        GEFloat          GetVisualLoDFactor( void ) const;
        GEBool           HasGraph( void ) const;
        GEBool           IsEnabled( void ) const;
        GEBool           IsLocked( void ) const;
        GEU16            Lock( void );
        void             SetContextBox( bCBox const & );
        void             SetFetchingMode( GEBool );
        void             SetFilePath( bCString const & );
        void             SetID( bCGuid const & );
        void             SetModified( void );
        void             SetObjectCullFactor( GEFloat );
        void             SetVisualLoDFactor( GEFloat );
        GEU16            Unlock( void );

    protected:
        void     CollectNodes( eCNode *, bTValArray<eCNode *> & ) const;
        void     Invalidate( void );
        bEResult ReadDependency( bCIStream &, bTValArray<eCNode *> & );
        bEResult WriteDependency( bCOStream &, bTValArray<eCNode *> const & );

};

#endif
