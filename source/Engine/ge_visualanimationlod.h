#ifndef GE_VISUALANIMATIONLOD_H_INCLUDED
#define GE_VISUALANIMATIONLOD_H_INCLUDED

class eCVisualAnimationFactory;
class eCAnimation_BaseRenderActor;

#pragma warning( push )
#pragma warning( disable : 4266 )// 'GEBool bCObjectBase::Write(bCOStream &) const' : no override available for virtual member function from base 'bCObjectBase'; function is hidden

class GE_DLLIMPORT eCVisualAnimationLoD :
    public bCObjectBase
{
    public: virtual GEU16    GetVersion( void ) const;
    public: virtual GEBool   IsValid( void ) const;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual bEResult CopyFrom( bCObjectBase const & );
    public: virtual         ~eCVisualAnimationLoD( void );

    public:
        eCVisualAnimationLoD( eCVisualAnimationLoD const & );
        eCVisualAnimationLoD( eCVisualAnimationFactory * );

    public:
        eCResourceAnimationActor_PS *    GetActor( void );
        bCString const &                 GetActorFileName( void ) const;
        eCWrapper_emfx2Actor const *     GetActorWrapper( void ) const;
        eCVisualAnimationFactory *       GetAnimationFactory( void );
        eCVisualAnimationFactory const * GetAnimationFactory( void ) const;
        eCAnimation_BaseRenderActor *    GetAnimationRenderHook( void );
        bTValArray<GEInt> const &        GetHardBufferBoneMap( void ) const;
        GEInt                            GetMaterialSwitch( void ) const;
        void                             GetMeshBoundary( bCBox & ) const;
        GEBool                           HasMeshData( void ) const;
        GEBool                           IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;
        GEBool                           ReleaseResources( void );
        GEBool                           RequestResources( void );
        GEBool                           SetActorFileName( bCString const & );
        void                             SetAnimationRenderHook( eCAnimation_BaseRenderActor * );
        void                             SetMaterialSwitch( GEInt );

    protected:
        eCVisualAnimationLoD const & operator = ( eCVisualAnimationLoD const & );

    protected:
        void   Invalidate( void );
        GEBool SetActor( eCResourceDataEntity * );

    public:
        bCString                      m_strActorFileName;
        eCResourceAnimationActor_PS * m_pActor;
        eCAnimation_BaseRenderActor * m_pAnimationRenderHook;
        GEBool                        m_bHasMeshData;
        GE_PADDING( 3 )
        bTValArray<GEInt>             m_HardBufferBoneMap;
        eCVisualAnimationFactory *    m_pVisAnimFactory;
        GEInt                         m_iMaterialSwitch;
        GEU32                         __UNK_0028;
};

GE_ASSERT_SIZEOF( eCVisualAnimationLoD, 0x2C )

#pragma warning( pop )

#endif
