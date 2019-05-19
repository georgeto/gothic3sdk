#ifndef GE_MODULEADMIN_H_INCLUDED
#define GE_MODULEADMIN_H_INCLUDED

class GE_DLLIMPORT eCModuleAdmin :
    public eCInputDispatcher
{
    public: virtual bEResult       ResetResources( GEBool );
    public: virtual bEResult       RestoreResources( GEBool );
    public: virtual GEU16          GetVersion( void ) const;
    public: virtual void           Destroy( void );
    public: virtual bEResult       Create( void );
    public: virtual               ~eCModuleAdmin( void );
    public: virtual bCGuid const & GetID( void ) const;
    public: virtual GEBool         RegisterModule( eCEngineComponentBase & );
    public: virtual GEBool         UnregisterModule( eCEngineComponentBase & );

    public:
        static eCModuleAdmin & GE_STDCALL GetInstance( void );

    public:
        eCModuleAdmin( eCModuleAdmin const & );
        eCModuleAdmin( void );

    public:
        void                    DoBeginRenderAlpha( void );
        void                    DoBeginRenderSolid( void );
        void                    DoEndRenderAlpha( void );
        void                    DoEndRenderSolid( void );
        bEResult                DoInitializeModules( void );
        bEResult                DoOnAppInitializeModules( void );
        bEResult                DoPostInitializeModules( void );
        void                    DoPostRender( void );
        bEResult                DoPreShutdownModules( void );
        bEResult                DoShutdownModules( void );
        bEResult                DoWorldActivate( void );
        bEResult                DoWorldDeactivate( void );
        eCEngineComponentBase * FindModule( bCString const & ) const;
        eCEngineComponentBase * GetModule( GEInt ) const;
        GEInt                   GetModuleCount( void ) const;
        GEBool                  IsEngineComponent( bCPropertyObjectBase const & ) const;
        void                    PostProcess( void );
        void                    Process( void );

    protected:
        eCModuleAdmin const & operator = ( eCModuleAdmin const & );

    protected:
        void Invalidate( void );

};

#endif
