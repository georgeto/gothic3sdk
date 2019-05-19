#ifndef GE_PROPERTYOBJECTBASE_H_INCLUDED
#define GE_PROPERTYOBJECTBASE_H_INCLUDED

class GE_DLLIMPORT bCPropertyObjectBase
{
    public:    virtual bCObjectRefBase *                GetObject() const        = 0;
    public:    virtual bCString const &                 GetClassName() const     = 0;
    public:    virtual bCString const &                 GetBaseClassName() const = 0;
    public:    virtual bCString const &                 GetDescription() const   = 0;
    public:    virtual bCPropertyObjectTypeBase const * GetType() const          = 0;
    public:    virtual GEU16                            Read( bCIStream & );
    public:    virtual void                             Write( bCOStream & );
    protected: virtual GEU16                            ReadData( bCIStream &, GEU16 a_u16Version );
    protected: virtual void                             WriteData( bCOStream & );
    protected: virtual void                             Destroy( void );
    protected: virtual void                             Create( void );
    public:    virtual bool                             SetObject( bCObjectRefBase * ) = 0;
    public:    virtual GEU32                            AddReference( void );
    public:    virtual GEU32                            ReleaseReference( void );
    protected: virtual bCPropertyObjectBase *           DoClone( void ) const;
    public:    virtual void                             CopyFrom( bCPropertyObjectBase const & );
    public:    virtual                                 ~bCPropertyObjectBase( void );

    protected:
        GEU32 m_u32Bitfield; // Bit1: IsRoot; Bit2: IsPersistable; Bit3: IsEmbedded

    public:
        bCPropertyObjectBase( bCString const & );

    public:
        bCPropertyObjectBase const & operator =  ( bCPropertyObjectBase const & );
        bCOStream &                  operator >> ( bCOStream & );
        bCIStream &                  operator << ( bCIStream & );

    public:
        bCPropertyObjectBase *           Clone( void ) const;
        void                             CopyTo( bCPropertyObjectBase & ) const;
        GEU32                            GetReferenceCount( void );
        bCPropertyObjectTypeBase const * GetTemplate( void ) const;
        GEU16                            GetVersion( void ) const;
        GEBool                           IsEmbedded( void ) const;
        GEBool                           IsPersistable( void ) const;
        GEBool                           IsRoot( void ) const; // The "static XXX::ms_PropertyObjectInstance_XXX" objects are the root objects


    protected:
        bCPropertyObjectBase( bCPropertyObjectBase const & );
        bCPropertyObjectBase( void );

    protected:
        void Invalidate( void );
        void ObjectPersistable( GEBool );

};

GE_ASSERT_SIZEOF( bCPropertyObjectBase, 0x08 );

#endif
