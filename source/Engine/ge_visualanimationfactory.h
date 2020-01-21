#ifndef GE_VISUALANIMATIONFACTORY_H_INCLUDED
#define GE_VISUALANIMATIONFACTORY_H_INCLUDED

struct eSAdditionalBodyPart;

class GE_DLLIMPORT eCVisualAnimationFactory
{
    public:
         eCVisualAnimationFactory( eCVisualAnimationFactory const & );
         eCVisualAnimationFactory( void );
        ~eCVisualAnimationFactory( void );

    public:
        GEBool                                   AddBodyPart( bCString const &, eCVisualAnimation_PS * );
        void                                     CacheInResources( void );
        void                                     CacheOutResources( void );
        bEResult                                 CopyFrom( eCVisualAnimationFactory const & );
        bEResult                                 Create( void );
        GEBool                                   CreateActorInstance( void );
        void                                     Destroy( void );
        GEBool                                   DestroyActorInstance( void );
        bTObjArray<eSAdditionalBodyPart> const & GetAdditionalBodyParts( void ) const;
        eCWrapper_emfx2Actor *                   GetAssembledActor( void );
        eCWrapper_emfx2Actor const *             GetAssembledActor( void ) const;
        bCString const &                         GetFacialActorFileName( void ) const;
        eCVisualAnimationLoD *                   GetFacialAnimationLoD( void );
        bCString const &                         GetMainActorFileName( void ) const;
        void                                     GetMeshBoundary( bCBox & ) const;
        bTValArray<bCMatrix> const &             GetRenderMatrices( void ) const;
        GEU16                                    GetVersion( void ) const;
        eCVisualAnimationLoD *                   GetVisualAnimationLoD( void );
        GEBool                                   IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;
        GEBool                                   IsBodyPartVisible( bCString const & );
        GEBool                                   IsFacialAnimationStarted( void ) const;
        bEResult                                 Read( bCIStream & );
        GEBool                                   RemoveBodyPart( bCString const & );
        GEBool                                   SetBodyPartVisible( bCString const &, GEBool );
        void                                     SetFacialActorFileName( bCString const & );
        void                                     SetMainActorFileName( bCString const & );
        GEBool                                   StartFacialAnimation( void );
        GEBool                                   StopFacialAnimation( void );
        GEBool                                   UpdateRenderMatrices( GEU32, bCMatrix const & );
        bEResult                                 Write( bCOStream & );

    protected:
        eCVisualAnimationFactory const & operator = ( eCVisualAnimationFactory const & );

    protected:
        void Invalidate( void );
        void RemoveNotUsedBones( void );

};

#endif
