#ifndef GE_OBJECTREFBASE_H_INCLUDED
#define GE_OBJECTREFBASE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4266 )// 'GEBool bCObjectBase::Write(bCOStream &) const' : no override available for virtual member function from base 'bCObjectBase'; function is hidden

class GE_DLLIMPORT bCObjectRefBase :
    public bCObjectBase
{
    /**
     *  If true, Add/ReleaseVirtualReference are called as virtual methods,
     *  otherwise the bCObjectRefBase implementation of the method is called directly.
     *  VirtualReference is enabled by default, only eCEntityPropertySet and eCResourceBase_PS have it disabled.
     */
    public:    virtual GEBool   IsVirtualReferencingEnabled( void ) const;
    public:    virtual bEResult PostInitializeProperties( void );
    private:   virtual GEU32    NotifyPropertyValueChangedEnter( GELPCChar );
    private:   virtual GEU32    NotifyPropertyValueChangedExit( GELPCChar );
    public:    virtual GEBool   OnNotifyPropertyValueChangedEnterEx( GELPCChar, GEBool );
    public:    virtual GEBool   OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    public:    virtual void     NotifyPropertyDeprecated( bCString const &, bCString const &, bCMemoryStream &, GEU16 );
    public:    virtual GEBool   NotifyPropertyValueChangedEnterEx( GELPCChar, GEBool a_bIsRead );
    public:    virtual GEBool   NotifyPropertyValueChangedExitEx( GELPCChar, GEBool a_bIsRead );
    public:    virtual GEU16    GetVersion( void ) const;
    public:    virtual GEBool   IsValid( void ) const;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );

    /**
     * If this object has a property object set, it will call
     * m_pPropertyObject->Add/ReleaseReference instead of modifying its own reference counter.
     */
    public:    virtual GEU32    AddReference( void );
    public:    virtual GEU32    ReleaseReference( void );
    protected: virtual         ~bCObjectRefBase( void );
    public: using bCObjectBase::GetReferenceCount;

    private:
        // 0000 // bCObjectRefBase::`vftable'
        /* 0004 */ bCPropertyObjectBase * m_pPropertyObject;
        /* 0008 */ GEU32                  m_u32ReferenceCount;

    public:
        bCObjectRefBase( bCObjectRefBase const & );
        bCObjectRefBase( void );

    public:
        bCObjectRefBase & operator = ( bCObjectRefBase const & );

    public:
        bCPropertyObjectBase *       GetPropertyObject( void );
        bCPropertyObjectBase const * GetPropertyObject( void ) const;
        GEU32                        GetReferenceCount( void ) const;

    protected:
        GEU32 AddVirtualReference( void );
        void  Invalidate( void );
        GEU32 ReleaseVirtualReference( void );
        void  SetPropertyObject( bCPropertyObjectBase const * );

    template<typename T>
    friend class bTPOPureSmartPtr;
};

GE_ASSERT_SIZEOF( bCObjectRefBase, 0x0C )

#pragma warning( pop )

#endif
