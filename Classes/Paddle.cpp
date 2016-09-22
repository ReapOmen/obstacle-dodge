#include "Paddle.h"

USING_NS_CC;

Paddle::Paddle(Size windowSize, int type)
: AbstractSprite::AbstractSprite(windowSize, "paddle.png")
{
    float offscreen_y = windowSize.height + getHalvedHeight();

    if(type == MIDDLE)
    {
        setPosition(Vec2(windowSize.width / 2,
                         offscreen_y));
    }
    else
    if(type == LEFT)
    {
        setPosition(Vec2(windowSize.width/2 - getHalvedWidth()*3,
                         offscreen_y));
    }
    else
    if(type == RIGHT)
    {
        setPosition(Vec2(windowSize.width/2 + getHalvedWidth()*3,
                         offscreen_y));
    }
}

Paddle::~Paddle()
{

}

void Paddle::update()
{
    Vec2 pos = getPosition();
    setPosition(Vec2(pos.x, pos.y - 10));
}
