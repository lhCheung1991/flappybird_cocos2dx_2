//
//  PlayScene.hpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#ifndef PlayScene_hpp
#define PlayScene_hpp

#include "BaseScene.hpp"

class PlayScene : public BaseScene
{
public:
    bool init();
    CREATE_FUNC(PlayScene);
    
    void updatePipe();
    
private:
    
    Sprite * mPipeSprite1;
    Sprite * mPipeSprite2;
    Sprite * mPipeSprite3;
    Sprite * mPipeSprite4;
};

#endif /* PlayScene_hpp */
