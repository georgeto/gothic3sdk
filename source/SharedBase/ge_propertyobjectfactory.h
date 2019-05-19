#ifndef GE_PROPERTYOBJECTFACTORY_H_INCLUDED
#define GE_PROPERTYOBJECTFACTORY_H_INCLUDED

class GE_DLLIMPORT bCPropertyObjectFactory
{
    protected: virtual void                      Destroy( void );
    protected: virtual bCPropertyObjectFactory * DoClone( void ) const;
    protected: virtual void                      CopyFrom( bCPropertyObjectFactory const & );
    public:    virtual                          ~bCPropertyObjectFactory( void );

    public:
        static GEU16 GE_STDCALL ReadSkip( bCIStream & );

    public:
        bCPropertyObjectFactory( bCString const & );

    public:
        bCOStream & operator >> ( bCOStream & );
        bCIStream & operator << ( bCIStream & );

    public:
        bTArrayBase<bCPropertyObjectBase *>::bCConstIterator BeginIterator( void ) const;
        bTArrayBase<bCPropertyObjectBase *>::bCConstIterator EndIterator( void ) const;
        GEInt                                                GetObjectCount( void ) const;
        GEInt                                                GetPropertyObjectIndex( bCPropertyObjectBase const & ) const;
        bCPropertyObjectBase const *                         GetRootObject( void ) const;
        GEU16                                                Read( bCIStream & );
        GEBool                                               RegisterPropertyObject( bCPropertyObjectBase const * );
        void                                                 SearchPropertyObjects( bTAutoPtrArray<bCPropertyObjectBase *> &, bCString const & );
        GEBool                                               UnregisterPropertyObject( bCPropertyObjectBase const * );
        void                                                 Write( bCOStream & );

    protected:
        static GEU16 GE_STDCALL ReadSkipObject( bCIStream & );

    protected:
        bCPropertyObjectFactory( bCPropertyObjectFactory const & );
        bCPropertyObjectFactory( void );

    protected:
        bCPropertyObjectFactory const & operator = ( bCPropertyObjectFactory const & );

    protected:
        bCPropertyObjectFactory * Clone( void ) const;
        bCPropertyObjectBase *    CloneObjectInstance( void ) const;
        void                      CopyTo( bCPropertyObjectFactory & ) const;
        void                      Invalidate( void );
        bCPropertyObjectBase *    ReadNewObject( bCIStream & );
        GEBool                    ReadObject( bCIStream &, bCPropertyObjectBase & );
        void                      WriteObject( bCOStream &, bCPropertyObjectBase * ) const;

    private:
        bTPtrArray<bCPropertyObjectBase *> m_arrPropertyObject;
        GEU16                              m_u16Unknown;
        GE_PADDING( 2 );
        bCString m_strFactoryName;
};

GE_ASSERT_SIZEOF( bCPropertyObjectFactory, 0x18 );

#endif
