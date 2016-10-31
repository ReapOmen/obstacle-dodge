#ifndef __PADDLE_H__
#define __PADDLE_H__

#include "cocos2d.h"
#include "AbstractSprite.h"

class Paddle : public AbstractSprite
{
public:
    static const int LEFT = 0, MIDDLE = 1, RIGHT = 2;

    Paddle(const int type);

    virtual ~Paddle();

    virtual void update(float speed);
};


#endif // __PADDLE_H__
