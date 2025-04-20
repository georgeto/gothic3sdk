#pragma once

#include <Engine/ge_particlematerial.h>

class GE_DLLIMPORT eCParticleMaterialBlendSubdivisions : public eCParticleMaterial
{
    // clang-format off
    public: GEBool SetImage(eCResourceImage_PS *) override;
    // clang-format on

  public:
    eCParticleMaterialBlendSubdivisions(eCParticleMaterialBlendSubdivisions const &);
    eCParticleMaterialBlendSubdivisions();
    ~eCParticleMaterialBlendSubdivisions();

  public:
    eCParticleMaterialBlendSubdivisions &operator=(eCParticleMaterialBlendSubdivisions const &);
};
