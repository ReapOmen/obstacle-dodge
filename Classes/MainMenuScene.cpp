#include "MainMenuScene.h"
#include "Globals.h"
#include "MainScene.h"
#include "ui/CocosGUI.h"
#include "ui/UILayout.h"
#include <iostream>

USING_NS_CC;
#define COCOS2D_DEBUG 1

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    auto background = LayerColor::create(Color4B(255, 255, 255, 255));

    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(background);
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool MainMenuScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

    playButton = MenuItemImage::create("play.png", "play_selected.png",
                                       CC_CALLBACK_1(MainMenuScene::startMainScene, this));
    playButton->setScale(Globals::scaleButtons);

    exitButton = MenuItemImage::create("exit.png", "exit_selected.png",
                                       CC_CALLBACK_1(MainMenuScene::quit, this));
    exitButton->setScale(Globals::scaleButtons);
/*
    CCLOG("%f %f", playButton->getPosition().x, playButton->getPosition().y);
*/
    auto menu = Menu::create(playButton, exitButton, NULL);
    menu->alignItemsVerticallyWithPadding(10);
    this->addChild(menu, 1);
    return true;
}

void MainMenuScene::startMainScene(Ref *sender)
{
    Director::getInstance()->replaceScene(MainScene::createScene());
}

void MainMenuScene::quit(Ref *sender)
{
    Director::getInstance()->end();
    exit(0);
}

MainMenuScene::~MainMenuScene()
{

}
