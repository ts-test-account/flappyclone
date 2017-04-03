#include "Pipe.h"
#include "Difinitions.h"

USING_NS_CC;

Pipe::Pipe( )
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
}

void Pipe::SpawnPipe(cocos2d::Layer* layer)
{
    CCLOG( "Spawn Pipe" );

    auto topPipe = Sprite::create( "Pipe.png" );
    auto bottomPipe = Sprite::create( "Pipe.png" );

    auto topPipeBody = PhysicsBody::createBox( topPipe->getContentSize() );
    auto bottomPipeBody = PhysicsBody::createBox( bottomPipe->getContentSize() );

    topPipeBody->setCollisionBitmask( OBSTACLE_COLLISION_BITMASK );
    bottomPipeBody->setCollisionBitmask( OBSTACLE_COLLISION_BITMASK );
    
    topPipeBody->setContactTestBitmask( true );
    bottomPipeBody->setContactTestBitmask( true );

    topPipeBody->setDynamic( false );
    bottomPipeBody->setDynamic( false );

    topPipe->setPhysicsBody( topPipeBody );
    bottomPipe->setPhysicsBody( bottomPipeBody );

    auto random = CCRANDOM_0_1();
    
    if ( random < LOWER_SCREEN_PIPE_THRESHOLD )
    {
        random = LOWER_SCREEN_PIPE_THRESHOLD;
    }
    else if ( random > UPPER_SCREEN_PIPE_THRESHOLD )
    {
        random = UPPER_SCREEN_PIPE_THRESHOLD;
    }

    auto topPipePosition = ( random * visibleSize.height ) + ( topPipe->getContentSize().height / 2 );

    topPipe->setPosition( Point( origin.x + visibleSize.width + topPipe->getContentSize().width, topPipePosition ) );
    
    bottomPipe->setPosition( Point( topPipe->getPositionX(), topPipePosition - ( Sprite::create( "Ball.png" )->getContentSize().height * PIPE_GAP ) - topPipe->getContentSize().height ) );
    
    layer->addChild( topPipe );
    layer->addChild( bottomPipe );

    auto topPipeAction = MoveBy::create( PIPE_SPAWN_SPEED * visibleSize.width, Point( -visibleSize.width * 1.5, 0) );
    auto bottomPipeAction = MoveBy::create( PIPE_SPAWN_SPEED * visibleSize.width, Point( -visibleSize.width * 1.5, 0) );

    topPipe->runAction( topPipeAction );
    bottomPipe->runAction( bottomPipeAction );

    auto pointNode = Node::create( );
    auto pointBody = PhysicsBody::createBox( Size( 1, Sprite::create( "ball.png" )->getContentSize( ).height * PIPE_GAP));
    
    pointBody->setDynamic( false );
    pointBody->setCollisionBitmask( POINT_COLLISION_BITMASK );
    pointBody->setContactTestBitmask( true );
    
    pointNode->setPhysicsBody( pointBody );
    pointNode->setPosition( Point( topPipe->getPositionX( ), topPipe->getPositionY( ) - ( topPipe->getContentSize( ).height / 2 ) - ((Sprite::create("ball.png")->getContentSize().height * PIPE_GAP) / 2 )));

    layer->addChild( pointNode );

    auto pointNodeAction = MoveBy::create( PIPE_SPAWN_SPEED * visibleSize.width, Point( -visibleSize.width * 1.5, 0) );

    pointNode->runAction( pointNodeAction );
}
