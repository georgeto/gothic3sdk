#ifndef GE_STRINGCONVERTER_H_INCLUDED
#define GE_STRINGCONVERTER_H_INCLUDED

class GE_DLLIMPORT bCStringConverter
{

    public:
        static bCString GE_STDCALL ConvertFloatsToString(bTSmallArray<GEFloat> const &);
        static GEBool GE_STDCALL ConvertStringToFloats(bCString const &,bTSmallArray<GEFloat> &);

    public:
        bCStringConverter & operator = ( bCStringConverter const & );

};

#endif
