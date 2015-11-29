//
//  PipeSprite.hpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/29/15.
//
//

#ifndef PipeSprite_hpp
#define PipeSprite_hpp

#include "cocos2d.h"

USING_NS_CC;

class PipeSprite : public Sprite
{
public:
    bool init();
    CREATE_FUNC(PipeSprite);
    
private:
    
    Sprite * mUpperPipe;
    Sprite * mBottomPipe;
    
    int mPipeAccessHeight;
    
};

#endif /* PipeSprite_hpp */
