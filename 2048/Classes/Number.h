//
//  Number.h
//  2048
//
//  Created by DonLiu on 14-9-1.
//
//

#ifndef ___048__Number__
#define ___048__Number__

#include "cocos2d.h"
USING_NS_CC;

class Number:public Node{
public:
    CREATE_FUNC(Number);
    int type;
    int nx,ny;
    Label * nLabel;
    void doubleNumber();
    static Number * createNumber(int type,int x,int y);
    bool init();
    void moveTo(int x,int y);
};
#endif /* defined(___048__Number__) */
