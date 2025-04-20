#pragma once

#include <SharedBase/propertysystem/enum/ge_enumwrapper.h>
#include <SharedBase/propertysystem/objects/ge_propertyobjecttypebase.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_string.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;
class bCPropertyID;

enum bEPropertyType
{
    bEPropertyType_Normal = 1,
    bEPropertyType_PropertyContainer = 2, // Used for enums
    bEPropertyType_PropertyObject = 3
};

class GE_DLLIMPORT bCPropertyTypeBase
{
    // clang-format off
    public:    virtual GEU32                            GetMemberOffset( ) const                                                                                                    = 0;
    public:    virtual GEU32                            GetDataSize( ) const                                                                                                        = 0;
    public:    virtual bCString const &                 GetObjectTypeClassName( ) const                                                                                             = 0;
    public:    virtual bCString const &                 GetPropertyClassName( ) const                                                                                               = 0;
    public:    virtual bCPropertyObjectTypeBase const * GetObjectType( ) const                                                                                                      = 0;
    public:    virtual GELPVoid                         PropertyInvalidate( bCPropertyObjectBase * a_pPropertyObject )                                                                   = 0;
    public:    virtual GEBool                           HasEnumValues( ) const                                                                                                      = 0;
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
    protected: virtual void                             Destroy( );
    protected: virtual void                             Create( );
    protected: virtual bCPropertyTypeBase *             DoClone( ) const;
    protected: virtual void                             CopyFrom( bCPropertyTypeBase const & );
    public:    virtual                                 ~bCPropertyTypeBase( );
    // clang-format on

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    bCPropertyID const &GetID() const;
    bCString const &GetPropertyCategory() const;
    bCString const &GetPropertyDescription() const;
    bCString const &GetPropertyName() const;
    bEPropertyType GetPropertyType() const;
    GEBool IsReadOnly() const;

  protected:
    bCPropertyTypeBase(bCString const &a_strPropertyName, bCString const &a_strPropertyCategory,
                       bCString const &a_strPropertyDescription, bEPropertyType a_enuPropertyType, GEBool a_bReadOnly);
    bCPropertyTypeBase(bCString const &a_strPropertyName, bCString const &a_strPropertyCategory,
                       bEPropertyType a_enuPropertyType, GEBool a_bReadOnly);
    bCPropertyTypeBase(bCString const &a_strPropertyName, bEPropertyType a_enuPropertyType); // a_bReadOnly = GEFalse

  protected:
    bCPropertyTypeBase const &operator=(bCPropertyTypeBase const &);

  protected:
    bCPropertyTypeBase *Clone() const;
    void CopyTo(bCPropertyTypeBase &) const;
    void Invalidate();

  private:
    bCPropertyTypeBase(bCPropertyTypeBase const &);
    bCPropertyTypeBase();

  private:
    bCString m_strPropertyName;
    bCString m_strPropertyDescription;
    bCString m_strPropertyCategory;
    bEPropertyType m_enuPropertyType;
    GEBool m_bReadOnly;
    GE_PADDING(0x3)
};

GE_ASSERT_SIZEOF(bCPropertyTypeBase, 0x18)
