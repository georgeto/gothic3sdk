#ifndef GS_EFFECT_H_INCLUDED
#define GS_EFFECT_H_INCLUDED

class gCEffect;

class GE_DLLIMPORT Effect
{
    public:
        Effect & operator = ( Effect const & );

    private:
        Effect( Effect const & );
        Effect( gCEffect * );

    private:
        operator gCEffect * ( void ) const;

    private:
        gCEffect * m_pHandle;
};

GE_ASSERT_SIZEOF( Effect, 0x04 )

#endif
