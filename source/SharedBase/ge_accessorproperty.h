#ifndef GE_ACCESSORPROPERTY_H_INCLUDED
#define GE_ACCESSORPROPERTY_H_INCLUDED

enum eEOperandValue
{
    eEOperandValue_Assign   = 0,
    eEOperandValue_Add      = 1,
    eEOperandValue_Subtract = 2,
    eEOperandValue_Multiply = 3,
    eEOperandValue_Divide   = 4
};

enum bEPropertyTypeDetail
{
    bEPropertyTypeDetail_None                = 0,
    bEPropertyTypeDetail_bCString            = 1,
    bEPropertyTypeDetail_bCUnicodeString     = 2,
    bEPropertyTypeDetail_bCGuid              = 3,
    bEPropertyTypeDetail_bCVector            = 4,
    bEPropertyTypeDetail_bCVector4           = 5,
    bEPropertyTypeDetail_bCMatrix            = 6,
    bEPropertyTypeDetail_bCMatrix3           = 7,
    bEPropertyTypeDetail_bCBox               = 8,
    bEPropertyTypeDetail_bCSphere            = 9,
    bEPropertyTypeDetail_bCQuaternion        = 10,
    bEPropertyTypeDetail_bCObjectBase        = 11,
    bEPropertyTypeDetail_bTPropertyObject    = 12,
    bEPropertyTypeDetail_float               = 13,
    bEPropertyTypeDetail_double              = 14,
    bEPropertyTypeDetail_bool                = 15,
    bEPropertyTypeDetail_char                = 16,
    bEPropertyTypeDetail___int64             = 17,
    bEPropertyTypeDetail_long                = 18,
    bEPropertyTypeDetail_short               = 19,
    bEPropertyTypeDetail_int                 = 20,
    bEPropertyTypeDetail_bTPropertyContainer = 21
};

class GE_DLLIMPORT bCAccessorProperty
{

    protected:
        static bCString ms_strEmptyName;

    public:
         bCAccessorProperty( bCAccessorProperty const & );
         bCAccessorProperty( bCAccessorCreator const & );
         bCAccessorProperty( bCAccessorPropertyObject const & );
         bCAccessorProperty( bCObjectRefBase const * );
         bCAccessorProperty( bCPropertyObjectBase const * );
         bCAccessorProperty( void );
        ~bCAccessorProperty( void );

    public:
        bCAccessorProperty const & operator =  ( bCAccessorProperty const & );
        GEBool                     operator == ( bCAccessorProperty const & ) const;
        GEBool                     operator != ( bCAccessorProperty const & ) const;
        bCAccessorProperty         operator [] ( bCString const & );
        bCAccessorProperty         operator [] ( bCString const & ) const;
        bCAccessorProperty         operator ++ ( GEInt );
        bCAccessorProperty &       operator ++ ( void );

    public:
                                         bCAccessorProperty( bCAccessorCreator const &, bCPropertyID const & );
                                         bCAccessorProperty( bCAccessorCreator const &, bCString const & );
                                         bCAccessorProperty( bCObjectRefBase const *, bCString const & );
        GEBool                           Compare( bCAccessorProperty const & ) const;
        void                             ConvertStringToValue( bCString const &, eEOperandValue );
        bCString                         ConvertValueToString( void );
        void                             CopyFrom( bCAccessorProperty const & );
        void                             CopyTo( bCAccessorProperty & ) const;
        void                             DumpOutputDebugString( void );
        bCAccessorPropertyObject &       GetAccessorPropertyObject( void );
        bCAccessorPropertyObject const & GetAccessorPropertyObject( void ) const;
        bCString const &                 GetClassNameA( void ) const;
        bCString const &                 GetPropertyCategory( void ) const;
        bCString const &                 GetPropertyDescription( void ) const;
        bCString                         GetPropertyHeader( void ) const;
        bCPropertyID const &             GetPropertyID( void ) const;
        bCString const &                 GetPropertyName( void ) const;
        bCPropertyObjectBase *           GetPropertyObject( void );
        bCPropertyObjectBase const *     GetPropertyObject( void ) const;
        bCString const &                 GetPropertyType( void ) const;
        bCPropertyTypeBase *             GetPropertyTypeObject( void );
        bCPropertyTypeBase const *       GetPropertyTypeObject( void ) const;
        bEPropertyTypeDetail             GetPropertyValueDetailType( void ) const;
        void                             Invalidate( void );
        GEBool                           IsEnum( void ) const;
        GEBool                           IsPropertyReadOnly( void ) const;
        GEBool                           IsValid( void ) const;

    protected:
        GEBool Iterate( void );
        GEBool ResolveProperty( bCPropertyID const & );
        GEBool ResolveProperty( bCString const & );

    private:
        GE_PADDING( 12 );
};

GE_ASSERT_SIZEOF( bCAccessorProperty, 12 );

#endif
