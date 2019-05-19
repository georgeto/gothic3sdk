#include "../Script.h"

#define IMPLEMENT_ITEM_PROPERTY_TAG( N, O )                                                \
    PSItemWrapper::Property ## N::operator bCString ( void ) const {                       \
        if((GELPByte)m_pEngineEntity != 0) {                                               \
            return bCString( *reinterpret_cast<bCString*>((GELPByte)m_pEngineEntity + O)); \
        } else {                                                                           \
            return bCString();                                                             \
        }                                                                                  \
    }

#define IMPLEMENT_ITEM_PROPERTY_VALUE( N, O )                     \
    PSItemWrapper::Property ## N::operator GEInt ( void ) const { \
        if((GELPByte)m_pEngineEntity != 0) {                      \
            return *((GELPByte)m_pEngineEntity + O);              \
        } else {                                                  \
            return 0;                                             \
        }                                                         \
    }

IMPLEMENT_ITEM_PROPERTY_TAG( ReqAttrib1Tag, 0x74 )
IMPLEMENT_ITEM_PROPERTY_VALUE( ReqAttrib1Value, 0x80 )
IMPLEMENT_ITEM_PROPERTY_TAG( ReqAttrib2Tag, 0x84 )
IMPLEMENT_ITEM_PROPERTY_VALUE( ReqAttrib2Value, 0x90 )
IMPLEMENT_ITEM_PROPERTY_TAG( ReqAttrib3Tag, 0x94 )
IMPLEMENT_ITEM_PROPERTY_VALUE( ReqAttrib3Value, 0xA0 )
IMPLEMENT_ITEM_PROPERTY_TAG( ReqAttrib4Tag, 0xA4 )
IMPLEMENT_ITEM_PROPERTY_VALUE( ReqAttrib4Value, 0xB0 )