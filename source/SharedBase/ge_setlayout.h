#ifndef GE_SETLAYOUT_H_INCLUDED
#define GE_SETLAYOUT_H_INCLUDED

class GE_DLLIMPORT bCSetLayout
{
    protected: virtual void  Destroy( void );
    protected: virtual void  Create( void );
    protected: virtual void  CopyFrom( bCSetLayout const & );
    public:    virtual GEU16 Read( bCIStream & );
    public:    virtual void  Write( bCOStream & );
    public:    virtual      ~bCSetLayout( void );

    public:
        bCSetLayout( void );

    public:
        bCSetLayout const & operator =  ( bCSetLayout const & );
        bCOStream &         operator >> ( bCOStream & );
        bCIStream &         operator << ( bCIStream & );

    public:
        void   FillLayout( void );
        GEBool IsValid( void ) const;

    protected:
        bCSetLayout( bCSetLayout const & );

    protected:
        void CopyTo( bCSetLayout & ) const;
        void Invalidate( void );

};

#endif
