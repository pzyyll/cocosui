//
//  chapter2_scene.cpp
//  TestUI
//
//  Created by ZHILI CAI on 2019/3/12.
//

#include "chapter2_scene.h"

using namespace cocos2d;

Scene *Chapter2Scene::createScene() {
    auto scene = Scene::create();
    
    auto layer = Chapter2Scene::create();
    
    scene->addChild(layer);
    
    return scene;
}


bool Chapter2Scene::init() {
    if (!Layer::init())
        return false;
    
    auto root_node = CSLoader::creater()
    
    return true;
}

