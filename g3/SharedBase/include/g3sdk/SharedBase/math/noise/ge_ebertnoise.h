#pragma once

#include <SharedBase/math/noise/ge_noise.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCEbertNoise : public bCNoise
{
    // clang-format off
    public: void SetSeed(GEInt) override;
    public: GEFloat GetNoise(GEFloat) const override;
    public: GEFloat GetNoise(GEFloat, GEFloat) const override;
    public: GEFloat GetNoise(GEFloat, GEFloat, GEFloat) const override;
    public: ~bCEbertNoise() override;
    // clang-format on

  public:
    static bCEbertNoise &GE_STDCALL GetEbertNoise();

  protected:
    bCEbertNoise(bCEbertNoise const &);
    bCEbertNoise();

  protected:
    bCEbertNoise &operator=(bCEbertNoise const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  protected:
    void CopyFrom(bCEbertNoise const &);
    void CopyTo(bCEbertNoise &) const;
    void Initialize(GEInt);
    void Invalidate();
    GEBool Read(bCIStream &);
    void Write(bCOStream &) const;
};
