#ifndef GE_AUDIOCHANNELGROUP_H_INCLUDED
#define GE_AUDIOCHANNELGROUP_H_INCLUDED

enum eEAudioResult;

namespace FMOD
{
    struct ChannelGroup;
}

class GE_DLLIMPORT eCAudioChannelGroup :
    public bCObjectRefBase
{
    public: virtual void Destroy( void );
    public: virtual     ~eCAudioChannelGroup( void );

    public:
        eCAudioChannelGroup( eCAudioChannelGroup const & );
        eCAudioChannelGroup( void );

    public:
        eCAudioChannelGroup & operator = ( eCAudioChannelGroup const & );

    public:
        FMOD::ChannelGroup * GetHandle( void ) const;
        eEAudioResult        GetPitch( GEFloat & ) const;
        eEAudioResult        GetVolume( GEFloat & ) const;
        eEAudioResult        OverrideMute( GEBool );
        eEAudioResult        SetPitch( GEFloat );
        eEAudioResult        SetVolume( GEFloat );

    protected:
        void Attach( FMOD::ChannelGroup * );
        void Invalidate( void );
};

#endif
