#ifndef GE_CONSOLEDATA_H_INCLUDED
#define GE_CONSOLEDATA_H_INCLUDED

class GE_DLLIMPORT eCConsoleData
{
    public: virtual ~eCConsoleData( void );

    public:
        eCConsoleData( eCConsoleData const & );
        eCConsoleData( void );

    public:
        eCConsoleData & operator = ( eCConsoleData const & );

    public:
        void Help( eCConsoleData *, GEInt );

};

#endif
