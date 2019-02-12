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
	verts[1].Set(28, -56);
	verts[2].Set(56, 0);

	b2PolygonShape Shape;
	Shape.Set(verts,3);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 10;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);

	shape.setPointCount(3);
	shape.setPoint(0, sf::Vector2f(0, 0));
	shape.setPoint(1, sf::Vector2f(28, -56));
	shape.setPoint(2, sf::Vector2f(56, 0));
	shape.setFillColor(color);

}

Custom_Object::~Custom_Object()
{
}

void Custom_Object::Update()
{
	float angle = Body->GetAngle();
	b2Vec2 position = Body->GetPosition();

	shape.setPosition(position.x, position.y);
	shape.setRotation((angle * 180) / b2_pi);
}
