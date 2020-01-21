#ifndef GE_ANIMATION_BASERENDERACTOR_H_INCLUDED
#define GE_ANIMATION_BASERENDERACTOR_H_INCLUDED

class GE_DLLIMPORT eCAnimation_BaseRenderActor
{
    public:    virtual bEResult Create( eCResourceAnimationActor_PS * ) = 0;
    protected: virtual bEResult Create( void );
    public:    virtual void     Destroy( void );
    public:    virtual GEBool   RemoveFromList( eCVisualAnimationLoD & ) = 0;
    public:    virtual void     Prefetch( GEInt ) = 0;
    public:    virtual         ~eCAnimation_BaseRenderActor( void );

    public:
        eCAnimation_BaseRenderActor( eCAnimation_BaseRenderActor const & );
        eCAnimation_BaseRenderActor( void );

    public:
        eCAnimation_BaseRenderActor & operator = ( eCAnimation_BaseRenderActor const & );

    public:
        eCWrapper_emfx2Actor * GetActorWrapper( void );

    protected:
        void Invalidate( void );
        void SetActorWrapper( eCWrapper_emfx2Actor * );

    private:
        eCWrapper_emfx2Actor * m_pActorWrapper;
};

GE_ASSERT_SIZEOF( eCAnimation_BaseRenderActor, 0x08 );

#endif
