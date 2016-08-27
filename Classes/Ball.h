#ifndef __BALL_H__
#define __BALL_H__

#include "cocos2d.h"
#include "AbstractSprite.h"


class Ball : public AbstractSprite
{
private:
    float maxRight, maxLeft, centerPos;

    bool centered;

public:
    Ball(cocos2d::Size windowSize);

    virtual ~Ball();

    virtual void moveLeft();

    virtual void moveRight();

    virtual void moveToCenter();

    bool isCentered() const;
};
#endif // __BALL_H__
