//
//  Game.hpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#ifndef Game_hpp
#define Game_hpp

#include "cocos2d.h"
#include "BaseScene.hpp"

USING_NS_CC;

class Game
{
public:
    
    Game();
    ~Game();
    
    Game(const Game &) = delete;
    void operator=(const Game &) = delete;
    
    void initGame();
    void runGame();
    void goToPlayScene(Ref * ref);
    
    BaseScene * getStartScene(){return mStartScene;}
    BaseScene * getPlayScene(){return mPlayScene;}
    
private:
    
    BaseScene * mStartScene;
    BaseScene * mPlayScene;
    BaseScene * mEndScene;
};

#endif /* Game_hpp */
