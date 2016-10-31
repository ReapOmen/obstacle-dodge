#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "GameOverScene.h"
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
    ball_ = new Ball();
    moveRight_ = moveLeft_ = false;
    this->addChild(ball_->getSprite());


    first_ = new Obstacle(Obstacle::NO_MIDDLE);
    this->addObstacle(first_);
    second_ = new Obstacle(Obstacle::NO_LEFT);
    this->addObstacle(second_);
    third_ = new Obstacle(Obstacle::NO_RIGHT);
    this->addObstacle(third_);
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
    if(this->moveRight_)
    {
        ball_->moveRight();
    }

    if(this->moveLeft_)
    {
        ball_->moveLeft();
    }

    if(!moveLeft_ && !moveRight_ && !ball_->isCentered())
    {
        ball_->moveToCenter();
    }
}

void MainScene::handleObstacleMovement()
{
    if(first_->getY() <= middleLine_)
        second_->update();

    if(first_->getY() >= bottomLine_ - first_->getHalvedHeight())
        first_->update();
    else
    {
        CC_SAFE_DELETE(first_);
        first_ = second_;
        second_ = third_;
        third_ = new Obstacle(rand() % 6);
        this->addObstacle(third_);
        score++;
        label_->setString("Score: " + std::to_string(score));
    }
}

bool MainScene::checkCollision()
{
    Rect ballRect = ball_->getSprite()->getBoundingBox();
    if(first_->getY() - first_->getHalvedHeight() <=
        ball_->getY() + ball_->getHalvedHeight())
    {
        std::vector<Paddle*> paddles = first_->getPaddles();
        for(Paddle* p : paddles)
        {
            Rect paddleRect = p->getSprite()->getBoundingBox();
            if(ballRect.intersectsRect(paddleRect))
                return true;
        }
    }
    return false;
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
    // 1. super init first_
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    middleLine_ = visibleSize.height / 2;
    bottomLine_ = 0.0f;
    score = 0;

    createSprites();

    setEventListeners();

    this->label_ = Label::createWithTTF("Score: " + std::to_string(score), "fonts/arial.ttf", 24);

    label_->setPosition(Vec2(origin.x + visibleSize.width - 70,
                            origin.y + visibleSize.height - 15));

    this->addChild(label_);

    this->scheduleUpdate();

    return true;
}

void MainScene::update(float delta)
{
    handleBallMovement();

    handleObstacleMovement();

    if(checkCollision())
    {
        auto scene = GameOverScene::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(0.3, scene, Color3B(255, 255, 255)));
    }
}

void MainScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch(keyCode)
    {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            this->moveRight_ = true;
            this->moveLeft_ = false;
            break;
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            this->moveLeft_ = true;
            this->moveRight_ = false;
            break;
        default:
            break;
    }
}

void MainScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch(keyCode)
    {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            this->moveRight_ = false;
            break;
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            this->moveLeft_ = false;
            break;
        default:
            break;
    }
}

MainScene::~MainScene()
{

}
