//
//  StartScene.cpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#include "StartScene.hpp"


bool StartScene::init()
{
    if (!BaseScene::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    /*************initialize the game label****************/
    gameLabel = Label::createWithTTF("Flappy Bird", "fonts/Marker_Felt.ttf", 35);
    gameLabel->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.5));
    gameLabel->enableOutline(Color4B::BLACK, 2);
    this->getRootLayer()->addChild(gameLabel);
    /*************initialize the game label****************/
    
    return true;
}