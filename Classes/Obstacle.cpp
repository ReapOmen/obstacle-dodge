#include "Obstacle.h"
#include "Paddle.h"

Obstacle::Obstacle(cocos2d::Size windowSize, int type)
{
    switch(type)
    {
        case NONE:
        {
            break;
        }
        case LEFT:
        {
            paddles.push_back(new Paddle(windowSize, Paddle::LEFT));
            break;
        }
        case MIDDLE:
        {
            paddles.push_back(new Paddle(windowSize, Paddle::MIDDLE));
            break;
        }
        case RIGHT:
        {
            paddles.push_back(new Paddle(windowSize, Paddle::RIGHT));
            break;
        }
        case NO_LEFT:
        {
            paddles.push_back(new Paddle(windowSize, Paddle::MIDDLE));
            paddles.push_back(new Paddle(windowSize, Paddle::RIGHT));
            break;
        }
        case NO_MIDDLE:
        {
            paddles.push_back(new Paddle(windowSize, Paddle::LEFT));
            paddles.push_back(new Paddle(windowSize, Paddle::RIGHT));
            break;
        }
        case NO_RIGHT:
        {
            paddles.push_back(new Paddle(windowSize, Paddle::LEFT));
            paddles.push_back(new Paddle(windowSize, Paddle::MIDDLE));
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
