#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Box_Object.h"
#include "Custom_Object.h"

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
private:
	const float SCALE = 32;
	Box_Object box;
	Box_Object plane;
	Custom_Object triangle;
};
