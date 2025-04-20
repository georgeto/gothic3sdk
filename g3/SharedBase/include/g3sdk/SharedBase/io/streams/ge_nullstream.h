#pragma once

#include <SharedBase/io/streams/ge_iostream.h>

class GE_DLLIMPORT bCNullStream : public bCIOStream
{
    // clang-format off
    // Overrides for bCIStream
    protected: GEU32 Read(GELPVoid, GEU32) override;
    public: ~bCNullStream() override;
    public: GEI64 GetPosition() const override;
    public: GEBool Seek(GEI64, bEStreamSeekMode) override;
    // Overrides for bCOStream
    protected: GEU32 Write(GELPCVoid, GEU32) override;
    // clang-format on

  public:
    bCNullStream(bCNullStream const &);
    bCNullStream();

  public:
    bCNullStream &operator=(bCNullStream const &);

  public:
    void Clear();
    GEU32 GetBytesWritten();

  protected:
    void ReallocBuffer(GEU32);
};
