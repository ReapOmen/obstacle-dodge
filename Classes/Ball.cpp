#include "Ball.h"
#include "AbstractSprite.h"

USING_NS_CC;

Ball::Ball(Size windowSize)
: AbstractSprite::AbstractSprite(windowSize, "ball.png")
{
    maxLeft = windowSize.width / 3;
    maxRight = 2 * maxLeft;
    setPosition(Vec2(windowSize.width / 2, windowSize.height / 15));

    centered = true;
    centerPos = getX();
}

Ball::~Ball()
{

}

bool Ball::isCentered() const
{
    return centered;
}

void Ball::moveLeft()
{
    centered = false;
    Vec2 pos = getPosition();
    pos.x -= 10;
    if(pos.x > maxLeft)
        setPosition(pos);
}

void Ball::moveRight()
{
    centered = false;
    Vec2 pos = getPosition();
    pos.x += 10;
    if(pos.x < maxRight)
        setPosition(pos);
}

void Ball::moveToCenter()
{
    Vec2 pos = getPosition();
    if(pos.x > centerPos)
        pos.x -= 10;
    else
        if(pos.x < centerPos)
            pos.x += 10;
        else
            centered = true;
    setPosition(pos);
}
