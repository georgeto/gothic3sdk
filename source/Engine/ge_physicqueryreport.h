#ifndef GE_PHYSICQUERYREPORT_H_INCLUDED
#define GE_PHYSICQUERYREPORT_H_INCLUDED

class GE_DLLIMPORT eCPhysicQueryReport
{

    public:
         eCPhysicQueryReport( eCPhysicQueryReport const & );
         eCPhysicQueryReport( void );
        ~eCPhysicQueryReport( void );

    public:
        eCPhysicQueryReport & operator = ( eCPhysicQueryReport const & );

    public:
        void Destroy( void );
        void Invalidate( void );
        void Reset( void );

    public:
        GEBool                 m_bFoundHit;
        eCEntity *             m_NearestHitEntity;
        GELPVoid               m_NearestUserData;
        GEU32                   __UNK_000C;
        bTPtrArray<eCEntity *> m_arrHitEntity;
        bTPtrArray<GELPVoid>   m_arrUserData;
        bTObjArray<bCVector>   m_arrWorldImpact;
        bTValArray<GEInt>      m_arrMaterialIndex;
        bTObjArray<bCVector>   m_arrWorldFaceNormal;
        bTObjArray<bCVector>   m_arrWorldNormal;
        bTValArray<GEFloat>    m_arrDistance;
        GEInt                  m_NearestMaterialIndex;
        bCVector               m_NearestWorldImpact;
        bCVector               m_NearestFaceNormal;
        bCVector               m_NearestNormal;
        GEFloat                m_NearestDistance;
};

GE_ASSERT_SIZEOF(eCPhysicQueryReport, 0x90);

#endif
