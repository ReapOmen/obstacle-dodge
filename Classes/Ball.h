#ifndef __BALL_H__
#define __BALL_H__

#include "cocos2d.h"
#include "AbstractSprite.h"


class Ball : public AbstractSprite
{
public:
    Ball();

    virtual ~Ball();

    virtual void moveLeft();

    virtual void moveRight();

    virtual void moveToCenter();

    bool isCentered() const;

private:
    float maxRight_, maxLeft_, centerPos_;

    bool isCentered_;
};
#endif // __BALL_H__
