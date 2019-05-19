#ifndef GE_PROPERTYOBJECTSINGLETON_H_INCLUDED
#define GE_PROPERTYOBJECTSINGLETON_H_INCLUDED


class GE_DLLIMPORT bCPropertyObjectSingleton
{
    protected: virtual void CopyFrom( bCPropertyObjectSingleton const & );
    protected: virtual     ~bCPropertyObjectSingleton( void );

    public:
        class bCPOTypeListItem
        {
            public:
                bCPOTypeListItem & operator =  ( bCPOTypeListItem const & );
                bCOStream &        operator >> ( bCOStream & ) const;
                bCIStream &        operator << ( bCIStream & );

            public:
                bCPOTypeListItem( bCPropertyObjectTypeBase * );

            public:
                bCPropertyObjectTypeBase *       AccessObjectType( void );
                bCString const &                 GetBaseClassName( void ) const;
                bCPropertyObjectTypeBase const * GetObjectType( void ) const;
        };

    public:
        static bCPropertyObjectSingleton & GE_STDCALL GetInstance( void );

    public:
        bTPtrMap<bCString, bCPOTypeListItem *>::bCConstIterator BeginIterator( void ) const;
        void                                                    EnableRegistration( GELPVoid, GEBool );
        bTPtrMap<bCString, bCPOTypeListItem *>::bCConstIterator EndIterator( void ) const;
        bCPropertyObjectTypeBase *                              FindTemplate( bCString const & ) const;
        bCPropertyObjectBase const *                            GetRootObject( bCString const & ) const;
        GEBool                                                  IsRegistrationEnabled( void );
        GEBool                                                  Matches( bCString const &, bCString const & ) const;
        bCPropertyObjectBase *                                  QueryNewObject( bCString const & );
        bCPropertyObjectBase *                                  ReadNewObject( bCIStream & );
        GEBool                                                  ReadObject( bCIStream &, bCPropertyObjectBase & );
        GEBool                                                  RegisterTemplate( bCPropertyObjectTypeBase const * );
        void                                                    WriteObject( bCOStream &, bCPropertyObjectBase * );

    protected:
        bCPropertyObjectSingleton( void );

    protected:
        bCPropertyObjectSingleton const & operator = ( bCPropertyObjectSingleton const & );

    protected:
        void CopyTo( bCPropertyObjectSingleton & ) const;
        void Create( void );
        void Destroy( void );
        void Invalidate( void );

    private:
        bCPropertyObjectSingleton( bCPropertyObjectSingleton const & );

};

#endif
