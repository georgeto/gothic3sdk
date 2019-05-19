#ifndef GE_TEMPLATEENTITY_H_INCLUDED
#define GE_TEMPLATEENTITY_H_INCLUDED

class GE_DLLIMPORT eCTemplateEntity :
    public eCEntity
{
    protected: virtual bEResult           ReadHeader( bCIStream &, GEU16 &, GEBool );
    protected: virtual bEResult           ReadContent( GEU16, bCIStream & );
    protected: virtual bEResult           ReadAll( bCIStream & );
    public:    virtual bEResult           ReadAll( void );
    protected: virtual bEResult           ReadSkipData( bCPOStream & );
    public:    virtual GEU16              GetVersion( void ) const;
    public: using bCObjectBase::Write;
    protected: virtual bEResult           Write( bCOStream & );
    protected: virtual bEResult           Read( bCIStream & );
    public:    virtual void               Destroy( void );
    public:    virtual bEResult           Create( void );
    public:    virtual bEResult           CopyFrom( bCObjectBase const & );
    protected: virtual                   ~eCTemplateEntity( void );
    protected: virtual void               OnReadContent( void );
    public:    virtual eCTemplateEntity * DoClone( void ) const;
    public:    virtual void               SetName( bCString const & );
    public:    virtual GEBool             IsHelperParent( void ) const;
    public:    virtual GEBool             IsResource( void ) const;

        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x00228CD0 - ?IsKilled@eCSpatialEntity@@UBE_NXZ
    public: virtual GEBool IsKilled( void ) const;


        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x0017AC90 - ?GetLinearVelocity@eCRigidBodyBase_PS@@UBE?AVbCVector@@XZ
    public: virtual bCVector GetLinearVelocity( void ) const;

    public: virtual void                     UpdateParentDependencies( void );
    public: virtual void                     UpdateChildDependencies( void );
    public: virtual void                     Kill( void );
    public: virtual eCTemplateEntity const * GetCreator( void ) const;
    public: virtual GEBool                   HasCreator( void ) const;
    public: virtual GEU32                    Modified( void );

        //FIXME: In VTable1 aber nicht in Exports enthalten: 0x0022AC70 - ?OnPostRead@eCDynamicEntity@@MAEXXZ
    protected: virtual void OnPostRead( void );


        //FIXME: In Exports aber nicht in VTable enthalten: 0x00033720 - ?OnCacheIn@eCTemplateEntity@@UAEXXZ - public: virtual void OnCacheIn(void)

        //FIXME: In Exports aber nicht in VTable enthalten: 0x00033720 - ?OnCacheOut@eCTemplateEntity@@UAEXXZ - public: virtual void OnCacheOut(void)

    public:
        static GEU32 GE_STDCALL GetMagicCode1( void );
        static GEU32 GE_STDCALL GetMagicCode2( void );

    public:
        void                     CacheOut( GEBool, GEBool );
        void                     DeleteContent( void );
        void                     DeleteInstances( void );
        void                     DeleteTemplate( void );
        eCEntity *               GetInstanceAt( GEInt );
        eCEntity const *         GetInstanceAt( GEInt ) const;
        GEInt                    GetInstanceCount( void ) const;
        eCTemplateEntity const * GetRefTemplate( void ) const;
        bCPropertyID const &     GetRefTemplateID( void ) const;
        GEBool                   IsContentLoaded( void ) const;
        GEBool                   IsDeleted( void ) const;
        GEBool                   IsReferencedTemplateEntity( void ) const;
        bEResult                 PatchEntity( eCEntity *, GEBool, GEBool ) const;
        GEBool                   PatchInstances( void );
        bEResult                 Save( bCString const & );
        void                     SetAsHelperParent( void );
        void                     SetRefTemplate( eCTemplateEntity const & );

    protected:
        eCTemplateEntity( eCTemplateEntity const & );
        eCTemplateEntity( void );

    protected:
        eCTemplateEntity const & operator = ( eCTemplateEntity const & );

    protected:
        void     AddInstanceEntity( eCEntity * );
        void     Invalidate( void );
        void     RemoveInstanceEntity( eCEntity * );
        bEResult WriteHeader( bCOStream & );

};

#endif
