#ifndef GE_CLASSLAYOUT_H_INCLUDED
#define GE_CLASSLAYOUT_H_INCLUDED

class GE_DLLIMPORT bCClassLayout
{
    protected: virtual void  Destroy( void );
    protected: virtual void  Create( void );
    protected: virtual void  CopyFrom( bCClassLayout const & );
    public:    virtual GEU16 Read( bCIStream & );
    public:    virtual void  Write( bCOStream & );
    public:    virtual      ~bCClassLayout( void );

    public:
        bCClassLayout( void );

    public:
        bCClassLayout const & operator =  ( bCClassLayout const & );
        bCOStream &           operator >> ( bCOStream & );
        bCIStream &           operator << ( bCIStream & );

    public:
        void   AssignPropertyObjectType( bCPropertyObjectTypeBase const * );
        GEBool IsValid( void ) const;

    protected:
        bCClassLayout( bCClassLayout const & );

    protected:
        void CopyTo( bCClassLayout & ) const;
        void FillLayout( void );
        void Invalidate( void );

};

#endif
