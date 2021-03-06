#ifndef __MAINMENUSCENE_H__
#define __MAINMENUSCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class MainMenuScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(MainMenuScene);

    virtual ~MainMenuScene();

private:
    cocos2d::MenuItemImage* playButton;
    cocos2d::MenuItemImage* exitButton;

    void startMainScene(cocos2d::Ref *sender);
    void quit(cocos2d::Ref *sender);
};

#endif // __MAINMENUSCENE_H__
