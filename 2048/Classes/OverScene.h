//
//  OverScene.h
//  2048
//
//  Created by DonLiu on 14-9-3.
//
//

#ifndef ___048__OverScene__
#define ___048__OverScene__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class OverScene:Layer{
public:
    static Scene * createScene();
    CREATE_FUNC(OverScene);
    bool init();
    void start(float t);
};
#endif /* defined(___048__OverScene__) */
