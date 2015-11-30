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
    
    Vec2 visiableOrigin = Director::getInstance()->getVisibleOrigin();
    
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
    
    this->configPipeRandom();
    
    this->addChild(mUpperPipe);
    this->addChild(mBottomPipe);
    
    return true;
}



void PipeSprite::configPipeRandom()
{

    Size visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 visiableOrigin = Director::getInstance()->getVisibleOrigin();
    mPipeAccessHeight = 300;    // change to random
    
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
        mUpperPipe->getPhysicsBody()->removeFromWorld();
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
        mBottomPipe->getPhysicsBody()->removeFromWorld();
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
    
    auto upperMoveBack = CallFuncN::create([](Node * node)
    {
        Size visiableSize = Director::getInstance()->getVisibleSize();
        node->setPosition(visiableSize.width, node->getPosition().y);
    });
    MoveTo * upperPipeMove = MoveTo::create(4, Vec2(-mUpperPipe->getContentSize().width * 1.5, mUpperPipe->getPosition().y));
    Sequence * seqRepeatUpper = Sequence::create(upperMoveBack, 0.01, upperPipeMove, NULL);
    
    Sequence * seqUpper = Sequence::create(upperPipeMoveFirst, 0.01, Repeat::create(seqRepeatUpper, -1), NULL);
    mUpperPipe->runAction(seqUpper);
    /****************add upper pipe movement*******************/
    
    /****************add bottom pipe movement*******************/
    mBottomPipe->setPosition(startX, mBottomPipe->getPosition().y);
    MoveTo * bottomPipeMoveFirst = MoveTo::create(4 * (startX / visiableSize.width), Vec2(-mBottomPipe->getContentSize().width * 1.5, mBottomPipe->getPosition().y));
    
    auto bottomMoveBack = CallFuncN::create([](Node * node)
    {
        Size visiableSize = Director::getInstance()->getVisibleSize();
        node->setPosition(visiableSize.width, node->getPosition().y);
    });
    MoveTo * bottomPipeMove = MoveTo::create(4, Vec2(-mBottomPipe->getContentSize().width * 1.5, mBottomPipe->getPosition().y));
    Sequence * seqRepeatBottom = Sequence::create(bottomMoveBack, 0.01, bottomPipeMove, NULL);
    
    Sequence * seqBottom = Sequence::create(bottomPipeMoveFirst, 0.01, Repeat::create(seqRepeatBottom, -1), NULL);
    mBottomPipe->runAction(seqBottom);
    /****************add bottom pipe movement*******************/
    
}