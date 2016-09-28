#include "AbstractSprite.h"
USING_NS_CC;

AbstractSprite::AbstractSprite(std::string spritePath)
{
    sprite_ = Sprite::create(spritePath);
    sprite_->setScale(0.2);

    Rect box = sprite_->getBoundingBox();
    width_ = box.getMaxX() - box.getMinX();
    halvedWidth_ = box.getMaxX() - box.getMidX();
    height_ = box.getMaxY() - box.getMinY();
    halvedHeight_ = box.getMaxY() - box.getMidY();
}

AbstractSprite::~AbstractSprite()
{
    delete sprite_;
}

Sprite* AbstractSprite::getSprite() const
{
    return sprite_;
}

float AbstractSprite::getHeight() const
{
    return height_;
}

float AbstractSprite::getHalvedHeight() const
{
    return halvedHeight_;
}

float AbstractSprite::getWidth() const
{
    return width_;
}

float AbstractSprite::getHalvedWidth() const
{
    return halvedWidth_;
}

float AbstractSprite::getX() const
{
    return sprite_->getPosition().x;
}

float AbstractSprite::getY() const
{
    return sprite_->getPosition().y;
}

Vec2 AbstractSprite::getPosition() const
{
    return sprite_->getPosition();
}

void AbstractSprite::setPosition(Vec2 newPos)
{
    sprite_->setPosition(newPos);
}
