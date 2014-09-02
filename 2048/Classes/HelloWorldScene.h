#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Number.h"
USING_NS_CC;
class HelloWorld : public cocos2d::Layer
{
private:
    LayerColor * colorBack;
    bool m_startMove;
    int m_x,m_y;
    int m_score;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    int row[4];
    int col[4];
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    Vector<Number *> allNumber;
    bool isMove;
    void moveUp();
    void moveLeft();
    void moveDown();
    void moveRight();
    int map[4][4];
    void newNumber();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__