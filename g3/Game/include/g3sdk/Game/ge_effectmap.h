#pragma once

#include <SharedBase.h>

class gCEffectCommandSequence;

class GE_DLLIMPORT gCEffectMap
{
    // clang-format off
    public: virtual ~gCEffectMap();
    // clang-format on

  public:
    gCEffectMap(gCEffectMap const &);
    gCEffectMap();

  public:
    gCEffectMap &operator=(gCEffectMap const &);

  public:
    bTValMap<bCString, gCEffectCommandSequence>::bCIterator Begin();
    bTValMap<bCString, gCEffectCommandSequence>::bCConstIterator Begin() const;
    GEBool Contains(bCString const &) const;
    bTValMap<bCString, gCEffectCommandSequence>::bCIterator End();
    bTValMap<bCString, gCEffectCommandSequence>::bCConstIterator End() const;
    gCEffectCommandSequence *InsertNewAt(bCString const &);
    GEBool Load(bCString const &);
    gCEffectCommandSequence *Lookup(bCString const &);
    GEBool Lookup(bCString const &, gCEffectCommandSequence &) const;
    void Read(bCIStream &);
    void RemoveAll();
    GEBool RemoveAt(bCString const &);
    GEBool Save(bCString const &) const;
    void Write(bCOStream &) const;

  protected:
    void Destroy();
    void Invalidate();
};
