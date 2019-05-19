#ifndef GE_ENCLAVEADMIN_H_INCLUDED
#define GE_ENCLAVEADMIN_H_INCLUDED

class GE_DLLIMPORT gCEnclaveAdmin :
    public eCEngineComponentBase
{
    public: virtual ~gCEnclaveAdmin( void );

    public:
        static gCEnclaveAdmin & GE_STDCALL             GetInstance( void );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCEnclaveAdmin( gCEnclaveAdmin const & );
        gCEnclaveAdmin( void );

    public:
        gCEnclaveAdmin const & operator = ( gCEnclaveAdmin const & );

    public:
        bEResult                           AddEnclave( gCEnclave_PS * );
        bTValArray<gCEnclave_PS *> const & GetEnclaves( void );
        void                               Invalidate( void );
        void                               RefreshEnclaveMembers( GEBool );
        bEResult                           RemoveEnclave( gCEnclave_PS * );

};

#endif
