#pragma once

#include <Engine/ge_particlematerial.h>

class GE_DLLIMPORT eCParticleMaterialSimple : public eCParticleMaterial
{
    // clang-format off
    public: GEBool SetImage(eCResourceImage_PS *) override;
    // clang-format on

  public:
    eCParticleMaterialSimple(eCParticleMaterialSimple const &);
    eCParticleMaterialSimple();
    ~eCParticleMaterialSimple();

  public:
    eCParticleMaterialSimple &operator=(eCParticleMaterialSimple const &);
};
