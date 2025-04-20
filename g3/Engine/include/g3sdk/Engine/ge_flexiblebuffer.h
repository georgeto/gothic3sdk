#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCFlexibleBuffer : public bCObjectRefBase
{
    // clang-format off
    public: virtual GEBool IsEmpty() const = 0;
    public: virtual GEBool IsElementValidAt(GEU32) const = 0;
    public: virtual GEBool IsDataValidAt(GEInt) const = 0;
    public: virtual GEU32 GetBufferSize() const = 0;
    public: virtual GEU32 GetElementCount() const = 0;
    public: virtual GEU32 GetElementSize() const = 0;
    public: virtual GELPByte GetElementAt(GEU32) = 0;
    public: virtual GELPByte GetData(GEU32) = 0;
    protected: virtual void Clear() = 0;
    protected: virtual GELPByte InsertNewData(GEU32) = 0;
    protected: virtual GELPByte RemoveOldData(GEU32, GEU32) = 0;
    public: virtual bEResult CopyFrom(eCFlexibleBuffer const &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCFlexibleBuffer() override;
    // clang-format on

  public:
    eCFlexibleBuffer(eCFlexibleBuffer const &);
    eCFlexibleBuffer();

  public:
    GELPByte AttachBuffer(eCFlexibleBuffer const &);
    GELPCByte GetData(GEU32) const;
    GELPCByte GetElementAt(GEU32) const;
    GELPByte InsertNewElement();
    GELPByte RemoveOldElement(GEU32);

  protected:
    eCFlexibleBuffer const &operator=(eCFlexibleBuffer const &);

  protected:
    GELPByte InsertNewData(GEU32, GELPCByte);
    void Invalidate();
};
