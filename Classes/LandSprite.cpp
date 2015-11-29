//
//  LandSprite.cpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#include "LandSprite.hpp"

bool LandSprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    
    Size visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 visiableOrigin = Director::getInstance()->getVisibleOrigin();
    
    Sprite * landSprite1 = Sprite::create("assets/land.png");
    landSprite1->setAnchorPoint(Vec2(0, 0));
    landSprite1->setPosition(Vec2(visiableOrigin.x, visiableOrigin.y));
    landSprite1->setScaleX(visiableSize.width / landSprite1->getContentSize().width / 2);
    
    Sprite * landSprite2 = Sprite::create("assets/land.png");
    landSprite2->setAnchorPoint(Vec2(0, 0));
    landSprite2->setPosition(Vec2(visiableOrigin.x + visiableSize.width / 2, visiableOrigin.y));
    landSprite2->setScaleX(visiableSize.width / landSprite2->getContentSize().width / 2);
    
    Sprite * landSprite3 = Sprite::create("assets/land.png");
    landSprite3->setAnchorPoint(Vec2(0, 0));
    landSprite3->setPosition(Vec2(visiableOrigin.x + visiableSize.width, visiableOrigin.y));
    landSprite3->setScaleX(visiableSize.width / landSprite3->getContentSize().width / 2);
    
    Sprite * landSprite4 = Sprite::create("assets/land.png");
    landSprite4->setAnchorPoint(Vec2(0, 0));
    landSprite4->setPosition(Vec2(visiableOrigin.x + visiableSize.width * 1.5, visiableOrigin.y));
    landSprite4->setScaleX(visiableSize.width / landSprite4->getContentSize().width / 2);
    
    Node * landAnimNode = Node::create();    // node hold the land animation
    landAnimNode->addChild(landSprite1);
    landAnimNode->addChild(landSprite2);
    landAnimNode->addChild(landSprite3);
    landAnimNode->addChild(landSprite4);
    
    MoveBy * landForward = MoveBy::create(3, Vec2(-visiableSize.width, 0));
    MoveBy * landBackward = MoveBy::create(0.001, Vec2(visiableSize.width, 0));
    Sequence * moveSeq = Sequence::create(landForward, 0.001, landBackward,NULL);
    landSprite1->runAction(RepeatForever::create(moveSeq));
    landSprite2->runAction(RepeatForever::create(moveSeq->clone()));
    landSprite3->runAction(RepeatForever::create(moveSeq->clone()));
    landSprite4->runAction(RepeatForever::create(moveSeq->clone()));
    
    this->addChild(landAnimNode);
    this->setAnchorPoint(Vec2(0, 0));
    this->setContentSize(Size(visiableSize.width, landSprite1->getContentSize().height));
    
    PhysicsBody * landPhysicsBody = PhysicsBody::createBox(Size(visiableSize.width, landSprite1->getContentSize().height), PhysicsMaterial(1, 1, 0));
    landPhysicsBody->setGravityEnable(false);
    landPhysicsBody->setDynamic(false);
    this->setPhysicsBody(landPhysicsBody);
    
    
    return true;
}