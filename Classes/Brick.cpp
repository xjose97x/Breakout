#include "Brick.h"
#include "Definitions.h"
#include "GameScene.h"

USING_NS_CC;

Brick::Brick(cocos2d::Layer *layer, float xOffset, float yOffset)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	auto BrickSprite = Sprite::create("brick.png");

	auto BrickBody = PhysicsBody::createBox((cocos2d::Size &)BrickSprite->getContentSize().width);
	BrickBody->getShape(0)->setRestitution(1.0f);
	BrickBody->getShape(0)->setFriction(0.0f);
	BrickBody->getShape(0)->setDensity(10.0f);
	BrickBody->setDynamic(false);
	BrickBody->setCollisionBitmask(BRICK_COLLISION_BITMASK);
	BrickBody->setContactTestBitmask(true);

	BrickSprite->setPosition(xOffset, yOffset);
	BrickSprite->setPhysicsBody(BrickBody);

	layer->addChild(BrickSprite);
}
