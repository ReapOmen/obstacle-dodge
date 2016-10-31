#ifndef __GAMEOVERSCENE_H__
#define __GAMEOVERSCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class GameOverScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameOverScene);

private:
    cocos2d::MenuItemImage* retryButton;
    cocos2d::MenuItemImage* giveUpButton;

    void startMainScene(cocos2d::Ref *sender);
    void quit(cocos2d::Ref *sender);
};

#endif // __GAMEOVERSCENE_H__
