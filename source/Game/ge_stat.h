#ifndef GE_STAT_H_INCLUDED
#define GE_STAT_H_INCLUDED

// Für dynamische Attribute (HP, MP, SP).
// Aktueller Wert steht in BaseValue, Modifier ist 0.
class GE_DLLIMPORT gCStat :
    public gCAttribute
{
    public:    virtual void          Destroy( void );
    public:    virtual              ~gCStat( void );
    public:    virtual GEInt         GetMaximum( void ) const; // BaseMaximum + MaximumModifier
    public:    virtual void          SetMaximum( GEInt );
    public:    virtual GEBool        ApplyPerm( EAttribModOperation, GEInt );
    public:    virtual GEBool        ApplyTemp( EAttribModOperation, GEInt );
    public:    virtual GEBool        UnapplyTemp( EAttribModOperation, GEInt );
    protected: virtual void          Cap( void );
    public:    virtual gCAttribute * Clone( void ) const;
    protected: virtual void          ApplyDefaults( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCStat( gCStat const & );
        gCStat( void );

    public:
        gCStat const & operator = ( gCStat const & );

    public:
        GEInt &       AccessBaseMaximum( void );
        GEInt &       AccessMaximumModifier( void );
        GEInt const & GetBaseMaximum( void ) const; // Attributwert ohne Boni
        GEInt const & GetMaximumModifier( void ) const; // Aktive Boni
        void          SetBaseMaximum( GEInt const & );
        void          SetMaximumModifier( GEInt const & );

    protected:
        void Invalidate( void );

};

#endif
