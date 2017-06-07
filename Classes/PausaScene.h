#ifndef __PAUSA_SCENE_H__
#define __PAUSA_SCENE_H__

#include "cocos2d.h"

class PausaScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(PausaScene);

private:
	void GoToMenuScene(cocos2d::Ref *sender);
};

#endif // __PAUSA_SCENE_H__
