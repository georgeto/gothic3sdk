#ifndef GE_MD5_H_INCLUDED
#define GE_MD5_H_INCLUDED

class GE_DLLIMPORT bCMd5
{

    public:
         bCMd5( void );
        ~bCMd5( void );

    public:
        void   Append( GELPCVoid, GEU32 );
        GEBool Create( void );
        void   Destroy( void );
        void   Finish( bCPropertyID::bSCore & );
        void   Finish( void );
        void   GetDigest16( bCPropertyID::bSCore & ) const;
        void   GetDigest32( bCPropertyID::bSCore & ) const;
        void   GetDigest8( bCPropertyID::bSCore & ) const;

    protected:
        void Invalidate( void );

    private:
        void Process( GELPCByte const );

};

#endif
