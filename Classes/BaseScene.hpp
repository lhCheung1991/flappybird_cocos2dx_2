//
//  BaseScene.hpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#ifndef BaseScene_hpp
#define BaseScene_hpp

#include "cocos2d.h"

USING_NS_CC;

class Game;

class BaseScene : public Scene
{
    
public:
    bool init();
    CREATE_FUNC(BaseScene);
    Layer * getRootLayer(){return mRootLayer;}
    
    Game * getGame() const {return mGame;}
    void setGame(Game * game){mGame = game;}
    
protected:
    Sprite * mLandSprite;
    Sprite * mSkySprite;

private:
    Layer * mRootLayer;    // BaseScene get a root layer to hold everything in the scene
    Game * mGame;
};

#endif /* BaseScene_hpp */
