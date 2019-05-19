#ifndef GE_HUDSTATICNPC_PS_H_INCLUDED
#define GE_HUDSTATICNPC_PS_H_INCLUDED

#include "Game.h"

class gCHUDStaticNPC : public CFFGFCStatic
{
    public:
        enum gEValueType
        {
            gEValueType_LEVEL = 0,
            gEValueType_XP = 1,
            gEValueType_TNL = 2,
            gEValueType_LP = 3,
            gEValueType_HP = 4,
            gEValueType_MP = 5,
            gEValueType_SP = 6,
            gEValueType_ALC = 7,
            gEValueType_THF = 8,
            gEValueType_SMT = 9,
            gEValueType_INT = 10,
            gEValueType_HNT = 11,
            gEValueType_STR = 12,
            gEValueType_PRO_LTG = 13,
            gEValueType_PRO_ICE = 14,
            gEValueType_PRO_FIR = 15,
            gEValueType_PRO_MIS = 16,
            gEValueType_PRO_IMP = 17,
            gEValueType_PRO_BLD = 18,
            gEValueType_GUILD = 19,
            gEValueType_RANK = 20
        };

        enum gEFieldType
        {
            gEFieldType_Label = 0,
            gEFieldType_Value = 1
        };

    public:
        eCEntityProxy m_EntityProxy;
        gEValueType   m_ValueType;
        gEFieldType   m_FieldType;

    protected: virtual  void  _UnkFunc( void );
    public:    virtual  void  OnPaint( void );
    public:    virtual       ~gCHUDStaticNPC( void );

    public:
        gCHUDStaticNPC( void );

    public:
        void Init( gEFieldType a_FieldType, gEValueType a_ValueType );
        void Load( void );
        void LoadLabel( void );
        void LoadValue( void );
        void SetEntity( eCEntity * a_pEntity );

    private:
        gCHUDStaticNPC( gCHUDStaticNPC const & );
        gCHUDStaticNPC & operator = ( gCHUDStaticNPC const & );

};

GE_ASSERT_SIZEOF(gCHUDStaticNPC, 0x34)

#endif
