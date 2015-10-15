#ifndef __PADDLE_H__
#define __PADDLE_H__

#include "cocos2d.h"

class Paddle
{
public:
	Paddle(cocos2d::Layer *layer);
	void MoveSystem(float pos);
	
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite *paddleSprite;
};

#endif // __PADDLE_H__
