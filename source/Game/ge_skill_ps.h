#ifndef GE_SKILL_PS_H_INCLUDED
#define GE_SKILL_PS_H_INCLUDED

class GE_DLLIMPORT gCSkill_PS :
    public eCEntityPropertySet
{
    public: virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult          Write( bCOStream & );
    public: virtual bEResult          Read( bCIStream & );
    public: virtual void              Destroy( void );
    public: virtual bEResult          Create( void );
    public: virtual bEResult          CopyFrom( bCObjectBase const & );
    public: virtual                  ~gCSkill_PS( void );
    public: virtual bEResult          PostInitializeProperties( void );
    public: virtual eEPropertySetType GetPropertySetType( void ) const;
    public: virtual GEBool            IsEditorRelevant( void ) const;
    public: virtual GEBool            SupportsRenderDebugOutput( void ) const;
    public: virtual void              GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    public: virtual void              GetOnScreenDebugLines( GEU32, bTObjArray<eSPropertySetDebugLine> & ) const;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCSkill_PS( gCSkill_PS const & );
        gCSkill_PS( void );

    public:
        gCSkill_PS const & operator = ( gCSkill_PS const & );

    public:
        bTPropertyContainer<gESkillCategory> &       AccessCategory( void );
        GEInt &                                      AccessLearnPoints( void );
        bCString &                                   AccessReqAttrib1Tag( void );
        GEInt &                                      AccessReqAttrib1Value( void );
        bCString &                                   AccessReqAttrib2Tag( void );
        GEInt &                                      AccessReqAttrib2Value( void );
        bCString &                                   AccessReqAttrib3Tag( void );
        GEInt &                                      AccessReqAttrib3Value( void );
        bCString &                                   AccessReqAttrib4Tag( void );
        GEInt &                                      AccessReqAttrib4Value( void );
        eCTemplateEntityProxy &                      AccessReqSkill1( void );
        GEInt &                                      AccessSortOrder( void );
        bCString &                                   AccessTag( void );
        bTPropertyContainer<gESkillCategory> const & GetCategory( void ) const;
        GEInt const &                                GetLearnPoints( void ) const;
        bCString const &                             GetReqAttrib1Tag( void ) const;
        GEInt const &                                GetReqAttrib1Value( void ) const;
        bCString const &                             GetReqAttrib2Tag( void ) const;
        GEInt const &                                GetReqAttrib2Value( void ) const;
        bCString const &                             GetReqAttrib3Tag( void ) const;
        GEInt const &                                GetReqAttrib3Value( void ) const;
        bCString const &                             GetReqAttrib4Tag( void ) const;
        GEInt const &                                GetReqAttrib4Value( void ) const;
        eCTemplateEntityProxy const &                GetReqSkill1( void ) const;
        GEInt const &                                GetSortOrder( void ) const;
        bCString const &                             GetTag( void ) const;
        void                                         SetCategory( bTPropertyContainer<gESkillCategory> const & );
        void                                         SetLearnPoints( int const & );
        void                                         SetReqAttrib1Tag( bCString const & );
        void                                         SetReqAttrib1Value( GEInt const & );
        void                                         SetReqAttrib2Tag( bCString const & );
        void                                         SetReqAttrib2Value( GEInt const & );
        void                                         SetReqAttrib3Tag( bCString const & );
        void                                         SetReqAttrib3Value( GEInt const & );
        void                                         SetReqAttrib4Tag( bCString const & );
        void                                         SetReqAttrib4Value( GEInt const & );
        void                                         SetReqSkill1( eCTemplateEntityProxy const & );
        void                                         SetSortOrder( GEInt const & );
        void                                         SetTag( bCString const & );

    protected:
        void Invalidate( void );

};

#endif
