#include "Obstacle.h"
#include "Paddle.h"
#include "Globals.h"

Obstacle::Obstacle(int type)
{
    AbstractSprite *absSpr = new AbstractSprite("paddle.png");
    height_ = absSpr->getHeight();
    halvedHeight_ = absSpr->getHalvedHeight();
    y_ = Globals::screenSize.height + halvedHeight_;

    switch(type)
    {
        case NONE:
        {
            break;
        }
        case LEFT:
        {
            paddles_.push_back(new Paddle(Paddle::LEFT));
            break;
        }
        case MIDDLE:
        {
            paddles_.push_back(new Paddle(Paddle::MIDDLE));
            break;
        }
        case RIGHT:
        {
            paddles_.push_back(new Paddle(Paddle::RIGHT));
            break;
        }
        case NO_LEFT:
        {
            paddles_.push_back(new Paddle(Paddle::MIDDLE));
            paddles_.push_back(new Paddle(Paddle::RIGHT));
            break;
        }
        case NO_MIDDLE:
        {
            paddles_.push_back(new Paddle(Paddle::LEFT));
            paddles_.push_back(new Paddle(Paddle::RIGHT));
            break;
        }
        case NO_RIGHT:
        {
            paddles_.push_back(new Paddle(Paddle::LEFT));
            paddles_.push_back(new Paddle(Paddle::MIDDLE));
            break;
        }
    };
}

Obstacle::~Obstacle()
{

}

std::vector<Paddle*> Obstacle::getPaddles() const
{
    return paddles_;
}

void Obstacle::update()
{
    y_ -= Globals::paddleSpeed;
    for(Paddle *p : paddles_)
        p->update(Globals::paddleSpeed);
}

float Obstacle::getY() const
{
    return y_;
}

float Obstacle::getHeight() const
{
    return height_;
}

float Obstacle::getHalvedHeight() const
{
    return halvedHeight_;
}
