//
//  StartScene.hpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#ifndef StartScene_hpp
#define StartScene_hpp

#include "BaseScene.hpp"

class StartScene : public BaseScene
{
public:
    bool init();
    CREATE_FUNC(StartScene);

private:
    void goToPlaySceneCallback(Ref* pSender);
    
private:
    Label * mGameLabel;
    Sprite * mBirdSprite;
    MenuItem * mGoToPlaySceneItem;
};

#endif /* StartScene_hpp */
