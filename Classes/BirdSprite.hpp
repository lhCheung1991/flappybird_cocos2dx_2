//
//  BirdSprite.hpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#ifndef BirdSprite_hpp
#define BirdSprite_hpp

#include "cocos2d.h"

USING_NS_CC;

class BirdSprite : public Sprite
{
public:
    bool init();
    CREATE_FUNC(BirdSprite);
    
    void flyUp();
    
private:
    void registerEventListener();
    bool onContactBegin(PhysicsContact & contact);
};

#endif /* BirdSprite_hpp */
