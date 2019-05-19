#ifndef GE_COLORBASE_H_INCLUDED
#define GE_COLORBASE_H_INCLUDED

enum bEPixelFormat
{
    bEPixelFormat_RGB_555 = 1,
    bEPixelFormat_RGB_565,
    bEPixelFormat_RGBA_4444,
    bEPixelFormat_ARGB_1555,
    bEPixelFormat_RGBA_8888,
    bEPixelFormat_ARGB_8888,
    bEPixelFormat_RGB_888,
    bEPixelFormat_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4265 )// class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT bCColorBase
{
    public: virtual void        Clear( void )                     = 0;
    public: virtual bCIStream & operator << ( bCIStream & )       = 0;
    public: virtual bCOStream & operator >> ( bCOStream & ) const = 0;

    public:
        enum bEColor
        {
            //TODO: Name bCColorBase::bEColor constants.
            bEColor_Black,       // #000000
            bEColor_White,       // #FFFFFF
            bEColor_Silver,      // #C0C0C0
            bEColor_3,           // #AFAFAF
            bEColor_4,           // #7F7F7F
            bEColor_5,           // #4F4F4F
            bEColor_LightGrey,   // #D3D3D3
            bEColor_7,           // #808A87
            bEColor_8,           // #808069
            bEColor_Red,         // #FF0000
            bEColor_10,          // #AF0000
            bEColor_11,          // #7F0000
            bEColor_12,          // #4F0000
            bEColor_Lime,        // #00FF00
            bEColor_14,          // #00AF00
            bEColor_15,          // #007F00
            bEColor_16,          // #004F00
            bEColor_Blue,        // #0000FF
            bEColor_18,          // #0000AF
            bEColor_19,          // #00007F
            bEColor_20,          // #00004F
            bEColor_Cyan,        // #00FFFF
            bEColor_22,          // #00AFAF
            bEColor_23,          // #007F7F
            bEColor_24,          // #004F4F
            bEColor_Yellow,      // #FFFF00
            bEColor_26,          // #AFAF00
            bEColor_27,          // #7F7F00
            bEColor_28,          // #4F4F00
            bEColor_Magenta,     // #FF00FF
            bEColor_30,          // #AF00AF
            bEColor_31,          // #7F007F
            bEColor_32,          // #4F004F
            bEColor_33,          // #292421
            bEColor_34,          // #FF8000
            bEColor_35,          // #ED9121
            bEColor_36,          // #3B5E2B
            bEColor_37,          // #082E54
            bEColor_SkyBlue,     // #87CEEB
            bEColor_SteelBlue,   // #4682B4
            bEColor_Aquamarine,  // #7FFFD4
            bEColor_Gold,        // #FFD700
            bEColor_Orchid,      // #DA70D6
            bEColor_43,          // #A020F0
            bEColor_44,          // #8F5E99
            bEColor_45,          // #802A2A
            bEColor_46,          // #87421F
            bEColor_47,          // #733D1A
            bEColor_48,          // #A39480
            bEColor_49,          // #FF7D40
            bEColor_Khaki       // #F0E68C
        };

    public:
        bCColorBase( bCColorBase const & );

    public:
        bCColorBase & operator = ( bCColorBase const & );

    protected:
         bCColorBase( void );
        ~bCColorBase( void );

};

#pragma warning( pop )

#endif
