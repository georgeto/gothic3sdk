#ifndef GE_INFOSCRIPTLINE_PS_H_INCLUDED
#define GE_INFOSCRIPTLINE_PS_H_INCLUDED

class GE_DLLIMPORT gCInfoScriptLine_PS :
    public bCObjectRefBase
{
    public: virtual GEBool   IsEditorRelevant( void ) const;
    public: virtual void     OnPreProcess( void );
    public: virtual void     OnProcess( void );
    public: virtual GEU16    GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual bEResult CopyFrom( bCObjectBase const & );
    public: virtual         ~gCInfoScriptLine_PS( void );
    public: virtual bEResult PostInitializeProperties( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCInfoScriptLine_PS( gCInfoScriptLine_PS const & );
        gCInfoScriptLine_PS( void );

    public:
        gCInfoScriptLine_PS const & operator = ( gCInfoScriptLine_PS const & );

    public:
        bCString &          AccessCommand( void );
        bCString &          AccessEntity1( void );
        bCString &          AccessEntity2( void );
        bCString &          AccessID1( void );
        bCString &          AccessID2( void );
        eCLocString &       AccessText( void );
        bCString const &    GetCommand( void ) const;
        bCString const &    GetEntity1( void ) const;
        bCString const &    GetEntity2( void ) const;
        bCString const &    GetID1( void ) const;
        bCString const &    GetID2( void ) const;
        eCLocString const & GetText( void ) const;
        void                SetCommand( bCString const & );
        void                SetEntity1( bCString const & );
        void                SetEntity2( bCString const & );
        void                SetID1( bCString const & );
        void                SetID2( bCString const & );
        void                SetText( eCLocString const & );

    protected:
        void Invalidate( void );

};

#endif
