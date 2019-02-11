#include "Game.h"
#include "Box_Object.h"
#include "Custom_Object.h"

const float SCALE = 32;

Box_Object box;
Box_Object plane;
Custom_Object triangle;


Game::Game():Gravity(0,10), world(Gravity), window(sf::VideoMode(1500, 1000, 64), "ZClub")
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

		window.draw(box.shape);
		window.draw(plane.shape);
		window.draw(triangle.shape);
		
		window.display();

	}
}

void Game::InputMethod()
{
	sf::Mouse key;
	//if (key.isButtonPressed(sf::Mouse::Button::Left)) {
	//	b2Vec2 f = box.Body->GetWorldVector(b2Vec2(0, -5));
	//	b2Vec2 p = box.Body->GetWorldPoint(b2Vec2(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
	//	box.Body->ApplyForce(f, p,false);
	//}
}
