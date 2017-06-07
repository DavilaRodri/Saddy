#include "AyudaScene.h"
#include "Definiciones.h"
#include "MenuScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* AyudaScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = AyudaScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool AyudaScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }


	auto director = Director::getInstance();
	Size visibleSize = director->getVisibleSize();

	auto spriteFondoAyuda = Sprite::create("images/FondoPausa.png");
	spriteFondoAyuda->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(spriteFondoAyuda, 0);
    
    return true;
}

