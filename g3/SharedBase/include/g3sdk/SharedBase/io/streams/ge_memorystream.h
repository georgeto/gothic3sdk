#pragma once

#include <SharedBase/io/streams/ge_iostream.h>

class GE_DLLIMPORT bCMemoryStream : public bCIOStream
{
    // clang-format off
    public: virtual GEI64 GetSize() const;
    public: virtual GEBool GetPosition(GEI64 &) const;
    public: virtual GEBool SetPosition(GEI64, bEStreamSeekMode);
    // Overrides for bCIStream
    public: GEU32 Read(GELPVoid, GEU32) override;
    public: ~bCMemoryStream() override;
    public: GEI64 GetPosition() const override;
    public: GEBool Seek(GEI64, bEStreamSeekMode) override;
    // Overrides for bCOStream
    public: GEU32 Write(GELPCVoid, GEU32) override;
    // clang-format on

  public:
    using bCIStream::Read;
    using bCOStream::Write;

  public:
    bCMemoryStream(bCMemoryStream const &);
    bCMemoryStream();

  public:
    bCMemoryStream &operator=(bCMemoryStream const &);

  public:
    GELPByte AccessBuffer(GEU32);
    GEBool Decrypt();
    void Destroy();
    GEBool Encrypt();
    GELPCByte GetBuffer(GEU32) const;
    void SetCount(GEU32);

  protected:
    static GEBool GE_STDCALL Decrypt(GELPVoid, GEU32);
    static GEBool GE_STDCALL Encrypt(GELPVoid, GEU32);

  protected:
    void Invalidate();

  private:
    GELPByte m_bBuffer;
    GEInt m_iPosition;
    GEInt m_iSize;
};

GE_ASSERT_SIZEOF(bCMemoryStream, 0x14)
