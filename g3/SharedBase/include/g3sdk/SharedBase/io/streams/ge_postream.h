#pragma once

#include <SharedBase/container/array/ge_objarray.h>
#include <SharedBase/container/map/ge_stringmap.h>
#include <SharedBase/io/streams/ge_memorystream.h>
#include <SharedBase/types/ge_string.h>

class GE_DLLIMPORT bCPOStream : public bCMemoryStream
{
    // clang-format off
    // Overrides for bCIStream
    public: GEU32 Read(GELPVoid, GEU32) override;
    public: GEU32 Read(bCString &) override;
    public: ~bCPOStream() override;
    // Overrides for bCOStream
    public: GEU32 Write(GELPCVoid, GEU32) override;
    public: GEU32 Write(bCString const &) override;
    // clang-format on

  public:
    static void GE_STDCALL DisableLegacyMode();
    static void GE_STDCALL GetStringList(bTObjArray<bCString> *&, bTStringValMap<GEI32> *&);
    static GEBool GE_STDCALL IsInLegacyMode();
    static void GE_STDCALL SetStringList(bTObjArray<bCString> *, bTStringValMap<GEI32> *);

  public:
    bCPOStream(bCPOStream const &);
    bCPOStream();

  public:
    bCPOStream &operator=(bCPOStream const &);

  public:
    void ClearStringHeaderMap();
    void Create();
    void Destroy();
    void FakeMainPOStream(GEBool);
    void ForceLegacyMode();
    GEBool IsForcedLegacyMode() const;
    GEBool IsMain() const;
    GEBool ReadFile(bCIStream &);
    GEBool WriteFile(bCOStream &);

  protected:
    static GEBool ms_bLegacyMode;
    static bCPOStream *ms_pMainPOStream;
    static bTObjArray<bCString> *ms_parrStringList;
    static bTStringValMap<GEI32> *ms_pmapStringSaveHashmap;

  protected:
    void Invalidate();

  private:
    GEBool m_bUnk;
    GEBool m_bForcedLegacyMode;
    GE_PADDING(0x2)
};

GE_ASSERT_SIZEOF(bCPOStream, 0x18)
