#ifndef GE_ENGINECOMPONENTBASE_H_INCLUDED
#define GE_ENGINECOMPONENTBASE_H_INCLUDED

class eCMenu;
struct eSModuleDebugLine;

class GE_DLLIMPORT eCEngineComponentBase :
    public eCInputReceiver
{
    public: virtual bCGuid const & GetID( void ) const;
    public: virtual bEResult       Initialize( void );
    public: virtual bEResult       PostInitialize( void );
    public: virtual bEResult       PreShutdown( void );
    public: virtual bEResult       Shutdown( void );
    public: virtual void           OnAppInitialized( void );
    public: virtual bEResult       WorldActivate( void );
    public: virtual bEResult       WorldDeactivate( void );
    public: virtual bEResult       ResetResources( GEBool );
    public: virtual bEResult       RestoreResources( GEBool );
    public: virtual void           OnBeginRenderAlpha( void );
    public: virtual void           OnBeginRenderSolid( void );
    public: virtual void           OnEndRenderAlpha( void );
    public: virtual void           OnEndRenderSolid( void );
    public: virtual void           OnPostRender( void );
    public: virtual void           PostProcess( void );
    public: virtual void           Process( void );
    public: virtual void           CreateMenu( eCMenu * );
    public: virtual void           GetDebugLines( bTObjArray<eSModuleDebugLine> & ) const;
    public: virtual GEU16          GetVersion( void ) const;
    public: virtual void           Destroy( void );
    public: virtual bEResult       Create( void );
    public: virtual bEResult       CopyFrom( bCObjectBase const & );
    public: virtual               ~eCEngineComponentBase( void );

    private:
        GEBool m_bEnabled;
        GEBool __UNK_0011;
        GE_PADDING( 2 )

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCEngineComponentBase( eCEngineComponentBase const & );
        eCEngineComponentBase( void );

    public:
        eCEngineComponentBase const & operator = ( eCEngineComponentBase const & );

    public:
        void   Enable( GEBool );
        GEBool IsEnabled( void ) const;

    protected:
        void Invalidate( void );

};

GE_ASSERT_SIZEOF( eCEngineComponentBase, 0x14 )

#endif
