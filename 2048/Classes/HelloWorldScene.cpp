#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto bg = Sprite::create("bg.png");
    bg->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    this->addChild(bg);
    
    for (int i = 0; i<4; i++) {
        row[i]=(visibleSize.width/2-150)+(i*100);
        col[i]=(visibleSize.height/2-150)+(i*100);
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            map[i][j]=0; //空白
        }
    }
    isMove=true;
//    Number * newN = Number::createNumber(4, row[0], col[0]);
//    this->addChild(newN);
//    allNumber.pushBack(newN);
    
    
//    newNumber();
//    this->schedule(schedule_selector(HelloWorld::moveLeft), 1);
//    moveDown();
    
    
    auto event = EventListenerTouchOneByOne::create();
    event->onTouchBegan=[&](Touch * tou,Event * eve){
        m_x=tou->getLocation().x;
        m_y=tou->getLocation().y;
        m_startMove=true;
        return true;
    };
    
    event->onTouchMoved=[&](Touch * tou,Event * eve){
        int x = tou->getLocation().x;
        int y = tou->getLocation().y;
        if (m_startMove&&(abs(m_x-x)>10||abs(m_y-y)>10)) {
            m_startMove=false;
            if (abs(m_x-x)>abs(m_y-y)) {
                if (m_x<x) {
                    HelloWorld::moveRight();
                }else{
                    HelloWorld::moveLeft();
                }
            }else{
                if (m_y<y) {
                    HelloWorld::moveUp();
                }else{
                    HelloWorld::moveDown();
                }
            }
            if (isMove) {
                HelloWorld::newNumber();
            }
        }
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event, this);
    return true;
}

void HelloWorld::newNumber(){
    Number * newW = Number::createNumber(2, 0, 0);
    int freeCount=16-allNumber.size();
//    CCLOG("%d",freeCount);
    srand((unsigned)time(NULL));
    int num=rand()%freeCount;
//    CCLOG("%d",num);
    int i=0;
    int j=0;
    int count=0;
    bool find = false;
    for (; i<4; i++) {
        for (j=0; j<4; j++) {
            if (map[i][j]==0) {
                count++;
                if (count>num) {
                    find=true;
//                    map[i][j]=1;
                    break;
                }
            }
        }
        if (find) {
            break;
        }
    }
    
    newW->moveTo(row[i], col[j]);
    this->addChild(newW);
    allNumber.pushBack(newW);
    map[i][j]=allNumber.getIndex(newW)+1;
    CCLOG("%d,%d",i,j);
    isMove=false;
//    CCLOG("%d",map[i][j]);
}


void HelloWorld::moveLeft(){
    for (int i=1; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (map[i][j]>0) {
                for (int h=i; h>0; h--) {
                    if (map[h-1][j]==0) {
                        map[h-1][j]=map[h][j];
                        map[h][j]=0;
                        allNumber.at(map[h-1][j]-1)->moveTo(row[h-1], col[j]);
                        isMove=true;
                    }else{
                        int numObj=allNumber.at(map[h-1][j]-1)->type;
                        int numNow=allNumber.at(map[h][j]-1)->type;
                        if (numNow==numObj) {
                            isMove=true;
//                            allNumber.at(map[h-1][j]-1)->type=allNumber.at(map[h-1][j]-1)->type*2;
                            allNumber.at(map[h-1][j]-1)->doubleNumber();
                            allNumber.at(map[h][j]-1)->removeFromParent();
                            int index = map[h][j];
                            allNumber.erase(map[h][j]-1);
                            for (int r = 0; r<4; r++) {
                                for (int c = 0; c<4; c++) {
                                    if (map[r][c]>index) {
                                        map[r][c]--;
                                    }
                                }
                            }
                            map[h][j]=0;
                        }
                        break;
                    }
                }
            }
        }
    }
}

void HelloWorld::moveUp(){
    for (int j = 2; j>=0; j--) {
        for (int i = 0; i<4; i++) {
            if (map[i][j]>0) {
                for (int h = j; h<3; h++) {
                    if (map[i][h+1]==0) {
                        map[i][h+1]=map[i][h];
                        map[i][h]=0;
                        allNumber.at(map[i][h+1]-1)->moveTo(row[i], col[h+1]);
                        isMove=true;
                    }else{
                        int numObj=allNumber.at(map[i][h+1]-1)->type;
                        int numNow=allNumber.at(map[i][h]-1)->type;
                        if (numObj==numNow) {
                            isMove=true;
                            allNumber.at(map[i][h+1]-1)->doubleNumber();
                            allNumber.at(map[i][h]-1)->removeFromParent();
                            int index = map[i][h];
                            allNumber.erase(map[i][h]-1);
                            for (int r = 0; r<4; r++) {
                                for (int c = 0; c<4; c++) {
                                    if (map[r][c]>index) {
                                        map[r][c]--;
                                    }
                                }
                            }
                            map[i][h]=0;
                        }
                        break;
                    }
                }
            }
        }
    }
}

void HelloWorld::moveRight(){
    for (int i = 2; i>=0; i--) {
        for (int j = 0; j<4; j++) {
            if (map[i][j]>0) {
                for (int h = i; h<3; h++) {
                    if (map[h+1][j]==0) {
                        map[h+1][j]=map[h][j];
                        map[h][j]=0;
                        allNumber.at(map[h+1][j]-1)->moveTo(row[h+1], col[j]);isMove=true;
                    }else{
                        int numObj=allNumber.at(map[h+1][j]-1)->type;
                        int numNow=allNumber.at(map[h][j]-1)->type;
                        if (numObj==numNow) {
                            isMove=true;
                            allNumber.at(map[h+1][j]-1)->doubleNumber();
                            allNumber.at(map[h][j]-1)->removeFromParent();
                            int index=map[h][j];
                            allNumber.erase(map[h][j]-1);
                            for (int r = 0; r<4; r++) {
                                for (int c = 0; c<4; c++) {
                                    if (map[r][c]>index) {
                                        map[r][c]--;
                                    }
                                }
                            }
                            map[h][j]=0;
                        }
                        break;
                    }
                }
            }
        }
    }
}

void HelloWorld::moveDown(){
    for (int j = 1; j<4; j++) {
        for (int i = 0; i<4;  i++) {
            if (map[i][j]>0) {
                for (int h = j; h>=1; h--) {
                    if (map[i][h-1]==0) {
                        map[i][h-1]=map[i][h];
                        map[i][h]=0;
                        allNumber.at(map[i][h-1]-1)->moveTo(row[i], col[h-1]);
                        isMove=true;
                    }else{
                        int numObj=allNumber.at(map[i][h-1]-1)->type;
                        int numNow=allNumber.at(map[i][h]-1)->type;
                        if (numObj==numNow) {
                            isMove=true;
                            allNumber.at(map[i][h-1]-1)->doubleNumber();
                            allNumber.at(map[i][h]-1)->removeFromParent();
                            int index = map[i][h];
                            allNumber.erase(map[i][h]-1);
                            for (int r = 0; r<4; r++) {
                                for (int c = 0; c<4; c++) {
                                    if (map[r][c]>index) {
                                        map[r][c]--;
                                    }
                                }
                            }
                            map[i][h]=0;
                        }
                        break;
                    }
                }
            }
        }
    }
}



