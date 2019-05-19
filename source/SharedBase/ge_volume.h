#ifndef GE_VOLUME_H_INCLUDED
#define GE_VOLUME_H_INCLUDED

class GE_DLLIMPORT bCVolume
{
    public: virtual void __purecall_1()  = 0;
    public: virtual void __purecall_2()  = 0;
    public: virtual void __purecall_3()  = 0;
    public: virtual void __purecall_4()  = 0;
    public: virtual void __purecall_5()  = 0;
    public: virtual void __purecall_6()  = 0;
    public: virtual void __purecall_7()  = 0;
    public: virtual void __purecall_8()  = 0;
    public: virtual void __purecall_9()  = 0;
    public: virtual void __purecall_10() = 0;
    public: virtual void __purecall_11() = 0;
    public: virtual void __purecall_12() = 0;
    public: virtual void __purecall_13() = 0;
    public: virtual void __purecall_14() = 0;
    public: virtual     ~bCVolume( void );

    public:
        bCVolume( bCVolume const & );
        bCVolume( void );

    public:
        bCVolume & operator = ( bCVolume const & );

};

template< typename T >
class bTVolume :
    public bCVolume
{

};

#include "ge_volume.inl"

#endif
