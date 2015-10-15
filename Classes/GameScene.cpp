#include "GameScene.h"
#include "Definitions.h"
#include "Box2D\Dynamics\b2Body.h"
#include "GameOverScene.h"

USING_NS_CC;

//create Scene
Scene* GameScene::createScene()
{
	
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Background.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);
	//borders collision
	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeBody->getShape(0)->setRestitution(1.0f);
	edgeBody->getShape(0)->setFriction(0.0f);
	edgeBody->getShape(0)->setDensity(1.0f);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeBody->setCollisionBitmask(WALL_COLLISION_BITMASK);
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);
	edgeNode->setTag(0);
	paddle = new Paddle(this);
	ball = new Ball(this);
	int arrbrick[50];
	GameScene::spawnBricks();



	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	score = 0;

	__String *tempScore = __String::createWithFormat("%i", score);

	scoreLabel = Label::createWithTTF(tempScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
	scoreLabel->setColor(Color3B::WHITE);
	scoreLabel->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height * 0.75 + origin.y));

	this->addChild(scoreLabel, 10000);
	
	this->scheduleUpdate();
	return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event)
{
	return true;
}
void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	auto pos = touch->getLocationInView().x;
	paddle->MoveSystem(pos);
}

void GameScene::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact & contact)
{
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();
	if ((BALL_COLLISION_BITMASK == a->getCollisionBitmask() && (BRICK_COLLISION_BITMASK) == b->getCollisionBitmask()) ||
		(BALL_COLLISION_BITMASK == b->getCollisionBitmask() && (BRICK_COLLISION_BITMASK) == a->getCollisionBitmask()))
	{
		
		auto bricky = b->getNode();
		this->removeChild(bricky);

		score++;
		__String *tempScore = __String::createWithFormat( "%i", score );
        scoreLabel->setString( tempScore->getCString( ) );
		if (score == 50)
		{
			auto scene = GameOverScene::createScene(score);

			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		}
	}
	return true;
}

void GameScene::spawnBricks()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	float padding = 46;
	float col = 19;
	int tag = 0;
	for (int i = 0; i < 10; i++, col += 24)
	{
		for (int j = 0; j < 5; j++, padding += 58.5, tag++)
		{
			float xOffset = (visibleSize.width / 2 + (origin.x / 2)) + padding;
			float yOffset = (visibleSize.height / 2 + (origin.y / 2) + 21) + col;
			brick = new Brick(this ,xOffset, yOffset);
		}
		padding = 46;
	}
}