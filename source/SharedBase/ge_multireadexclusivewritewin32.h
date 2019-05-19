#ifndef GE_MULTIREADEXCLUSIVEWRITEWIN32_H_INCLUDED
#define GE_MULTIREADEXCLUSIVEWRITEWIN32_H_INCLUDED

class GE_DLLIMPORT bCMultiReadExclusiveWriteWin32
{

    public:
         bCMultiReadExclusiveWriteWin32( void );
        ~bCMultiReadExclusiveWriteWin32( void );

    public:
        bCMultiReadExclusiveWriteWin32 & operator = ( bCMultiReadExclusiveWriteWin32 const & );

    public:
        void  BeginRead( void );
        void  BeginWrite( void );
        void  EndRead( void );
        void  EndWrite( void );
        GEU32 GetLockCount( void ) const;

    protected:
        GEBool WriterIsOnlyReader( void ) const;

};

#endif
