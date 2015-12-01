//
//  PipeSprite.cpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/29/15.
//
//

#include "PipeSprite.hpp"

#include <time.h>
#include <stdlib.h>
#include "PlayScene.hpp"

bool PipeSprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    
    Vec2 visiableOrigin = Director::getInstance()->getVisibleOrigin();
    
    Sprite * tmpLandSprite = Sprite::create("assets/land.png");
    tmpLandSprite->setAnchorPoint(Vec2(0, 0));
    tmpLandSprite->setPosition(Vec2(visiableOrigin.x, visiableOrigin.y));
    mLandHeight = tmpLandSprite->getContentSize().height;
    
    mPipeAccessHeight = getRandomAccessHeight();
    
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
    
    this->configPipeRandom();
    
    this->addChild(mUpperPipe);
    this->addChild(mBottomPipe);
    
    return true;
}



void PipeSprite::configPipeRandom()
{

    Size visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 visiableOrigin = Director::getInstance()->getVisibleOrigin();
    
    /**********************config upper pipe********************************/
    mUpperPipe->setPosition(Vec2(0, mPipeAccessHeight + 40));
    upperPipeExpand->setPosition(mUpperPipe->getPosition().x, mUpperPipe->getContentSize().height);
    upperPipeExpand->setScaleY((visiableSize.height - mUpperPipe->getPosition().y - mUpperPipe->getContentSize().height) / upperPipeExpand->getContentSize().height);
    /**********************config upper pipe********************************/
    
    /**********************config bottom pipe********************************/
    mBottomPipe->setPosition(Vec2(0, mPipeAccessHeight - 40));
    bottomPipeExpand->setPosition(0, -mBottomPipe->getPosition().y + mLandHeight);
    bottomPipeExpand->setScaleY((mBottomPipe->getPosition().y - mLandHeight) / bottomPipeExpand->getContentSize().height);
    /**********************config bottom pipe********************************/
    
    /****************add upper physics body*******************/
    if (mUpperPipe->getPhysicsBody() != nullptr)
    {
        mUpperPipe->removeComponent(mUpperPipe->getPhysicsBody());
    }
    PhysicsBody * newUpperPipeBody = PhysicsBody::createBox(Size(mUpperPipe->getContentSize().width,
                                                              visiableSize.height - mUpperPipe->getPosition().y));
    newUpperPipeBody->setPositionOffset(Vec2(0, (visiableSize.height - mUpperPipe->getPosition().y - mUpperPipe->getContentSize().height) / 2));
    newUpperPipeBody->setGravityEnable(false);
    newUpperPipeBody->setDynamic(false);
    mUpperPipe->setPhysicsBody(newUpperPipeBody);
    /****************add upper physics body*******************/
    
    /****************add bottom physics body*******************/
    if (mBottomPipe->getPhysicsBody() != nullptr)
    {
        mBottomPipe->removeComponent(mBottomPipe->getPhysicsBody());
    }
    PhysicsBody * newBottomPipeBody = PhysicsBody::createBox(Size(mBottomPipe->getContentSize().width,
                                                                  mBottomPipe->getPosition().y - mLandHeight + mBottomPipe->getContentSize().height));
    newBottomPipeBody->setPositionOffset(Vec2(0, -(mBottomPipe->getPosition().y - mLandHeight) / 2));
    newBottomPipeBody->setGravityEnable(false);
    newBottomPipeBody->setDynamic(false);
    mBottomPipe->setPhysicsBody(newBottomPipeBody);
    /****************add bottom physics body*******************/
}


void PipeSprite::startMovement(int startX)
{
    Size visiableSize = Director::getInstance()->getVisibleSize();
    
    /****************add upper pipe movement*******************/
    mUpperPipe->setPosition(startX, mUpperPipe->getPosition().y);
    MoveTo * upperPipeMoveFirst = MoveTo::create(4 * (startX / visiableSize.width), Vec2(-mUpperPipe->getContentSize().width * 1.5, mUpperPipe->getPosition().y));
    
    CallFuncN * upperMoveRemove = CallFuncN::create([](Node * node)
    {
        ((PlayScene *)node->getScene())->updatePipe();
        node->getParent()->removeFromParentAndCleanup(true);
    });
    
    Sequence * seqUpper = Sequence::create(upperPipeMoveFirst, DelayTime::create(0.1), upperMoveRemove , NULL);
    mUpperPipe->runAction(seqUpper);
    /****************add upper pipe movement*******************/
    
    /****************add bottom pipe movement*******************/
    mBottomPipe->setPosition(startX, mBottomPipe->getPosition().y);
    MoveTo * BottomPipeMoveFirst = MoveTo::create(4 * (startX / visiableSize.width), Vec2(-mBottomPipe->getContentSize().width * 1.5, mBottomPipe->getPosition().y));
    
    mBottomPipe->runAction(BottomPipeMoveFirst);
    /****************add bottom pipe movement*******************/
}


int PipeSprite::getRandomAccessHeight()
{
    time_t curTime;
    time(&curTime);
    srand((unsigned int)curTime);
    return random(200, 400);
}