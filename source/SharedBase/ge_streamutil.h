#ifndef GE_STREAMUTIL_H_INCLUDED
#define GE_STREAMUTIL_H_INCLUDED

struct bSStreamSnapshot
{
    GEInt        m_iPositionPreDummy;
    GEInt        m_iPositionAfterDummy;
    bCIOStream * m_pStream;
};

bSStreamSnapshot WriteSizeDummy( bCOStream & a_Stream );
void             ReplaceSizeDummy( bSStreamSnapshot const & );

#endif