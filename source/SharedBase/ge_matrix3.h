#ifndef GE_MATRIX3_H_INCLUDED
#define GE_MATRIX3_H_INCLUDED

class GE_DLLIMPORT bCMatrix3
{
    enum bEElement
    {
        bEElement_11,
        bEElement_12,
        bEElement_13,
        bEElement_21,
        bEElement_22,
        bEElement_23,
        bEElement_31,
        bEElement_32,
        bEElement_33,
        bEElement_Count,
        bEElement_ForceDWORD = GE_FORCE_DWORD
    };
    enum bERow
    {
        bERow_XAxis,
        bERow_YAxis,
        bERow_ZAxis,
        bERow_Count,
        bERow_ForceDWORD = GE_FORCE_DWORD
    };
    enum bEColumn
    {
        bEColumn_X,
        bEColumn_Y,
        bEColumn_Z,
        bEColumn_Count,
        bEColumn_ForceDWORD = GE_FORCE_DWORD
    };
    private:
        union
        {
            GEFloat m_fElements[ bEElement_Count ];
            GEFloat m_fRowColumn[ bERow_Count ][ bEColumn_Count ];
        };

    public:
        static bCMatrix3 GE_STDCALL GetIdentity( void );
        static void GE_STDCALL      GetIdentity( bCMatrix3 & );

    public:
         bCMatrix3( bCQuaternion & );
         bCMatrix3( bCMatrix3 const & );
         bCMatrix3( bCMatrix const & );
         bCMatrix3( bCQuaternion const & );
         bCMatrix3( GEFloat );
         bCMatrix3( GEFloat const * const );
         bCMatrix3( bCVector const * const );
         bCMatrix3( void );
        ~bCMatrix3( void );

    public:
        bCMatrix3 &      operator =  ( bCMatrix3 const & );
        bCOStream &      operator >> ( bCOStream & ) const;
        bCIStream &      operator << ( bCIStream & );
        GEBool           operator == ( bCMatrix3 const & ) const;
        GEBool           operator != ( bCMatrix3 const & ) const;
        GEFloat &        operator [] ( GEInt );
        GEFloat          operator [] ( GEInt ) const;
        bCMatrix3        operator *  ( bCMatrix3 const & ) const;
        bCMatrix3        operator *  ( bCAxisAngle const & ) const;
        bCMatrix3        operator *  ( bCEulerAngles const & ) const;
        bCMatrix3        operator *  ( bCQuaternion const & ) const;
        bCMatrix3        operator *  ( GEFloat ) const;
        bCVector         operator *  ( bCVector const & ) const;
        bCMatrix3        operator -  ( bCMatrix3 const & ) const;
        bCMatrix3        operator -  ( void ) const;
        bCMatrix3        operator +  ( bCMatrix3 const & ) const;
        bCMatrix3        operator /  ( GEFloat ) const;
        GEFloat &        operator () ( GEInt, GEInt );
        bCVector &       operator () ( GEInt );
        bCVector const & operator () ( GEInt ) const;
        GEFloat          operator () ( GEInt, GEInt ) const;
        bCMatrix3        operator ~  ( void ) const;
        bCMatrix3 &      operator *= ( bCMatrix3 const & );
        bCMatrix3 &      operator *= ( bCAxisAngle const & );
        bCMatrix3 &      operator *= ( bCEulerAngles const & );
        bCMatrix3 &      operator *= ( bCQuaternion const & );
        bCMatrix3 &      operator *= ( GEFloat );
        bCMatrix3 &      operator += ( bCMatrix3 const & );
        bCMatrix3 &      operator -= ( bCMatrix3 const & );
        bCMatrix3 &      operator /= ( GEFloat );

