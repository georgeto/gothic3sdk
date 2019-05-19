#ifndef GE_INPUTDISPATCHER_H_INCLUDED
#define GE_INPUTDISPATCHER_H_INCLUDED

class GE_DLLIMPORT eCInputDispatcher :
    public eCInputReceiver
{
    public:    virtual bCGuid const & GetID( void ) const;
    protected: virtual GEBool         RegisterModule( eCEngineComponentBase & );
    protected: virtual GEBool         UnregisterModule( eCEngineComponentBase & );
    public:    virtual void           SetSession( eCInputReceiver * );
    public:    virtual void           SetActionMapper( eCInputReceiver * );
    public:    virtual void           EnableDebugMode( GEBool );
    public:    virtual void           Dispatch( void );
    public:    virtual GEU16          GetVersion( void ) const;
    public:    virtual void           Destroy( void );
    public:    virtual bEResult       Create( void );

    public: virtual ~eCInputDispatcher( void );

    public:
        eCInputDispatcher( eCInputDispatcher const & );
        eCInputDispatcher( void );

    protected:
        eCInputDispatcher const & operator = ( eCInputDispatcher const & );

    protected:
        void Invalidate( void );

};

#endif
