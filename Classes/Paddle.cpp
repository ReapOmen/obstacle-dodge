#include "Paddle.h"

USING_NS_CC;

Paddle::Paddle(Size windowSize, int type)
: AbstractSprite::AbstractSprite(windowSize, "paddle.png")
{
    if(type == MIDDLE)
    {
        setPosition(Vec2(windowSize.width / 2,
                         windowSize.height / 2));
    }
    else
    if(type == LEFT)
    {
        setPosition(Vec2(windowSize.width/2 - getHalvedWidth()*3,
                         windowSize.height / 2));
    }
    else
    if(type == RIGHT)
    {
        setPosition(Vec2(windowSize.width/2 + getHalvedWidth()*3,
                         windowSize.height / 2));
    }
}

Paddle::~Paddle()
{

}
