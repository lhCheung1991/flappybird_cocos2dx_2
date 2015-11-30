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
    
    mPipeAccessHeight = 200;    // change to random
    
    Sprite * tmpLandSprite = Sprite::create("assets/land.png");
    tmpLandSprite->setAnchorPoint(Vec2(0, 0));
    tmpLandSprite->setPosition(Vec2(visiableOrigin.x, visiableOrigin.y));
    mLandHeight = tmpLandSprite->getContentSize().height;
    
    /****************upper pipe*******************/
    mUpperPipe = Sprite::create("assets/pipe_down.png");
    mUpperPipe->setAnchorPoint(Vec2(0, 0));
    mUpperPipe->setScaleX(1.5);
    // upperPipeExpand
    upperPipeExpand = Sprite::create("assets/pipe.png");
    upperPipeExpand->setAnchorPoint(Vec2(0, 0));
    mUpperPipe->addChild(upperPipeExpand);
    /****************upper pipe*******************/
    
    /****************bottom pipe*******************/
    mBottomPipe = Sprite::create("assets/pipe_up.png");
    mBottomPipe->setAnchorPoint(Vec2(0, 0));
    mBottomPipe->setScaleX(1.5);
    // bottomPipeExpand
    bottomPipeExpand = Sprite::create("assets/pipe.png");
    bottomPipeExpand->setAnchorPoint(Vec2(0, 0));
    mBottomPipe->addChild(bottomPipeExpand);
    /****************bottom pipe*******************/
    
    /****************add physics body*******************/
    PhysicsBody * upperPipeBody = PhysicsBody::createBox(Size(mUpperPipe->getContentSize().width,
                                                              mUpperPipe->getContentSize().height + upperPipeExpand->getContentSize().height));
    mUpperPipe->setPhysicsBody(upperPipeBody);
    /****************add physics body*******************/
    
    this->addChild(mUpperPipe);
    this->addChild(mBottomPipe);
    
    return true;
}

void PipeSprite::buildPipeRandom()
{

    Size visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 visiableOrigin = Director::getInstance()->getVisibleOrigin();
    
    // set upper pipe
    mUpperPipe->setPosition(Vec2(0, mPipeAccessHeight + 40));
    upperPipeExpand->setPosition(mUpperPipe->getPosition().x, mUpperPipe->getContentSize().height);
    upperPipeExpand->setScaleY((visiableSize.height - mUpperPipe->getPosition().y - mUpperPipe->getContentSize().height) / upperPipeExpand->getContentSize().height);
    
    // set bottom pipe
    mBottomPipe->setPosition(Vec2(0, mPipeAccessHeight - 40));
    bottomPipeExpand->setPosition(0, -mBottomPipe->getPosition().y + mLandHeight);
    bottomPipeExpand->setScaleY((mBottomPipe->getPosition().y - mLandHeight) / bottomPipeExpand->getContentSize().height);
}