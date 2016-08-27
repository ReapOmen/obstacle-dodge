#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "Ball.h"

class MainScene : public cocos2d::Layer
{
private:
    Ball *ball;
    bool moveRight, moveLeft;
    cocos2d::Label *label;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    virtual void update(float delta);

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);

    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

};

#endif // __HELLOWORLD_SCENE_H__
