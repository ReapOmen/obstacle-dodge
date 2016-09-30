#include "Ball.h"
#include "AbstractSprite.h"
#include "Globals.h"

USING_NS_CC;

Ball::Ball()
: AbstractSprite::AbstractSprite("ball.png")
{
    Size windowSize = Globals::screenSize;
    maxLeft_ = windowSize.width / 3;
    maxRight_ = 2 * maxLeft_;
    setPosition(Vec2(windowSize.width / 2, windowSize.height / 15));

    isCentered_ = true;
    centerPos_ = getX();
}

Ball::~Ball()
{

}

void Ball::moveLeft()
{
    isCentered_ = false;
    Vec2 pos = getPosition();
    pos.x -= Globals::ballSpeed;
    if(pos.x > maxLeft_)
        setPosition(pos);
}

void Ball::moveRight()
{
    isCentered_ = false;
    Vec2 pos = getPosition();
    pos.x += Globals::ballSpeed;
    if(pos.x < maxRight_)
        setPosition(pos);
}

void Ball::moveToCenter()
{
    Vec2 pos = getPosition();
    if(pos.x > centerPos_)
        pos.x -= Globals::ballSpeed;
    else
        if(pos.x < centerPos_)
            pos.x += Globals::ballSpeed;
        else
            isCentered_ = true;
    setPosition(pos);
}

bool Ball::isCentered() const
{
    return isCentered_;
}
