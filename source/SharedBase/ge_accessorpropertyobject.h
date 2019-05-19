#ifndef GE_ACCESSORPROPERTYOBJECT_H_INCLUDED
#define GE_ACCESSORPROPERTYOBJECT_H_INCLUDED

class GE_DLLIMPORT bCAccessorPropertyObject
{

    public:
         bCAccessorPropertyObject( bCAccessorPropertyObject const & );
         bCAccessorPropertyObject( bCAccessorCreator const & );
         bCAccessorPropertyObject( bCString const & );
         bCAccessorPropertyObject( bCObjectRefBase * );
         bCAccessorPropertyObject( bCPropertyObjectBase * );
         bCAccessorPropertyObject( bCObjectRefBase const * );
         bCAccessorPropertyObject( bCPropertyObjectBase const * );
         bCAccessorPropertyObject( void );
        ~bCAccessorPropertyObject( void );

    public:
        bCAccessorPropertyObject const & operator =  ( bCAccessorPropertyObject const & );
        bCOStream &                      operator >> ( bCOStream & );
        bCIStream &                      operator << ( bCIStream & );
        GEBool                           operator == ( bCAccessorPropertyObject const & ) const;
        GEBool                           operator != ( bCAccessorPropertyObject const & ) const;
        bCAccessorPropertyObject         operator ++ ( GEInt );
        bCAccessorPropertyObject &       operator ++ ( void );

    public:
        bCAccessorPropertyObject         Clone( void ) const;
        GEBool                           Compare( bCAccessorPropertyObject const & ) const;
        void                             CopyFrom( bCAccessorPropertyObject const & );
        void                             CopyTo( bCAccessorPropertyObject & ) const;
        void                             DumpOutputDebugString( GEBool );
        bCAccessorPropertyObject         GetBaseClass( void ) const;
        bCString const &                 GetClassNameA( void ) const;
        bCObjectRefBase *                GetNativeObject( void );
        bCObjectRefBase const *          GetNativeObject( void ) const;
        bCPropertyObjectBase *           GetPropertyObject( void );
        bCPropertyObjectBase const *     GetPropertyObject( void ) const;
        bCString                         GetPropertyObjectHeader( void ) const;
        bCPropertyObjectTypeBase const * GetPropertyObjectType( void ) const;
        bCPropertyObjectBase const *     GetRootObject( void ) const;
        GEBool                           HasBaseClass( void ) const;
        GEBool                           HasPropertyObject( void ) const;
        GEBool                           IsDerivedFrom( bCAccessorPropertyObject const & ) const;
        GEBool                           IsDerivedFrom( bCPropertyObjectBase const * ) const;
        GEBool                           IsKindOf( bCAccessorPropertyObject const & ) const;
        GEBool                           IsValid( void ) const;
        GEU16                            Read( bCIStream & );
        void                             Write( bCOStream & );

    protected:
        void Invalidate( void );
        void SetInstance( bCObjectRefBase * );
        void SetInstance( bCPropertyObjectBase * );

    private:
        GE_PADDING(8);
};

GE_ASSERT_SIZEOF(bCAccessorPropertyObject, 8);

bCIStream & GE_STDCALL operator >>( bCIStream &, bCAccessorPropertyObject & );
bCOStream & GE_STDCALL operator <<( bCOStream &, bCAccessorPropertyObject & );

#endif
