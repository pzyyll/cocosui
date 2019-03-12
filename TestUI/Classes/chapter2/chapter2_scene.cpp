//
//  chapter2_scene.cpp
//  TestUI
//
//  Created by ZHILI CAI on 2019/3/12.
//

#include "chapter2_scene.h"

#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

#include <iostream>

USING_NS_CC;

using namespace cocostudio::timeline;

Scene *Chapter2Scene::createScene() {
    auto scene = Scene::create();
    
    auto layer = Chapter2Scene::create();
    
    scene->addChild(layer);
    
    return scene;
}


bool Chapter2Scene::init() {
    if (!Layer::init())
        return false;
    
    auto root_node = CSLoader::createNode("chapter2/Chapter2Scene.csb");
    
    addChild(root_node);
    
    auto bottom_bg = root_node->getChildByName<Sprite*>("ZigzagForest_Square_1");
    
    bottom_bg->setAnchorPoint(Vec2(0, 0));
    bottom_bg->setPosition(Vec2(0, 0));
    _floor_height = bottom_bg->getContentSize().height;
    
    unsigned bottom_num =
        Director::getInstance()->getVisibleSize().width
            / bottom_bg->getContentSize().width;
    std::cout << bottom_num << std::endl;
    for (unsigned i = 1; i <= bottom_num; ++i) {
        auto bottom_bg_1 = Sprite::createWithTexture(bottom_bg->getTexture());
        bottom_bg_1->setAnchorPoint(Vec2(0, 0));
        bottom_bg_1->setScale(bottom_bg->getScale());
        bottom_bg_1->setContentSize(bottom_bg->getContentSize());
        bottom_bg_1->setPosition(
                                 bottom_bg->getPosition().x + i * bottom_bg->getContentSize().width,
                                 bottom_bg->getPosition().y);
        
        bottom_bg->addChild(bottom_bg_1);
    }
    
    auto player_white = root_node->getChildByName<Sprite*>("White_Front1_4");
    player_white->setVisible(false);
    auto player_lightbule = root_node->getChildByName<Sprite*>("LightBlue_Front1_5");
    player_lightbule->setVisible(false);
    
    auto player_blue = root_node->getChildByName<Sprite*>("Blue_Front1_3");
    player_blue->setAnchorPoint(Vec2(0.5, 0));
    player_blue->setPosition(Vec2(player_blue->getContentSize().width/2, _floor_height));
    
    auto moveto = MoveTo::create(10, Vec2(Director::getInstance()->getVisibleSize().width, _floor_height));
    player_blue->runAction(moveto);
    
    return true;
}

