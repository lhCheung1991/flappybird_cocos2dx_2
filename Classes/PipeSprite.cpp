//
//  PipeSprite.cpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/29/15.
//
//

#include "PipeSprite.hpp"

bool PipeSprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    
    Size visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 visiableOrigin = Director::getInstance()->getVisibleOrigin();
    
//    mPipeAccessHeight = visiableSize.height / 2;    // change to random
    mPipeAccessHeight = 400;    // change to random
    
    Sprite * tmpLandSprite = Sprite::create("assets/land.png");
    tmpLandSprite->setAnchorPoint(Vec2(0, 0));
    tmpLandSprite->setPosition(Vec2(visiableOrigin.x, visiableOrigin.y));
    
    /****************upper pipe*******************/
    mUpperPipe = Sprite::create("assets/pipe_down.png");
    mUpperPipe->setAnchorPoint(Vec2(0, 0));
    mUpperPipe->setScaleX(1.5);
    mUpperPipe->setPosition(Vec2(0, mPipeAccessHeight + 40));
    // upperPipeExpand
    Sprite * upperPipeExpand = Sprite::create("assets/pipe.png");
    upperPipeExpand->setAnchorPoint(Vec2(0, 0));
    upperPipeExpand->setPosition(mUpperPipe->getPosition().x, mUpperPipe->getContentSize().height);
    upperPipeExpand->setScaleY((visiableSize.height - mUpperPipe->getPosition().y - mUpperPipe->getContentSize().height) / upperPipeExpand->getContentSize().height);
    mUpperPipe->addChild(upperPipeExpand);
    /****************upper pipe*******************/
    
    /****************bottom pipe*******************/
    mBottomPipe = Sprite::create("assets/pipe_up.png");
    mBottomPipe->setAnchorPoint(Vec2(0, 0));
    mBottomPipe->setScaleX(1.5);
    mBottomPipe->setPosition(Vec2(0, mPipeAccessHeight - 40));
    // bottomPipeExpand
    Sprite * bottomPipeExpand = Sprite::create("assets/pipe.png");
    bottomPipeExpand->setAnchorPoint(Vec2(0, 0));
    bottomPipeExpand->setPosition(0, -mBottomPipe->getPosition().y + tmpLandSprite->getContentSize().height);
    bottomPipeExpand->setScaleY((mBottomPipe->getPosition().y - tmpLandSprite->getContentSize().height) / bottomPipeExpand->getContentSize().height);
    mBottomPipe->addChild(bottomPipeExpand);
    /****************bottom pipe*******************/
    
    this->addChild(mUpperPipe);
    this->addChild(mBottomPipe);
    
    return true;
}