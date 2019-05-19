#ifndef GE_QUATERNION_H_INCLUDED
#define GE_QUATERNION_H_INCLUDED

class GE_DLLIMPORT bCQuaternion
{
    private:
        GEFloat m_fX;
        GEFloat m_fY;
        GEFloat m_fZ;
        GEFloat m_fW;

    public:
         bCQuaternion( bCQuaternion const & );
         bCQuaternion( bCAxisAngle const & );
         bCQuaternion( bCEulerAngles const & );
         bCQuaternion( bCMatrix3 const & );
         bCQuaternion( bCMatrix const & );
         bCQuaternion( bCSphericalRotation const & );
         bCQuaternion( void );
        ~bCQuaternion( void );

    public:
        bCQuaternion & operator =  ( bCQuaternion const & );
        bCQuaternion & operator =  ( bCAxisAngle const & );
        bCQuaternion & operator =  ( bCEulerAngles const & );
        bCQuaternion & operator =  ( bCMatrix3 const & );
        bCQuaternion & operator =  ( bCMatrix const & );
        bCQuaternion & operator =  ( bCSphericalRotation const & );
        bCOStream &    operator >> ( bCOStream & ) const;
        bCIStream &    operator << ( bCIStream & );
        GEBool         operator == ( bCQuaternion const & ) const;
        GEBool         operator != ( bCQuaternion const & ) const;
        bCQuaternion   operator *  ( bCQuaternion const & ) const;
        bCQuaternion   operator *  ( GEFloat ) const;
        bCQuaternion   operator -  ( bCQuaternion const & ) const;
        bCQuaternion   operator -  ( void ) const;
        bCQuaternion   operator +  ( bCQuaternion const & ) const;
        bCQuaternion   operator /  ( GEFloat ) const;
        bCQuaternion   operator ~  ( void ) const;
        bCQuaternion & operator *= ( bCQuaternion const & );
        bCQuaternion & operator *= ( GEFloat );
        bCQuaternion & operator += ( bCQuaternion const & );
        bCQuaternion & operator -= ( bCQuaternion const & );
        bCQuaternion & operator /= ( GEFloat );

    public:
                            bCQuaternion( GEFloat, GEFloat, GEFloat, GEFloat );
        GEFloat &           AccessW( void );
        GEFloat &           AccessX( void );
        GEFloat &           AccessY( void );
        GEFloat &           AccessZ( void );
        void                Add( bCQuaternion const & );
        void                Clear( void );
        bCAxisAngle         GetAxisAngle( void ) const;
        void                GetAxisAngle( bCAxisAngle & ) const;
        bCQuaternion        GetDifference( bCQuaternion const & ) const;
        void                GetDifference( bCQuaternion &, bCQuaternion const & ) const;
        GEFloat             GetDotProduct( bCQuaternion const & ) const;
        bCEulerAngles       GetEulerAngles( void ) const;
        void                GetEulerAngles( bCEulerAngles & ) const;
        bCQuaternion        GetInverted( void ) const;
        void                GetInverted( bCQuaternion & ) const;
        bCQuaternion        GetLerp( bCQuaternion const &, GEFloat ) const;
        GEFloat             GetMagnitude( void ) const;
        bCMatrix3           GetMatrix3( void ) const;
        void                GetMatrix3( bCMatrix3 & ) const;
        bCMatrix            GetMatrix( void ) const;
        void                GetMatrix( bCMatrix & ) const;
        bCQuaternion        GetNegated( void ) const;
        void                GetNegated( bCQuaternion & ) const;
        bCQuaternion        GetNormalized( void ) const;
        void                GetNormalized( bCQuaternion & ) const;
        bCQuaternion        GetProduct( bCQuaternion const & ) const;
        bCQuaternion        GetProduct( GEFloat ) const;
        void                GetProduct( bCQuaternion &, bCQuaternion const & ) const;
        void                GetProduct( bCQuaternion &, GEFloat ) const;
        bCQuaternion        GetReverseProduct( bCQuaternion const & ) const;
        void                GetReverseProduct( bCQuaternion &, bCQuaternion const & ) const;
        bCQuaternion        GetRotatedAxisX( GEFloat ) const;
        void                GetRotatedAxisX( bCQuaternion &, GEFloat ) const;
        bCQuaternion        GetRotatedAxisY( GEFloat ) const;
        void                GetRotatedAxisY( bCQuaternion &, GEFloat ) const;
        bCQuaternion        GetRotatedAxisZ( GEFloat ) const;
        void                GetRotatedAxisZ( bCQuaternion &, GEFloat ) const;
        bCQuaternion        GetRotatedLocalAxisX( GEFloat ) const;
        void                GetRotatedLocalAxisX( bCQuaternion &, GEFloat ) const;
        bCQuaternion        GetRotatedLocalAxisY( GEFloat ) const;
        void                GetRotatedLocalAxisY( bCQuaternion &, GEFloat ) const;
        bCQuaternion        GetRotatedLocalAxisZ( GEFloat ) const;
        void                GetRotatedLocalAxisZ( bCQuaternion &, GEFloat ) const;
        bCQuaternion        GetSlerp( bCQuaternion const &, GEFloat ) const;
        bCSphericalRotation GetSphericalRotation( void ) const;
        void                GetSphericalRotation( bCSphericalRotation & ) const;
        GEFloat             GetSquareMagnitude( void ) const;
        bCQuaternion        GetSum( bCQuaternion const & ) const;
        void                GetSum( bCQuaternion &, bCQuaternion const & ) const;
        bCVector            GetTransformedVector( bCVector const & ) const;
        GEFloat             GetW( void ) const;
        void                GetW( GEFloat & ) const;
        GEFloat             GetX( void ) const;
        void                GetX( GEFloat & ) const;
        GEFloat             GetY( void ) const;
        void                GetY( GEFloat & ) const;
        GEFloat             GetZ( void ) const;
        void                GetZ( GEFloat & ) const;
        void                Invert( void );
        GEBool              IsEqual( bCQuaternion const & ) const;
        GEBool              IsNormalized( void ) const;
        void                Multiply( bCQuaternion const & );
        void                Multiply( GEFloat );
        void                Negate( void );
        void                Normalize( void );
        void                ReverseMultiply( bCQuaternion const & );
        void                RotateAxis( bCVector const &, GEFloat );
        void                RotateAxisX( GEFloat );
        void                RotateAxisY( GEFloat );
        void                RotateAxisZ( GEFloat );
        void                RotateLocalAxisX( GEFloat );
        void                RotateLocalAxisY( GEFloat );
        void                RotateLocalAxisZ( GEFloat );
        void                SetLerp( bCQuaternion, bCQuaternion const &, GEFloat );
        void                SetQuaternion( bCQuaternion const & );
        void                SetQuaternion( bCAxisAngle const & );
        void                SetQuaternion( bCEulerAngles const & );
        void                SetQuaternion( bCMatrix3 const & );
        void                SetQuaternion( bCMatrix const & );
        void                SetQuaternion( bCSphericalRotation const & );
        void                SetQuaternion( bCVector const &, bCVector const & );
        void                SetQuaternion( GEFloat, GEFloat, GEFloat, GEFloat );
        void                SetSlerp( bCQuaternion, bCQuaternion, GEFloat );
        void                SetToProduct( bCQuaternion const &, bCQuaternion const & );
        void                SetW( GEFloat );
        void                SetX( GEFloat );
        void                SetY( GEFloat );
        void                SetZ( GEFloat );
        void                Sub( bCQuaternion const & );

};

#endif
