#ifndef GE_DUMMYVISUALBASE_PS_H_INCLUDED
#define GE_DUMMYVISUALBASE_PS_H_INCLUDED


/* error C2504: 'eCEditorEntityPropertySet' : base class undefined

class GE_DLLIMPORT gCDummyVisualBase_PS :
    public eCEditorEntityPropertySet
{
    public: virtual void              Destroy( void );
    public: virtual                  ~gCDummyVisualBase_PS( void );
    public: virtual eEPropertySetType GetPropertySetType( void ) const;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCDummyVisualBase_PS( gCDummyVisualBase_PS const & );
        gCDummyVisualBase_PS( void );

    public:
        gCDummyVisualBase_PS const & operator = ( gCDummyVisualBase_PS const & );

    public:
        gCDummyCollectorBase * GetVisCollector( void ) const;
        eCEntity *             GetVisGameEntity( void ) const;
        void                   SetVisCollector( gCDummyCollectorBase * );
        void                   SetVisGameEntity( eCEntity * );

    protected:
        void Invalidate( void );

};*/

#endif
