#ifndef GE_PROPERTYLAYOUT_H_INCLUDED
#define GE_PROPERTYLAYOUT_H_INCLUDED

class GE_DLLIMPORT bCPropertyLayout
{
    protected: virtual void  Destroy( void );
    protected: virtual void  Create( void );
    protected: virtual void  CopyFrom( bCPropertyLayout const & );
    public:    virtual GEU16 Read( bCIStream & );
    public:    virtual void  Write( bCOStream & );
    public:    virtual      ~bCPropertyLayout( void );

    public:
        bCPropertyLayout( void );

    public:
        bCPropertyLayout const & operator =  ( bCPropertyLayout const & );
        bCOStream &              operator >> ( bCOStream & );
        bCIStream &              operator << ( bCIStream & );

    public:
        void   AssignPropertyType( bCPropertyTypeBase const * );
        GEBool IsValid( void ) const;

    protected:
        bCPropertyLayout( bCPropertyLayout const & );

    protected:
        void CopyTo( bCPropertyLayout & ) const;
        void Invalidate( void );

};

#endif
