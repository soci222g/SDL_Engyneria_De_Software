#include<SDL3/SDL.h>
#include <exception>
#include"Game.h"
#include <iostream>

int main() {
	Game game;
	
	try {

		game.Init();

	}
	catch (std::exception e) {
		std::cout << "Error: " << e.what();
		game.releas();
		return -1;
	}


	
	while (!game.IsRunning())
	{
		
		game.HandleElement();
		game.Update();
		game.Renderer();
		
	}
	game.releas();

	return 0;

}

