#ifndef GE_AUDIOMODULE_H_INCLUDED
#define GE_AUDIOMODULE_H_INCLUDED

class eCAudioSound;
class eCAudioSystem;
struct eSSetupEngine;

enum eEAudioChannelGroup
{
    eEAudioChannelGroup_Master  = 0,
    eEAudioChannelGroup_Voice   = 1,
    eEAudioChannelGroup_Music   = 2,
    eEAudioChannelGroup_FX      = 3,
    eEAudioChannelGroup_Ambient = 4,
};

class GE_DLLIMPORT eCAudioModule :
    public eCEngineComponentBase
{
    public: virtual         ~eCAudioModule( void );
    public: virtual bEResult Initialize( void );
    public: virtual bEResult PostInitialize( void );
    public: virtual bEResult PreShutdown( void );
    public: virtual bEResult Shutdown( void );
    public: virtual void     Process( void );
    public: virtual void     GetDebugLines( bTObjArray<eSModuleDebugLine> & ) const;

    public:
        static eCAudioModule & GE_STDCALL              GetInstance( void );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCAudioModule( eCAudioModule const & );
        eCAudioModule( void );

    public:
        eCAudioModule const & operator = ( eCAudioModule const & );

    public:
        void                  EnableListenerAutoUpdate( GEBool );
        void                  EnableOcclusionAutoUpdate( GEBool );
        eCAudioChannelGroup * GetChannelGroup( eEAudioChannelGroup ) const;
        GEU8                  GetChannelGroupPriority( eEAudioChannelGroup ) const;
        eCAudioSystem *       GetSystem( void ) const;
        GEBool                IsListenerAutoUpdateEnabled( void ) const;
        GEBool                IsOcclusionAutoUpdateEnabled( void ) const;
        GEBool                PlaySample2D( eEAudioChannelGroup, bCString const &, GEFloat, eCAudioChannel * ) const;
        GEBool                PlaySample3D( eEAudioChannelGroup, bCString const &, bCVector const &, GEFloat, GEFloat, GEFloat, eCAudioChannel * ) const;
        GEBool                PlayStream2D( eEAudioChannelGroup, bCString const &, GEFloat, eCAudioSound *, eCAudioChannel * ) const;
        GEBool                PlayStream3D( eEAudioChannelGroup, bCString const &, bCVector const &, GEFloat, GEFloat, GEFloat, eCAudioSound *, eCAudioChannel * ) const;
        GEBool                UpdateOcclusion( FMOD::Channel *, GEBool ) const;

    protected:
        GEBool CreateChannelGroups( eSSetupEngine const & );
        GEBool CreateStream( bCString const &, GEU32, eCAudioSound * ) const;
        void   DestroyChannelGroups( void );
        void   Invalidate( void );
        void   UpdateListener( void );
        void   UpdateOcclusion( void );
};

#endif
