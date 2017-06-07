#include "PausaScene.h"
#include "Definiciones.h"
#include "AyudaScene.h"
#include "GameScene.h"
#include "MenuScene.h"

USING_NS_CC;

Scene* PausaScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PausaScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PausaScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	auto director = Director::getInstance();
	Size visibleSize = director->getVisibleSize();

	auto spriteFondo = Sprite::create("images/FondoPausa.png");
		spriteFondo ->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		addChild(spriteFondo, 0);
    
    return true;
}



