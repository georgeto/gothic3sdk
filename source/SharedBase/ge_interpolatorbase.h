#ifndef GE_INTERPOLATORBASE_H_INCLUDED
#define GE_INTERPOLATORBASE_H_INCLUDED

enum bEInterpolator;

#pragma warning( push )
#pragma warning( disable : 4265 )// class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT bCInterpolatorBase
{
    public: virtual void __purecall_1() = 0;
    public: virtual void __purecall_2() = 0;
    public: virtual void __purecall_3() = 0;
    public: virtual void __purecall_4() = 0;
    public: virtual void __purecall_5() = 0;
    public: virtual void __purecall_6() = 0;
    public: virtual void __purecall_7() = 0;
    public: virtual void __purecall_8() = 0;

    public:
         bCInterpolatorBase( void );
        ~bCInterpolatorBase( void );

    public:
        bCOStream & operator >> ( bCOStream & );
        bCIStream & operator << ( bCIStream & );

    public:
        GEInt          GetFrameBegin( void ) const;
        void           GetFrameBegin( GEInt & ) const;
        GEInt          GetFrameCount( void ) const;
        void           GetFrameCount( GEInt & ) const;
        GEInt          GetFrameEnd( void ) const;
        void           GetFrameEnd( GEInt & ) const;
        bEInterpolator GetType( void ) const;
        void           GetType( bEInterpolator & ) const;
        void           SetFrameBegin( GEInt );
        void           SetFrameEnd( GEInt );

    protected:
        bCInterpolatorBase( bCInterpolatorBase const & );

    protected:
        bCInterpolatorBase const & operator = ( bCInterpolatorBase const & );

    protected:
        GEInt &          AccessFrameBegin( void );
        GEInt &          AccessFrameEnd( void );
        bEInterpolator & AccessType( void );
        void             SetType( bEInterpolator );

};

#pragma warning( pop )

#endif
