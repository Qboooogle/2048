//
//  Menu.h
//  2048
//
//  Created by DonLiu on 14-9-3.
//
//

#ifndef ___048__Menu__
#define ___048__Menu__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class GMenu:Layer{
public:
    static Scene * createScene();
    CREATE_FUNC(GMenu);
    bool init();
    void start(float t);
};
#endif /* defined(___048__Menu__) */
