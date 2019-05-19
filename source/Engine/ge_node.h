#ifndef GE_NODE_H_INCLUDED
#define GE_NODE_H_INCLUDED

class GE_DLLIMPORT eCNode :
    public bCObjectRefBase
{
    public:    virtual eCNode const * GetParent( void ) const;
    public:    virtual eCNode *       GetParent( void );
    public:    virtual eCNode const * GetRoot( void ) const;
    public:    virtual eCNode const * GetChildAt( GEInt ) const;
    public:    virtual eCNode *       GetChildAt( GEInt );
    protected: virtual void           SetContext( eCContextBase * );
    public:    virtual void           OnReadContent( void );
    public:    virtual GEInt          AttachChild( eCNode * );
    public:    virtual GEBool         DetachChildByIndex( GEInt );
    public:    virtual void           RemoveAllChildren( void );
    protected: virtual eCNode *       DoClone( void ) const;
    public:    virtual void           ChildrenAvailable( GEBool );
    public:    virtual GEU16          GetVersion( void ) const;
    public:    virtual GEBool         IsValid( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult       Write( bCOStream & );
    public:    virtual bEResult       Read( bCIStream & );
    public:    virtual void           Destroy( void );
    public:    virtual bEResult       Create( void );
    public:    virtual bEResult       CopyFrom( bCObjectBase const & );
    protected: virtual               ~eCNode( void );

    public:
        eCNode( eCNode const & );
        eCNode( void );

    public:
        eCNode const & operator = ( eCNode const & );

    public:
        eCNode *              Clone( void ) const;
        eCNode *              CloneSubgraph( void ) const;
        void                  CollectChildrenRecursive( bTPtrArray<eCNode *> & ) const;
        GEBool                ContainsParent( eCNode const * ) const;
        GEBool                DetachChild( eCNode * );
        GEInt                 GetChildIndex( eCNode const * ) const;
        GEInt                 GetChildrenCount( void ) const;
        eCContextBase *       GetCurrentContext( void );
        eCContextBase const * GetCurrentContext( void ) const;
        bCPropertyID &        GetID( void );
        bCPropertyID const &  GetID( void ) const;
        GEInt                 GetLevel( void ) const;
        GEBool                HasParent( void ) const;
        GEBool                IsInContext( void ) const;
        GEBool                IsRoot( void ) const;
        GEBool                IsValidChildIndex( GEInt ) const;
        void                  RemoveFromParent( void );

    protected:
        void Invalidate( void );
        void MoveToNode( eCNode * );
        void SetID( bCPropertyID );

};

#endif
