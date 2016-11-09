#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "Ball.h"
#include "Paddle.h"
#include "Obstacle.h"
#include "ui/CocosGUI.h"


class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    virtual void update(float delta);

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);

    virtual ~MainScene();

private:
    Ball* ball_;

    int score;

    Obstacle* first_, *second_, *third_;

    bool moveRight_, moveLeft_;

    float middleLine_, bottomLine_;

    cocos2d::Label* label_;

    void createSprites();

    void addObstacle(Obstacle* obstacle);

    void setEventListeners();

    void handleBallMovement();

    void handleObstacleMovement();

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    bool checkCollision();
};

#endif // __HELLOWORLD_SCENE_H__
