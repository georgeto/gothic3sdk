#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCBox;
class bCPlane;
class bCVector;

class bCOctTreeEntryBase
{
    GE_UNIMPL_STRUCT(bCOctTreeEntryBase)
};

class GE_DLLIMPORT bCOctTree
{
  public:
    explicit bCOctTree(bCBox const &);
    ~bCOctTree();

  public:
    bCOctTree &operator=(bCOctTree const &);

  public:
    void AddEntry(bCOctTreeEntryBase *);
    void Check();
    void CleanUp();
    void IncludeBox(bCBox const &);
    void MoveEntry(bCOctTreeEntryBase *, bCBox const &);
    void RemoveEntry(bCOctTreeEntryBase *);
    enum bEOctTreeCull(GE_STDCALL *SetCullingCallback(bEOctTreeCull(GE_STDCALL *)(bCBox const &)))(bCBox const &);
    void(GE_STDCALL *SetTouchCallback(void(GE_STDCALL *)(bCOctTreeEntryBase *, bCOctTreeEntryBase *,
                                                         GEBool)))(bCOctTreeEntryBase *, bCOctTreeEntryBase *, GEBool);
    void Traverse(void(GE_STDCALL *)(bCOctTreeEntryBase *), bCBox const &);
    void Traverse(void(GE_STDCALL *)(bCOctTreeEntryBase *), bCVector const &);
    void Traverse(void(GE_STDCALL *)(bCOctTreeEntryBase *), bCPlane const *, GEInt);
    void Traverse(void(GE_STDCALL *)(bCOctTreeEntryBase *), bCPlane const *, GEInt, bCPlane const &);

  private:
    void ExpandBox(GEInt, GEInt, GEInt);
};
