#ifndef GE_ITEM_PS_H_INCLUDED
#define GE_ITEM_PS_H_INCLUDED


class GE_DLLIMPORT gCItem_PS :
    public eCEntityPropertySet
{
    public:
        struct SScriptLine
        {
            bCString Command;
            bCString Entity1;
            bCString Entity2;
            bCString ID1;
            bCString ID2;
        };

    public:    virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                                   Write( bCOStream & );
    public:    virtual bEResult                                   Read( bCIStream & );
    public:    virtual void                                       Destroy( void );
    public:    virtual bEResult                                   Create( void );
    public:    virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public:    virtual                                           ~gCItem_PS( void );
    public:    virtual bEResult                                   PostInitializeProperties( void );
    public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
    public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
    public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public:    virtual void                                       GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    protected: virtual void                                       OnTouch( eCEntity *, eCContactIterator & );
    protected: virtual void                                       OnPostRead( void );
    public:    virtual void                                       OnCustomPatch( eCEntityPropertySet const * );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCItem_PS( gCItem_PS const & );
        gCItem_PS( void );

    public:
        gCItem_PS const & operator = ( gCItem_PS const & );

    public:
        eCTemplateEntityProxy &                          AccessActivateSkill1( void );
        eCTemplateEntityProxy &                          AccessActivateSkill2( void );
        GEU32 &                                          AccessAmount( void );
        eCTemplateEntityProxy &                          AccessArmorSet( void );
        bTPropertyContainer<gEItemCategory> &            AccessCategory( void );
        GEBool &                                         AccessDropped( void );
        GEBool &                                         AccessFullBody( void );
        GEI32 &                                          AccessGoldValue( void );
        eCTemplateEntityProxy &                          AccessItemInventory( void );
        eCTemplateEntityProxy &                          AccessItemWorld( void );
        GEBool &                                         AccessMissionItem( void );
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
        GEBool &                                         AccessPermanent( void );
        GEU32 &                                          AccessQuality( void );
        bTPropertyContainer<EAttribReqOperation> &       AccessReqAttrib1Op( void );
        bCString &                                       AccessReqAttrib1Tag( void );
        GEInt &                                          AccessReqAttrib1Value( void );
        bTPropertyContainer<EAttribReqOperation> &       AccessReqAttrib2Op( void );
        bCString &                                       AccessReqAttrib2Tag( void );
        GEInt &                                          AccessReqAttrib2Value( void );
        bTPropertyContainer<EAttribReqOperation> &       AccessReqAttrib3Op( void );
        bCString &                                       AccessReqAttrib3Tag( void );
        GEInt &                                          AccessReqAttrib3Value( void );
        bTPropertyContainer<EAttribReqOperation> &       AccessReqAttrib4Op( void );
        bCString &                                       AccessReqAttrib4Tag( void );
        GEInt &                                          AccessReqAttrib4Value( void );
        eCTemplateEntityProxy &                          AccessRequiredSkill1( void );
        eCTemplateEntityProxy &                          AccessRequiredSkill2( void );
        GEBool &                                         AccessRobe( void );
        eCTemplateEntityProxy &                          AccessSkill( void );
        eCTemplateEntityProxy &                          AccessSpell( void );
        bCString &                                       AccessTexture( void );
        GEInt                                            Compare( gCItem_PS const &, gCInventory_PS const & ) const;
        GEBool                                           ExecuteScript( void ) const;
        eCTemplateEntityProxy const &                    GetActivateSkill1( void ) const;
        eCTemplateEntityProxy const &                    GetActivateSkill2( void ) const;
        GEU32 const &                                    GetAmount( void ) const;
        eCTemplateEntityProxy const &                    GetArmorSet( void ) const;
        bTPropertyContainer<gEItemCategory> const &      GetCategory( void ) const;
        GEBool const &                                   GetDropped( void ) const;
        GEBool const &                                   GetFullBody( void ) const;
        GEI32 const &                                    GetGoldValue( void ) const;
        bCString                                         GetImage( void ) const;
        eCTemplateEntityProxy const &                    GetItemInventory( void ) const;
        eCTemplateEntityProxy const &                    GetItemWorld( void ) const;
        GEBool const &                                   GetMissionItem( void ) const;
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
        GEInt                                            GetModValue( bCString const & ) const;
        GEBool const &                                   GetPermanent( void ) const;
        GEU32 const &                                    GetQuality( void ) const;
        bTPropertyContainer<EAttribReqOperation> const & GetReqAttrib1Op( void ) const;
        bCString const &                                 GetReqAttrib1Tag( void ) const;
        GEInt const &                                    GetReqAttrib1Value( void ) const;
        bTPropertyContainer<EAttribReqOperation> const & GetReqAttrib2Op( void ) const;
        bCString const &                                 GetReqAttrib2Tag( void ) const;
        GEInt const &                                    GetReqAttrib2Value( void ) const;
        bTPropertyContainer<EAttribReqOperation> const & GetReqAttrib3Op( void ) const;
        bCString const &                                 GetReqAttrib3Tag( void ) const;
        GEInt const &                                    GetReqAttrib3Value( void ) const;
        bTPropertyContainer<EAttribReqOperation> const & GetReqAttrib4Op( void ) const;
        bCString const &                                 GetReqAttrib4Tag( void ) const;
        GEInt const &                                    GetReqAttrib4Value( void ) const;
        eCTemplateEntityProxy const &                    GetRequiredSkill1( void ) const;
        eCTemplateEntityProxy const &                    GetRequiredSkill2( void ) const;
        GEBool const &                                   GetRobe( void ) const;
        bTObjArray<SScriptLine> &                        GetScript( void );
        bTObjArray<SScriptLine> const &                  GetScript( void ) const;
        eCTemplateEntityProxy const &                    GetSkill( void ) const;
        gESlot                                           GetSlot( void ) const;
        eCTemplateEntityProxy const &                    GetSpell( void ) const;
        bCString const &                                 GetTexture( void ) const;
        GEBool                                           IsEquipped( void ) const;
        GEBool                                           IsVisible( void ) const;
        void                                             SetActivateSkill1( eCTemplateEntityProxy const & );
        void                                             SetActivateSkill2( eCTemplateEntityProxy const & );
        void                                             SetAmount( GEU32 const & );
        void                                             SetArmorSet( eCTemplateEntityProxy const & );
        void                                             SetCategory( bTPropertyContainer<gEItemCategory> const & );
        void                                             SetDropped( GEBool const & );
        void                                             SetFullBody( GEBool const & );
        void                                             SetGoldValue( GEI32 const & );
        void                                             SetItemInventory( eCTemplateEntityProxy const & );
        void                                             SetItemWorld( eCTemplateEntityProxy const & );
        void                                             SetMissionItem( GEBool const & );
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
        void                                             SetPermanent( GEBool const & );
        void                                             SetQuality( GEU32 const & );
        void                                             SetReqAttrib1Op( bTPropertyContainer<EAttribReqOperation> const & );
        void                                             SetReqAttrib1Tag( bCString const & );
        void                                             SetReqAttrib1Value( GEInt const & );
        void                                             SetReqAttrib2Op( bTPropertyContainer<EAttribReqOperation> const & );
        void                                             SetReqAttrib2Tag( bCString const & );
        void                                             SetReqAttrib2Value( GEInt const & );
        void                                             SetReqAttrib3Op( bTPropertyContainer<EAttribReqOperation> const & );
        void                                             SetReqAttrib3Tag( bCString const & );
        void                                             SetReqAttrib3Value( GEInt const & );
        void                                             SetReqAttrib4Op( bTPropertyContainer<EAttribReqOperation> const & );
        void                                             SetReqAttrib4Tag( bCString const & );
        void                                             SetReqAttrib4Value( GEInt const & );
        void                                             SetRequiredSkill1( eCTemplateEntityProxy const & );
        void                                             SetRequiredSkill2( eCTemplateEntityProxy const & );
        void                                             SetRobe( GEBool const & );
        void                                             SetSkill( eCTemplateEntityProxy const & );
        void                                             SetSlot( gESlot );
        void                                             SetSpell( eCTemplateEntityProxy const & );
        void                                             SetTexture( bCString const & );
        void                                             SetVisible( GEBool );

    protected:
        void Invalidate( void );

};

#endif
