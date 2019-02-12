#include "Box_Object.h"

Box_Object::Box_Object()
{
}

Box_Object::Box_Object(float sizeX, float sizeY, sf::Color color, b2BodyType type, b2Vec2 position, b2World& world)
{
	BodyDef.position = position;
	BodyDef.type = type;
	Body = world.CreateBody(&BodyDef);
	
	b2PolygonShape Shape;
	Shape.SetAsBox(sizeX / 2, sizeY / 2);
	FixtureDef.density = 1;
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
	float angle = Body->GetAngle();
	b2Vec2 position = Body->GetPosition();

	shape.setPosition(position.x, position.y);
	shape.setRotation((angle * 180) / b2_pi);
}
