#include "Bird.h"
#include "Difinitions.h"

USING_NS_CC;

Bird::Bird( cocos2d::Layer* layer )
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    flappyBird = Sprite::create( "Ball.png" );
    flappyBird->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );

    auto flappybody = PhysicsBody::createCircle( flappyBird->getContentSize().width / 2 );
    flappybody->setCollisionBitmask( BIRD_COLLISION_BITMASK );
    flappybody->setContactTestBitmask( true );
    
    flappyBird->setPhysicsBody( flappybody );

    layer->addChild( flappyBird, 100 );
    
    isFalling = true;

}

void Bird::Fall( )
{
    if( isFalling == true )
    {
        flappyBird->setPositionX( origin.x + visibleSize.width / 2 );
        flappyBird->setPositionY( flappyBird->getPositionY( ) - ( BIRD_FALLING_SPEED * visibleSize.height ) );
    }
    else
    {
        flappyBird->setPositionX( origin.x + visibleSize.width / 2 );
        flappyBird->setPositionY( flappyBird->getPositionY( ) + ( BIRD_FALLING_SPEED * visibleSize.height ) );
    }

}


