//
//  chapter2_scene.hpp
//  TestUI
//
//  Created by ZHILI CAI on 2019/3/12.
//

#ifndef chapter2_scene_hpp
#define chapter2_scene_hpp

#include <cstdio>

#include "cocos2d.h"

class Chapter2Scene : public cocos2d::Layer {
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Chapter2Scene);
    
private:
    // @todo
    
    double _floor_height;
};

#endif /* chapter2_scene_hpp */
