#ifndef GE_OCTTREE_H_INCLUDED
#define GE_OCTTREE_H_INCLUDED

class bCOctTreeEntryBase;
enum bEOctTreeCull;

class GE_DLLIMPORT bCOctTree
{

    public:
         bCOctTree( bCBox const & );
        ~bCOctTree( void );

    public:
        bCOctTree & operator = ( bCOctTree const & );

    public:
        void AddEntry( bCOctTreeEntryBase * );
        void Check( void );
        void CleanUp( void );
        void IncludeBox( bCBox const & );
        void MoveEntry( bCOctTreeEntryBase *, bCBox const & );
        void RemoveEntry( bCOctTreeEntryBase * );
        bEOctTreeCull ( GE_STDCALL*SetCullingCallback( bEOctTreeCull ( GE_STDCALL* )( bCBox const & )))( bCBox const & );
        void ( GE_STDCALL*SetTouchCallback( void ( GE_STDCALL* )( bCOctTreeEntryBase *, bCOctTreeEntryBase *, GEBool )))( bCOctTreeEntryBase *, bCOctTreeEntryBase *, GEBool );
        void Traverse( void ( GE_STDCALL* )( bCOctTreeEntryBase * ), bCBox const & );
        void Traverse( void ( GE_STDCALL* )( bCOctTreeEntryBase * ), bCVector const & );
        void Traverse( void ( GE_STDCALL* )( bCOctTreeEntryBase * ), bCPlane const *, GEInt );
        void Traverse( void ( GE_STDCALL* )( bCOctTreeEntryBase * ), bCPlane const *, GEInt, bCPlane const & );

    private:
        void ExpandBox( GEInt, GEInt, GEInt );

};

#endif
