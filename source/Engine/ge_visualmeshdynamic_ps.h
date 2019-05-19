#ifndef GE_VISUALMESHDYNAMIC_PS_H_INCLUDED
#define GE_VISUALMESHDYNAMIC_PS_H_INCLUDED

class GE_DLLIMPORT eCVisualMeshDynamic_PS :
    public eCVisualMeshBase_PS
{
    public:    virtual GEU16    GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual bEResult CopyFrom( bCObjectBase const & );
    public:    virtual         ~eCVisualMeshDynamic_PS( void );
    protected: virtual bEResult PostInitializeProperties( void );
    protected: virtual void   OnPostRead( void );
    public:    virtual GEBool ConvertFrom( eCVisualMeshBase_PS const & );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCVisualMeshDynamic_PS( eCVisualMeshDynamic_PS const & );
        eCVisualMeshDynamic_PS( void );

    public:
        eCVisualMeshDynamic_PS const & operator = ( eCVisualMeshDynamic_PS const & );

    public:
        bCMeshResourceString &       AccessResourceFilePath( void );
        bCMeshResourceString const & GetResourceFilePath( void ) const;
        void                         SetResourceFilePath( bCMeshResourceString const & );

};

#endif
