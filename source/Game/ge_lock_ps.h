#ifndef GE_LOCK_PS_H_INCLUDED
#define GE_LOCK_PS_H_INCLUDED

GE_IMPORT_PROPERTY_SET( gCLock_PS, eCEntityPropertySet )
public: virtual GEU16    GetVersion( void ) const;
public: using bCObjectBase::Write;
public: virtual bEResult Write( bCOStream & );
public: virtual bEResult Read( bCIStream & );
public: virtual void     Destroy( void );
public: virtual bEResult Create( void );
public: virtual bEResult CopyFrom( bCObjectBase const & );
public: virtual ~gCLock_PS( void );
public: virtual bEResult                                   PostInitializeProperties( void );
public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
public: virtual bEResult                                   ReadSaveGame( bCIStream & );
public: virtual bEResult                                   WriteSaveGame( bCOStream & );
public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public: virtual void                                       GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );

public:

private:
    static bTPropertyObject<gCLock_PS, eCEntityPropertySet> ms_PropertyObjectInstance_gCLock_PS;

public:
    GE_IMPORT_DECLARE_ENUMPROP( gELockStatus, Status, m_enuStatus )
    GE_IMPORT_DECLARE_PROPERTY( eCTemplateEntityProxy, Key,        m_proxyKey )
    GE_IMPORT_DECLARE_PROPERTY( GEInt,                 Difficulty, m_bDifficulty )
    GE_IMPORT_DECLARE_PROPERTY( GEInt,                 KeyAmount,  m_bKeyAmount )

public:
    static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

public:
    gCLock_PS( gCLock_PS const & );
    gCLock_PS( void );

public:
    gCLock_PS const & operator = ( gCLock_PS const & );

protected:
    void Invalidate( void );

};

GE_ASSERT_SIZEOF( gCLock_PS, 0x30 )

#endif
