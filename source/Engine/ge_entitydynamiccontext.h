#ifndef GE_ENTITYDYNAMICCONTEXT_H_INCLUDED
#define GE_ENTITYDYNAMICCONTEXT_H_INCLUDED

class GE_DLLIMPORT eCEntityDynamicContext :
    public eCContextBase
{
    public: virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult          Write( bCOStream & );
    public: virtual bEResult          Read( bCIStream & );
    public: virtual void              Destroy( void );
    public: virtual bEResult          Create( void );
    public: virtual bEResult          CopyFrom( bCObjectBase const & );
    public: virtual                  ~eCEntityDynamicContext( void );
    public: virtual eCDynamicEntity * CreateSpecificEntity( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCEntityDynamicContext( eCEntityDynamicContext const & );
        eCEntityDynamicContext( void );

    public:
        eCEntityDynamicContext const & operator = ( eCEntityDynamicContext const & );

    public:
        void     Invalidate( void );
        bEResult ReadSaveGame( bCIStream & );
        void     SetCreationCallbackFunc( eCEntity * (GE_STDCALL*)(void));
        bEResult WriteSaveGame( bCOStream & );

};

#endif
