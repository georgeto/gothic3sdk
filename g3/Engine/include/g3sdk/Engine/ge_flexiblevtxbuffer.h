#pragma once

#include <Engine/ge_flexiblebuffer.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCFlexibleVtxBuffer : public eCFlexibleBuffer
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCFlexibleVtxBuffer() override;
    public: GEBool IsEmpty() const override;
    public: GEBool IsElementValidAt(GEU32) const override;
    public: GEBool IsDataValidAt(GEInt) const override;
    public: GEU32 GetBufferSize() const override;
    public: GEU32 GetElementCount() const override;
    public: GEU32 GetElementSize() const override;
    public: GELPByte GetElementAt(GEU32) override;
    public: GELPByte GetData(GEU32) override;
    protected: void Clear() override;
    protected: GELPByte InsertNewData(GEU32) override;
    protected: GELPByte RemoveOldData(GEU32, GEU32) override;
    public: bEResult CopyFrom(eCFlexibleBuffer const &) override;
    // clang-format on

  public:
    eCFlexibleVtxBuffer(eCFlexibleVtxBuffer const &);
    explicit eCFlexibleVtxBuffer(GEU32);
    eCFlexibleVtxBuffer();

  public:
    bEResult Create(GEU32);
    bCFlexibleVertexFormat const &GetFormat() const;
    bCFlexibleVertexPtr GetVertexAt(GEU32);
    GEBool GetVertexAt(GEU32, bCFlexibleVertexPtr &);
    void SetElementCount(GEU32);

  protected:
    eCFlexibleVtxBuffer const &operator=(eCFlexibleVtxBuffer const &);

  protected:
    void Invalidate();
};
