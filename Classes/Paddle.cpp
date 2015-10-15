#include "Paddle.h"
#include "Definitions.h"

USING_NS_CC;

Paddle::Paddle(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	paddleSprite = Sprite::create("paddle.png");
	paddleSprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height / 2 + origin.y - 175));

	auto paddleBody = PhysicsBody::createBox((cocos2d::Size &)paddleSprite->getContentSize().width);
	paddleBody->getShape(0)->setRestitution(1.0f);
	paddleBody->getShape(0)->setFriction(0.0f);
	paddleBody->getShape(0)->setDensity(10.0f);
	paddleBody->setDynamic(false);
	paddleSprite->setPhysicsBody(paddleBody);
	layer->addChild(paddleSprite, 100);

}

void Paddle::MoveSystem(float pos)
{
	paddleSprite->setPositionX(pos);
}