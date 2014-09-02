//
//  Number.cpp
//  2048
//
//  Created by DonLiu on 14-9-1.
//
//

#include "Number.h"
Number * Number::createNumber(int type, int x, int y){
    Number * newN=Number::create();
    switch (type) {
        case 2:
            newN->nLabel=Label::createWithSystemFont("2", "", 36);
            break;
        case 4:
            newN->nLabel=Label::createWithSystemFont("4", "", 36);
            break;
        case 8:
            newN->nLabel=Label::createWithSystemFont("8", "", 36);
            break;
        case 16:
            newN->nLabel=Label::createWithSystemFont("16", "", 36);
            break;
        case 32:
            newN->nLabel=Label::createWithSystemFont("32", "", 36);
            break;
        case 64:
            newN->nLabel=Label::createWithSystemFont("64", "", 36);
            break;
        case 128:
            newN->nLabel=Label::createWithSystemFont("128", "", 36);
            break;
        case 256:
            newN->nLabel=Label::createWithSystemFont("258", "", 36);
            break;
        case 512:
            newN->nLabel=Label::createWithSystemFont("512", "", 36);
            break;
        case 1024:
            newN->nLabel=Label::createWithSystemFont("1024", "", 36);
            break;
        case 2048:
            newN->nLabel=Label::createWithSystemFont("2048", "", 36);
            break;
    }
    newN->type=type;
    newN->addChild(newN->nLabel);
    newN->moveTo(x, y);
    
    return newN;
}

bool Number::init(){
    if (!Node::init()) {
        return false;
    }
    
    return true;
}

void Number::moveTo(int x,int y){
    this->nLabel->setPosition(x,y);
    this->nx=x;
    this->ny=y;
}


void Number::doubleNumber(){
    this->type=this->type*2;
    this->nLabel->setString(StringUtils::format("%d",this->type));
}
