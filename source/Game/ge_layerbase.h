#ifndef GE_LAYERBASE_H_INCLUDED
#define GE_LAYERBASE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4263 )// member function does not override any base class virtual member function
#pragma warning( disable : 4264 )// no override available for virtual member function from base 'eCProcessibleElement'; function is hidden

class GE_DLLIMPORT gCLayerBase :
    public eCProcessibleElement
{
    public:    virtual bCString                       GetLayerCategory( void ) const;
    protected: virtual bCPropertyObjectBase *         OnCreateContext( void );
    public:    virtual GEBool                         IsValid( void ) const;
    public:    virtual void                           Destroy( void );
    public:    virtual                               ~gCLayerBase( void );
    public:    virtual bEResult                       PostInitializeProperties( void );
    public:    virtual GEBool                         IsDataAvailable( void ) const;
    protected: virtual GEBool                         CanGotoState( eCProcessibleElement::eEState );
    protected: virtual eCProcessibleElement::eEResult CreateData( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCLayerBase( gCLayerBase const & );
        gCLayerBase( void );

    public:
        gCLayerBase const & operator = ( gCLayerBase const & );

    public:
      //bTPOSmartPtr<gCSector> &       AccessSectorPtr( void );
        void                           Enable( GEBool );
        eCContextBase &                GetContext( void );
        eCContextBase const &          GetContext( void ) const;
        gCSector &                     GetSector( void );
        gCSector const &               GetSector( void ) const;
      //bTPOSmartPtr<gCSector> const & GetSectorPtr( void ) const;
        GEBool                         HasSector( void ) const;
        GEBool                         IsEnabled( void ) const;
        GEBool                         IsLocked( void ) const;
        GEU16                          Lock( void );
        GEFloat                        QueryProgress( void );
      //void                           SetSectorPtr( bTPOSmartPtr<gCSector> const & );
        GEU16                          Unlock( void );

    protected:
        void                           Invalidate( void );
        eCProcessibleElement::eEResult SetContext( bCPropertyObjectBase * );
        eCProcessibleElement::eEResult SetContext( eCContextBase * );
        void                           SetSector( bCPropertyObjectBase const * );
        void                           SetSector( gCSector const * );

};

#pragma warning( pop )

#endif
