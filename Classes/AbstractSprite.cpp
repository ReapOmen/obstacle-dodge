#include "AbstractSprite.h"
USING_NS_CC;

AbstractSprite::AbstractSprite(Size windowSize, std::string spritePath)
{
    sprite = Sprite::create(spritePath);
    sprite->setScale(0.2);
    sprite->setPosition(windowSize.width / 2,
                        windowSize.height / 15);

    Rect box = sprite->getBoundingBox();
    width = box.getMaxX() - box.getMinX();
    halvedWidth = box.getMaxX() - box.getMidX();
    height = box.getMaxY() - box.getMinY();
    halvedHeight = box.getMaxY() - box.getMidY();
}

AbstractSprite::~AbstractSprite()
{

}

Sprite* AbstractSprite::getSprite() const
{
    return sprite;
}

float AbstractSprite::getHeight() const
{
    return height;
}

float AbstractSprite::getWidth() const
{
    return width;
}

float AbstractSprite::getHalvedHeight() const
{
    return halvedHeight;
}

float AbstractSprite::getHalvedWidth() const
{
    return halvedWidth;
}

float AbstractSprite::getX() const
{
    return sprite->getPosition().x;
}

float AbstractSprite::getY() const
{
    return sprite->getPosition().y;
}

void AbstractSprite::setPosition(Vec2 newPos)
{
    sprite->setPosition(newPos);
}

Vec2 AbstractSprite::getPosition() const
{
    return sprite->getPosition();
}
