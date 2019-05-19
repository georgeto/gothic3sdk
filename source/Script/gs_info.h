#ifndef GS_INFO_H_INCLUDED
#define GS_INFO_H_INCLUDED

class gCInfo_PS;

class GE_DLLIMPORT Info
{
    protected:
        gCInfo_PS *m_pGameInfo;

    public:
         Info( gCInfo_PS * );
         Info( void );
        ~Info( void );

    public:
        Info & operator = ( Info const & );

    public:
        gEInfoCondType GetConditionType( void ) const;
        gEInfoType     GetInfoType( void ) const;
        GEBool         IsComment( void ) const;
        GEBool         IsImportant( void ) const;
        GEBool         IsValid( void ) const;

};

#endif
