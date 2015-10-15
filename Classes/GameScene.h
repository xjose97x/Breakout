#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Paddle.h"
#include "cocos2d.h"
#include "Ball.h"
#include "Brick.h"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
	void SetPhysicsWorld(cocos2d::PhysicsWorld *world)
	{
		sceneWorld = world;
	}


	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	bool onContactBegin(cocos2d::PhysicsContact &contact);
	cocos2d::PhysicsWorld *sceneWorld;
	Paddle *paddle;
	Ball *ball;
	Brick *brick;
	void spawnBricks();
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	bool contact = true;

	unsigned int score;

	cocos2d::Label *scoreLabel;
};

#endif // __GAME_SCENE_H__
