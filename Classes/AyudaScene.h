#ifndef __AYUDA_SCENE_H__
#define __AYUDA_SCENE_H__

#include "cocos2d.h"

class AyudaScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(AyudaScene);

private:
	void GoToGameScene(float dt);
	void GoToMenuScene(float dt);
};

#endif // __AYUDA_SCENE_H__
