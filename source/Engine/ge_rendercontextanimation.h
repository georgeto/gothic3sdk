#ifndef GE_RENDERCONTEXTANIMATION_H_INCLUDED
#define GE_RENDERCONTEXTANIMATION_H_INCLUDED

class GE_DLLIMPORT eCRenderContextAnimation :
    public eCRenderContext
{
    public:    virtual void                          Destroy( void );
    protected: virtual bEResult                      Create( void );
    public:    virtual                              ~eCRenderContextAnimation( void );
    public:    virtual GEBool                        IsDynamicOCEnabled( void ) const;
    public:    virtual GEBool                        SupportsOccluderZPass( void ) const;
    public:    virtual GEBool                        IsPrefetching( void ) const;
    public:    virtual eCResourceShaderMaterial_PS * GetMaterial( GEU32 ) const;
    public:    virtual void                          UpdateLoD( eSEntityLoDInfoDesc const * );
    public:    virtual void                          FillSolidRenderOps( eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> & );
    public:    virtual void                          FillAlphaRenderOps( eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> & );
    public:    virtual GEBool                        RenderZPass( GEBool );
    public:    virtual GEBool                        Render( eCRenderOp2 const & );
    protected: virtual GEBool                        Prefetch( void );

    public:
        eCRenderContextAnimation( eCRenderContextAnimation const & );
        eCRenderContextAnimation( void );

    public:
        eCRenderContextAnimation & operator = ( eCRenderContextAnimation const & );

    protected:
        void Invalidate( void );

    public:
        GEBool                m_bIsPrefetching;
        eCVisualAnimation_PS *m_VisualAnimationPS;
};

GE_ASSERT_SIZEOF( eCRenderContextAnimation, 0x24 )

#endif
