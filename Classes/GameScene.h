#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:

	void GoToPausaScene(cocos2d::Ref *sender);


	void update(float dt);
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event);
	bool tocando;


	cocos2d::Sprite* _saddy;
	
	void touchListener();
	void moverSaddy(cocos2d::Touch* toque, cocos2d::Event* event);

	float touchPosition;
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event * event);


	

};

#endif // __GAME_SCENE_H__
