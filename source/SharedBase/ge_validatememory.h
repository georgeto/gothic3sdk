#ifndef GE_VALIDATEMEMORY_H_INCLUDED
#define GE_VALIDATEMEMORY_H_INCLUDED

class GE_DLLIMPORT bCValidateMemory
{

    public:
        static bCValidateMemory & GE_STDCALL GetInstance( void );

    public:
        bCValidateMemory & operator = ( bCValidateMemory const & );

    public:
        GEBool GetBreakOnError( void ) const;
        GEBool GetFatalErrorOnError( void ) const;
        GEBool GetTraceOnError( void ) const;
        GEBool GetWarningMessageOnError( void ) const;
        void   SetBreakOnError( GEBool );
        void   SetFatalErrorOnError( GEBool );
        void   SetTraceOnError( GEBool );
        void   SetWarningMessageOnError( GEBool );
        void   Validate( void );

    protected:
         bCValidateMemory( void );
        ~bCValidateMemory( void );

    protected:
             bCValidateMemory( GEBool, GEBool, GEBool, GEBool );
        void Invalidate( void );

};

#endif
