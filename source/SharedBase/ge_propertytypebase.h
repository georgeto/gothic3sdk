#ifndef GE_PROPERTYTYPEBASE_H_INCLUDED
#define GE_PROPERTYTYPEBASE_H_INCLUDED

enum bEPropertyType
{
    bEPropertyType_Normal = 1,
    bEPropertyType_PropertyContainer = 2, // Used for enums
    bEPropertyType_PropertyObject = 3
};

class bCEnumWrapper;

class GE_DLLIMPORT bCPropertyTypeBase
{
    public:    virtual GEU32                            GetMemberOffset( void ) const                                                                                                    = 0;
    public:    virtual GEU32                            GetDataSize( void ) const                                                                                                        = 0;
    public:    virtual bCString const &                 GetObjectTypeClassName( void ) const                                                                                             = 0;
    public:    virtual bCString const &                 GetPropertyClassName( void ) const                                                                                               = 0;
    public:    virtual bCPropertyObjectTypeBase const * GetObjectType( void ) const                                                                                                      = 0;
    public:    virtual GELPVoid                         PropertyInvalidate( bCPropertyObjectBase * a_pPropertyObject )                                                                   = 0;
    public:    virtual GEBool                           HasEnumValues( void ) const                                                                                                      = 0;
    public:    virtual GEInt                            GetEnumValueCount() const                                                                                                        = 0;
    public:    virtual bCEnumWrapper const *            GetEnumValue( GEInt a_iIndex ) const                                                                                             = 0;
    public:    virtual void                             PropertySet( bCPropertyObjectBase * a_pPropertyObject, GELPCVoid a_pValue )                                                      = 0;
    public:    virtual GELPCVoid                        PropertyGet( bCPropertyObjectBase const * a_pPropertyObject )                                                                    = 0;
    public:    virtual GELPVoid                         PropertyAccess( bCPropertyObjectBase * a_pPropertyObject )                                                                       = 0;
    public:    virtual GEBool                           PropertyCopy( bCPropertyObjectBase * a_pDestPropertyObject, bCPropertyObjectBase const * a_pSource )                             = 0;
    public:    virtual void                             PropertyWrite( bCOStream &, bCPropertyObjectBase * a_pSource )                                                                   = 0;
    public:    virtual void                             PropertyRead( bCIStream &, bCPropertyObjectBase & a_pPropertyObject )                                                            = 0;
    public:    virtual void                             PropertyDeprecate( bCIStream &, bCPropertyObjectBase & a_pPropertyObject, bCString const &, bCString const &, GEBool a_bNotify ) = 0;
    public:    virtual GEU16                            Read( bCIStream & );
    public:    virtual void                             Write( bCOStream & );
    protected: virtual void                             Destroy( void );
    protected: virtual void                             Create( void );
    protected: virtual bCPropertyTypeBase *             DoClone( void ) const;
    protected: virtual void                             CopyFrom( bCPropertyTypeBase const & );
    public:    virtual                                 ~bCPropertyTypeBase( void );

    public:
        bCOStream & operator >> ( bCOStream & );
        bCIStream & operator << ( bCIStream & );

    public:
        bCPropertyID const & GetID( void ) const;
        bCString const &     GetPropertyCategory( void ) const;
        bCString const &     GetPropertyDescription( void ) const;
        bCString const &     GetPropertyName( void ) const;
        bEPropertyType       GetPropertyType( void ) const;
        GEBool               IsReadOnly( void ) const;

    protected:
        bCPropertyTypeBase const & operator = ( bCPropertyTypeBase const & );

    protected:
                             bCPropertyTypeBase( bCString const & a_strPropertyName, bCString const & a_strPropertyCategory, bCString const & a_strPropertyDescription, bEPropertyType a_enuPropertyType, GEBool a_bReadOnly );
                             bCPropertyTypeBase( bCString const & a_strPropertyName, bCString const & a_strPropertyCategory, bEPropertyType a_enuPropertyType, GEBool a_bReadOnly );
                             bCPropertyTypeBase( bCString const & a_strPropertyName, bEPropertyType a_enuPropertyType ); // a_bReadOnly = GEFalse
        bCPropertyTypeBase * Clone( void ) const;
        void                 CopyTo( bCPropertyTypeBase & ) const;
        void                 Invalidate( void );

    private:
        bCString       m_strPropertyName;
        bCString       m_strPropertyDescription;
        bCString       m_strPropertyCategory;
        bEPropertyType m_enuPropertyType;
        GEBool         m_bReadOnly;
        GE_PADDING( 3 )

    private:
        bCPropertyTypeBase( bCPropertyTypeBase const & );
        bCPropertyTypeBase( void );

};

GE_ASSERT_SIZEOF( bCPropertyTypeBase, 0x18 )

#endif
