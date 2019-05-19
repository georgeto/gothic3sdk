#ifndef GE_AXISANGLE_H_INCLUDED
#define GE_AXISANGLE_H_INCLUDED

class GE_DLLIMPORT bCAxisAngle
{

    public:
         bCAxisAngle( bCAxisAngle const & );
         bCAxisAngle( bCEulerAngles const & );
         bCAxisAngle( bCQuaternion const & );
         bCAxisAngle( void );
        ~bCAxisAngle( void );

    public:
        bCAxisAngle & operator =  ( bCAxisAngle const & );
        bCAxisAngle & operator =  ( bCEulerAngles const & );
        bCAxisAngle & operator =  ( bCQuaternion const & );
        bCOStream &   operator >> ( bCOStream & ) const;
        bCIStream &   operator << ( bCIStream & );
        GEBool        operator == ( bCAxisAngle const & ) const;
        GEBool        operator != ( bCAxisAngle const & ) const;

    public:
                         bCAxisAngle( bCVector const &, GEFloat );
        GEFloat &        AccessAngle( void );
        bCVector &       AccessAxis( void );
        void             Clear( void );
        GEFloat          GetAngle( void ) const;
        void             GetAngle( GEFloat & ) const;
        bCVector const & GetAxis( void ) const;
        void             GetAxis( bCVector & ) const;
        bCEulerAngles    GetEulerAngles( void ) const;
        bCQuaternion     GetQuaternion( void ) const;
        GEBool           IsEqual( bCAxisAngle const & ) const;
        void             SetAngle( GEFloat );
        void             SetAxis( bCVector const & );
        void             SetAxisAngle( bCAxisAngle const & );
        void             SetAxisAngle( bCEulerAngles const & );
        void             SetAxisAngle( bCQuaternion const & );
        void             SetAxisAngle( bCVector const &, GEFloat );

};

#endif
