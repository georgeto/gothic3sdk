#ifndef GE_ENTITYPROXYINTERNAL_H_INCLUDED
#define GE_ENTITYPROXYINTERNAL_H_INCLUDED

class GE_DLLIMPORT eCEntityProxyInternal
{
    private:
        eCEntity* m_Entity;
        GEU32     m_ReferenceCount;

    public:
        eCEntityProxyInternal & operator = ( eCEntityProxyInternal const & );

    public:
        GEU32            AddReference( void );
        eCEntity *       GetEntity( void );
        eCEntity const * GetEntity( void ) const;
        GEU32            GetReferenceCount( void ) const;
        GEU32            ReleaseReference( void );

    protected:
         eCEntityProxyInternal( void );
        ~eCEntityProxyInternal( void );

    protected:
        void Invalidate( void );
        void SetEntity( eCEntity const * );

};

GE_ASSERT_SIZEOF( eCEntityProxyInternal, 0x08 );

#endif
