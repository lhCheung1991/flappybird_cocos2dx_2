//
//  BaseScene.cpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#include "BaseScene.hpp"
#include "LandSprite.hpp"
#include "BirdSprite.hpp"

bool BaseScene::init()
{
    if (!Scene::initWithPhysics())
    {
        return false;
    }
    
    Scene::getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    Scene::getPhysicsWorld()->setGravity(Vec2(0, -9.8f * 50));
    
    mRootLayer = Layer::create();
    this->addChild(mRootLayer);
    
    mLandSprite = LandSprite::create();
    mRootLayer->addChild(mLandSprite);
    
    mBirdSprite = BirdSprite::create();
    mRootLayer->addChild(mBirdSprite);
    
    return true;
}