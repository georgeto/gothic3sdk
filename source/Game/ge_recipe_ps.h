#ifndef GE_RECIPE_PS_H_INCLUDED
#define GE_RECIPE_PS_H_INCLUDED

class GE_DLLIMPORT gCRecipe_PS :
    public eCEntityPropertySet
{
    public: virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult          Write( bCOStream & );
    public: virtual bEResult          Read( bCIStream & );
    public: virtual void              Destroy( void );
    public: virtual bEResult          Create( void );
    public: virtual bEResult          CopyFrom( bCObjectBase const & );
    public: virtual                  ~gCRecipe_PS( void );
    public: virtual bEResult          PostInitializeProperties( void );
    public: virtual eEPropertySetType GetPropertySetType( void ) const;
    public: virtual GEBool            IsEditorRelevant( void ) const;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCRecipe_PS( gCRecipe_PS const & );
        gCRecipe_PS( void );

    public:
        gCRecipe_PS const & operator = ( gCRecipe_PS const & );

    public:
        bTPropertyContainer<gESkillCategory> &       AccessCraft( void );
        GEU32 &                                      AccessIngredient1Amount( void );
        eCTemplateEntityProxy &                      AccessIngredient1Item( void );
        GEU32 &                                      AccessIngredient2Amount( void );
        eCTemplateEntityProxy &                      AccessIngredient2Item( void );
        GEU32 &                                      AccessIngredient3Amount( void );
        eCTemplateEntityProxy &                      AccessIngredient3Item( void );
        GEU32 &                                      AccessIngredient4Amount( void );
        eCTemplateEntityProxy &                      AccessIngredient4Item( void );
        bCString &                                   AccessReqAttrib1Tag( void );
        GEU32 &                                      AccessReqAttrib1Value( void );
        eCTemplateEntityProxy &                      AccessReqSkill1( void );
        GEU32 &                                      AccessResultAmount( void );
        eCTemplateEntityProxy &                      AccessResultItem( void );
        GEU32 &                                      AccessResultQuality( void );
        GEInt                                        CompareTo( gCRecipe_PS const & ) const;
        bTPropertyContainer<gESkillCategory> const & GetCraft( void ) const;
        GEU32 const &                                GetIngredient1Amount( void ) const;
        eCTemplateEntityProxy const &                GetIngredient1Item( void ) const;
        GEU32 const &                                GetIngredient2Amount( void ) const;
        eCTemplateEntityProxy const &                GetIngredient2Item( void ) const;
        GEU32 const &                                GetIngredient3Amount( void ) const;
        eCTemplateEntityProxy const &                GetIngredient3Item( void ) const;
        GEU32 const &                                GetIngredient4Amount( void ) const;
        eCTemplateEntityProxy const &                GetIngredient4Item( void ) const;
        bCString const &                             GetReqAttrib1Tag( void ) const;
        GEU32 const &                                GetReqAttrib1Value( void ) const;
        eCTemplateEntityProxy const &                GetReqSkill1( void ) const;
        GEU32 const &                                GetResultAmount( void ) const;
        eCTemplateEntityProxy const &                GetResultItem( void ) const;
        GEU32 const &                                GetResultQuality( void ) const;
        void                                         SetCraft( bTPropertyContainer<gESkillCategory> const & );
        void                                         SetIngredient1Amount( GEU32 const & );
        void                                         SetIngredient1Item( eCTemplateEntityProxy const & );
        void                                         SetIngredient2Amount( GEU32 const & );
        void                                         SetIngredient2Item( eCTemplateEntityProxy const & );
        void                                         SetIngredient3Amount( GEU32 const & );
        void                                         SetIngredient3Item( eCTemplateEntityProxy const & );
        void                                         SetIngredient4Amount( GEU32 const & );
        void                                         SetIngredient4Item( eCTemplateEntityProxy const & );
        void                                         SetReqAttrib1Tag( bCString const & );
        void                                         SetReqAttrib1Value( GEU32 const & );
        void                                         SetReqSkill1( eCTemplateEntityProxy const & );
        void                                         SetResultAmount( GEU32 const & );
        void                                         SetResultItem( eCTemplateEntityProxy const & );
        void                                         SetResultQuality( GEU32 const & );

    protected:
        void Invalidate( void );

};

#endif
