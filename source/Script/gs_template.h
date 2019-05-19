#ifndef GS_TEMPLATE_H_INCLUDED
#define GS_TEMPLATE_H_INCLUDED

class bCPropertyID;

class GE_DLLIMPORT Template
{
    GELPVoid pguid_Data1;
    GELPVoid pguid_Data2;
    GELPVoid pguid_Data3;
    GELPVoid pguid_Data4;
    GEU32    count;

    public:
         Template( Template const & );
         Template( bCPropertyID const & );
         Template( GELPCChar );
         Template( void );
        ~Template( void );

    public:
        Template & operator =                    ( Template const & );
        Template & operator =                    ( bCPropertyID const & );
        Template & operator =                    ( GELPCChar );
        GEBool     operator ==                   ( bCPropertyID const & ) const;
        GEBool     operator !=                   ( bCPropertyID const & ) const;
                   operator bCPropertyID &       ( void );
                   operator bCPropertyID const & ( void ) const;

    public:
        GEBool IsValid( void ) const;

    private:
        void Create( GELPCChar );

};

#endif
