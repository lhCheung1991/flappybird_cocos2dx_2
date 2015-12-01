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
    mPipeSprite2 = PipeSprite::create();
    this->getRootLayer()->addChild(mPipeSprite2);
    mPipeSprite3 = PipeSprite::create();
    this->getRootLayer()->addChild(mPipeSprite3);
    mPipeSprite4 = PipeSprite::create();
    this->getRootLayer()->addChild(mPipeSprite4);
    /*******************pipe initialization*************************/
    
    ((PipeSprite *)mPipeSprite1)->startMovement(visiableSize.width);
    ((PipeSprite *)mPipeSprite2)->startMovement(visiableSize.width + visiableSize.width * 0.25);
    ((PipeSprite *)mPipeSprite3)->startMovement(visiableSize.width + visiableSize.width * 0.5);
    ((PipeSprite *)mPipeSprite4)->startMovement(visiableSize.width + visiableSize.width * 0.75);
    return true;
}

void PlayScene::updatePipe()
{
    Size visiableSize = Director::getInstance()->getVisibleSize();
    
    PipeSprite * curPipeSprite = PipeSprite::create();
    this->getRootLayer()->addChild(curPipeSprite);
    curPipeSprite->startMovement(visiableSize.width);
}