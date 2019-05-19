#ifndef GE_ATTRIBUTE_H_INCLUDED
#define GE_ATTRIBUTE_H_INCLUDED

class GE_DLLIMPORT gCAttribute :
    public bCObjectRefBase
{
    public:    virtual GEInt         GetValue( void ) const; // BaseValue + Modifier
    public:    virtual GEInt         GetMaximum( void ) const; // Value
    public:    virtual void          SetValue( GEInt );
    public:    virtual void          SetMaximum( GEInt );
    public:    virtual GEBool        ApplyPerm( EAttribModOperation, GEInt );
    public:    virtual GEBool        ApplyTemp( EAttribModOperation, GEInt );
    public:    virtual GEBool        UnapplyTemp( EAttribModOperation, GEInt );
    protected: virtual void          Cap( void );
    public:    virtual gCAttribute * Clone( void ) const;
    protected: virtual void          ApplyDefaults( void );
    public:    virtual void          Destroy( void );
    public:    virtual              ~gCAttribute( void );
    public:    virtual bEResult      PostInitializeProperties( void );
    public:    virtual GEBool        OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCAttribute( gCAttribute const & );
        gCAttribute( void );

    public:
        gCAttribute const & operator = ( gCAttribute const & );

    public:
        GEInt &          AccessBaseValue( void );
        GEInt &          AccessModifier( void );
        bCString &       AccessTag( void );
        GEInt const &    GetBaseValue( void ) const; // Wert ohne Boni
        eCLocString      GetDescription( void ) const;
        eCLocString      GetLongName( void ) const;
        GEInt const &    GetModifier( void ) const; // Aktive Boni
        eCLocString      GetShortName( void ) const;
        bCString const & GetTag( void ) const;
        void             SetBaseValue( GEInt const & );
        void             SetModifier( GEInt const & );
        void             SetTag( bCString const & );

    protected:
        void Invalidate( void );

};

#endif
