//
//  OverScene.cpp
//  2048
//
//  Created by DonLiu on 14-9-3.
//
//

#include "OverScene.h"
USING_NS_CC;

Scene * OverScene::createScene(){
    auto scene=Scene::create();
    auto layer=OverScene::create();
    scene->addChild(layer);
    return scene;
}

bool OverScene::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto over = Label::createWithSystemFont("GameOver", "", 50);
    over->setPosition(Vec2(Director::getInstance()->getWinSize().width/2,Director::getInstance()->getWinSize().height/2));
    this->addChild(over);
    
    return true;
}