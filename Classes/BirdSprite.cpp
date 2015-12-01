//
//  BirdSprite.cpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#include "BirdSprite.hpp"


bool BirdSprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    
    /******************create bird animation***************************/
    Sprite * tmpBirdSprite = Sprite::create("assets/bird.png");
    int birdFrameWidth = tmpBirdSprite->getContentSize().width;
    int birdFrameHeight = tmpBirdSprite->getContentSize().height / 4;
    Vector<SpriteFrame *> birdAnimFrames;
    birdAnimFrames.pushBack(SpriteFrame::create("assets/bird.png",
                                                Rect(0, 0, birdFrameWidth, birdFrameHeight)));
    birdAnimFrames.pushBack(SpriteFrame::create("assets/bird.png",
                                                Rect(0, birdFrameHeight + 1, birdFrameWidth, birdFrameHeight)));
    birdAnimFrames.pushBack(SpriteFrame::create("assets/bird.png",
                                                Rect(0, birdFrameHeight * 2 + 1, birdFrameWidth, birdFrameHeight)));
    birdAnimFrames.pushBack(SpriteFrame::create("assets/bird.png",
                                                Rect(0, birdFrameHeight * 3 + 1, birdFrameWidth, birdFrameHeight)));
    Animation * birdAnimation = Animation::createWithSpriteFrames(birdAnimFrames, 0.1);
    Animate * birdAnimate = Animate::create(birdAnimation);
    /******************create bird animation***************************/
    
    Sprite * birdAnimNode = Sprite::create();    // node hold the bird animation
    birdAnimNode->setAnchorPoint(Vec2(0, 0));
    birdAnimNode->runAction(RepeatForever::create(birdAnimate));
    
    this->addChild(birdAnimNode);
    this->setAnchorPoint(Vec2(0, 0));
    this->setScale(2);
    this->setContentSize(Size(birdFrameWidth, birdFrameHeight));
    
    PhysicsBody * birdPhysicsBody = PhysicsBody::createBox(Size(birdFrameWidth, birdFrameHeight),
                                                           PhysicsMaterial(1, 0.5, 0.5));
    birdPhysicsBody->setRotationEnable(false);
    this->setPhysicsBody(birdPhysicsBody);
    this->registerEventListener();
    
    return true;
}


void BirdSprite::flyUp()
{
    this->getPhysicsBody()->
    setVelocity(Vec2(0, 20 * 9.8));
    
    RotateTo * rotACW = RotateTo::create(0.05, -25);
    RotateTo * rotCW = RotateTo::create(0.9, 60);
    Sequence * seq = Sequence::create(rotACW, 0.01, rotCW, NULL);
    this->runAction(seq);
}

void BirdSprite::registerEventListener()
{
    EventListenerKeyboard * keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = [](EventKeyboard::KeyCode code, Event* event)
    {
        if (code == EventKeyboard::KeyCode::KEY_SPACE)
        {
            ((BirdSprite *)event->getCurrentTarget())->flyUp();
        }
        
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}