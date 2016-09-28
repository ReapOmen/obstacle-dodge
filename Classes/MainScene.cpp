#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "Globals.h"
#include <iostream>
#include <cstdlib>
#include <string>

USING_NS_CC;

void MainScene::addObstacle(Obstacle* obstacle)
{
    std::vector<Paddle*> paddles = obstacle->getPaddles();
    for(Paddle* paddle : paddles)
    {
        this->addChild(paddle->getSprite());
    }
}

void MainScene::createSprites()
{
    ball = new Ball();
    moveRight = moveLeft = false;
    this->addChild(ball->getSprite());


    first = new Obstacle(Obstacle::NO_MIDDLE);
    this->addObstacle(first);
    second = new Obstacle(Obstacle::NO_LEFT);
    this->addObstacle(second);
    third = new Obstacle(Obstacle::NO_RIGHT);
    this->addObstacle(third);
}

void MainScene::setEventListeners()
{
    EventListenerKeyboard *eventListener = EventListenerKeyboard::create();

    eventListener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event* event) {
        onKeyPressed(keyCode, event);
    };
    eventListener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event* event) {
        onKeyReleased(keyCode, event);
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}

void MainScene::handleBallMovement()
{
    if(this->moveRight)
    {
        ball->moveRight();
    }

    if(this->moveLeft)
    {
        ball->moveLeft();
    }

    if(!moveLeft && !moveRight && !ball->isCentered())
    {
        ball->moveToCenter();
    }
}

void MainScene::handleObstacleMovement()
{
    if(first->getY() <= middleLine)
        second->update();

    if(first->getY() >= bottomLine + first->getHalvedHeight())
        first->update();
    else
    {
        delete first;
        first = second;
        second = third;
        third = new Obstacle(rand() % 6);
        this->addObstacle(third);
    }
}

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Globals::init();

    middleLine = visibleSize.height / 2;
    bottomLine = 0.0f;

    createSprites();

    setEventListeners();

    this->label = Label::createWithTTF(std::to_string(Globals::screenSize.height), "fonts/arial.ttf", 24);

    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                            origin.y + visibleSize.height / 2 ));

    this->addChild(label);

    this->scheduleUpdate();

    return true;
}

void MainScene::update(float delta)
{
    handleBallMovement();

    handleObstacleMovement();
}

void MainScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch(keyCode)
    {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            this->moveRight = true;
            this->moveLeft = false;
            break;
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            this->moveLeft = true;
            this->moveRight = false;
            break;
    }
}

void MainScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch(keyCode)
    {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            this->moveRight = false;
            break;
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            this->moveLeft = false;
            break;
    }
}
