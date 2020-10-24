#ifndef GE_GFXADMIN_H_INCLUDED
#define GE_GFXADMIN_H_INCLUDED

class eCGfxAssistantAdmin;
class eCGfxContextAdmin;
class eCGfxGaugeAdmin;

class GE_DLLIMPORT eCGfxAdmin :
    public eCEngineComponentBase
{
    public: virtual GEBool   IsValid( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual         ~eCGfxAdmin( void );
    public: virtual bEResult Initialize( void );
    public: virtual bEResult PostInitialize( void );
    public: virtual bEResult Shutdown( void );
    public: virtual void     Process( void );

    protected:
        static eCAPIInstance * ms_pAPIInstance;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static bEResult GE_STDCALL                     sEnumAdapterDesc( GEU32, eCGfxShared::eSGfxAdapterDesc & );
        static bEResult GE_STDCALL                     sGetAdapterCount( GEU32 & );
        static bEResult GE_STDCALL                     sGetAdapterDisplayMode( GEU32, eCGfxShared::eSGfxModeDesc & );

    public:
        eCGfxAdmin( eCGfxAdmin const & );
        eCGfxAdmin( void );

    public:
        eCGfxAdmin const & operator = ( eCGfxAdmin const & );

    public:
        bEResult               Create( eCGfxShared::eEAPIType );
        bEResult               EnumContext( GEU32, eCGfxShared::eSGfxContextDesc & ) const;
        eCGfxShared::eEAPIType GetAPIType( void ) const;
        eCGfxAssistantAdmin &  GetAccessToAssistant( void );
        eCGfxContextAdmin &    GetAccessToContext( void );
        eCGfxGaugeAdmin &      GetAccessToGauge( void );
        eCGfxMixerAdmin &      GetAccessToMixer( void );
        bEResult               GetContextCount( GEU32 & ) const;
        void                   Invalidate( void );

    protected:
        static eCAPIInstance * GE_STDCALL sGetAPIInstance( void );

    protected:
        void InitializeAdmin( eCGfxShared::eEAPIType );

};

#endif
