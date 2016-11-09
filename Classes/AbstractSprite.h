#ifndef __ABSTRACT_SPRITE_H__
#define __ABSTRACT_SPRITE_H__

#include "cocos2d.h"

class AbstractSprite
{
public:
    AbstractSprite(const std::string& spritePath);

    virtual ~AbstractSprite();

    cocos2d::Sprite* getSprite() const;

    float getHeight() const;

    float getHalvedHeight() const;

    float getWidth() const;

    float getHalvedWidth() const;

    float getX() const;

    float getY() const;

    cocos2d::Vec2 getPosition() const;

    virtual void setPosition(const cocos2d::Vec2& newPos);

private:
    cocos2d::Sprite* sprite_;

    float width_, height_, halvedWidth_, halvedHeight_;

};
#endif // __ABSTRACT_SPRITE_H__
