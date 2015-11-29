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
    
private:
    
    Sprite * mPipeSprite1;
};

#endif /* PlayScene_hpp */
