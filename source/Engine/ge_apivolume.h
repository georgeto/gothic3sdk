#ifndef GE_APIVOLUME_H_INCLUDED
#define GE_APIVOLUME_H_INCLUDED

class GE_DLLIMPORT eCAPIVolume
{
    public: virtual bEResult LockVolumeBox( GEUInt, GEU32, GEInt *, GEInt *, GELPVoid * ) = 0;
    public: virtual bEResult UnlockVolumeBox( GEUInt ) = 0;
    public: virtual bEResult SetVolume( GEU32 ) = 0;
    public: virtual bEResult GenerateVolumeMipMaps( GEUInt, eCGfxShared::eECopyFilter ) = 0;
    public: virtual         ~eCAPIVolume( void );

    public:
        eCAPIVolume( eCAPIVolume const & );

    public:
        eCAPIVolume & operator = ( eCAPIVolume const & );

    public:
        GEU32 AddRef( void );
        GEU32 Release( void );

    protected:
        eCAPIVolume( void );

    private:
        GEU32 m_u32ReferenceCount;
};

#endif
