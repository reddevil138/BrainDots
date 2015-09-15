//
//  TiledBodyCreator.h
//  BrainDotsDebug
//
//  Created by Nguyen Minh Hoang on 2015/09/02.
//
//

#ifndef __BrainDotsDebug__TiledBodyCreator__
#define __BrainDotsDebug__TiledBodyCreator__

#include <cocos2d.h>
#include <Box2D/Box2D.h>
#include "SceneManager.h"

USING_NS_CC;

class FixtureDef
{
public:
    FixtureDef()
    : next(nullptr) {}
    
    ~FixtureDef() {
        delete next;
        delete fixture.shape;
    }
    
    FixtureDef *next;
    b2FixtureDef fixture;
    int callbackData;
};

class BodyDef
{
public:
    BodyDef()
    : fixtures(nullptr) {}
    
    ~BodyDef() {
        if (fixtures)
            delete fixtures;
    }
    
    FixtureDef *fixtures;
    Point anchorPoint;
};

class Joint2Body
{
public:
    std::string nameBodyA, nameBodyB;
    b2Body* bodyA, *bodyB;
    bool collideConnected;
    bool enableLimit;
    bool enableMotor;
    b2JointType jointType;
    b2Vec2 localAnchorA;
    b2Vec2 localAnchorB;
    float lowerAngle;
    float maxMotorTorque;
    float motorSpeed;
    float upperAngle;
};

class TiledBodyCreator
{
public:
    // init map
    static void initMapLevel(TMXTiledMap* map, b2World* world, std::string layerName, uint16 categorybits, uint16 maskbits);
    
    static void executeObjectList(cocos2d::TMXTiledMap *map, b2World *world, ValueVector objectList, uint16 categorybits, uint16 maskbits);
    static void executeJointList(b2World *world, ValueVector jointList);
    
    static FixtureDef* createFixture(ValueMap object, b2BodyDef bd);
    
    static FixtureDef* createPolygon(ValueMap object, b2BodyDef bd);
    static FixtureDef* createPolyline(ValueMap object, b2BodyDef bd);
    static FixtureDef* createCircle(ValueMap object, b2BodyDef bd);
    static FixtureDef* createRect(ValueMap object, b2BodyDef bd);
    
    static std::vector<Rect> getRectListObjects(TMXTiledMap* map,std::string objectsName, std::string layerName);
    
    // static body
    static void createStaticBodies(b2World *world, ValueVector staticBodyList, uint16 categorybits, uint16 maskbits);
    
    // dynamic body
    static void createDynamicBodies(cocos2d::TMXTiledMap *map, b2World *world, ValueVector dynamicBodyList, uint16 categorybits, uint16 maskbits);
    
    // create joints
    static void createJoint(b2World* world, Joint2Body* joint);
    
};


#endif /* defined(__BrainDotsDebug__TiledBodyCreator__) */
