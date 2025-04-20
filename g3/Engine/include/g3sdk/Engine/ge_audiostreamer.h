#pragma once

#include <Engine/ge_audiochannelgroup.h>

class GE_DLLIMPORT eCAudioStreamer
{
    // clang-format off
    public: virtual ~eCAudioStreamer();
    // clang-format on

  public:
    static eCAudioStreamer &GE_STDCALL GetInstance();

  public:
    eCAudioStreamer(eCAudioStreamer const &);
    eCAudioStreamer();

  public:
    eCAudioStreamer &operator=(eCAudioStreamer const &);

  public:
    eEAudioResult CloseFile(GELPVoid);
    eEAudioResult OpenFile(GELPCChar, GEInt, GEUInt *, GELPVoid *);
    eEAudioResult ReadFile(GELPVoid, GELPVoid, GEUInt, GEUInt *);
    eEAudioResult SeekFile(GELPVoid, GEUInt);
};
