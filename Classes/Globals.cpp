#include "Globals.h"
#include "AbstractSprite.h"

USING_NS_CC;

Size Globals::screenSize = Director::getInstance()->getVisibleSize();
float Globals::paddleY = 0.0f;
float Globals::paddleHeight = 0.0f;
float Globals::paddleHalvedHeight = 0.0f;

void Globals::init()
{
    screenSize = Director::getInstance()->getVisibleSize();
    AbstractSprite *paddle = new AbstractSprite("paddle.png");
    paddleHeight = paddle->getHeight();
    paddleHalvedHeight = paddle->getHalvedHeight();
    paddleY = paddle->getY();
}
