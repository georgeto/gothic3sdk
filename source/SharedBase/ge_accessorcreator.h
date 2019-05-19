#ifndef GE_ACCESSORCREATOR_H_INCLUDED
#define GE_ACCESSORCREATOR_H_INCLUDED

class GE_DLLIMPORT bCAccessorCreator
{

    public:
         bCAccessorCreator( bCAccessorCreator const & );
         bCAccessorCreator( bCString const & );
         bCAccessorCreator( bCPropertyObjectBase * );
        ~bCAccessorCreator( void );

    public:
        bCAccessorCreator const &    operator =                            ( bCAccessorCreator const & );
                                     operator bCPropertyObjectBase *       ( void );
                                     operator bCPropertyObjectBase const * ( void ) const;
        bCPropertyObjectBase *       operator ->                           ( void );
        bCPropertyObjectBase const * operator ->                           ( void ) const;

    public:
                                        bCAccessorCreator( bCPropertyID const &, bCString const * );
        bCAccessorCreator               Clone( void ) const;
        void                            CopyFrom( bCAccessorCreator const & );
        void                            CopyTo( bCAccessorCreator & ) const;
        bCPropertyObjectFactory *       GetObjectFactory( void );
        bCPropertyObjectFactory const * GetObjectFactory( void ) const;
        GEBool                          HasBaseClass( void ) const;
        void                            Invalidate( void );
        GEBool                          IsValid( void ) const;
        bCAccessorCreator               QueryBaseClass( void );
        void                            SetInstance( bCPropertyObjectBase * );

    protected:
        bCAccessorCreator( void );

    private:
        GE_PADDING(4);

};

GE_ASSERT_SIZEOF(bCAccessorCreator, 4);

#endif
