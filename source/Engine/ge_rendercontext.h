#ifndef GE_RENDERCONTEXT_H_INCLUDED
#define GE_RENDERCONTEXT_H_INCLUDED

struct eSEntityLoDInfoDesc;
class eCRenderOp2;

class GE_DLLIMPORT eCRenderContext :
    public bCObjectRefBase
{
    public:    virtual GEBool                        SupportsZPass( void ) const;
    public:    virtual GEBool                        IsDynamicOCEnabled( void ) const;
    public:    virtual GEBool                        SupportsOccluderZPass( void ) const;
    public:    virtual GEBool                        IsPrefetching( void ) const = 0;
    public:    virtual eCResourceShaderMaterial_PS * GetMaterial( GEU32 ) const = 0;
    public:    virtual void                          UpdateDepthSortValue( bCVector4 const & );
    public:    virtual void                          UpdateLoD( struct eSEntityLoDInfoDesc const * ) = 0;
    public:    virtual void                          FillSolidRenderOps( eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> & ) = 0;
    public:    virtual void                          FillAlphaRenderOps( eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> & ) = 0;
    public:    virtual void                          FillRefractedRenderOps( eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> & );
    public:    virtual GEBool                        RenderZPass( GEBool ) = 0;
    public:    virtual GEBool                        Render( eCRenderOp2 const & ) = 0;
    public:    virtual GEBool                        RenderRefrationMask( eCRenderOp2 const & );
    protected: virtual GEBool                        Prefetch( void ) = 0;
    public:    virtual void                          Destroy( void );
    protected: virtual bEResult                      Create( void );
    public:    virtual                              ~eCRenderContext( void );

    public:
        eCRenderContext( eCRenderContext const & );
        eCRenderContext( void );

    public:
        eCRenderContext & operator = ( eCRenderContext const & );

    public:
        bEResult   Create( eCEntity *, eCEntityPropertySet * );
        GEFloat    GetDepthSortValue( void ) const;
        eCEntity * GetEntity( void );

    protected:
        void Invalidate( void );

    public:
        eCEntity *            m_pEntity;
        eCEntityPropertySet * m_pEntityPropertySet;
        GEU32                 m_BitField;
        GEFloat               m_fDepthSortValue;
};

GE_ASSERT_SIZEOF( eCRenderContext, 0x1C )

#endif
