#ifndef GE_EVENT_H_INCLUDED
#define GE_EVENT_H_INCLUDED

class GE_DLLIMPORT bCEvent :
    public bCObjectRefBase
{
    public:    virtual GEBool   IsDeleteable( void );
    private: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );
    protected: virtual         ~bCEvent( void );

    public:
        bCEvent( bCEvent const & );
        bCEvent( void );

    public:
        bCEvent & operator = ( bCEvent const & );

    protected:
        void Invalidate( void );

    protected:
        GEU32  __UNK_000C;
        GEBool __UNK_0010;
        // Id of the window that caused the window (if any): eCGUIManager::GetInstance()->AccessWindowByID(m_u32WindowId)
        GEU32  m_u32WindowId;
};

GE_ASSERT_SIZEOF( bCEvent, 0x18 )

#endif
