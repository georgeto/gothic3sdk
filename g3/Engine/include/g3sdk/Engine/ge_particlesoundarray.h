#pragma once

#include <Engine/ge_particlesound.h>

#include <SharedBase.h>

class eCAudioSound;

class GE_DLLIMPORT eCParticleSoundArray
{
  public:
    struct SItem
    {
      public:
        SItem(SItem const &);
        SItem();
        ~SItem();

      public:
        SItem &operator=(SItem const &);
    };

  public:
    eCParticleSoundArray(eCParticleSoundArray const &);
    eCParticleSoundArray();
    ~eCParticleSoundArray();

  public:
    eCParticleSoundArray &operator=(eCParticleSoundArray const &);

  public:
    GEBool GetItem(GEInt, eSParticleSound &) const;
    GEInt GetItemCount() const;
    eCAudioSound *GetSound(GEInt);
    GEInt InsertItem(GEInt, eSParticleSound const &);
    void Read(bCIStream &);
    void RemoveAllItems();
    GEBool RemoveItem(GEInt);
    void Write(bCOStream &);
};
