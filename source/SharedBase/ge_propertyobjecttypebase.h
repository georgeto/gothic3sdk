#ifndef GE_PROPERTYOBJECTTYPEBASE_H_INCLUDED
#define GE_PROPERTYOBJECTTYPEBASE_H_INCLUDED

class GE_DLLIMPORT bCPropertyObjectTypeBase
{
    public:    virtual bCString const &                GetClassName() const     = 0;
    public:    virtual bCString const &                GetBaseClassName() const = 0;
    public:    virtual bCPropertyObjectFactory const * GetObjectFactory() const = 0;
    public:    virtual bCPropertyObjectFactory *       AccessObjectFactory()    = 0;
    public:    virtual GEU16                           Read( bCIStream & );
    public:    virtual void                            Write( bCOStream & );
    protected: virtual void                            Destroy( void );
    protected: virtual bCPropertyObjectTypeBase *      DoClone( void ) const;
    protected: virtual void                            CopyFrom( bCPropertyObjectTypeBase const & );
    public:    virtual                                ~bCPropertyObjectTypeBase( void );

    public:
        bCOStream & operator >> ( bCOStream & );
        bCIStream & operator << ( bCIStream & );

    public:
        bTArrayBase<bCPropertyTypeBase *>::bCConstIterator BeginIterator( void ) const;
        bTArrayBase<bCPropertyTypeBase *>::bCConstIterator EndIterator( void ) const;
        bCPropertyTypeBase const *                         FindPropertyTemplate( bCString const & ) const;
        bCString const &                                   GetDescription( void ) const;
        bCPropertyTypeBase const &                         GetPropertyType( GEInt ) const;
        GEInt                                              GetPropertyTypeCount( void ) const;
        GEBool                                             IsPersistable( void ) const;
        GEBool                                             IsPropertyTypeValid( GEInt ) const;
        GEBool                                             RegisterPropertyTemplate( bCPropertyTypeBase const * );
        void                                               SetDescription( bCString const & );
        GEBool                                             UnregisterPropertyTemplate( bCPropertyTypeBase const * );

    protected:
        bCPropertyObjectTypeBase( GEBool );

    protected:
        bCPropertyObjectTypeBase const & operator = ( bCPropertyObjectTypeBase const & );

    protected:
        bCPropertyObjectTypeBase * Clone( void ) const;
        void                       CopyTo( bCPropertyObjectTypeBase & ) const;
        void                       Invalidate( void );

    private:
        bCPropertyObjectTypeBase( bCPropertyObjectTypeBase const & );
        bCPropertyObjectTypeBase( void );

    private:
        GEInt GetPropertyTemplateIndex( bCPropertyTypeBase const & ) const;

    protected:
        bCString                         m_strDescription;
        bTPtrArray<bCPropertyTypeBase *> m_arrPropertyType;
        GEByte                           m_u8BitfieldPersistable;
};

GE_ASSERT_SIZEOF( bCPropertyObjectTypeBase, 0x18 );

#endif
