#include "GameOverScene.h"
#include "Globals.h"
#include "MainScene.h"
#include "ui/CocosGUI.h"
#include "ui/UILayout.h"
#include <iostream>

USING_NS_CC;
#define COCOS2D_DEBUG 1

Scene* GameOverScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    auto background = LayerColor::create(Color4B(255, 255, 255, 255));

    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(background);
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool GameOverScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

    Label* l = Label::createWithTTF("Try again! Come on!", "fonts/arial.ttf", 24);
    l->setColor(Color3B(0, 0, 0));

    MenuItemLabel* label = MenuItemLabel::create(l);

    retryButton = MenuItemImage::create("retry.png", "retry_selected.png",
                                        CC_CALLBACK_1(GameOverScene::startMainScene, this));
    retryButton->setScale(Globals::scaleButtons);

    giveUpButton = MenuItemImage::create("exit.png", "exit_selected.png",
                                         CC_CALLBACK_1(GameOverScene::quit, this));
    giveUpButton->setScale(Globals::scaleButtons);

    auto menu = Menu::create(label, retryButton, giveUpButton, NULL);
    menu->alignItemsVerticallyWithPadding(10);
    this->addChild(menu, 1);

    return true;
}

void GameOverScene::startMainScene(Ref *sender)
{
    auto scene = MainScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.3, scene, Color3B(0, 0, 0)));
}

void GameOverScene::quit(Ref *sender)
{
    Director::getInstance()->end();
    exit(0);
}
