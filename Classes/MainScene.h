#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "Ball.h"
#include "Paddle.h"
#include "Obstacle.h"


class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    virtual void update(float delta);

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);

private:
    Ball *ball;

    std::vector<Obstacle*> obstacles;

    Obstacle *first, *second, *third;

    bool moveRight, moveLeft;

    float middleLine, bottomLine;

    cocos2d::Label *label;

    void createSprites();

    void addObstacle(Obstacle* obstacle);

    void setEventListeners();

    void handleBallMovement();

    void handleObstacleMovement();

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
};

#endif // __HELLOWORLD_SCENE_H__
