#ifndef GE_FLEXIBLEVERTEXFORMAT_H_INCLUDED
#define GE_FLEXIBLEVERTEXFORMAT_H_INCLUDED

class GE_DLLIMPORT bCFlexibleVertexFormat
{

    public:
        static GEInt GE_STDCALL GetMaxTextureStages( void );

    public:
         bCFlexibleVertexFormat( bCFlexibleVertexFormat const & );
         bCFlexibleVertexFormat( GEU32 );
        ~bCFlexibleVertexFormat( void );

    public:
        bCFlexibleVertexFormat & operator =     ( bCFlexibleVertexFormat const & );
        GEBool                   operator ==    ( bCFlexibleVertexFormat const & ) const;
        GEBool                   operator !=    ( bCFlexibleVertexFormat const & ) const;
                                 operator GEU32 ( void ) const;

    public:
        GEU32 & AccessFormat( void );
        void    CopyFrom( bCFlexibleVertexFormat const & );
        void    CopyTo( bCFlexibleVertexFormat & ) const;
        void    EnableDiffuse( GEBool );
        void    EnableNormal( GEBool );
        void    EnablePointSize( GEBool );
        void    EnableRHW( GEBool );
        void    EnableSpecular( GEBool );
        GEU32   GetFormat( void ) const;
        void    GetFormat( GEU32 & ) const;
        GEInt   GetOffsetDiffuse( void ) const;
        GEInt   GetOffsetNormal( void ) const;
        GEInt   GetOffsetPointSize( void ) const;
        GEInt   GetOffsetRHW( void ) const;
        GEInt   GetOffsetSpecular( void ) const;
        GEInt   GetOffsetTextureCoord( GEInt, GEInt ) const;
        GEInt   GetOffsetTextureCoords( GEInt ) const;
        GEInt   GetOffsetTextureCoords( void ) const;
        GEInt   GetOffsetWeight( GEInt ) const;
        GEInt   GetOffsetWeights( void ) const;
        GEInt   GetOffsetX( void ) const;
        GEInt   GetOffsetXYZ( void ) const;
        GEInt   GetOffsetY( void ) const;
        GEInt   GetOffsetZ( void ) const;
        GEInt   GetTextureCoordCount( GEInt ) const;
        GEInt   GetTextureStageCount( void ) const;
        GEInt   GetVertexByteCount( void ) const;
        GEInt   GetWeightCount( void ) const;
        GEBool  HasDiffuse( void ) const;
        GEBool  HasNormal( void ) const;
        GEBool  HasPointSize( void ) const;
        GEBool  HasRHW( void ) const;
        GEBool  HasSpecular( void ) const;
        GEBool  HasWeight( GEInt ) const;
        GEBool  HasXYZ( void ) const;
        GEBool  IsTransformedAndLit( void ) const;
        GEBool  IsValid( void ) const;
        GEBool  MatchesMask( GEU32 ) const;
        void    ModifyStyle( GEU32, GEU32 );
        void    SetFormat( GEU32 );
        void    SetTextureCoordCount( GEInt, GEInt );
        void    SetTextureStageCount( GEInt );
        void    SetWeightCount( GEInt );

};

#endif
