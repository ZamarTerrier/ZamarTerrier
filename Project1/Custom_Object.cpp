#include "Custom_Object.h"


Custom_Object::Custom_Object()
{
}

Custom_Object::Custom_Object(sf::Color color, b2BodyType type, b2Vec2 position, b2World& world)
{

	b2BodyDef BodyDef;
	BodyDef.position = position;
	BodyDef.type = type;
	Body = world.CreateBody(&BodyDef);

	b2Vec2 verts[3];
	verts[0].Set(0, 0);
	verts[1].Set(14, -28);
	verts[2].Set(28, 0);

	b2EdgeShape Shape;
	Shape.Set(verts[0],verts[1]);
	Shape.Set(verts[1], verts[2]);
	Shape.Set(verts[2], verts[0]);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 10;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);

	shape.setPointCount(3);
	shape.setPoint(0, sf::Vector2f(0, 0));
	shape.setPoint(1, sf::Vector2f(14, -28));
	shape.setPoint(2, sf::Vector2f(28, 0));
	shape.setFillColor(color);

	Body->SetTransform(b2Vec2(200, 100), 30);
}

Custom_Object::~Custom_Object()
{
}

void Custom_Object::Update()
{
	shape.setPosition(sf::Vector2f(Body->GetPosition().x, Body->GetPosition().y));
	shape.setRotation(Body->GetAngle());
}
