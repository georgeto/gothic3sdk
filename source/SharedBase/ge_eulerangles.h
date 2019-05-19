#ifndef GE_EULERANGLES_H_INCLUDED
#define GE_EULERANGLES_H_INCLUDED

class GE_DLLIMPORT bCEulerAngles
{
    private:
        GEFloat m_fYaw;
        GEFloat m_fPitch;
        GEFloat m_fRoll;

    public:
         bCEulerAngles( bCEulerAngles const & );
         bCEulerAngles( bCAxisAngle const & );
         bCEulerAngles( bCQuaternion const & );
         bCEulerAngles( bCVector const & );
         bCEulerAngles( void );
        ~bCEulerAngles( void );

    public:
        bCEulerAngles &     operator =  ( bCEulerAngles const & );
        bCOStream &         operator >> ( bCOStream & ) const;
        bCIStream &         operator << ( bCIStream & );
        GEBool              operator == ( bCEulerAngles const & ) const;
        GEBool              operator != ( bCEulerAngles const & ) const;
        GEFloat &           operator [] ( GEInt );
        GEFloat             operator [] ( GEInt ) const;
        bCEulerAngles const operator *  ( GEFloat ) const;
        bCEulerAngles const operator -  ( bCEulerAngles const & ) const;
        bCEulerAngles const operator -  ( void ) const;
        bCEulerAngles const operator +  ( bCEulerAngles const & ) const;
        bCEulerAngles &     operator *= ( GEFloat );
        bCEulerAngles &     operator += ( bCEulerAngles const & );
        bCEulerAngles &     operator -= ( bCEulerAngles const & );

    public:
                     bCEulerAngles( GEFloat, GEFloat, GEFloat );
        GEFloat &    AccessPitch( void );
        GEFloat &    AccessRoll( void );
        GEFloat &    AccessYaw( void );
        void         Clear( void );
        bCAxisAngle  GetAxisAngle( void ) const;
        GEFloat      GetPitch( void ) const;
        void         GetPitch( GEFloat & ) const;
        bCQuaternion GetQuaternion( void ) const;
        GEFloat      GetRoll( void ) const;
        void         GetRoll( GEFloat & ) const;
        GEFloat      GetYaw( void ) const;
        void         GetYaw( GEFloat & ) const;
        void         SetEulerAngles( bCEulerAngles const & );
        void         SetEulerAngles( bCAxisAngle const & );
        void         SetEulerAngles( bCMatrix const & );
        void         SetEulerAngles( bCQuaternion const & );
        void         SetEulerAngles( GEFloat, GEFloat, GEFloat );
        void         SetPitch( GEFloat );
        void         SetRoll( GEFloat );
        void         SetYaw( GEFloat );

};

#endif
