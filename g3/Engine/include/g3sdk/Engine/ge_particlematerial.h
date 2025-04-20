#pragma once

#include <SharedBase.h>

class eCResourceImage_PS;
class eCShaderParticle;

class GE_DLLIMPORT eCParticleMaterial
{
    // clang-format off
    public: virtual GEBool SetImage(eCResourceImage_PS *) = 0;
    // clang-format on

  public:
    eCParticleMaterial(eCParticleMaterial const &);
    ~eCParticleMaterial();

  public:
    eCParticleMaterial &operator=(eCParticleMaterial const &);

  public:
    eCShaderParticle *GetShader() const;

  protected:
    eCParticleMaterial();
};
