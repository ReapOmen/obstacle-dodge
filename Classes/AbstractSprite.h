#ifndef __ABSTRACT_SPRITE_H__
#define __ABSTRACT_SPRITE_H__

#include "cocos2d.h"

class AbstractSprite
{
private:
    cocos2d::Sprite *sprite;

    float width, height, halvedWidth, halvedHeight;

public:
    AbstractSprite(cocos2d::Size windowSize, std::string spritePath);

    virtual ~AbstractSprite();

    cocos2d::Sprite* getSprite() const;

    float getHeight() const;

    float getHalvedHeight() const;

    float getWidth() const;

    float getHalvedWidth() const;

    float getX() const;

    float getY() const;

    cocos2d::Vec2 getPosition() const;

    virtual void setPosition(cocos2d::Vec2 newPos);
};
#endif // __ABSTRACT_SPRITE_H__
