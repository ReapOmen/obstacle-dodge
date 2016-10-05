#include "MainMenuScene.h"
#include "Globals.h"
#include "MainScene.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool MainMenuScene::init()
{
    playButton = ui::Button::create("play.png", "play_selected.png");
    playButton->setScale(Globals::scaleButtons);
    Globals::init();
    Size screenSize = Globals::screenSize;
    playButton->setPosition(Vec2(screenSize.width / 2,
                                 screenSize.height / 2));
    playButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::startMainScene, this));
    this->addChild(playButton);
    return true;
}

void MainMenuScene::startMainScene(Ref *sender, ui::Widget::TouchEventType type)
{
    Director::getInstance()->replaceScene(MainScene::createScene());
}
