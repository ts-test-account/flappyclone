#include "LostinSpace.h"
#include "MainMenuScene.h"
#include "Difinitions.h"

USING_NS_CC;

Scene* LostinSpace::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LostinSpace::create();

    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LostinSpace::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    this->scheduleOnce( schedule_selector( LostinSpace::GoToMainMenuScene ), DISPLAY_TIME_LOSTINSPACE_SCENE );

    auto backgroundSprite = Sprite::create( "star.png" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y) );

    this->addChild( backgroundSprite );

    return true;
}

void LostinSpace::GoToMainMenuScene( float dt )
{
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->replaceScene( TransitionFade::create( TRANSITION_TIME, scene));
}
