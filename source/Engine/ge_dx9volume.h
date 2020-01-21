#ifndef GE_DX9VOLUME_H_INCLUDED
#define GE_DX9VOLUME_H_INCLUDED

class GE_DLLIMPORT eCDX9Volume :
    public eCAPIVolume
{
    public: virtual bEResult LockVolumeBox( GEUInt, GEU32, GEInt *, GEInt *, GELPVoid * );
    public: virtual bEResult UnlockVolumeBox( GEUInt );
    public: virtual bEResult SetVolume( GEU32 );
    public: virtual bEResult GenerateVolumeMipMaps( GEUInt, eCGfxShared::eECopyFilter );
    public: virtual         ~eCDX9Volume( void );

    protected:
        static GEBool ms_bOptimize;

    public:
        eCDX9Volume( eCDX9Volume const & );

    public:
        eCDX9Volume & operator = ( eCDX9Volume const & );

    protected:
        static void ( GE_STDCALL * ms_pRegVolumeLock )( void );
        static void ( GE_STDCALL * ms_pRegVolumeSwitch )( void );
        static void GE_STDCALL sDisableOptimization( void );
        static void GE_STDCALL sEnableOptimization( void );
        static void GE_STDCALL sSetVolumeActCallback( void ( GE_STDCALL* )( void ) );
        static void GE_STDCALL sSetVolumeLockCallback( void ( GE_STDCALL* )( void ) );

    protected:
        eCDX9Volume( eCGfxShared::eSGfxLayersDesc const &, IDirect3DDevice9 *, GEBool & );

    private:
        void  Count( void );
        GEU32 GetSize( void );

};

#endif
