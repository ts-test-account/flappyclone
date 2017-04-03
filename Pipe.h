#ifndef __PIPE__
#define __PIPE__

#include "cocos2d.h"

class Pipe
{
public:
    Pipe();

    void SpawnPipe( cocos2d::Layer* layer );

private:
    cocos2d::Size visibleSize;
    cocos2d::Point origin;
};


#endif /* defined(__LostinSpace__Pipe__) */
