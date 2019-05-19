#ifndef ME_RH_ENTITY_H_INCLUDED
#define ME_RH_ENTITY_H_INCLUDED

#include "me_requesthandler.h"

#include "Engine.h"

class mCEntityRequestHandler :
    public mCRequestHandler
{
    public:
        virtual void HandleRequest();
        virtual void Process();

    private:
        class mCPutToGroundController
        {
            public:
                mCPutToGroundController();
                mCPutToGroundController( bCPropertyID a_EntityID );

                void   EnableDynamicPhysics();
                void   RestorePhysics();
                GEBool HasFinished();

            private:
                eCEntity * GetEntity();

            private:
                bCPropertyID             m_EntityID;
                GEBool                   m_bCollisionEnabled;
                GEBool                   m_bAddedRigidBody;
                GEBool                   m_bAddedCollisionShape;
                eECollisionGroup         m_OriginalColGroup;
                bTValArray<eEShapeGroup> m_arrOriginalShapeColGroup;
                GEU32                    m_msEnableTimestamp;
        };

        bTObjMap<bCPropertyID, mCPutToGroundController> m_putToGround;
};

#endif