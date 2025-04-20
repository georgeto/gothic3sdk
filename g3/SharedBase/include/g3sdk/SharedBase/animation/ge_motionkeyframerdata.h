#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;

class GE_DLLIMPORT bCMotionKeyFramerData
{
  public:
    bCMotionKeyFramerData(bCMotionKeyFramerData const &);
    bCMotionKeyFramerData();
    ~bCMotionKeyFramerData();

  public:
    bCMotionKeyFramerData const &operator=(bCMotionKeyFramerData const &);

  public:
    void ReadCAM(bCIStream &, GEInt, GEFloat);
};