    public:
                         bCMatrix3( GEFloat const (*const)[3] );
        GEFloat &        AccessElement( GEInt );
        GEFloat &        AccessElement( GEInt, GEInt );
        bCVector &       AccessRow( GEInt );
        bCVector &       AccessXAxis( void );
        bCVector &       AccessYAxis( void );
        bCVector &       AccessZAxis( void );
        void             Add( bCMatrix3 const & );
        void             Clear( void );
        void             Divide( GEFloat );
        bCVector         GetColumn( GEInt ) const;
        void             GetColumn( GEInt, bCVector & ) const;
        void             GetColumn( GEInt, GEFloat * const ) const;
        GEFloat          GetDeterminant( void ) const;
        GEFloat          GetDeterminantAdjoint( int, int ) const;
        bCMatrix3        GetDifference( bCMatrix3 const & ) const;
        void             GetDifference( bCMatrix3 &, bCMatrix3 const & ) const;
        GEFloat          GetElement( GEInt ) const;
        GEFloat          GetElement( GEInt, GEInt ) const;
        void             GetElement( GEInt, GEFloat & ) const;
        void             GetElement( GEInt, GEInt, GEFloat & ) const;
        bCMatrix3        GetInverted( void ) const;
        void             GetInverted( bCMatrix3 & ) const;
        bCMatrix3        GetNegated( void ) const;
        void             GetNegated( bCMatrix3 & ) const;
        bCMatrix3        GetOrthogonalized( void ) const;
        void             GetOrthogonalized( bCMatrix3 & ) const;
        bCMatrix3        GetOrthonormalized( void ) const;
        void             GetOrthonormalized( bCMatrix3 & ) const;
        bCMatrix3        GetProduct( bCMatrix3 const & ) const;
        bCMatrix3        GetProduct( GEFloat ) const;
        void             GetProduct( bCMatrix3 &, bCMatrix3 const & ) const;
        void             GetProduct( bCMatrix3 &, GEFloat ) const;
        bCMatrix3        GetProductPrefix( bCMatrix3 const & ) const;
        void             GetProductPrefix( bCMatrix3 &, bCMatrix3 const & ) const;
        bCMatrix3        GetQuotient( GEFloat ) const;
        void             GetQuotient( bCMatrix3 &, GEFloat ) const;
        bCMatrix3        GetRotated( bCAxisAngle const & ) const;
        bCMatrix3        GetRotated( bCEulerAngles const & ) const;
        bCMatrix3        GetRotated( bCQuaternion const & ) const;
        void             GetRotated( bCMatrix3 &, bCAxisAngle const & ) const;
        void             GetRotated( bCMatrix3 &, bCEulerAngles const & ) const;
        void             GetRotated( bCMatrix3 &, bCQuaternion const & ) const;
        bCMatrix3        GetRotatedAxisX( GEFloat ) const;
        void             GetRotatedAxisX( bCMatrix3 &, GEFloat ) const;
        bCMatrix3        GetRotatedAxisY( GEFloat ) const;
        void             GetRotatedAxisY( bCMatrix3 &, GEFloat ) const;
        bCMatrix3        GetRotatedAxisZ( GEFloat ) const;
        void             GetRotatedAxisZ( bCMatrix3 &, GEFloat ) const;
        bCMatrix3        GetRotatedLocal( bCAxisAngle const & ) const;
        bCMatrix3        GetRotatedLocal( bCEulerAngles const & ) const;
        bCMatrix3        GetRotatedLocal( bCQuaternion const & ) const;
        void             GetRotatedLocal( bCMatrix3 &, bCAxisAngle const & ) const;
        void             GetRotatedLocal( bCMatrix3 &, bCEulerAngles const & ) const;
        void             GetRotatedLocal( bCMatrix3 &, bCQuaternion const & ) const;
        bCMatrix3        GetRotatedLocalAxisX( GEFloat ) const;
        void             GetRotatedLocalAxisX( bCMatrix3 &, GEFloat ) const;
        bCMatrix3        GetRotatedLocalAxisY( GEFloat ) const;
        void             GetRotatedLocalAxisY( bCMatrix3 &, GEFloat ) const;
        bCMatrix3        GetRotatedLocalAxisZ( GEFloat ) const;
        void             GetRotatedLocalAxisZ( bCMatrix3 &, GEFloat ) const;
        bCVector const & GetRow( GEInt ) const;
        void             GetRow( GEInt, bCVector & ) const;
        void             GetRow( GEInt, GEFloat * const ) const;
        bCMatrix3        GetSum( bCMatrix3 const & ) const;
        void             GetSum( bCMatrix3 &, bCMatrix3 const & ) const;
        bCMatrix3        GetTransposed( void ) const;
        void             GetTransposed( bCMatrix3 & ) const;
        bCVector const & GetXAxis( void ) const;
        void             GetXAxis( bCVector & ) const;
        bCVector const & GetYAxis( void ) const;
        void             GetYAxis( bCVector & ) const;
        bCVector const & GetZAxis( void ) const;
        void             GetZAxis( bCVector & ) const;
        void             Invert( void );
        GEBool           IsEqual( bCMatrix3 const & ) const;
        GEBool           IsIdentity( void ) const;
        void             LookAt( bCVector const &, bCVector const & );
        void             LookAt( bCVector const & );
        void             ModifyXAxis( bCVector const & );
        void             ModifyYAxis( bCVector const & );
        void             ModifyZAxis( bCVector const & );
        void             Multiply( bCMatrix3 const & );
        void             Multiply( GEFloat );
        void             Negate( void );
        void             Orthogonalize( void );
        void             Orthonormalize( void );
        void             ReverseMultiply( bCMatrix3 const & );
        void             Rotate( bCAxisAngle const & );
        void             Rotate( bCEulerAngles const & );
        void             Rotate( bCQuaternion const & );
        void             RotateAxisX( GEFloat );
        void             RotateAxisY( GEFloat );
        void             RotateAxisZ( GEFloat );
        void             RotateLocal( bCAxisAngle const & );
        void             RotateLocal( bCEulerAngles const & );
        void             RotateLocal( bCQuaternion const & );
        void             RotateLocalAxisX( GEFloat );
        void             RotateLocalAxisY( GEFloat );
        void             RotateLocalAxisZ( GEFloat );
        void             Scale( bCVector const & );
        void             Scale( GEFloat );
        void             SetElement( GEInt, GEInt, GEFloat );
        void             SetElement( GEInt, GEFloat );
        void             SetIdentity( void );
        void             SetMatrix( bCMatrix3 const & );
        void             SetMatrix( bCMatrix const & );
        void             SetMatrix( GEFloat );
        void             SetMatrix( GEFloat const (*const)[3] );
        void             SetMatrix( GEFloat const * const );
        void             SetMatrix( bCVector const * const );
        void             SetRow( GEInt, bCVector const & );
        void             SetRow( GEInt, GEFloat const * const );
        void             SetToCrossProduct( bCVector const & );
        void             SetToInverse( bCMatrix3 const & );
        void             SetToProduct( bCMatrix3 const &, bCMatrix3 const & );
        void             SetToRotation( bCAxisAngle const & );
        void             SetToRotation( bCEulerAngles const & );
        void             SetToRotation( bCQuaternion const & );
        void             SetToRotationAxisX( GEFloat );
        void             SetToRotationAxisY( GEFloat );
        void             SetToRotationAxisZ( GEFloat );
        void             SetToScaling( bCVector const & );
        void             SetToScaling( GEFloat );
        void             Sub( bCMatrix3 const & );
        void             Transpose( void );

};

#endif
