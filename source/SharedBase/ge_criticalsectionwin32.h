#ifndef GE_CRITICALSECTIONWIN32_H_INCLUDED
#define GE_CRITICALSECTIONWIN32_H_INCLUDED

class GE_DLLIMPORT bCCriticalSectionWin32
{

    public:
         bCCriticalSectionWin32( void );
        ~bCCriticalSectionWin32( void );

    public:
        bCCriticalSectionWin32 & operator = ( bCCriticalSectionWin32 const & );

    public:
        void   Acquire( void );
        GEU32  GetLockCount( void ) const;
        void   Release( void );
        void   SetSpinCount( GEU32 );
        GEBool TryAcquire( void );

};

#endif
