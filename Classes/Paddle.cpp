#include "Paddle.h"

USING_NS_CC;

Paddle::Paddle(Size windowSize)
: AbstractSprite::AbstractSprite(windowSize, "paddle.png")
{
    setPosition(Vec2(windowSize.width / 2, windowSize.height / 2));
}

Paddle::~Paddle()
{

}
