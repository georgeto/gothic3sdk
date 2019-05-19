#include "../SharedBase.h"
#include "ge_streamutil.h"

bSStreamSnapshot WriteSizeDummy(bCOStream & a_Stream)
{
    bSStreamSnapshot Snapshot;
    Snapshot.m_pStream = dynamic_cast<bCIOStream *>(&a_Stream);
    Snapshot.m_iPositionPreDummy = static_cast<GEInt>(Snapshot.m_pStream->GetPosition());
    Snapshot.m_pStream->Write(0);
    Snapshot.m_iPositionAfterDummy = static_cast<GEInt>(Snapshot.m_pStream->GetPosition());
    return Snapshot;
}

void ReplaceSizeDummy(bSStreamSnapshot const & a_Snapshot)
{
    GEInt iPositionCurrent = static_cast<GEI32>(a_Snapshot.m_pStream->GetPosition());
    a_Snapshot.m_pStream->Seek(a_Snapshot.m_iPositionPreDummy, bEStreamSeekMode_Begin);
    a_Snapshot.m_pStream->Write(iPositionCurrent - a_Snapshot.m_iPositionAfterDummy);
    a_Snapshot.m_pStream->Seek(iPositionCurrent, bEStreamSeekMode_Begin);
}