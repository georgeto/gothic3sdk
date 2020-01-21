#ifndef GE_LIGHTMAPBATCHER_H_INCLUDED
#define GE_LIGHTMAPBATCHER_H_INCLUDED

class GE_DLLIMPORT eCLightmapBatcher
{
    public:
        struct eSHorizonRow
        {
            GEU16 m_uStart;
            GEU16 m_uEnd;
        };


    public: virtual ~eCLightmapBatcher( void );

    public:
        eCLightmapBatcher( eCLightmapBatcher const & );

    public:
        eCLightmapBatcher & operator = ( eCLightmapBatcher const & );

    public:
               eCLightmapBatcher( GEInt, GEInt );
        void   Clear( GEBool );
        GEBool FindPlace( GEInt a_uLightmapWidth, GEInt a_iLightmapHeight, GEInt & o_iOffsetX, GEInt & o_iOffsetY, eSHorizonRow const * a_pYHorizon );
        GEBool Insert( GEInt a_uLightmapWidth, GEInt a_iLightmapHeight, GEInt a_iOffsetX, GEInt a_iOffsetY, eSHorizonRow const * a_pYHorizon );

    public:
        GEInt             m_iWidth;
        GEInt             m_iHeight;
        bTValArray<GEU16> m_arrRowNextFreeOffset;
};

#endif
