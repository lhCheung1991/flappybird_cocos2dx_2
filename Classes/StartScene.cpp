//
//  StartScene.cpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#include "StartScene.hpp"
#include "BirdSprite.hpp"

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
    mBirdSprite->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.5 + 80));
//    mBirdSprite->flyShaking();
    this->getRootLayer()->addChild(mBirdSprite);
    /*************initialize the BirdSprite****************/
    
    return true;
}