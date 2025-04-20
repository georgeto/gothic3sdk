#pragma once

#include <Engine.h>

class gCAmbientEnvironment;
class gCAmbientSound;
class gCAmbientSoundList;

struct gSAmbientObject
{
    GE_UNIMPL_STRUCT(gSAmbientObject)
};

class GE_DLLIMPORT gCAmbientLibrary
{
    // clang-format off
    public: virtual ~gCAmbientLibrary();
    // clang-format on

  public:
    gCAmbientLibrary(gCAmbientLibrary const &);
    gCAmbientLibrary();

  public:
    gCAmbientLibrary &operator=(gCAmbientLibrary const &);

  public:
    GEBool AddObject(eEAmbientEnvironment, eCEntity const *);
    void CopyFrom(gCAmbientLibrary const &);
    void Create();
    void Destroy();
    eCEntity const *FindObject() const;
    gCAmbientSound *FindSound(eEAmbientClimate, eEAmbientEnvironment, eEAmbientDayTime) const;
    gCAmbientEnvironment *GetEnvironment(eEAmbientClimate, eEAmbientEnvironment) const;
    GEInt GetObjectCount(eEAmbientEnvironment) const;
    bTValArray<gSAmbientObject> &GetObjects();
    bTValArray<gSAmbientObject> const &GetObjects() const;
    gCAmbientSoundList &GetSounds();
    gCAmbientSoundList const &GetSounds() const;
    GEBool Load(bCString const &);
    void Read(bCIStream &);
    GEBool RemoveObject(eCEntity const *);
    GEBool Save(bCString const &) const;
    void Write(bCOStream &) const;

  protected:
    GEInt FindIndex(eCEntity const *) const;
    void Invalidate();
    void ReadEnvironments(bCIStream &);
    void WriteEnvironments(bCOStream &) const;
};
