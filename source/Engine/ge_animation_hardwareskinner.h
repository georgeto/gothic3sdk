#ifndef GE_ANIMATION_HARDWARESKINNER_H_INCLUDED
#define GE_ANIMATION_HARDWARESKINNER_H_INCLUDED

class GE_DLLIMPORT eCAnimation_HardwareSkinner :
    public bCObjectRefBase
{
    public: virtual GEU16    GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual bEResult CopyFrom( bCObjectBase const & );
    public: virtual         ~eCAnimation_HardwareSkinner( void );

    public:
        eCAnimation_HardwareSkinner( eCAnimation_HardwareSkinner const & );
        eCAnimation_HardwareSkinner( void );

    public:
        void   PrefetchActor( eCVisualAnimation_PS & );
        GEBool RemoveActorResource( eCResourceDataEntity * );
        void   ResetResources( void );

    protected:
        eCAnimation_HardwareSkinner const & operator = ( eCAnimation_HardwareSkinner const & );

    protected:
        eCAnimation_HardRenderActor * InsertOrGetActor( eCVisualAnimationLoD &, eCVisualAnimation_PS & );
        void                          Invalidate( void );
        GEBool                        RemoveActor( eCVisualAnimationLoD & );
        void                          Render( eCVisualAnimation_PS &, GEBool, GEBool );

    public:
        bTPtrMap<eCResourceDataEntity *, eCAnimation_HardRenderActor *> m_mapResourceToActor;
        bTPtrArray<eCVisualAnimationLoD *>                              m_arrVisAnimLoD;
};

GE_ASSERT_SIZEOF( eCAnimation_HardwareSkinner, 0x28 );

#endif
