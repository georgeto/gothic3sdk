#pragma once

#include <SharedBase/math/noise/ge_noise.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCPeacheyNoise : public bCNoise
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
    public: ~bCPeacheyNoise() override;
    // clang-format on

  public:
    static bCPeacheyNoise &GE_STDCALL GetPeacheyNoise();

  public:
    GEFloat GNoise(GEFloat, GEFloat, GEFloat) const;
    GEFloat GVNoise(GEFloat, GEFloat, GEFloat, GEFloat) const;
    bEAlgorithm GetAlgorithm() const;
    GEFloat SCNoise(GEFloat, GEFloat, GEFloat) const;
    void SetAlgorithm(bEAlgorithm);
    GEFloat VCNoise(GEFloat, GEFloat, GEFloat) const;
    GEFloat VNoise(GEFloat, GEFloat, GEFloat) const;

  protected:
    static GELPByte ms_pu8Permutations;

  protected:
    bCPeacheyNoise(bCPeacheyNoise const &);
    bCPeacheyNoise();

  protected:
    bCPeacheyNoise &operator=(bCPeacheyNoise const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  protected:
    GEFloat CatRom2(GEFloat) const;
    void CopyFrom(bCPeacheyNoise const &);
    void CopyTo(bCPeacheyNoise &) const;
    GEFloat GLattice(GEInt, GEInt, GEInt, GEFloat, GEFloat, GEFloat) const;
    void Initialize(GEInt);
    void Invalidate();
    GEBool Read(bCIStream &);
    GEFloat Spline(GEFloat, GEInt, GEFloat const *) const;
    GEFloat VLattice(GEInt, GEInt, GEInt) const;
    void Write(bCOStream &) const;
};
