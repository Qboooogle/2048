//
//  Menu.cpp
//  2048
//
//  Created by DonLiu on 14-9-3.
//
//

#include "Menu.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene * GMenu::createScene(){
    auto scene=Scene::create();
    auto layer=GMenu::create();
    scene->addChild(layer);
    return scene;
}

bool GMenu::init(){
    if (!Layer::init()) {
        return false;
    }
    auto title = Label::createWithSystemFont("StartGame", "", 50);
    title->setPosition(Vec2(Director::getInstance()->getWinSize().width/2,Director::getInstance()->getWinSize().height/2));
    this->addChild(title);
    this->schedule(schedule_selector(GMenu::start), 2);
    return true;
}

void GMenu::start(float t){
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.2, scene));
}