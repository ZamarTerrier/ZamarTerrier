#include "Box_Object.h"

Box_Object::Box_Object()
{
}

Box_Object::Box_Object(float sizeX, float sizeY, sf::Color color, b2BodyType type, b2Vec2 position, b2World& world)
{

	b2BodyDef BodyDef;
	BodyDef.position = position;
	BodyDef.type = type;
	Body = world.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(sizeX / 2, sizeY / 2);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 10;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);

	shape.setSize(sf::Vector2f(sizeX, sizeY));
	shape.setOrigin(sizeX / 2, sizeY / 2);
	shape.setFillColor(color);

}

Box_Object::~Box_Object()
{
}

void Box_Object::Update()
{
	shape.setPosition(sf::Vector2f(Body->GetPosition().x, Body->GetPosition().y));
	shape.setRotation(Body->GetAngle());
}
