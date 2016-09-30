#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "cocos2d.h"

class Globals
{
public:
    static void init();
    static cocos2d::Size screenSize;
    static float paddleHeight, paddleHalvedHeight, paddleY;
    static float scaleObjects, scaleButtons;
    static float ballSpeed, paddleSpeed;
};

#endif // __GLOBALS_H__
