#pragma once

#include <SharedBase/io/streams/ge_iostream.h>
#include <SharedBase/io/streams/ge_ostream.h>

struct bSStreamSnapshot
{
    GEInt m_iPositionPreDummy;
    GEInt m_iPositionAfterDummy;
    bCIOStream *m_pStream;
};

bSStreamSnapshot WriteSizeDummy(bCOStream &a_Stream);
void ReplaceSizeDummy(bSStreamSnapshot const &);
