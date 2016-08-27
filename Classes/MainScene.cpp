#include "MainScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

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

    ball = new Ball(visibleSize);
    moveRight = false;

    paddle = new Paddle(visibleSize);

    EventListenerKeyboard *eventListener = EventListenerKeyboard::create();

    eventListener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event* event) {
        onKeyPressed(keyCode, event);
    };
    eventListener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event* event) {
        onKeyReleased(keyCode, event);
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

    this->label = Label::createWithTTF("", "fonts/arial.ttf", 24);

    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                            origin.y + visibleSize.height / 2 ));

    this->addChild(ball->getSprite());
    this->addChild(paddle->getSprite());

    this->addChild(label);

    this->scheduleUpdate();

    return true;
}

void MainScene::update(float delta)
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

void MainScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch(keyCode)
    {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            this->moveRight = true;
            break;
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            this->moveLeft = true;
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
