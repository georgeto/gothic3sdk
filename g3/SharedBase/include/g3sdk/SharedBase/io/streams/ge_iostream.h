#pragma once

#include <SharedBase/io/streams/ge_istream.h>
#include <SharedBase/io/streams/ge_ostream.h>

enum bEStreamSeekMode
{
    bEStreamSeekMode_Begin,
    bEStreamSeekMode_Current,
    bEStreamSeekMode_End,
    bEStreamSeekMode_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT bCIOStream : public bCIStream, public bCOStream
{
    // clang-format off
    public: virtual GEI64 GetPosition() const = 0;
    public: virtual GEBool Seek(GEI64, bEStreamSeekMode) = 0;
    public: ~bCIOStream() override;
    // clang-format on

  public:
    bCIOStream(bCIOStream const &);
    bCIOStream();

  public:
    bCIOStream &operator=(bCIOStream const &);
};
