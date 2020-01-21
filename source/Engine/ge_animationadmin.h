#ifndef GE_ANIMATIONADMIN_H_INCLUDED
#define GE_ANIMATIONADMIN_H_INCLUDED

class GE_DLLIMPORT eCAnimationAdmin :
    public eCEngineComponentBase
{
    public: virtual GEU16          GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult       Write( bCOStream & );
    public: virtual bEResult       Read( bCIStream & );
    public: virtual void           Destroy( void );
    public: virtual bEResult       Create( void );
    public: virtual bEResult       CopyFrom( bCObjectBase const & );
    public: virtual GEU32 const    GetProfileLastTicksFirst( void ) const;
    public: virtual               ~eCAnimationAdmin( void );
    public: virtual bCGuid const & GetID( void ) const;
    public: virtual bEResult       Initialize( void );
    public: virtual bEResult       PreShutdown( void );
    public: virtual bEResult       ResetResources( GEBool );
    public: virtual void           Process( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCAnimationAdmin( eCAnimationAdmin const & );
        eCAnimationAdmin( void );

    public:
        eCAnimationAdmin const & operator = ( eCAnimationAdmin const & );

    public:
        void                          AddMissingAnimation( bCString const & );
        void                          AddProfileTicks( GEU32 );
        void                          ClearMissingAnimations( void );
        GEFloat                       GetAniExtroBlending( bCString & ) const;
        GEFloat                       GetAniIntroBlending( bCString & ) const;
        void                          GetAniVariation( bCString & ) const;
        eCAnimation_HardwareSkinner * GetHardwareSkinner( void );
        GEFloat                       GetPhysicControllerDistance( void ) const;
        GEFloat                       GetStandardAniFadeTime( void );
        GEBool                        IsAnimationMissed( bCString const & ) const;
        void                          Prefetch( eCVisualAnimation_PS & );
        eCResourceDataEntity *        QueryMotionDataEntity( bCString const &, eEResourceCacheBehavior );
        void                          Render( eCVisualAnimation_PS &, GEBool, GEBool );
        void                          SetAniVariationMax( bCString const & );
        void                          SetPhysicControllerDistance( GEFloat );
        void                          SetStandardAniFadeTime( GEFloat );

    protected:
        void Invalidate( void );

};

#endif
