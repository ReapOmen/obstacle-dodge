#include "Paddle.h"
#include "Globals.h"

USING_NS_CC;

Paddle::Paddle(int type)
: AbstractSprite::AbstractSprite("paddle.png")
{
    Size windowSize = Globals::screenSize;

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

void Paddle::update(float speed)
{
    Vec2 pos = getPosition();
    setPosition(Vec2(pos.x, pos.y - speed));
}
