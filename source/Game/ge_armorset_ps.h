#ifndef GE_ARMORSET_PS_H_INCLUDED
#define GE_ARMORSET_PS_H_INCLUDED

class GE_DLLIMPORT gCArmorSet_PS :
    public eCEntityPropertySet
{
    public: virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult          Write( bCOStream & );
    public: virtual bEResult          Read( bCIStream & );
    public: virtual void              Destroy( void );
    public: virtual bEResult          Create( void );
    public: virtual bEResult          CopyFrom( bCObjectBase const & );
    public: virtual                  ~gCArmorSet_PS( void );
    public: virtual bEResult          PostInitializeProperties( void );
    public: virtual eEPropertySetType GetPropertySetType( void ) const;
    public: virtual GEBool            IsEditorRelevant( void ) const;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCArmorSet_PS( gCArmorSet_PS const & );
        gCArmorSet_PS( void );

    public:
        gCArmorSet_PS const & operator = ( gCArmorSet_PS const & );

    public:
        eCTemplateEntityProxy &                          AccessActivateSkill1( void );
        eCTemplateEntityProxy &                          AccessActivateSkill2( void );
        eCTemplateEntityProxy &                          AccessBody( void );
        eCTemplateEntityProxy &                          AccessHand1( void );
        eCTemplateEntityProxy &                          AccessHand2( void );
        eCTemplateEntityProxy &                          AccessHead( void );
        bTPropertyContainer<EAttribModOperation> &       AccessModAttrib1Op( void );
        bCString &                                       AccessModAttrib1Tag( void );
        GEInt &                                          AccessModAttrib1Value( void );
        bTPropertyContainer<EAttribModOperation> &       AccessModAttrib2Op( void );
        bCString &                                       AccessModAttrib2Tag( void );
        GEInt &                                          AccessModAttrib2Value( void );
        bTPropertyContainer<EAttribModOperation> &       AccessModAttrib3Op( void );
        bCString &                                       AccessModAttrib3Tag( void );
        GEInt &                                          AccessModAttrib3Value( void );
        bTPropertyContainer<EAttribModOperation> &       AccessModAttrib4Op( void );
        bCString &                                       AccessModAttrib4Tag( void );
        GEInt &                                          AccessModAttrib4Value( void );
        bTPropertyContainer<EAttribModOperation> &       AccessModAttrib5Op( void );
        bCString &                                       AccessModAttrib5Tag( void );
        GEInt &                                          AccessModAttrib5Value( void );
        bTPropertyContainer<EAttribModOperation> &       AccessModAttrib6Op( void );
        bCString &                                       AccessModAttrib6Tag( void );
        GEInt &                                          AccessModAttrib6Value( void );
        eCTemplateEntityProxy &                          AccessRing1( void );
        eCTemplateEntityProxy &                          AccessRing2( void );
        eCTemplateEntityProxy const &                    GetActivateSkill1( void ) const;
        eCTemplateEntityProxy const &                    GetActivateSkill2( void ) const;
        eCTemplateEntityProxy const &                    GetBody( void ) const;
        eCTemplateEntityProxy const &                    GetHand1( void ) const;
        eCTemplateEntityProxy const &                    GetHand2( void ) const;
        eCTemplateEntityProxy const &                    GetHead( void ) const;
        bTPropertyContainer<EAttribModOperation> const & GetModAttrib1Op( void ) const;
        bCString const &                                 GetModAttrib1Tag( void ) const;
        GEInt const &                                    GetModAttrib1Value( void ) const;
        bTPropertyContainer<EAttribModOperation> const & GetModAttrib2Op( void ) const;
        bCString const &                                 GetModAttrib2Tag( void ) const;
        GEInt const &                                    GetModAttrib2Value( void ) const;
        bTPropertyContainer<EAttribModOperation> const & GetModAttrib3Op( void ) const;
        bCString const &                                 GetModAttrib3Tag( void ) const;
        GEInt const &                                    GetModAttrib3Value( void ) const;
        bTPropertyContainer<EAttribModOperation> const & GetModAttrib4Op( void ) const;
        bCString const &                                 GetModAttrib4Tag( void ) const;
        GEInt const &                                    GetModAttrib4Value( void ) const;
        bTPropertyContainer<EAttribModOperation> const & GetModAttrib5Op( void ) const;
        bCString const &                                 GetModAttrib5Tag( void ) const;
        GEInt const &                                    GetModAttrib5Value( void ) const;
        bTPropertyContainer<EAttribModOperation> const & GetModAttrib6Op( void ) const;
        bCString const &                                 GetModAttrib6Tag( void ) const;
        GEInt const &                                    GetModAttrib6Value( void ) const;
        eCTemplateEntityProxy const &                    GetRing1( void ) const;
        eCTemplateEntityProxy const &                    GetRing2( void ) const;
        void                                             SetActivateSkill1( eCTemplateEntityProxy const & );
        void                                             SetActivateSkill2( eCTemplateEntityProxy const & );
        void                                             SetBody( eCTemplateEntityProxy const & );
        void                                             SetHand1( eCTemplateEntityProxy const & );
        void                                             SetHand2( eCTemplateEntityProxy const & );
        void                                             SetHead( eCTemplateEntityProxy const & );
        void                                             SetModAttrib1Op( bTPropertyContainer<EAttribModOperation> const & );
        void                                             SetModAttrib1Tag( bCString const & );
        void                                             SetModAttrib1Value( GEInt const & );
        void                                             SetModAttrib2Op( bTPropertyContainer<EAttribModOperation> const & );
        void                                             SetModAttrib2Tag( bCString const & );
        void                                             SetModAttrib2Value( GEInt const & );
        void                                             SetModAttrib3Op( bTPropertyContainer<EAttribModOperation> const & );
        void                                             SetModAttrib3Tag( bCString const & );
        void                                             SetModAttrib3Value( GEInt const & );
        void                                             SetModAttrib4Op( bTPropertyContainer<EAttribModOperation> const & );
        void                                             SetModAttrib4Tag( bCString const & );
        void                                             SetModAttrib4Value( GEInt const & );
        void                                             SetModAttrib5Op( bTPropertyContainer<EAttribModOperation> const & );
        void                                             SetModAttrib5Tag( bCString const & );
        void                                             SetModAttrib5Value( GEInt const & );
        void                                             SetModAttrib6Op( bTPropertyContainer<EAttribModOperation> const & );
        void                                             SetModAttrib6Tag( bCString const & );
        void                                             SetModAttrib6Value( GEInt const & );
        void                                             SetRing1( eCTemplateEntityProxy const & );
        void                                             SetRing2( eCTemplateEntityProxy const & );

    protected:
        void Invalidate( void );

};

#endif
