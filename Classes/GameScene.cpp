#include "GameScene.h"
#include "Definiciones.h"
#include "PausaScene.h"
#include "AyudaScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void GameScene::moverSaddy(Touch* toque, Event* event) 
{
	auto positiontocado = toque->getLocation();
	if (_saddy->getBoundingBox().containsPoint(positiontocado)) 
	{
		_saddy->setPositionX(positiontocado.x);

	}
}


void GameScene::touchListener()
{
	auto listener1 = EventListenerTouchOneByOne::create();

	listener1->setSwallowTouches(true);
	listener1->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener1->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	listener1->onTouchCancelled = CC_CALLBACK_2(GameScene::onTouchCancelled, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);

	
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	auto director = Director::getInstance();
	Size visibleSize = director->getVisibleSize();
	auto Tamano = director->getWinSize();

	auto spriteFondo = Sprite::create("images/FondoJuego.png");
		spriteFondo ->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		addChild(spriteFondo, 0);

	auto spriteFondo2 = Sprite::create("images/FondoNubes.png");
		spriteFondo2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		this ->addChild(spriteFondo2);

	auto BotonPausa = MenuItemImage::create("images/BotonPausa.png", "images/BotonPausaPulsado.png", CC_CALLBACK_1(GameScene::GoToPausaScene, this));
	BotonPausa->setPosition(1200, 650);

	auto pausa = Menu::create(BotonPausa, NULL);
	pausa->setPosition(Point::ZERO);

	this->addChild(pausa);

	_saddy = Sprite::create("images/Saddy.png");
	_saddy -> setPosition(Tamano.width / 2, Tamano.height * 0.17);
	this->addChild(_saddy, 1);

	touchListener();
	tocando = false;
	touchPosition = 0;
	this->scheduleUpdate();


	return true;
}

void GameScene::GoToPausaScene(cocos2d::Ref *sender) {
	auto scene = PausaScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event)
{
	tocando = true;
	touchPosition = touch->getLocation().x;
	return true;
}


void GameScene::update(float dt)
{



	auto director = Director::getInstance();
	Size visibleSize = director->getVisibleSize();


	if (true == tocando)
	{

		if (touchPosition < visibleSize.width / 2)
		{

			_saddy->setPositionX(_saddy->getPosition().x - (0.50 * visibleSize.width * dt));


			if (_saddy->getPosition().x <= 0 +
				(_saddy->getContentSize().width / 2))
			{
				_saddy->setPositionX(_saddy->getContentSize().width / 2);
			}
		}
		else
		{

			_saddy->setPositionX(_saddy->getPosition().x + (0.50 * visibleSize.width * dt));

			if (_saddy->getPosition().x >=
				visibleSize.width - (_saddy->
					getContentSize().width / 2))
			{
				_saddy->setPositionX(visibleSize.width -
					(_saddy->getContentSize().width / 2));
			}
		}
	}


}


void GameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event)
{
	tocando = false;
}
void GameScene::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event * event)
{
	onTouchEnded(touch, event);
}

