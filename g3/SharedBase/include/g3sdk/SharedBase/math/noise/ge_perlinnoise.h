#pragma once

#include <SharedBase/math/noise/ge_noise.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCPerlinNoise : public bCNoise
{
  public:
    enum bEAlgorithm
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: void SetSeed(GEInt) override;
    public: GEFloat GetNoise(GEFloat) const override;
    public: GEFloat GetNoise(GEFloat, GEFloat) const override;
    public: GEFloat GetNoise(GEFloat, GEFloat, GEFloat) const override;
    public: ~bCPerlinNoise() override;
    // clang-format on

  public:
    static bCPerlinNoise &GE_STDCALL GetPerlinNoise();

  public:
    bEAlgorithm GetAlgorithm() const;
    GEFloat ImprovedNoise(GEFloat) const;
    GEFloat ImprovedNoise(GEFloat, GEFloat) const;
    GEFloat ImprovedNoise(GEFloat, GEFloat, GEFloat) const;
    GEFloat Noise(GEFloat) const;
    GEFloat Noise(GEFloat, GEFloat) const;
    GEFloat Noise(GEFloat, GEFloat, GEFloat) const;
    void SetAlgorithm(bEAlgorithm);

  protected:
    static GEInt *ms_piPermutations;

  protected:
    bCPerlinNoise(bCPerlinNoise const &);
    bCPerlinNoise();

  protected:
    bCPerlinNoise &operator=(bCPerlinNoise const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  protected:
    void CopyFrom(bCPerlinNoise const &);
    void CopyTo(bCPerlinNoise &) const;
    void Initialize(GEInt);
    void Invalidate();
    GEBool Read(bCIStream &);
    void Write(bCOStream &) const;
};
