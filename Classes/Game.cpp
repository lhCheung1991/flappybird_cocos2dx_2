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
    mPlayScene = PlayScene::create();
    mPlayScene->setGame(this);
    mStartScene = StartScene::create();
    mStartScene->setGame(this);
    
}

void Game::runGame()
{
    Director::getInstance()->runWithScene(mStartScene);
//    Director::getInstance()->runWithScene(mPlayScene);
}

void Game::goToPlayScene(Ref * ref)
{
    Director::getInstance()->pushScene(mStartScene);
    Director::getInstance()->replaceScene(mPlayScene);
}
