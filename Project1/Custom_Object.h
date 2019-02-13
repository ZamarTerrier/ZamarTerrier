#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Custom_Object {
public:
	Custom_Object();
	Custom_Object(sf::Color color, b2BodyType type, b2Vec2 position, b2World& world);
	~Custom_Object();
	void Update();
	int dotCount;
	sf::ConvexShape shape;
	b2Body* Body;
};
