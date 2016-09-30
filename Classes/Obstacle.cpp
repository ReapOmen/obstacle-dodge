#include "Obstacle.h"
#include "Paddle.h"
#include "Globals.h"

Obstacle::Obstacle(int type)
{
    AbstractSprite *absSpr = new AbstractSprite("paddle.png");
    height = absSpr->getHeight();
    halvedHeight = absSpr->getHalvedHeight();
    y = Globals::screenSize.height + halvedHeight;

    switch(type)
    {
        case NONE:
        {
            break;
        }
        case LEFT:
        {
            paddles.push_back(new Paddle(Paddle::LEFT));
            break;
        }
        case MIDDLE:
        {
            paddles.push_back(new Paddle(Paddle::MIDDLE));
            break;
        }
        case RIGHT:
        {
            paddles.push_back(new Paddle(Paddle::RIGHT));
            break;
        }
        case NO_LEFT:
        {
            paddles.push_back(new Paddle(Paddle::MIDDLE));
            paddles.push_back(new Paddle(Paddle::RIGHT));
            break;
        }
        case NO_MIDDLE:
        {
            paddles.push_back(new Paddle(Paddle::LEFT));
            paddles.push_back(new Paddle(Paddle::RIGHT));
            break;
        }
        case NO_RIGHT:
        {
            paddles.push_back(new Paddle(Paddle::LEFT));
            paddles.push_back(new Paddle(Paddle::MIDDLE));
            break;
        }
    };
}

Obstacle::~Obstacle()
{

}

std::vector<Paddle*> Obstacle::getPaddles() const
{
    return paddles;
}

void Obstacle::update()
{
    y -= Globals::paddleSpeed;
    for(Paddle *p : paddles)
        p->update(Globals::paddleSpeed);
}

float Obstacle::getY() const
{
    return y;
}

float Obstacle::getHeight() const
{
    return height;
}

float Obstacle::getHalvedHeight() const
{
    return halvedHeight;
}
