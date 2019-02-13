#include "Game.h"
#include "Box_Object.h"
#include "Custom_Object.h"
#include <math.h>

const float SCALE = 32;

Box_Object box;
Box_Object plane;
Custom_Object triangle;


Game::Game():Gravity(0,10), world(Gravity), window(sf::VideoMode(800, 600, 64), "ZClub")
{
	Initialize();
}

Game::~Game()
{
}

void Game::Initialize()
{
	box = Box_Object(50, 50, sf::Color::Red, b2BodyType::b2_dynamicBody, b2Vec2(100, 100), world);

	plane = Box_Object(800, 16, sf::Color::Black, b2BodyType::b2_staticBody, b2Vec2(0, 300), world);

	triangle = Custom_Object(sf::Color::Red, b2BodyType::b2_dynamicBody, b2Vec2(150, 100), world);
}

void Game::Update()
{
	world.Step(1 / 30.f, 8, 3);

	box.Update();

	plane.Update();

	triangle.Update();

	InputMethod();

}

void Game::Draw()
{

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Blue);

		Update();

		for (int i = 0; i < triangle.shape.getPointCount(); i++) {
			sf::CircleShape s(5);
			s.setFillColor(sf::Color::Green);
			s.setOrigin(sf::Vector2f(5, 5));
			sf::Vector2f origPos = triangle.shape.getPosition();
			origPos.x = origPos.x + (triangle.shape.getPoint(i).x * (std::sin(triangle.shape.getRotation() / b2_pi)));
			origPos.y = origPos.y + (triangle.shape.getPoint(i).y * (std::cos(triangle.shape.getRotation() / b2_pi)));
			s.setPosition(origPos);
			window.draw(s);
		}

		window.draw(box.shape);
		window.draw(plane.shape);
		window.draw(triangle.shape);
		
		window.display();

	}
}

void Game::InputMethod()
{
	sf::Vector2i pixPos = sf::Mouse::getPosition(window);
	sf::Vector2f pos = window.mapPixelToCoords(pixPos);

	b2Vec2 dist;
	dist.x = pos.x - box.Body->GetPosition().x;
	dist.y = pos.y - box.Body->GetPosition().y;

	b2Vec2 dist2;
	dist2.x = pos.x - triangle.Body->GetPosition().x;
	dist2.y = pos.y - triangle.Body->GetPosition().y;

	sf::Mouse key;
	if (key.isButtonPressed(sf::Mouse::Button::Left)) {

		box.Body->SetLinearVelocity(dist);
		box.Body->SetAngularVelocity(0.1f);
		triangle.Body->SetLinearVelocity(dist2);
		triangle.Body->SetAngularVelocity(0.1f);

	}
}
