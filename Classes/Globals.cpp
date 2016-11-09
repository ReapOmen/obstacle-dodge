#include "Globals.h"
#include "AbstractSprite.h"

USING_NS_CC;

Size Globals::screenSize = Director::getInstance()->getVisibleSize();
float Globals::paddleY = 0.0f;
float Globals::paddleHeight = 0.0f;
float Globals::paddleHalvedHeight = 0.0f;
float Globals::scaleObjects = 0.0f;
float Globals::scaleButtons = 0.0f;
float Globals::ballSpeed = 0.0f;
float Globals::paddleSpeed = 0.0f;

void Globals::init()
{
    screenSize = Director::getInstance()->getVisibleSize();
    AbstractSprite *paddle = new AbstractSprite("paddle.png");
    paddleHeight = paddle->getHeight();
    paddleHalvedHeight = paddle->getHalvedHeight();
    paddleY = paddle->getY();
    scaleObjects = (0.2 * screenSize.width) / 1024;
    scaleButtons = (0.5 * screenSize.width) / 1024;
    ballSpeed = (10 * screenSize.width) / 1024;
    paddleSpeed = (10 * screenSize.height) / 768;
}
