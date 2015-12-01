//
//  SkySprite.cpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 12/1/15.
//
//

#include "SkySprite.hpp"

bool SkySprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    
    Size visibleSize= Director::getInstance()->getVisibleSize();
    Vec2 visiableOrigin = Director::getInstance()->getVisibleOrigin();
    
    Sprite * tmpLandSprite = Sprite::create("assets/land.png");
    tmpLandSprite->setAnchorPoint(Vec2(0, 0));
    tmpLandSprite->setPosition(Vec2(visiableOrigin.x, visiableOrigin.y));
    int landHeight = tmpLandSprite->getContentSize().height;
    
    Sprite * skySprite1 = Sprite::create("assets/sky.png");
    skySprite1->setScale(visibleSize.width / skySprite1->getContentSize().width * 0.5);
    skySprite1->setAnchorPoint(Vec2(0, 0));
    skySprite1->setPosition(Vec2(0, landHeight));
    
    Sprite * skySprite2 = Sprite::create("assets/sky.png");
    skySprite2->setScale(visibleSize.width / skySprite2->getContentSize().width * 0.5);
    skySprite2->setAnchorPoint(Vec2(0, 0));
    skySprite2->setPosition(Vec2(visibleSize.width * 0.5, landHeight));
    
    Sprite * skySprite3 = Sprite::create("assets/sky.png");
    skySprite3->setScale(visibleSize.width / skySprite3->getContentSize().width * 0.5);
    skySprite3->setAnchorPoint(Vec2(0, 0));
    skySprite3->setPosition(Vec2(visibleSize.width, landHeight));
    
    Sprite * skySprite4 = Sprite::create("assets/sky.png");
    skySprite4->setScale(visibleSize.width / skySprite4->getContentSize().width * 0.5);
    skySprite4->setAnchorPoint(Vec2(0, 0));
    skySprite4->setPosition(Vec2(visibleSize.width * 1.5, landHeight));
    
    Sprite * skyTop = Sprite::create("assets/sky.png", Rect(0, 0, 276, 3));
    skyTop->setPosition(Vec2(0, 220));
    skyTop->setAnchorPoint(Vec2(0, 0));
    skyTop->setScaleX(visibleSize.width / skyTop->getContentSize().width);
    skyTop->setScaleY(100);
    
    auto moveForwardAction = MoveBy::create(12, Vec2(-visibleSize.width, 0));
    auto moveBackAction = MoveBy::create(0, Vec2(visibleSize.width, 0));
    
    auto seq = Sequence::create(moveForwardAction, 0.001, moveBackAction, NULL);
    auto rep = RepeatForever::create(seq);
    
    Node * skyAnimNode = Node::create();    // node hold the sky animation
    skyAnimNode->addChild(skySprite1);
    skyAnimNode->addChild(skySprite2);
    skyAnimNode->addChild(skySprite3);
    skyAnimNode->addChild(skySprite4);
    skyAnimNode->addChild(skyTop);
    
    skySprite1->runAction(rep);
    skySprite2->runAction(rep->clone());
    skySprite3->runAction(rep->clone());
    skySprite4->runAction(rep->clone());
    
    this->addChild(skyAnimNode);
    
    return true;
}