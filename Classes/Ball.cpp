#include "Ball.h"
#include "Definitions.h"

USING_NS_CC;

Ball::Ball(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	BallSprite = Sprite::create("ball.png");
	BallSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	auto BallBody = PhysicsBody::createCircle((BallSprite->getContentSize().height/2), PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	BallBody->setGravityEnable(false);
	BallBody->getShape(0)->setRestitution(1.0f);
	BallBody->getShape(0)->setFriction(0.0f);
	BallBody->getShape(0)->setDensity(0.25f);
	BallBody->applyImpulse(Vec2(10000,-10000));
	BallBody->setCollisionBitmask(BALL_COLLISION_BITMASK);
	BallBody->setContactTestBitmask(true);
	BallSprite->setPhysicsBody(BallBody);
	BallSprite->setTag(1);

	layer->addChild(BallSprite, 100);

}