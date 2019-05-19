#ifndef GE_PROCESSIBLEELEMENT_H_INCLUDED
#define GE_PROCESSIBLEELEMENT_H_INCLUDED

class GE_DLLIMPORT eCProcessibleElement :
    public bCObjectRefBase
{
    public:
        enum eEState;
        enum eEResult;

    public:    virtual GEBool   IsDataAvailable( void ) const;
    protected: virtual GEFloat  QueryProgress( void ) const;
    public:    virtual bCString GetFileExt( void ) const;
    public:    virtual bCString GetFileType( void ) const;
    public:    virtual bCString GetDataFileExt( void ) const;
    public:    virtual bCString GetDataFileType( void ) const;
    public:    virtual GEU16    GetFileVersion( void ) const;
    public:    virtual bCString GetFileDir( void ) const;
    protected: virtual eEResult DoLoadData( bCIStream & );
    protected: virtual eEResult DoSaveData( bCOStream &, bCString const & );
    protected: virtual eEResult Load( eCArchiveFile & );
    protected: virtual eEResult Load( bCString const & );
    public:    virtual eEResult Save( void );
    protected: virtual void     OnModify( void );
    protected: virtual void     OnActivate( void );
    protected: virtual GEBool   CanGotoState( eEState );
    protected: virtual void     UpdateState( void );
    public:    virtual eEResult Activate( void );
    protected: virtual eEResult CreateFileA( bCString const &, bCString const & );
    protected: virtual eEResult CreateData( void );
    protected: virtual eEResult ReleaseData( void );
    protected: virtual eEResult Create( bCString const &, bCString const & );
    public:    virtual GEBool   IsValid( void ) const;
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );
    public:    virtual         ~eCProcessibleElement( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCProcessibleElement( eCProcessibleElement const & );
        eCProcessibleElement( void );

    public:
        eCProcessibleElement const & operator = ( eCProcessibleElement const & );

    public:
        GEBool &       AccessIsPersistable( void );
        GEBool         CanHaveData( void ) const;
        eEResult       Deactivate( void );
        bCString       GetDataFilePath( void ) const;
        bCString       GetFileBaseName( void ) const;
        bCString       GetFileName( void ) const;
        bCString       GetFilePath( void ) const;
        GEBool const & GetIsPersistable( void ) const;
        eEState        GetState( void ) const;
        GEBool         IsActive( void );
        GEBool         IsModified( void ) const;
        eEState        QueryState( void );
        void           SetFileBaseName( bCString const & );
        void           SetIsPersistable( GEBool const & );
        void           SetModified( void );

    protected:
        void     Invalidate( void );
        eEResult LoadData( void );
        eEResult SaveData( void );

};

#endif
