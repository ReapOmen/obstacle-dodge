#ifndef __PADDLE_H__
#define __PADDLE_H__

#include "cocos2d.h"
#include "AbstractSprite.h"

class Paddle : public AbstractSprite
{
public:
    Paddle(cocos2d::Size windowSize);

    virtual ~Paddle();
};


#endif // __PADDLE_H__
