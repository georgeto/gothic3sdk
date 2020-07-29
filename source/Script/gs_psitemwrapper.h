#ifndef GS_PSITEMWRAPPER_H_INCLUDED
#define GS_PSITEMWRAPPER_H_INCLUDED

#define DECLARE_ITEM_PROPERTY( N, T )                             \
    class Property ## N {                                         \
        protected:                                                \
            GELPByte m_pEngineEntity;                             \
        private:                                                  \
            Property ## N ( void );                               \
            Property ## N ( Property ## N const & );              \
            Property ## N & operator = ( Property ## N const & ); \
        public:                                                   \
            operator T ( void ) const;                            \
            /*Property##N & operator =       ( T const & );*/     \
        protected:                                                \
            friend PSItemWrapper;                                 \
            typedef Property ## N PropertySetProperty;            \
    };                                                            \
    GS_DECLARE_PROPERTY_WRAPPER( N, T )

class bCString;

class PSItemWrapper
{
    public:
        template< typename PSP >
        inline PSP & AccessProperty( void );
        template< typename PSP >
        inline PSP const & GetProperty( void ) const;

    protected:
        GELPByte m_pEngineEntity;

    protected:
        typedef PSItemWrapper PropertySet;
    private:
        PSItemWrapper( PSItemWrapper const & );
        PSItemWrapper( void );
    private:
        /* hide copy assignment operator */
        PSItemWrapper & operator = ( PSItemWrapper const & );
    public:
        DECLARE_ITEM_PROPERTY( ReqAttrib1Tag,   bCString )
        DECLARE_ITEM_PROPERTY( ReqAttrib1Value, GEInt )
        DECLARE_ITEM_PROPERTY( ReqAttrib2Tag,   bCString )
        DECLARE_ITEM_PROPERTY( ReqAttrib2Value, GEInt )
        DECLARE_ITEM_PROPERTY( ReqAttrib3Tag,   bCString )
        DECLARE_ITEM_PROPERTY( ReqAttrib3Value, GEInt )
        DECLARE_ITEM_PROPERTY( ReqAttrib4Tag,   bCString )
        DECLARE_ITEM_PROPERTY( ReqAttrib4Value, GEInt )
};

template< typename PSP >
PSP & PSItemWrapper::AccessProperty( void )
{
    return *reinterpret_cast< typename PSP::PropertySetProperty * >( this );
}

template< typename PSP >
PSP const & PSItemWrapper::GetProperty( void ) const
{
    return *reinterpret_cast< typename PSP::PropertySetProperty const * >( this );
}

#endif
