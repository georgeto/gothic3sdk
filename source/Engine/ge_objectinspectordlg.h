#ifndef GE_OBJECTINSPECTORDLG_H_INCLUDED
#define GE_OBJECTINSPECTORDLG_H_INCLUDED

struct eIDispatch;
class eCScopeInstance;

class GE_DLLIMPORT eCObjectInspectorDlg :
    public eCDialog
{
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    protected: virtual void     Destroy( void );
    public:    virtual         ~eCObjectInspectorDlg( void );
    protected: virtual void     OnSize( GEU32, GEInt, GEInt );
    protected: virtual GEBool   OnChildNotify( GEU32, GEU32, GEU32, GEI32 * );
    protected: virtual void     OnRender( void );
    public: using eCWnd::Create;
    public:    virtual bEResult Create( GEU32, bCRect const &, GEU32, eCWnd * );
    public:    virtual GEInt    OnKeyDown( eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const & );
    public: using eCInputReceiver::CopyFrom;

    public:
        eCObjectInspectorDlg( eCObjectInspectorDlg const & );
        eCObjectInspectorDlg( void );

    public:
        eCObjectInspectorDlg & operator =  ( eCObjectInspectorDlg const & );
        bCOStream &            operator >> ( bCOStream & );
        bCIStream &            operator << ( bCIStream & );

    public:
        void   CopyFrom( eCObjectInspectorDlg const & );
        void   CopyTo( eCObjectInspectorDlg & ) const;
        void   Resize( void );
        GEBool SetInstance( eCScopeInstance * );

    protected:
        void AddControls( eIDispatch * );
        void AddControls( eCScopeInstance * );
        void Invalidate( void );
        void RemoveControls( void );

};

#endif
