#ifndef GE_PROPERTYDUMMYVISUAL_PS_H_INCLUDED
#define GE_PROPERTYDUMMYVISUAL_PS_H_INCLUDED

/* error C2504: 'gCDummyVisualBase_PS' : base class undefined

class GE_DLLIMPORT gCPropertyDummyVisual_PS :
    public gCDummyVisualBase_PS
{
    public:    virtual     ~gCPropertyDummyVisual_PS( void );
    protected: virtual void OnUpdatedWorldMatrix( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCPropertyDummyVisual_PS( gCPropertyDummyVisual_PS const & );
        gCPropertyDummyVisual_PS( void );

    public:
        gCPropertyDummyVisual_PS const & operator = ( gCPropertyDummyVisual_PS const & );

    public:
        eEPropertySetType     GetVisPSType( void ) const;
        eCEntityPropertySet * GetVisPropertySet( void ) const;
        void                  SetBlockApplyExternal( GEBool );
        void                  SetVisPSType( eEPropertySetType );
        void                  SetVisPropertySet( eCEntityPropertySet * );

    protected:
        void Invalidate( void );
        void SetBlockApplyInternal( GEBool );

};*/

#endif
