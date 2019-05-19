#ifndef GE_FLEXIBLEVERTEXPTR_H_INCLUDED
#define GE_FLEXIBLEVERTEXPTR_H_INCLUDED

class GE_DLLIMPORT bCFlexibleVertexPtr
{

    public:
         bCFlexibleVertexPtr( bCFlexibleVertexPtr const & );
         bCFlexibleVertexPtr( void );
        ~bCFlexibleVertexPtr( void );

    public:
        bCFlexibleVertexPtr & operator =  ( bCFlexibleVertexPtr const & );
        GEBool                operator == ( bCFlexibleVertexPtr const & ) const;
        GEBool                operator != ( bCFlexibleVertexPtr const & ) const;
        bCFlexibleVertexPtr   operator ++ ( GEInt );
        bCFlexibleVertexPtr & operator ++ ( void );
        bCFlexibleVertexPtr   operator -- ( GEInt );
        bCFlexibleVertexPtr & operator -- ( void );
        bCFlexibleVertexPtr   operator -  ( GEInt );
        bCFlexibleVertexPtr   operator +  ( GEInt );
        bCFlexibleVertexPtr & operator += ( GEInt );
        bCFlexibleVertexPtr & operator -= ( GEInt );

    public:
        GELPByte &                     AccessBuffer( void );
        GEU32 &                        AccessDiffuse( void );
        bCFlexibleVertexFormat &       AccessFormat( void );
        bCVector &                     AccessNormal( void );
        GEFloat &                      AccessPointSize( void );
        bCVector &                     AccessPosition( void );
        GEFloat &                      AccessRHW( void );
        GEU32 &                        AccessSpecular( void );
        bCVector2 &                    AccessTextureCoords2( GEInt );
        bCVector &                     AccessTextureCoords3( GEInt );
        bCVector4 &                    AccessTextureCoords4( GEInt );
        GEFloat &                      AccessWeight( GEInt );
        GEFloat &                      AccessX( void );
        GEFloat &                      AccessY( void );
        GEFloat &                      AccessZ( void );
        void                           Advance( GEInt );
        void                           AttachTo( bCFlexibleVertexFormat const &, GELPByte );
        void                           CopyFrom( bCFlexibleVertexPtr const & );
        void                           CopyTo( bCFlexibleVertexPtr & ) const;
        GELPByte                       GetBuffer( void );
        GELPCByte                      GetBuffer( void ) const;
        void                           GetBuffer( GELPByte & ) const;
        GEU32                          GetDiffuse( void ) const;
        bCFlexibleVertexFormat const & GetFormat( void ) const;
        void                           GetFormat( bCFlexibleVertexFormat & ) const;
        bCVector                       GetNormal( void ) const;
        void                           GetNormal( bCVector & ) const;
        GEFloat                        GetPointSize( void ) const;
        bCVector                       GetPosition( void ) const;
        void                           GetPosition( bCVector2 & ) const;
        void                           GetPosition( bCVector & ) const;
        GEFloat                        GetRHW( void ) const;
        GEU32                          GetSpecular( void ) const;
        void                           GetTextureCoords( GEInt, bCVector2 & ) const;
        void                           GetTextureCoords( GEInt, bCVector4 & ) const;
        void                           GetTextureCoords( GEInt, bCVector & ) const;
        GEFloat                        GetWeight( GEInt ) const;
        GEFloat                        GetX( void ) const;
        GEFloat                        GetY( void ) const;
        GEFloat                        GetZ( void ) const;
        void                           Invalidate( void );
        GEBool                         IsBufferValid( void ) const;
        GEBool                         IsFormatValid( void ) const;
        GEBool                         IsValid( void ) const;
        void                           Rewind( GEInt );
        void                           SetAllTextureCoords( bCVector2 const & );
        void                           SetAllTextureCoords( bCVector4 const & );
        void                           SetAllTextureCoords( bCVector const & );
        void                           SetAllWeights( GEFloat );
        void                           SetBuffer( GELPByte );
        void                           SetDiffuse( GEU32 );
        void                           SetFormat( bCFlexibleVertexFormat const & );
        void                           SetFormat( GEU32 );
        void                           SetNormal( bCVector const & );
        void                           SetPointSize( GEFloat );
        void                           SetPosition( bCVector const & );
        void                           SetRHW( GEFloat );
        void                           SetSpecular( GEU32 );
        void                           SetTextureCoords( GEInt, bCVector2 const & );
        void                           SetTextureCoords( GEInt, bCVector4 const & );
        void                           SetTextureCoords( GEInt, bCVector const & );
        void                           SetWeight( GEInt, GEFloat );
        void                           SetX( GEFloat );
        void                           SetY( GEFloat );
        void                           SetZ( GEFloat );

};

#endif
