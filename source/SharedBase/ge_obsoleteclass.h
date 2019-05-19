#ifndef GE_OBSOLETECLASS_H_INCLUDED
#define GE_OBSOLETECLASS_H_INCLUDED

class bCObsoleteClass :
    public bCObjectRefBase
{
    protected: virtual ~bCObsoleteClass( void );

    public:
        inline bCObsoleteClass & operator = ( bCObsoleteClass const & a_Object )
        {
            bCObjectRefBase:: operator = ( a_Object );
            return *this;
        }
};

#endif
