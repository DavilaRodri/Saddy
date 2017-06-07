#include "IntroScene.h"
#include "Definiciones.h"
#include "MenuScene.h"

USING_NS_CC;

Scene* IntroScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = IntroScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool IntroScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	auto director = Director::getInstance();
	Size visibleSize = director->getVisibleSize();

	this->scheduleOnce(schedule_selector(IntroScene::GoToMenuScene), DISPLAY_TIME_INTRO_SCENE);

	auto spriteFondo = Sprite::create("images/FondoIntro.png");
		spriteFondo ->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		addChild(spriteFondo, 0);
    
    return true;
}

void IntroScene::GoToMenuScene(float dt)
{
	auto scene = MenuScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

