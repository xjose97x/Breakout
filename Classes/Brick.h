#ifndef __BRICK_H__
#define __BRICK_H__

#include "cocos2d.h"

class Brick
{
public:
	Brick(cocos2d::Layer *layer, float xOffset, float yOffset);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite *BrickSprite;
};

#endif // __BRICK_H__
