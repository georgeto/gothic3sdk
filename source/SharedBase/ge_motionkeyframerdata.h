#ifndef GE_MOTIONKEYFRAMERDATA_H_INCLUDED
#define GE_MOTIONKEYFRAMERDATA_H_INCLUDED

class GE_DLLIMPORT bCMotionKeyFramerData
{

    public:
         bCMotionKeyFramerData( bCMotionKeyFramerData const & );
         bCMotionKeyFramerData( void );
        ~bCMotionKeyFramerData( void );

    public:
        bCMotionKeyFramerData const & operator = ( bCMotionKeyFramerData const & );

    public:
        void ReadCAM( bCIStream &, GEInt, GEFloat );

};

#endif
