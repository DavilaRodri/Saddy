#include "MenuScene.h"
#include "GameScene.h"
#include "Definiciones.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	auto director = Director::getInstance();
	Size visibleSize = director->getVisibleSize();


	auto spriteFondo = Sprite::create("images/FondoMenu.png");
		spriteFondo ->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		this -> addChild(spriteFondo);

	auto BotonPlay = MenuItemImage::create("images/BotonPlay.png", "images/BotonPlayPulsado.png", CC_CALLBACK_1(MenuScene::GoToGameScene, this));
		BotonPlay->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	auto menu = Menu::create(BotonPlay, NULL);
		menu->setPosition(Point::ZERO);

	this->addChild(menu);

    
    return true;
}

void MenuScene::GoToGameScene(cocos2d::Ref *sender) {
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}

//ME QUEDA TERMINAR LOS BOTONES DE MENU HACIA AYUDA, DE PAUSA A MENU Y COLISIONES

