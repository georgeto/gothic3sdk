#ifndef GE_WRAPPER_EMFX2ACTOR_H_INCLUDED
#define GE_WRAPPER_EMFX2ACTOR_H_INCLUDED

namespace MCore
{
    template<typename T>
    struct Array
    {
        GEInt mLength;
        GEInt mMaxLength;
        T *mData;
    };
}

namespace EMotionFX
{
    class Node
    {
        public:
            GE_PADDING( 0x178 )
            GEInt mBoneRelatedID;
            GE_PADDING( 0xC )
            GEInt mID;
            GE_PADDING( 0x4 )
    };
    GE_ASSERT_SIZEOF( Node, 0x190 )

    class Actor : public Node
    {
        public:
            GE_PADDING( 0x24 )
            MCore::Array<Node> mNodes;
            GE_PADDING( 0x64 )
    };
    GE_ASSERT_SIZEOF( Actor, 0x224 )

    class eCNovodexPhysicsController;
};

struct eSHardBuffer;
struct eSSoftPrimitive;

class eCWrapper_emfx2Motion
{
    public:
        enum eEMotionBlendMode;
        enum eEMotionPlayMode;
        struct eSMotionDesc;
};
class eCResourceShaderMaterial_PS;

class eCGfxVertexData;
class eCGfxIndexData;

class GE_DLLIMPORT eCWrapper_emfx2Actor :
    public bCObjectRefBase
{
    public:    virtual GEU16    GetVersion( void ) const;
    public:    virtual GEBool   IsValid( void ) const;
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );
    public:    virtual bEResult CopyFrom( bCObjectBase const & );
    protected: virtual         ~eCWrapper_emfx2Actor( void );

    public:
        enum eEMotionType;

    public:
        static void GE_STDCALL CleanUpHierachy( EMotionFX::Actor * );
        static void GE_STDCALL CleanUpHierachy( EMotionFX::Actor *, EMotionFX::Node *, bTValArray<GEInt> & );

    public:
        eCWrapper_emfx2Actor( eCWrapper_emfx2Actor const & );
        eCWrapper_emfx2Actor( void );

    public:
                                                 eCWrapper_emfx2Actor( EMotionFX::Actor const * );
        GEU16                                    AddLoDLevel( eCWrapper_emfx2Actor * );
        void                                     CalculateAmbientOcclusion( bTObjArray<bTValArray<GEU32> > &, GEFloat );
        void                                     CalculateDynamicMeshTotals( GEU16, GEInt &, GEInt & );
        void                                     CalculateStaticMeshTotals( GEU16, GEInt &, GEInt & );
        eCWrapper_emfx2Actor *                   CreateInstance( void ) const;
        GEBool                                   FillHardBuffersAndPrimitves( GEU16, bTObjArray<eSHardBuffer> &, eCGfxVertexData * &, eCGfxIndexData * & );
        void                                     FillSoftBuffers( GEU16, eCGfxVertexData * &, eCGfxVertexData * &, eCGfxIndexData * &, eCGfxIndexData * & );
        void                                     FillSoftPrimitiveArray( GEU16, bTValArray<eSSoftPrimitive> &, bTValArray<eSSoftPrimitive> & );
        bCString const &                         GetActorName( void ) const;
        bCString                                 GetActorNodeName( void ) const;
        eCWrapper_emfx2Motion::eEMotionBlendMode GetBlendMode( eEMotionType ) const;
        bCBox                                    GetBoundary( void );
        void                                     GetBoundary( bCBox & );
        GEU16                                    GetCurrentLoDLevel( void ) const;
        void                                     GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
        GEFloat                                  GetExtroBlending( eEMotionType ) const;
        EMotionFX::Actor *                       GetInstance( void );
        EMotionFX::Actor const *                 GetInstance( void ) const;
        GEFloat                                  GetIntroBlending( eEMotionType ) const;
        GEU16                                    GetLoDCount( void ) const;
        eCResourceShaderMaterial_PS *            GetMaterialByID( GEU32 ) const;
        GEDouble                                 GetMaxTime( eEMotionType ) const;
        bCString                                 GetName( EMotionFX::Node * );
        EMotionFX::Node *                        GetNodeByName( bCString const & );
        GEFloat                                  GetPlaySpeed( eEMotionType ) const;
        GEDouble                                 GetPlayTime( eEMotionType ) const;
        eCWrapper_emfx2Motion::eEMotionPlayMode  GetPrimary1PlayMode( void ) const;
        GEFloat                                  GetTargetWeight( eEMotionType ) const;
        bCMatrix                                 GetWorldMatrix( EMotionFX::Node * );
        GEBool                                   HasMesh( void ) const;
        GEBool                                   HasMotionInstance( eEMotionType ) const;
        bEResult                                 ImportEMFX2Actor( bCString const & );
        GEBool                                   IntersectsRay( eSRayIntersectionDesc &, eCCollisionDesc * *, GEU16 ) const;
        GEBool                                   IsActorPlaying( eEMotionType ) const;
        GEBool                                   IsInstance( void ) const;
        GEBool                                   IsMotionRunning( eEMotionType ) const;
        void                                     PauseMotion( GEBool, eEMotionType );
        void                                     PlayMotion( eEMotionType, eCWrapper_emfx2Motion &, eCWrapper_emfx2Motion::eSMotionDesc * );
        void                                     Process( bCMatrix const &, GEBool, GEBool, GEFloat );
        void                                     ProcessGeometry( void );
        bEResult                                 SaveActor( eCArchiveFile &, eCArchiveFile & );
        void                                     SetActorName( bCString const & );
        void                                     SetBlendMode( eEMotionType, eCWrapper_emfx2Motion::eEMotionBlendMode );
        void                                     SetCurrentLoDLevel( GEU16 );
        void                                     SetIntroExtroBlending( eEMotionType, bCString & );
        void                                     SetIntroExtroBlending( eEMotionType, GEFloat, GEFloat );
        void                                     SetPlaySpeed( eEMotionType, GEFloat );
        void                                     SetPlayTime( eEMotionType, GEFloat );
        void                                     SetTargetWeight( eEMotionType, GEFloat );
        void                                     StopAtLoopEnd( eEMotionType );
        void                                     StopMotion( eEMotionType, GEFloat );
        void                                     SwitchFadeOut( eEMotionType, GEBool, GEFloat );
        void                                     UpdateDynamicSoftBuffer( GEU16, eCGfxVertexData * );

    protected:
        eCWrapper_emfx2Actor const & operator = ( eCWrapper_emfx2Actor const & );

    protected:
        void     CreateAndSaveMaterialTechnique( eCArchiveFile & );
        void     Invalidate( void );
        bCString ResolveFileName( bCString ) const;
        void     RunStopPrevention( GEFloat );
        void     SetActor( EMotionFX::Actor * );

    public:
        EMotionFX::Actor * m_pInstance;
        GE_PADDING( 32 )
        bCBox              m_Boundary;
        GE_PADDING( 32 )
        bCString           m_strActorName;
        GE_PADDING( 4 )
        GEFloat            m_fExtroBlending;
        GE_PADDING( 12 )
};

GE_ASSERT_SIZEOF( eCWrapper_emfx2Actor, 0x80 )

#endif
