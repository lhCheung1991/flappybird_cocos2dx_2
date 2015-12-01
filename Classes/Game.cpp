//
//  Game.cpp
//  flappybird_cocos2dx_2
//
//  Created by zlh on 11/28/15.
//
//

#include "Game.hpp"

#include "StartScene.hpp"
#include "PlayScene.hpp"

Game::Game()
{
    
}

Game::~Game()
{
    
}

void Game::initGame()
{
    mStartScene = StartScene::create();
    mStartScene->setGame(this);
}

void Game::runGame()
{
    Director::getInstance()->runWithScene(mStartScene);
}

void Game::goToPlayScene(Ref * ref)
{
    Director::getInstance()->pushScene(mStartScene);

    mPlayScene = PlayScene::create();
    mPlayScene->setGame(this);
    
    Director::getInstance()->replaceScene(mPlayScene);
}
