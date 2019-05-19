#ifndef GS_PSSKILL_H_INCLUDED
#define GS_PSSKILL_H_INCLUDED

class gCSkill_PS;

GS_DECLARE_PROPERTYSET( PSSkill, gCSkill_PS )
public:
    GS_DECLARE_PROPERTY_COPY_ONLY( LearnPoints )
    GS_DECLARE_PROPERTY_COPY_ONLY( ReqAttrib1Tag )
    GS_DECLARE_PROPERTY_COPY_ONLY( ReqAttrib1Value )
    GS_DECLARE_PROPERTY_COPY_ONLY( ReqAttrib2Tag )
    GS_DECLARE_PROPERTY_COPY_ONLY( ReqAttrib2Value )
    GS_DECLARE_PROPERTY_COPY_ONLY( ReqAttrib3Tag )
    GS_DECLARE_PROPERTY_COPY_ONLY( ReqAttrib3Value )
    GS_DECLARE_PROPERTY_COPY_ONLY( ReqAttrib4Tag )
    GS_DECLARE_PROPERTY_COPY_ONLY( ReqAttrib4Value )
    GS_DECLARE_PROPERTY_COPY_ONLY( Tag )

public:
    Entity GetRequiredSkill( void ) const;
    GEBool IsValid( void ) const;

};

#endif
