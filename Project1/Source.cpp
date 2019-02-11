#include "Game.h"
#include <Windows.h>

Game game;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{

	game.Draw();

	return 0;
}
