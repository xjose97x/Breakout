#include "ShieldScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

//create Scene
Scene* ShieldScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ShieldScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool ShieldScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	//AUDIO PRELOADER
	//CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Hit.mp3");
	//CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Point.mp3");
	//CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Wing.mp3");

	//Screen Size Set
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//Go to Main Menu after 2 seconds(so logo can be seen)
	this->scheduleOnce(schedule_selector(ShieldScene::GoToMainMenu), DISPLAY_TIME_SHIELD_SCENE);
	auto backgroundSprite = Sprite::create("Splash Screen.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);
	return true;
}

void ShieldScene::GoToMainMenu(float dt)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}