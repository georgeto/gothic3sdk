#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCLightmapBatcher
{
  public:
    struct eSHorizonRow
    {
        GEU16 m_uStart;
        GEU16 m_uEnd;
    };

    // clang-format off
    public: virtual ~eCLightmapBatcher();
    // clang-format on

  public:
    eCLightmapBatcher(eCLightmapBatcher const &);
    eCLightmapBatcher(GEInt, GEInt);

  public:
    eCLightmapBatcher &operator=(eCLightmapBatcher const &);

  public:
    void Clear(GEBool);
    GEBool FindPlace(GEInt a_uLightmapWidth, GEInt a_iLightmapHeight, GEInt &o_iOffsetX, GEInt &o_iOffsetY,
                     eSHorizonRow const *a_pYHorizon);
    GEBool Insert(GEInt a_uLightmapWidth, GEInt a_iLightmapHeight, GEInt a_iOffsetX, GEInt a_iOffsetY,
                  eSHorizonRow const *a_pYHorizon);

  public:
    GEInt m_iWidth;
    GEInt m_iHeight;
    bTValArray<GEU16> m_arrRowNextFreeOffset;
};
