#pragma once

#include <SharedBase/io/streams/ge_iostream.h>

enum bEFileCreationMode
{
    bEFileCreationMode_OpenExisting,
    bEFileCreationMode_OpenAlways,
    bEFileCreationMode_CreateAlways,
    bEFileCreationMode_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT bCFile : public bCIOStream
{
    // clang-format off
    public: virtual GEBool IsValid() const;
    public: virtual GEBool IsOpen() const;
    public: virtual GEI64 GetLength() const;
    public: virtual GEBool Open(bCString const &, bEFileCreationMode);
    public: virtual GEBool Close();
    public: virtual GEBool Seek(GEI64, bEStreamSeekMode) const;
    public: ~bCFile() override;
    public: GEI64 GetPosition() const override;
    // clang-format on

  public:
    bCFile(bCFile const &);
    bCFile();

  public:
    bCFile &operator=(bCFile const &);

  public:
    GEBool Eof() const;
    GEBool SeekToBegin() const;
    GEBool SeekToEnd() const;
};
