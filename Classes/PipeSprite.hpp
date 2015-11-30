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
    
    void setPipeAccessHeight(int height){mPipeAccessHeight = height;}
    
    void buildPipeRandom();
    
private:
    
    Sprite * mUpperPipe;
    Sprite * upperPipeExpand;
    Sprite * mBottomPipe;
    Sprite * bottomPipeExpand;
    
    int mPipeAccessHeight;
    int mLandHeight;
    
};

#endif /* PipeSprite_hpp */
