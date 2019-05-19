#ifndef GE_OBJECTBASE_H_INCLUDED
#define GE_OBJECTBASE_H_INCLUDED

class GE_DLLIMPORT bCObjectBase
{
    public:    virtual GEU16       GetVersion( void ) const;
    public:    virtual GEBool      IsValid( void ) const;
    private:   virtual GEBool      Write( bCOStream & ) const;
    public:    virtual bEResult    Write( bCOStream & );
    public:    virtual bEResult    Read( bCIStream & );
    protected: virtual void        Destroy( void );
    public:    virtual bEResult    Create( void );
    public:    virtual bEResult    CopyFrom( bCObjectBase const & );
    public:    virtual GEU32       AddReference( void );
    public:    virtual GEU32       ReleaseReference( void );
    public:    virtual GEU32       GetReferenceCount( void );
    public:    virtual GEU32 const GetProfileLastTicksFirst( void ) const;
    public:    virtual GEU32 const GetProfileLastTicksSecond( void ) const;
    public:    virtual GEU32 const GetProfileLastTicksThird( void ) const;
    public:    virtual            ~bCObjectBase( void );

    public:
        bCObjectBase( bCObjectBase const & );
        bCObjectBase( void );

    public:
        bCObjectBase const & operator =  ( bCObjectBase const & );
        bCOStream &          operator >> ( bCOStream & );
        bCIStream &          operator << ( bCIStream & );

    protected:
        bEResult CopyTo( bCObjectBase & ) const;
        void     Invalidate( void );

};

bCIStream & GE_STDCALL operator >>( bCIStream &, bCObjectBase & );
bCOStream & GE_STDCALL operator <<( bCOStream &, bCObjectBase & );

#endif
