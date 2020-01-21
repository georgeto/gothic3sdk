#ifndef GE_ANIMATION_HARDRENDERACTOR_H_INCLUDED
#define GE_ANIMATION_HARDRENDERACTOR_H_INCLUDED

class eCGfxVisual;
class eCGfxVertexDecl;
struct eSHardPrimitive;
struct eSShaderMaterialIllumination;
class eCTerrainShadowMap;

class GE_DLLIMPORT eCAnimation_HardRenderActor :
    public eCAnimation_BaseRenderActor
{
    public:    virtual void     Render( eCVisualAnimation_PS *, eCVisualAnimationLoD &, GEBool, GEBool );
    public:    virtual bEResult Create( eCResourceAnimationActor_PS * );
    protected: virtual bEResult Create( void );
    public:    virtual void     Destroy( void );
    public:    virtual GEBool   RemoveFromList( eCVisualAnimationLoD & );
    public:    virtual void     Prefetch( GEInt );
    public:    virtual         ~eCAnimation_HardRenderActor( void );

    protected:
        static GEFloat           ms_fMaxBoneLODDistance;
        static eCGfxVertexDecl * ms_pGfXVertexDeclaration;

    public:
        eCAnimation_HardRenderActor( eCAnimation_HardRenderActor const & );
        eCAnimation_HardRenderActor( void );

    public:
        eCAnimation_HardRenderActor & operator = ( eCAnimation_HardRenderActor const & );

    public:
        bTValArray<GEInt> const & GetBoneIDMap( void ) const;

    protected:
        GEBool CreateLoD( GEU16, GEU16 &, GEU16 & );
        void   Invalidate( void );
        void   RenderPrimitive( eSHardPrimitive const &, GEInt, eSShaderMaterialIllumination *, eCTerrainShadowMap *, GEInt );

    public:
        eCResourceAnimationActor_PS * m_pResourceAnimationActor;
        bTPtrArray<eCGfxVertexData *> m_arrVertexData;
        bTPtrArray<eCGfxIndexData *>  m_arrIndexData;
        GE_PADDING( 0x10 )
        bTValArray<GEInt>             m_BoneIDMap;
        GE_PADDING( 0x0C )
        eCGfxVisual *                 m_pGfxVisual;


};

GE_ASSERT_SIZEOF( eCAnimation_HardRenderActor, 0x50 );

#endif
