#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Box_Object {
public :
	Box_Object();
	Box_Object(float sizeX, float sizeY, sf::Color color, b2BodyType type,b2Vec2 position, b2World& world);
	~Box_Object();
	void Update();
	sf::RectangleShape shape;
	b2Body* Body;
	b2BodyDef BodyDef;
	b2PolygonShape Shape;
	b2FixtureDef FixtureDef;
};
