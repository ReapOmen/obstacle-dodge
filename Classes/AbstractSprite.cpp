#include "AbstractSprite.h"
#include "Globals.h"
USING_NS_CC;

AbstractSprite::AbstractSprite(const std::string& spritePath)
    :sprite_(Sprite::create(spritePath)), width_(0.0f), height_(0.0f),
     halvedWidth_(0.0f), halvedHeight_(0.0f)
{
    sprite_->setScale(Globals::scaleObjects);

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

void AbstractSprite::setPosition(const Vec2& newPos)
{
    sprite_->setPosition(newPos);
}
