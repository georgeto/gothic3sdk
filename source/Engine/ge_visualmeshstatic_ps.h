#ifndef GE_VISUALMESHSTATIC_PS_H_INCLUDED
#define GE_VISUALMESHSTATIC_PS_H_INCLUDED

class GE_DLLIMPORT eCVisualMeshStatic_PS :
    public eCVisualMeshBase_PS
{
    public:    virtual GEU16    GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual bEResult CopyFrom( bCObjectBase const & );
    public:    virtual         ~eCVisualMeshStatic_PS( void );
    protected: virtual void     OnPostRead( void );
    public:    virtual GEBool   ConvertFrom( eCVisualMeshBase_PS const & );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCVisualMeshStatic_PS( eCVisualMeshStatic_PS const & );
        eCVisualMeshStatic_PS( void );

    public:
        eCVisualMeshStatic_PS const & operator = ( eCVisualMeshStatic_PS const & );

    public:
        bCMeshResourceString &       AccessResourceFilePath( void );
        bCMeshResourceString const & GetResourceFilePath( void ) const;
        void                         SetResourceFilePath( bCMeshResourceString const & );

};

#endif
