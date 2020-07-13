#ifndef GE_GOTHIC3ENGINEDIALOGS_H_INCLUDED
#define GE_GOTHIC3ENGINEDIALOGS_H_INCLUDED

class bSAllocationItem;

class GE_DLLIMPORT bCGothic3EngineDialogs
{
    public:
        enum bEGE3DialogsLogMessageType
        {
            bEGE3DialogsLogMessageType_Error = 1,
            bEGE3DialogsLogMessageType_ErrorHistory,
            bEGE3DialogsLogMessageType_ErrorMemory,
            bEGE3DialogsLogMessageType_ErrorCallstack,
            bEGE3DialogsLogMessageType_FileNotUnique,
            bEGE3DialogsLogMessageType_ForceDWORD = GE_FORCE_DWORD
        };
    public:
        class GE_DLLIMPORT bCDialogHandle
        {
            public:
                bCDialogHandle& operator = ( bCDialogHandle const & );
            public:
                void   AddItemToMemoryOverview( bSAllocationItem const *, GEBool );
                GEU16  AddReference( void );
                GEBool AddText( bEGE3DialogsLogMessageType, GELPCChar );
                GEBool CreateErrorDialog( GEBool );
                GEBool CreateFileNotUniqueDialog( void );
                GEBool CreateMemoryDialog( void );
                GEBool DestroyErrorDialog( void );
                GEBool DestroyFileNotUniqueDialog( void );
                GEBool DestroyMemoryDialog( void );
                void   GetErrorDialogState( GEBool &, GEBool & );
                GEU16  GetReferenceCount( void ) const;
                GEU16  ReleaseReference( void );
                GEBool ShowModalErrorDialog( void );
                GEBool ShowModalFileNotUniqueDialog( void );
                GEBool ShowModalMemoryDialog( void );
            protected:
                void Invalidate( void );
            protected:
                 bCDialogHandle( void );
                ~bCDialogHandle( void );
        };

    public:
         bCGothic3EngineDialogs( void );
        ~bCGothic3EngineDialogs( void );

    public:
        bCGothic3EngineDialogs & operator = ( bCGothic3EngineDialogs const & );

    public:
        bCDialogHandle & GetDialogHandle( void ) const;
        GEBool           IsLoaded( void ) const;
        GEBool           LoadGE3DialogLib( GEBool );
        void             UnloadGE3DialogLib( void );

};

#endif
