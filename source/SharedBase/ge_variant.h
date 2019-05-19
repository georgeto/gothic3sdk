#ifndef GE_VARIANT_H_INCLUDED
#define GE_VARIANT_H_INCLUDED

union bUType;
enum bEType;

class GE_DLLIMPORT bCVariant
{
    public:
         bCVariant( GEI8 const & );
         bCVariant( GEU8 const & );
         bCVariant( GEI16 const & );
         bCVariant( GEU16 const & );
         bCVariant( GEInt const & );
         bCVariant( GEI32 const & );
         bCVariant( GEU32 const & );
         bCVariant( GEFloat const & );
         bCVariant( GEDouble const & );
         bCVariant( GELPChar const & );
         bCVariant( GELPVoid const & );
         bCVariant( bCVariant const & );
         bCVariant( GEI64 const & );
         bCVariant( GEU64 const & );
         bCVariant( GEBool const & );
         bCVariant( void );
        ~bCVariant( void );

    public:
        bCVariant const & operator = ( GEI8 const & );
        bCVariant const & operator = ( GEU8 const & );
        bCVariant const & operator = ( GEI16 const & );
        bCVariant const & operator = ( GEU16 const & );
        bCVariant const & operator = ( GEInt const & );
        bCVariant const & operator = ( GEI32 const & );
        bCVariant const & operator = ( GEU32 const & );
        bCVariant const & operator = ( GEFloat const & );
        bCVariant const & operator = ( GEDouble const & );
        bCVariant const & operator = ( GELPChar const & );
        bCVariant const & operator = ( GELPVoid const & );
        bCVariant const & operator = ( bCVariant const & );
        bCVariant const & operator = ( GEI64 const & );
        bCVariant const & operator = ( GEU64 const & );
        bCVariant const & operator = ( GEBool const & );

    public:
        void             Clear( void );
        void             CopyFrom( bCVariant const & );
        void             CopyTo( bCVariant & ) const;
        GEBool const &   GetBool( void ) const;
        bUType const &   GetData( void ) const;
        void             GetData( GEI8 & ) const;
        void             GetData( GEU8 & ) const;
        void             GetData( GEI16 & ) const;
        void             GetData( GEU16 & ) const;
        void             GetData( GEInt & ) const;
        void             GetData( GEI32 & ) const;
        void             GetData( GEU32 & ) const;
        void             GetData( GEFloat & ) const;
        void             GetData( GEDouble & ) const;
        void             GetData( GELPChar & ) const;
        void             GetData( GELPVoid & ) const;
        void             GetData( bUType & ) const;
        void             GetData( GEI64 & ) const;
        void             GetData( GEU64 & ) const;
        void             GetData( GEBool & ) const;
        GEDouble const & GetDouble( void ) const;
        GEFloat const &  GetFloat( void ) const;
        GEI16 const &    GetI16( void ) const;
        GEI32 const &    GetI32( void ) const;
        GEI64 const &    GetI64( void ) const;
        GEI8 const &     GetI8( void ) const;
        GEInt const &    GetInt( void ) const;
        GELPChar const & GetString( void ) const;
        bEType const &   GetType( void ) const;
        void             GetType( bEType & ) const;
        GEU16 const &    GetU16( void ) const;
        GEU32 const &    GetU32( void ) const;
        GEU64 const &    GetU64( void ) const;
        GEU8 const &     GetU8( void ) const;
        GELPVoid const & GetVoidPointer( void ) const;
        void             SetData( GEI8 );
        void             SetData( GEU8 );
        void             SetData( GEI16 );
        void             SetData( GEU16 );
        void             SetData( GEInt );
        void             SetData( GEI32 );
        void             SetData( GEU32 );
        void             SetData( GEFloat );
        void             SetData( GEDouble );
        void             SetData( GELPCChar );
        void             SetData( GELPCVoid );
        void             SetData( GEI64 );
        void             SetData( GEU64 );
        void             SetData( GEBool );

    protected:
        bUType & AccessData( void );
        bEType & AccessType( void );
        void     Init( void );
        void     SetData( bUType const & );
        void     SetType( bEType const & );

};

#endif
