//
//  StartScene.cpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#include "StartScene.hpp"
#include "BirdSprite.hpp"

#include "Game.hpp"

bool StartScene::init()
{
    if (!BaseScene::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    /*************initialize the game label****************/
    mGameLabel = Label::createWithTTF("Flappy Bird", "fonts/Marker_Felt.ttf", 35);
    mGameLabel->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.5));
    mGameLabel->enableOutline(Color4B::BLACK, 2);
    this->getRootLayer()->addChild(mGameLabel);
    /*************initialize the game label****************/
    
    /*************initialize the BirdSprite****************/
    mBirdSprite = BirdSprite::create();
    mBirdSprite->setPosition(Vec2(visibleSize.width * 0.5 - 20, visibleSize.height * 0.5 + 80));
    this->getRootLayer()->addChild(mBirdSprite);
    /*************initialize the BirdSprite****************/
    
    /*************initialize the menu item****************/
    mGoToPlaySceneItem =  MenuItemImage::create(
                          "assets/replay.png",
                          "assets/replay.png",
                          CC_CALLBACK_1(StartScene::goToPlaySceneCallback, this));
    mGoToPlaySceneItem->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.5 - 80));
    
    auto menu = Menu::create(mGoToPlaySceneItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->getRootLayer()->addChild(menu);
    /*************initialize the menu item****************/
    
    return true;
}

void StartScene::goToPlaySceneCallback(Ref *pSender)
{
    StartScene * scene = (StartScene *)((MenuItemImage *)pSender)->getScene();
    scene->getGame()->goToPlayScene(pSender);
}