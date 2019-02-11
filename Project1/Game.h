#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Game {
public :
	Game();
	~Game();
	void Initialize();
	void Update();
	void Draw();
	void InputMethod();
	b2Vec2 Gravity;
	b2World world;
	sf::RenderWindow window;
};
