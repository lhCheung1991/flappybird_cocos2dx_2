//
//  PlayScene.cpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#include "PlayScene.hpp"

#include "PipeSprite.hpp"

bool PlayScene::init()
{
    if (!BaseScene::init())
    {
        return false;
    }
    
    Size visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 visiableOrigin = Director::getInstance()->getVisibleOrigin();
    
    
    /*******************bird initialization*************************/
    mBirdSprite->setPosition(Vec2(visiableOrigin.x + visiableSize.width * 0.2,
                                  visiableOrigin.y + visiableSize.height * 0.5));
    /*******************bird initialization*************************/
    
    /*******************pipe initialization*************************/
    mPipeSprite1 = PipeSprite::create();
    this->getRootLayer()->addChild(mPipeSprite1);
    /*******************pipe initialization*************************/
    return true;
}